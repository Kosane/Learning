#include "filedialog.h"
#include "ui_filedialog.h"
#include <QFile>
#include <QTextStream>




FileDialog::FileDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileDialog)
{
    ui->setupUi(this);
}

FileDialog::~FileDialog()
{
    delete ui;
}


void FileDialog::openFile(){
  QString filename =  QFileDialog::getOpenFileName(
        this,
        "Открыть",
        QDir::currentPath(),
        "All files (*.*)");

  if( !filename.isNull() )
  {
    path = filename.toUtf8();
  }
}

