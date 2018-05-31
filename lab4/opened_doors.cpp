#include "opened_doors.h"

doors::doors(QObject *parent) : QObject(parent)
{
    mState = State::CLOSED;
    mTimer = nullptr;
}

void doors::onOpening(){
    mState = State::OPENING;
    emit doOpening();
    mTimer = new QTimer;
    mTimer->setInterval(opening_interval);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(onOpened()));
    mTimer->start();
//    mState = State::OPENING; // поставить в начало
}

void doors::onOpened(){
    mState = State::OPENED;
    delete mTimer;
    emit doOpened();
    mTimer = new QTimer;
    mTimer->setInterval(staying_interval);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(onClosing()));
    mTimer->start();
//    mState = State::OPENED;
}

void doors::onClosing(){
    mState = State::CLOSING;
    delete mTimer;
    emit doClosing();
    mTimer = new QTimer;
    mTimer->setInterval(closing_interval);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(onClosed()));
    mTimer->start();
//    mState = State::CLOSING;
}

void doors::onClosed(){
    mState = State::CLOSED;
    delete mTimer;
    doClosed();
//    mState = State::CLOSED;
}
