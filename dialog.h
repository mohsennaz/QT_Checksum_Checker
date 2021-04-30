#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();



private slots:
    void on_btnCalculate_clicked();

    void on_btnClear_clicked();

private:
    Ui::Dialog *ui;

    QString getRadioButton(QObject* obj);
};

#endif // DIALOG_H
