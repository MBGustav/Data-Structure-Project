#ifndef QUESTIONARIO_H
#define QUESTIONARIO_H

#include <QDialog>

namespace Ui {
class Questionario;
}

class Questionario : public QDialog
{
    Q_OBJECT

public:
    explicit Questionario(QWidget *parent = nullptr);
    ~Questionario();

private:
    Ui::Questionario *ui;
};

#endif // QUESTIONARIO_H
