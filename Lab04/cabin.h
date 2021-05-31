#pragma once

#include <QObject>

#include <constants.h>
#include <control_panel.h>
#include <door.h>
#include <weight_sensor.h>

class Cabin : public QObject {
  Q_OBJECT
  enum cabin_state { MOVE, WAIT, STOP };

public:
  explicit Cabin(QObject *parent = nullptr);

  void enter(int weight);
  void exit(int weight);

signals:
  void called();
  void floor_crossed(int floor, direction d);
  void target_reached(int floor);
  void stopped(int floor);

public slots:
  void move();
  void stop();
  void call(int floor, direction dir);

private:
  int current_floor;
  int target;
  bool new_target;
  cabin_state current_state;
  direction current_direction;
  Doors doors;
  WeightSensor weight_sensor;
  QTimer crossing_floor_timer;
  QTimer wait_opened_timer;
};
