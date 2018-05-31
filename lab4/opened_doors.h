#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>


class doors : public QObject
{
    Q_OBJECT
public:
    doors(){
        mState = State::CLOSED;
        mTimer = nullptr;
    };
    explicit doors(QObject *parent = nullptr);

private:
    enum class State
    {
        OPENED,
        OPENING,
        CLOSED,
        CLOSING
    };

    State mState;
    QTimer* mTimer;
    static const size_t opening_interval = 1000;
    static const size_t closing_interval = 1000;
    static const size_t staying_interval = 1000;

signals:
    void doOpening();
    void doOpened();
    void doClosing();
    void doClosed();

public slots:
    void onOpening();
    void onOpened();
    void onClosing();
    void onClosed();
};

#endif // DOORS_H
