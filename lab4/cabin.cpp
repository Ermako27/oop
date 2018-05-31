#include "cabin.h"

cabin::cabin(QObject *parent) : QObject(parent)
{
    mState = State::IDLE;
    mMotor = new motor(nullptr);
    mDoors = new doors(nullptr);
    mCurrentLevel = 1;
    mRequestedLevels = new QSet<int>;

    connect(this, SIGNAL(doMoveUp()), mMotor, SLOT(onMoveUp()));
    connect(this, SIGNAL(doMoveDown()), mMotor, SLOT(onMoveDown()));
    connect(this, SIGNAL(doStop()), mMotor, SLOT(onStop()));
    connect(this, SIGNAL(doOpen()), mDoors, SLOT(onOpening()));

    connect(mMotor, SIGNAL(doMoveUp()), this, SLOT(onMovingUp()));
    connect(mMotor, SIGNAL(doMoveDown()), this, SLOT(onMovingDown()));
    connect(mMotor, SIGNAL(doStop()), this, SLOT(onIdle()));

    connect(mDoors, SIGNAL(doOpening()), this, SLOT(onOpening()));
    connect(mDoors, SIGNAL(doOpened()), this, SLOT(onOpened()));
    connect(mDoors, SIGNAL(doClosing()), this, SLOT(onClosing()));
    connect(mDoors, SIGNAL(doClosed()), this, SLOT(onIdle()));
}

void cabin::onPushButton(int level){
    mLog.printLevelCall(level);
    mRequestedLevels->insert(level);
    if (mState == State::IDLE){
        int nearest = getNearestLevel();
        if (nearest != 0){
            if (nearest > mCurrentLevel){
                emit doMoveUp();
            } else if (nearest < mCurrentLevel){
                emit doMoveDown();
            } else {
                emit doOpen();
            }
        }
    }
    mState = State::BUTTON_PUSHED;
}

void cabin::onMovingUp(){
    ++mCurrentLevel;
    mLog.printLevelMoveUp(mCurrentLevel);
    if (mRequestedLevels->contains(mCurrentLevel)){
        emit doStop();
    }
    mState = State::MOVING_UP;
}

void cabin::onMovingDown(){
    --mCurrentLevel;
    mLog.printLevelMoveDown(mCurrentLevel);
    if (mRequestedLevels->contains(mCurrentLevel)){
        emit doStop();
    }
    mState = State::MOVING_DOWN;
}

void cabin::onIdle(){
    if (mState == State::CLOSING){
        mLog.printString("Двери лифта закрыты");
    } else if (mState == State::MOVING_UP || mState == State::MOVING_DOWN){
        mLog.printLevelStop(mCurrentLevel);
    }
    int nearest = getNearestLevel();
    if (nearest != 0){
        if (nearest > mCurrentLevel){
            emit doMoveUp();
        } else if (nearest < mCurrentLevel){
            emit doMoveDown();
        }
        else{
            emit doOpen();
        }
    }
    mState = State::IDLE;
}

void cabin::onOpening(){
    mLog.printString("Двери лифта открываются");
    mState = State::OPENING;
}

void cabin::onOpened(){
    mLog.printString("Двери лифта открыты");
    mRequestedLevels->remove(mCurrentLevel);
    mState = State::OPENED;
}

void cabin::onClosing(){
    mLog.printString("Двери лифта закрываются");
    mState = State::CLOSING;
}

bool cabin::n(int level, int nearest){
    return abs(mCurrentLevel - level) < abs(mCurrentLevel - nearest);
}

int cabin::getNearestLevel(){
    int nearest = 0;
    for (auto level = mRequestedLevels->begin(); level != mRequestedLevels->end(); level++){
        if ((nearest == 0) || max(*level, nearest)){
            nearest = *level;
        }
    }
    return nearest;
}
