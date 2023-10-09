#include "errordialog.h"
#include "ui_errordialog.h"
#include "texts.h"

ErrorDialog::ErrorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorDialog)
{
    ui->setupUi(this);
    ui->ERROR_FILE->setText(ERROR_FILE);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowIcon(QIcon(":error_icon.png"));
}

ErrorDialog::~ErrorDialog()
{
    delete ui;
}

void ErrorDialog::on_pushButton_clicked(){
    close();
}
