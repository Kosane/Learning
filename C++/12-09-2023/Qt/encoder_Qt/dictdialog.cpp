#include "dictdialog.h"
#include "ui_dictdialog.h"

DictDialog::DictDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DictDialog)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowIcon(QIcon(":dict_icon.png"));
}

DictDialog::~DictDialog()
{
    delete ui;
}

void DictDialog::setDictionary(QString dictionary){

    this->ui->Dictionary->setText(dictionary);
}

void DictDialog::on_pushButton_clicked()
{
    close();
}
