#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QWidget>
#include <QMessageBox>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>
#include <QKeyEvent>
#include <QString>
#include <QPlainTextEdit>
#include <QTimer>
#include <QtGui>
#include <QtCore>
#include <QObject>
#include <QEvent>
#include <QtGui>
#include <QImage>
#include <QProgressBar>
#include <QProgressDialog>
#include <QtCharts>


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
    void on_ExitButton_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_action_2_triggered();
    void on_action_4_triggered();
    void on_action_5_triggered();
    void on_action_6_triggered();
    void on_button6_clicked();
    void on_pushButton_7_clicked();
    void on_button9_clicked();
    void on_button8_clicked();
    void nosignal();
    void nosignal_2();
    void nosignal_3();
    void nosignal_4();
    void on_button10_clicked();
    void on_button11_clicked();    

private:
    Ui::MainWindow *ui;
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    QChart *chrt;

};
#endif // MAINWINDOW_H
