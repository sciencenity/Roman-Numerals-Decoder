#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::romanConverter(QString rom){
    std::string roman = rom.toStdString();
    std::unordered_map<char, int> romanMap = {
           {'I', 1},
           {'V', 5},
           {'X', 10},
           {'L', 50},
           {'C', 100},
           {'D', 500},
           {'M', 1000}
       };
       int total = 0;
       int prevValue = 0;
       for (int i = roman.size() - 1; i >= 0; --i) {
           char currentChar = roman[i];
           int currentValue = romanMap[currentChar];
           if (currentValue < prevValue) {
               total -= currentValue;
           } else {
               total += currentValue;
           }
           prevValue = currentValue;
       }
       return QString::fromStdString(std::to_string(total));
   }

void MainWindow::on_pushButton_clicked()
{
    QString toDecode = ui->lineEdit->text();
    ui->textBrowser->setText(romanConverter(toDecode));
}
