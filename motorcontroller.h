#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <QtQml/qqmlregistration.h>
#include <QObject>
#include <QTimer>
#include "motor.h"
#include "pidcontroller.h"

class MotorController : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(double speed READ speed NOTIFY speedChanged)
    Q_PROPERTY(bool running READ running NOTIFY runningChanged)
    Q_PROPERTY(double target READ target WRITE setTarget NOTIFY targetChanged)
public:
    explicit MotorController(QObject *parent = nullptr);
    double speed() const;
    bool running() const;
    double target() const;
    void setTarget(double newTarget);


public slots:
    void start();
    void stop();

signals:
    void speedChanged();
    void runningChanged();
    void targetChanged();


private:
    void step();
    Motor m_motor;
    PidController m_pid;
    QTimer m_timer;
    double m_target=1500.0;
    bool m_running=false;
};


#endif // MOTORCONTROLLER_H
