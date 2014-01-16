#include "ProgressMessageBox.h"
#include "ui_ProgressMessageBox.h"

ProgressMessageBox::ProgressMessageBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressMessageBox)
{
    ui->setupUi(this);
}

ProgressMessageBox::~ProgressMessageBox()
{
    delete ui;
}

void ProgressMessageBox::setFileLabelName(QString s)
{
    ui->progressLabel->setText(s);
}

void ProgressMessageBox::on_pushButton_clicked()
{
    this->close();
}
