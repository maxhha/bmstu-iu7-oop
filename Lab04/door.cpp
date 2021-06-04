#include <door.h>

#include <QDebug>

Doors::Doors(QObject *parent) : QObject(parent), current_state(OPENED) {
  doors_open_timer.setSingleShot(true);
  doors_close_timer.setSingleShot(true);

  QObject::connect(
              &doors_open_timer,
              SIGNAL(timeout()),
              this,
              SLOT(finish_openning()));

  QObject::connect(
              &doors_close_timer,
              SIGNAL(timeout()),
              this,
              SLOT(finish_closing()));
}

void Doors::start_openning() {
  if (CLOSED != current_state && CLOSING != current_state)
    return;

  qDebug() << "Doors are opening...";

  if (current_state == CLOSED) {
    doors_open_timer.start(DOORS_TIME);
  } else {
    int t = doors_close_timer.remainingTime();
    doors_close_timer.stop();
    doors_open_timer.start(DOORS_TIME - t);
  }


  current_state = OPENING;
}

void Doors::start_closing() {
  if (OPENED != current_state && OPENING != current_state)
      return;

  qDebug() << "Doors are closing...";

  if (current_state == OPENED) {
    doors_close_timer.start(DOORS_TIME);
  } else {
    int t = doors_open_timer.remainingTime();
    doors_open_timer.stop();
    doors_close_timer.start(DOORS_TIME - t);
  }

  current_state = CLOSING;
}

void Doors::finish_openning() {
  if (current_state != OPENING)
    return;

  qDebug() << "The doors are opened!";
  qDebug() << "Waiting for passengers...";

  current_state = OPENED;
  emit doors_opened();
}

void Doors::finish_closing() {
  if (current_state != CLOSING)
    return;

  qDebug() << "The doors are closed.";

  current_state = CLOSED;
  emit doors_closed();
}
