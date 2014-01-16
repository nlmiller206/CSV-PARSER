#ifndef PROGRESSMESSAGEBOX_H
#define PROGRESSMESSAGEBOX_H

#include <QWidget>
#include <QString>

namespace Ui {
class ProgressMessageBox;
}

class ProgressMessageBox : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressMessageBox(QWidget *parent = 0);
    ~ProgressMessageBox();

    void setFileLabelName(QString s);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ProgressMessageBox *ui;
};

#endif // PROGRESSMESSAGEBOX_H
