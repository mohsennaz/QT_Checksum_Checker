#include "dialog.h"
#include "ui_dialog.h"



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->radioButton_Hex->setChecked(true);
    ui->linedit_Input->setInputMask(">HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH HH");
    ui->linedit_Input->setMaxLength(100);


    /* define not editable the qLineEdit in defualt */
    ui->lineedit_Result->setReadOnly(true);

    /*QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::gray);
    palette->setColor(QPalette::Text,Qt::darkGray);
    ui->lineedit_Result->setPalette(*palette);*/

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnCalculate_clicked()
{
    /*qDebug() << "The calculatation clicked";
    ui->lineedit_Result->setText("Test");*/

    /* get input value entered by user */
    QString input = ui->linedit_Input->text();
    QString typeInput = getRadioButton(ui->groupBox);
    if(typeInput == "Hex")
    {
        bool ok;
        qDebug() << "The Input Value is = " << input.toInt(&ok,16);
        QStringList inputvalue = input.split(' ');
        ui->lineedit_Result->setText(input);
        int lenght = ((ui->linedit_Input->text().length() + 1 - 35) / 2 );
        qDebug() << "The lenght of text is = " << lenght << "byets";
        foreach(QString v, inputvalue)
        {
            if(v == "")
            {
                break;
            }
            else
            {
                bool ok;
             qDebug() << v.toInt(&ok,16);
            }

        }



    }
    else if (typeInput == "Decimal")
    {

    }



}

void Dialog::on_btnClear_clicked()
{
    ui->linedit_Input->clear();
    ui->lineedit_Result->clear();
}

QString Dialog::getRadioButton(QObject *obj)
{
    QString textRadioButton = "None";
    QList<QRadioButton*> list = obj->findChildren<QRadioButton*>(QString(), Qt::FindDirectChildrenOnly);

    foreach(QRadioButton* rdo, list)
    {
        if(rdo->isChecked())
        {
            textRadioButton = rdo->text();
            break;
        }
    }

    qDebug() << "The type of input is = " << textRadioButton;
    return textRadioButton;

}
