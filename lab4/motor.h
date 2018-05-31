#ifndef Motor_H
#define Motor_H

#include <QObject>
#include <QTimer>


class motor : public QObject
{
    Q_OBJECT
public:
    motor(){
        mState = State::IDLE;
        mTimer = nullptr;
    };
    explicit motor(QObject *parent = nullptr);

private:
    enum class State
    {
        IDLE,
        MOVING_UP,
        MOVING_DOWN,
    };

    State mState;
    QTimer* mTimer;

    static const size_t moving_interval = 2000;

signals:
    void doStart();
    void doMoveUp();
    void doMoveDown();
    void doStop();

public slots:
    void onMoveUp();
    void onMoveDown();
    void onStop();
    void MoveUpEmitter() {emit doMoveUp();}
    void MoveDownEmitter() {emit doMoveDown();}
};

#endif // Motor_H
