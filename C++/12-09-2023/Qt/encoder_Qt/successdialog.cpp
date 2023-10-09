#include "successdialog.h"
#include "ui_successdialog.h"
#include "texts.h"

SuccessDialog::SuccessDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SuccessDialog)
{
    ui->setupUi(this);
    ui->SUCCESSED->setText(SUCCESSED);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowIcon(QIcon(":success_icon.png"));
}

SuccessDialog::~SuccessDialog()
{
    delete ui;
}

void SuccessDialog::on_pushButton_clicked(){
    close();
}
