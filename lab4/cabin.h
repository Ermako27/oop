#ifndef cabin_H
#define cabin_H

#include <QObject>
#include <QSet>
#include <math.h>
#include "opened_doors.h"
#include "motor.h"
#include "infolog.h"

class cabin : public QObject
{
    Q_OBJECT
public:
    explicit cabin(QObject *parent = nullptr);

private:
    enum class State
    {
        BUTTON_PUSHED,
        MOVING_UP,
        MOVING_DOWN,
        IDLE,
        OPENING,
        OPENED,
        CLOSING
    };
    State mState;
    motor* mMotor;
    doors* mDoors;
    infolog mLog;
    QSet<int>* mRequestedLevels;
    int mCurrentLevel;

    int getNearestLevel();
    bool nearestFloor(int level, int nearest);

signals:
    void doMoveUp();
    void doMoveDown();
    void doOpen();
    void doStop();

public slots:
    void onPushButton(int level);
    void onMovingUp();
    void onMovingDown();
    void onIdle();
    void onOpening();
    void onClosing();
    void onOpened();
};

#endif // cabin_H
