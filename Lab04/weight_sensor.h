#pragma once

#include <QObject>

#include <constants.h>

class WeightSensor : public QObject {

  Q_OBJECT
  enum weight_sensor_state { NORMAL, IGNORE  };

public:
  explicit WeightSensor(QObject *parent = nullptr);
  void increase_weight(int weight);
  void decrease_weight(int weight);

signals:
  void overweight(bool overweight);

public slots:
   void start_ignore();
   void end_ignore();

private:
  weight_sensor_state current_state;
  int weight;
};
