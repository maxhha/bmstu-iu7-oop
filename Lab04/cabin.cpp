#include <cabin.h>

#include <QString>

#include <QDebug>

Cabin::Cabin(QObject *parent)
    : QObject(parent), current_floor(1), target(-1), new_target(false),
      current_state(STOP), current_direction(STAY) {
  crossing_floor_timer.setSingleShot(true);
  overweight_timer.setSingleShot(false);

  QObject::connect(this, SIGNAL(cabin_called()), &doors, SLOT(start_closing()));
  QObject::connect(this, SIGNAL(cabin_reached_target(int)), this,
                   SLOT(cabin_stopping()));

  QObject::connect(this, SIGNAL(cabin_stopped(int)), &doors,
                   SLOT(start_openning()));

  QObject::connect(&doors, SIGNAL(closed_doors()), this, SLOT(cabin_move()));
  QObject::connect(&crossing_floor_timer, SIGNAL(timeout()), this,
                   SLOT(cabin_move()));

  QObject::connect(&weight_sensor, SIGNAL(overweight(bool)), this, SLOT(set_overweight(bool)));
  QObject::connect(&overweight_timer, SIGNAL(timeout()), &doors, SLOT(start_openning()));
}

void Cabin::enter(int weight) {
  weight_sensor.increase_weight(weight);
  qDebug() << "Enter " << weight << " kg";
}

void Cabin::exit(int weight) {
  weight_sensor.decrease_weight(weight);
  qDebug() << "Exit " << weight << " kg";
}

void Cabin::set_overweight(bool overweight) {
  if (current_state != WAIT && current_state != STOP)
     return;

  if (overweight) {
      current_state = OVERWEIGHT;
      overweight_timer.start(OVERWEIGHT_REOPEN);
  } else {
      current_state = WAIT;
      overweight_timer.stop();
  }
}

void Cabin::cabin_move() {
  if (new_target && current_state == WAIT) {
    current_state = MOVE;

    if (current_floor == target) {
      emit cabin_reached_target(current_floor);
    } else {
      crossing_floor_timer.start(CROSSING_FLOOR);
    }

    return;
  }

  if (current_state == MOVE) {
    current_state = MOVE;

    current_floor += current_direction;

    if (current_floor == target) {
      emit cabin_reached_target(current_floor);
    } else {
      emit cabin_crossing_floor(current_floor, current_direction);
      crossing_floor_timer.start(CROSSING_FLOOR);
    }
  }
}

void Cabin::cabin_stopping() {
  if (current_state != MOVE)
    return;

  current_state = STOP;
  qDebug() << "Stopped at floor " << QString::number(current_floor) << ".";
  emit cabin_stopped(current_floor);
}

void Cabin::cabin_call(int floor, direction dir) {
  if (current_state != STOP)
    return;

  new_target = true;
  current_state = WAIT;
  target = floor;

  current_direction = dir;
  emit cabin_called();
}
