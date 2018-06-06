#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QLineEdit>
#include <vector>
#include "facade.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Facade* facade;
    QGraphicsScene *holst;
    void draw();
    double scanField(QLineEdit*);
    int getPointSize(std::vector<Point> point);
    int getPolygonSize(Figure* f, int i);
    int getPolygon(Figure* f, int i, int j);
    Point getPoint(Figure* f, int ind);
    ~MainWindow();

protected slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

protected:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
