#include <control_panel.h>

#include <iostream>

#include <QDebug>

ControlPanel::ControlPanel(QObject *parent)
    : QObject(parent), cur_floor(1), cur_target(-1),
      is_target(NUM_FLOORS, false), current_state(WAIT), cur_direction(STAY) {

    QObject::connect(
                this,
                SIGNAL(set_target(int, direction)),
                this,
                SLOT(pass_floor(int)));
}

void ControlPanel::set_new_target(int floor) {
  is_target[floor - 1] = true;

  if (cur_target == -1) {
    cur_target = floor;
  }

  if ((cur_direction == UP && floor > cur_target) ||
      (cur_direction == DOWN && floor < cur_target)) {
    cur_target = floor;
  }

  next_target(floor);
  cur_direction = (cur_floor > cur_target) ? DOWN : UP;

  emit set_target(floor, cur_direction);
}

void ControlPanel::reach_floor(int floor) {
  if (current_state != WATCH)
    return;

  cur_floor = floor;
  is_target[floor - 1] = false;

  if (cur_floor == cur_target) {
    cur_target = -1;
    find_new_target();
  }

  current_state = WAIT;

  if (next_target(floor)) {
    cur_direction = (cur_floor > cur_target) ? DOWN : UP;

    emit set_target(floor, cur_direction);
  }
}

void ControlPanel::pass_floor(int floor) {
  if (WATCH != current_state && WAIT != current_state)
    return;

  qDebug() << "Panel is watching cabin moving...";

  if (WATCH == current_state)
       cur_floor = floor;

  current_state = WATCH;
}

void ControlPanel::find_new_target() {
  int state = false;

  if (cur_direction == UP) {
    for (int i = NUM_FLOORS; i >= 1 && !state; i--) {
      if (is_target[i - 1]) {
        state = true;
        cur_target = i;
      }
    }
    return;
  }

  for (int i = 1; i <= NUM_FLOORS && !state; i++) {
    if (is_target[i - 1]) {
      state = true;
      cur_target = i;
    }
  }
}

bool ControlPanel::next_target(int &floor) {
  bool state = false;
  if (cur_target > cur_floor) {
    bool flag = true;
    for (int i = cur_floor; i <= NUM_FLOORS && flag; i += 1) {
      if (is_target[i - 1]) {
        floor = i;
        state = true;
        flag = false;
      }
    }
  } else {
    bool flag = true;
    for (int i = cur_floor; i >= 1 && flag; i -= 1) {
      if (is_target[i - 1]) {
        floor = i;
        state = true;
        flag = false;
      }
    }
  }
  return state;
}
