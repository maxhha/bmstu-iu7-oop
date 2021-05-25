#pragma once

#include <QObject>
#include <QTextEdit>

#include <cabin.h>
#include <constants.h>
#include <control_panel.h>

class Lift : public QObject {
  Q_OBJECT

public:
  Lift();
  void click(int floor);
  void enter(int weight);
  void exit(int weight);

private:
  ControlPanel control_panel;
  Cabin cabin;
};
