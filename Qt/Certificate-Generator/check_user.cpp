#include "check_user.h"
#include "ui_check_user.h"
#include "string"
#include <QMessageBox>
Check_User::Check_User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Check_User)
{
    ui->setupUi(this);
}


Check_User::~Check_User()
{
    delete ui;
}


enum type_user {adm = 0, coord, def};
struct users
{
    type_user tipo;
    QString user;
    QString pass;
}
users[] = {{adm,"admin", "admin"},
           {coord,"palestrante", "123456"},
           {def,"usuario", "usuario"}};

void Check_User::on_pushButton_clicked()
{
     //fix-me: erro com uso de sizeof() total_users deve ser automatico
    int total_users = 4;
    bool Auth_login = false;
    int i = 0;
    QString user = ui->txt_user->text();
    QString pass = ui->txt_pass->text();
    type_user log_type;
    do {
        if(users[i].user == user && users[i].pass == pass){
            Auth_login = true;
            log_type = users[i].tipo;
        }
    i++;
    }while (i <= total_users);
    QString texto;

    switch (log_type) {
    case(adm):
        texto = "Administrador";
        break;
    case (coord):
        texto = "Palestrante";
        break;
    case (def):
        texto = "Usuario Comum";
        break;
    }

    if(Auth_login){
     QMessageBox::information(this, "Login Efetuado!", "Usuario logado como "+texto);

    }
    else{
        QMessageBox::warning(this, "Erro de Login!", "Usuario e/ou senha incorretos");
    }
}

