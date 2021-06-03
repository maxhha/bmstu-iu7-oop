#include <weight_sensor.h>
#include <QDebug>

WeightSensor::WeightSensor(QObject *parent)
    : QObject(parent), current_state(NORMAL), weight(0) {
}

void WeightSensor::increase_weight(int w) {
    if (current_state != NORMAL)
            return;

    qDebug() << "Enter" << w << "kg; Now " << weight + w << "kg";

    if (weight + w > MAX_WEIGHT)
    {
        qDebug() << "OVERWEIGHT!";
        emit overweight();
    }

    weight += w;
}

void WeightSensor::decrease_weight(int w) {
    if (current_state != NORMAL)
        return;

    qDebug() << "Exit" << w << "kg; Now " << weight - w << "kg";

    if (weight > MAX_WEIGHT && weight - w <= MAX_WEIGHT) {
        qDebug() << "WEIGHT BECOME NORMAL!";
        emit normal();
    }

    weight -= w;
}

void WeightSensor::deactivate() {
    if (NORMAL != current_state)
        return;

    qDebug() << "Weight sensor was deactivated.";
    current_state = IGNORE;
}

void WeightSensor::activate() {
    if (IGNORE != current_state)
        return;

    qDebug() << "Weight sensor was activated!";
    current_state = NORMAL;
}
