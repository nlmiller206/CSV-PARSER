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
            commaSeparatedFileList+=",";
        }
    }
    ui->FileLineEdit->setText(commaSeparatedFileList);

}

void MainWindow::on_AddFileButton_clicked()
{
    QStringList files=ui->FileLineEdit->text().split(",");

    for(int i=0;i<files.size();i++){
        ui->listWidget->addItem(files.at(i));
    }//endfor

}

void MainWindow::on_ValidateButton_clicked()
{
    messageBox=new ProgressMessageBox();
    messageBox->show();
    for(int i=0;i<ui->listWidget->count();i++){
        messageBox->setFileLabelName(ui->listWidget->item(i)->text());
        parsePIMSFile(ui->listWidget->item(i)->text());
    }//endfor

    messageBox->close();
    delete messageBox;
}

void MainWindow::parsePIMSFile(QString fileName)
{
    //return from the function if the file is an incorrect format (i.e. not csv)
    if(!fileName.contains(".csv")){
        return;
    }//endif

    //create the QFile file handler, and return if the file doesn't open properly based on the parameters
    QFile readfile(fileName);
    if(!readfile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }//endif

    QString fixedFile;
    fixedFile=fileName+"_fixed";
    QFile writefile(fixedFile);
    if(!writefile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }//endif

    QTextStream infile(&readfile);
    QTextStream outfile(&writefile);


}




















