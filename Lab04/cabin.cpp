#include <cabin.h>

#include <QString>

#include <QDebug>

Cabin::Cabin(QObject *parent)
    : QObject(parent), current_floor(1), target(-1), new_target(false),
      current_state(PENDING), current_direction(STAY) {
  crossing_floor_timer.setSingleShot(true);
  wait_opened_timer.setSingleShot(true);
  wait_opened_timer.setInterval(LOAD_TIME + DOORS_TIME);

  QObject::connect(
              this,
              SIGNAL(called()),
              &doors,
              SLOT(start_closing()));

  QObject::connect(
              this,
              SIGNAL(target_reached(int)),
              this,
              SLOT(stop()));

  QObject::connect(
              this,
              SIGNAL(stopped(int)),
              &doors,
              SLOT(start_openning()));

  QObject::connect(
              this,
              SIGNAL(stopped(int)),
              &weight_sensor,
              SLOT(activate()));

  QObject::connect(
              &wait_opened_timer,
              SIGNAL(timeout()),
              this,
              SLOT(pend()));

  QObject::connect(
              &doors,
              SIGNAL(doors_closed()),
              &weight_sensor,
              SLOT(deactivate()));

  QObject::connect(
              &doors,
              SIGNAL(doors_closed()),
              this,
              SLOT(move()));

  QObject::connect(
              &crossing_floor_timer,
              SIGNAL(timeout()),
              this,
              SLOT(move()));

  QObject::connect(
              &weight_sensor,
              SIGNAL(overweight()),
              &doors,
              SLOT(start_openning()));

  QObject::connect(
              &weight_sensor,
              SIGNAL(overweight()),
              &wait_opened_timer,
              SLOT(stop()));

  QObject::connect(
              &weight_sensor,
              SIGNAL(normal()),
              this,
              SLOT(pend()));
}

void Cabin::enter(int weight) {
  weight_sensor.increase_weight(weight);
}

void Cabin::exit(int weight) {
  weight_sensor.decrease_weight(weight);
}

void Cabin::move() {

  if (current_state != WAIT && current_state != MOVE)
    return;

  if (current_state == MOVE)
  {
    current_floor += current_direction;
  }

  qDebug() << "Cabin is moving [" << current_floor << "]... tun tun turu tun tun tuturu";

  current_state = MOVE;

  if (current_floor != target) {
    crossing_floor_timer.start(CROSSING_FLOOR);
  }

  if (current_floor == target) {
    emit target_reached(current_floor);
  } else {
    emit floor_crossed(current_floor, current_direction);
  }
}

void Cabin::stop() {
  if (MOVE != current_state)
    return;

  qDebug() << "Cabin stopped at floor" << current_floor << ".";

  current_state = STOP;
  wait_opened_timer.start();
  emit stopped(current_floor);
}

void Cabin::pend() {
    if (STOP != current_state)
        return;

    qDebug() << "Fetch call";

    current_state = PENDING;
    emit wait_call();
}

void Cabin::call(int floor, direction dir) {
  if (current_state != PENDING)
    return;

  qDebug() << "Cabin called to" << floor << ".";

  new_target = true;
  current_state = WAIT;
  target = floor;
  current_direction = dir;
  emit called();
}
