#include <lift.h>

Lift::Lift() {
  QObject::connect(
              &control_panel,
              SIGNAL(set_target(int, direction)),
              &cabin,
              SLOT(call(int, direction)));

  QObject::connect(
              &cabin,
              SIGNAL(floor_crossed(int, direction)),
              &control_panel,
              SLOT(pass_floor(int)));

  QObject::connect(
              &cabin,
              SIGNAL(stopped(int)),
              &control_panel,
              SLOT(reach_floor(int)));
}

void Lift::click(int floor) { control_panel.set_new_target(floor); }
void Lift::enter(int weight) { cabin.enter(weight); }
void Lift::exit(int weight) { cabin.exit(weight); }
