#include <weight_sensor.h>

WeightSensor::WeightSensor(QObject *parent)
    : QObject(parent), current_state(NORMAL), weight(0) {
}

void WeightSensor::increase_weight(int w) {

    if (current_state != NORMAL)
            return;

    if (weight + w > MAX_WEIGHT)
        emit overweight(true);

    weight += w;
}

void WeightSensor::decrease_weight(int w) {
    if (current_state != NORMAL)
        return;

    if (weight - w <= MAX_WEIGHT)
        emit overweight(false);

    weight -= w;
}

void WeightSensor::start_ignore() {
    current_state = IGNORE;
}

void WeightSensor::end_ignore() {
    current_state = NORMAL;
}
