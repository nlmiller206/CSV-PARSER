#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_FileBrowseButton_clicked()
{
    QStringList fileList;
    fileList=QFileDialog::getOpenFileNames();

    QString commaSeparatedFileList;
    for(int i=0;i<fileList.size();i++){
        commaSeparatedFileList+=fileList.at(i);
        if(i<(fileList.size()-1)){
            commaSeparatedFileList+=", ";
        }
    }
    ui->FileLineEdit->setText(commaSeparatedFileList);

}
