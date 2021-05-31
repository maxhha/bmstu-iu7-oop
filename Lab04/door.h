#pragma once

#include <QObject>

#include <constants.h>

class Doors : public QObject {
  Q_OBJECT
  enum doors_state { OPENING, OPENED, CLOSING, CLOSED };

public:
  explicit Doors(QObject *parent = nullptr);

signals:
  void doors_closed();
  void doors_opened();

public slots:
  void start_openning();
  void start_closing();

private slots:
  void finish_openning();
  void finish_closing();

private:
  doors_state current_state;
  QTimer doors_open_timer;
  QTimer doors_close_timer;
};
