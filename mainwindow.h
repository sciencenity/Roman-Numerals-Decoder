#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<string>
#include<map>
#include<iostream>
#include <unordered_map>
#include<QKeyEvent>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::MainWindow *ui;
    QString romanConverter(QString rom);
protected:
    void keyPressEvent(QKeyEvent *e) override;
};
#endif // MAINWINDOW_H
