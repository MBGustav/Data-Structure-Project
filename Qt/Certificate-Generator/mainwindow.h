#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "check_user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Check_User *check;
};
#endif // MAINWINDOW_H
