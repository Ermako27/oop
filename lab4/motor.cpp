#include "motor.h"

motor::motor(QObject *parent) : QObject(parent)
{
    mState = State::IDLE;
    mTimer = nullptr;
}

void motor::onMoveUp(){
    mState = State::MOVING_UP;
    emit doStart();
    mTimer = new QTimer;
    mTimer->setInterval(moving_interval);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(MoveUpEmitter()));
    mTimer->start();
}

void motor::onMoveDown(){
    mState = State::MOVING_DOWN;
    emit doStart();
    mTimer = new QTimer;
    mTimer->setInterval(moving_interval);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(MoveDownEmitter()));
    mTimer->start();
}

void motor::onStop(){
    mState = State::IDLE;
    delete mTimer;
    emit doStop();
}
