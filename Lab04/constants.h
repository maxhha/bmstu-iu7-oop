#pragma once

#include <QTextEdit>
#include <QTimer>
#include <QObject>

#include <pub_consts.h>

enum direction {
    DOWN = -1,
    STAY,
    UP
};

#define CROSSING_FLOOR 1500
#define DOORS_TIME 2000
#define WAITING_TIME 2000
#define MAX_WEIGHT 200
#define LOAD_TIME 10000
