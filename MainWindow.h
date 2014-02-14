#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "ProgressMessageBox.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_FileBrowseButton_clicked();

    void on_AddFileButton_clicked();

    void on_ValidateButton_clicked();

private:
    Ui::MainWindow *ui;
    ProgressMessageBox *messageBox;

    //private functions
    void parsePIMSFile(QString fileName);
};

#endif // MAINWINDOW_H
