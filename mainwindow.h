#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include <QWaitCondition>
#include <QSemaphore>
#include <pthread.h>
#include <string>
#include "trem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int calcValue(int value, int percent);
    QString getFormatedValue(int value);


public slots:
    void updateInterface(int,int,int);
    void on_velTrem01_valueChanged(int value);
    void on_velTrem02_valueChanged(int value);
    void on_velTrem04_valueChanged(int value);
    void on_velTrem03_valueChanged(int value);
    void on_velTrem05_valueChanged(int value);

private slots:
    void start_trains();

private:
    Ui::MainWindow *ui;

    //trens presentes na interface do usuário
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
};

#endif // MAINWINDOW_H
