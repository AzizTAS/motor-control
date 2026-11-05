#include <QTest>
#include "../pidcontroller.h"
#include "../motor.h"

class TestPidController : public QObject
{
    Q_OBJECT

private slots:
    void pOnlyOutput();
    void outputIsLimitedToOne();
    void outputNeverNegative();
    void reachesTarget();
};

void TestPidController::pOnlyOutput()
{
    PidController pid(0.001, 0.0, 0.0);

    QCOMPARE(pid.compute(1500.0, 1000.0, 0.1), 0.5);
}

void TestPidController::outputIsLimitedToOne()
{
    PidController pid(0.001, 0.0, 0.0);
    QCOMPARE(pid.compute(1500.0, 0.0, 0.1), 1.0);
}

void TestPidController::outputNeverNegative()
{
    PidController pid(0.001, 0.0, 0.0);
    QCOMPARE(pid.compute(1500.0, 2000.0, 0.1), 0.0);
}

void TestPidController::reachesTarget()
{
    Motor motor;
    const double target = 1500.0;
    const double dt = 0.1;
    PidController pid(0.001, 0.002, 0.0);
    for (int i = 1; i <= 100; i++) {
        double power = pid.compute(target, motor.speed(), dt);
        motor.update(power, dt);
    }
    QVERIFY(qAbs(motor.speed() - target) < 15.0);
}

QTEST_APPLESS_MAIN(TestPidController)
#include "tst_pidcontroller.moc"
