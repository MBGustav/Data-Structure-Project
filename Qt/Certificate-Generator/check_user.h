#ifndef CHECK_USER_H
#define CHECK_USER_H

#include <QDialog>

namespace Ui {
class Check_User;
}

class Check_User : public QDialog
{
    Q_OBJECT

public:
    explicit Check_User(QWidget *parent = nullptr);
    ~Check_User();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Check_User *ui;
};

#endif // CHECK_USER_H
