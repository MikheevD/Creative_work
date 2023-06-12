#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  QPixmap igm(":/img/igm/1663872039_1-phonoteka-org-p-foni-dlya-prilozhenii-krasivo-1.jpg");
  igm = igm.scaled(this->size(), Qt::IgnoreAspectRatio);
  QPalette palette;
  palette.setBrush(QPalette::Background, igm);
  this->setPalette(palette);
  QPixmap pc(":/img/igm/1247691.jpg");
  int w = ui->pushButton->width();
  int h =  ui->pushButton->height();
  ui->pushButton->setIcon(pc.scaled(w,h,Qt::KeepAspectRatio));
  ui->pushButton_4->setIcon(pc.scaled(w,h,Qt::KeepAspectRatio));
  ui->pushButton_2->setIcon(pc.scaled(w,h,Qt::KeepAspectRatio));
  ui->pushButton_3->setIcon(pc.scaled(w,h,Qt::KeepAspectRatio));
  ui->pushButton_5->setIcon(pc.scaled(w,h,Qt::KeepAspectRatio));
  ui->pushButton_6->setIcon(pc.scaled(w,h,Qt::KeepAspectRatio));
  ui->pushButton_7->setIcon(pc.scaled(w,h,Qt::KeepAspectRatio));
  ui->pushButton->hide();
  ui->pushButton_2->hide();
  ui->pushButton_3->hide();
  ui->pushButton_4->hide();
  ui->pushButton_5->hide();
  ui->pushButton_6->hide();
  ui->pushButton_7->hide();
  ui->button1->hide();
  ui->button2->hide();
  ui->button3->hide();
  ui->button4->hide();
  ui->button5->hide();
  ui->textEdit->hide();
  ui->label->hide();
  ui->button6->hide();
  ui->label_5->hide();
  ui->label_6->hide();
  ui->label_7->hide();
  ui->label_8->hide();
  ui->label_9->hide();
  ui->lineEdit->hide();
  ui->lineEdit_2->hide();
  ui->lineEdit_3->hide();
  ui->lineEdit_4->hide();
  ui->lineEdit_5->hide();
  ui->label_10->hide();
  ui->label1->hide();
  ui->label2->hide();
  ui->label3->hide();
  ui->label4->hide();
  ui->label5->hide();
  ui->label6->hide();
  ui->button8->hide();
  ui->button9->hide();
  ui->button10->hide();
  ui->button11->hide();
  ui->textEdit_2->hide();
  ui->widget->hide();

}


MainWindow::~MainWindow()
{

    delete ui;
}



void MainWindow::on_ExitButton_clicked()
{
    QString User = ui->UserEdit->text();
    QString password = ui->passwordEdit->text();

    if (User == "admin" && password == "admin")
    {       
        QMessageBox::information(this, "Авторизация","Добро пожаловать!");
        ui->statusbar->showMessage("Добро пожаловать!");
        QTimer::singleShot(320000, this, &MainWindow::nosignal);
        QTimer::singleShot(500000, this, &MainWindow::nosignal_2);
        QTimer::singleShot(200000, this, &MainWindow::nosignal_3);
        QTimer::singleShot(30000, this, &MainWindow::nosignal_4);
        ui->ExitButton->hide();
        ui->UserEdit->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->passwordEdit->hide();
        ui->pushButton->show();
        ui->pushButton_2->show();
        ui->pushButton_3->show();
        ui->pushButton_4->show();
        ui->pushButton_5->show();
        ui->pushButton_6->show();
         ui->pushButton_7->show();
        ui->button5->show();
        ui->textEdit->show();
        ui->label->show();
        ui->label1->show();
        ui->label2->show();
        ui->label3->show();
        ui->label4->show();
        ui->label5->show();
        ui->label6->show();
        ui->widget->show();

        chrt = new QChart;
        ui->widget->setChart(chrt);
        chrt->setTitle("Состояние сети");
        QValueAxis *axiaX = new QValueAxis;
        axiaX->setRange(0, 1000);
        axiaX->setTickCount(10);
        axiaX->setLabelFormat("%g");

        QValueAxis *axiaY = new QValueAxis;
        axiaY->setRange(-1, 1);
        axiaY->setTickCount(3);
        axiaY->setLabelFormat("%g");

        QLineSeries *serias1 = new QLineSeries();
        QLineSeries *serias2 = new QLineSeries();
        serias1->setName("Качество подключения");
        serias2->setName("Помехи в соединении");

        for (int i=0; i<150;i++)
        {
            serias1->append(i, 1);
            serias2->append(i, -1);

        }
        for (int i=150; i<300;i++)
        {
            serias1->append(i, 0);
            serias2->append(i, -1);

        }
        for (int i=300; i<500;i++)
        {
            serias1->append(i, 0);
            serias2->append(i, 0);

        }
        for (int i=500; i<650;i++)
        {
            serias1->append(i, 1);
            serias2->append(i, 0);

        }
        for (int i=650; i<800;i++)
        {
            serias1->append(i, 0);
            serias2->append(i, -1);

        }
        for (int i=800; i<1000;i++)
        {
            serias1->append(i, 1);
            serias2->append(i, -1);

        }

        chrt->addSeries(serias1);
        chrt->addSeries(serias2);

        chrt->setAxisX(axiaX, serias1);
        chrt->setAxisY(axiaY, serias1);
        chrt->setAxisX(axiaX, serias2);
        chrt->setAxisY(axiaY, serias2);



    }
    else if( User == "user" && password == "qwerty")
    {QMessageBox::information(this, "Авторизация","Добро пожаловать!");
        ui->statusbar->showMessage("Добро пожаловать!");
        ui->ExitButton->hide();
        ui->UserEdit->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->passwordEdit->hide();
        ui->button8->show();
        ui->button9->show();
        ui->button1->show();
        ui->button2->show();
        ui->button3->show();
        ui->button4->show();
        ui->widget->show();

        chrt = new QChart;
        ui->widget->setChart(chrt);
        chrt->setTitle("Состояние сети");
        QValueAxis *axiaX = new QValueAxis;
        axiaX->setRange(0, 1000);
        axiaX->setTickCount(10);
        axiaX->setLabelFormat("%g");

        QValueAxis *axiaY = new QValueAxis;
        axiaY->setRange(-1, 1);
        axiaY->setTickCount(3);
        axiaY->setLabelFormat("%g");

        QLineSeries *serias1 = new QLineSeries();
        QLineSeries *serias2 = new QLineSeries();
        serias1->setName("Качество подключения");
        serias2->setName("Помехи в соединении");

        for (int i=0; i<150;i++)
        {
            serias1->append(i, 1);
            serias2->append(i, -1);

        }
        for (int i=150; i<300;i++)
        {
            serias1->append(i, 1);
            serias2->append(i, -1);

        }
        for (int i=300; i<500;i++)
        {
            serias1->append(i, 0);
            serias2->append(i, 0);

        }
        for (int i=500; i<650;i++)
        {
            serias1->append(i, 0);
            serias2->append(i, 0);

        }
        for (int i=650; i<800;i++)
        {
            serias1->append(i, 1);
            serias2->append(i, -1);

        }
        for (int i=800; i<1000;i++)
        {
            serias1->append(i, 1);
            serias2->append(i, -1);

        }
        chrt->addSeries(serias1);
        chrt->addSeries(serias2);

        chrt->setAxisX(axiaX, serias1);
        chrt->setAxisY(axiaY, serias1);
        chrt->setAxisX(axiaX, serias2);
        chrt->setAxisY(axiaY, serias2);

    }
    else {
        QMessageBox::warning(this, "Авторизация","Неверный логин или пароль!");
        ui->statusbar->showMessage("Не верный логин или пароль");
    }

}






void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "Подключение", "Доступ разрешен, вы подключены к компютеру 1");
    ui->statusbar->showMessage("Вы подключены к компьютеру 1.");
    ui->button1->show();
    ui->button2->show();
    ui->button3->show();
    ui->button4->show();
    ui->button6->show();
    ui->label_5->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->label_9->show();
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
    ui->label_10->show();
    ui->lineEdit->setText("192.168.0.2");
    QString Ip = ui->lineEdit->text();
    ui->lineEdit->setText(Ip);

}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this, "Подключение", "Доступ разрешен, вы подключены к компютеру 2.");
    ui->statusbar->showMessage("Вы подключены к компьютеру 2.");
    ui->button1->show();
    ui->button2->show();
    ui->button3->show();
    ui->button4->show();
    ui->button6->show();
    ui->label_5->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->label_9->show();
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
    ui->label_10->show();
    ui->lineEdit->setText("192.168.0.10");
    QString Ip = ui->lineEdit->text();
    ui->lineEdit->setText(Ip);
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::information(this, "Подключение", "Доступ разрешен, вы подключены к компютеру 3.");
    ui->statusbar->showMessage("Вы подключены к компьютеру 3.");
    ui->button1->show();
    ui->button2->show();
    ui->button3->show();
    ui->button4->show();
    ui->button6->show();
    ui->label_5->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->label_9->show();
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
    ui->label_10->show();
    ui->lineEdit->setText("192.168.0.3");
    QString Ip = ui->lineEdit->text();
    ui->lineEdit->setText(Ip);
}


void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::information(this, "Подключение", "Доступ разрешен, вы подключены к компютеру 4.");
    ui->statusbar->showMessage("Вы подключены к компьютеру 4.");
    ui->button1->show();
    ui->button2->show();
    ui->button3->show();
    ui->button4->show();
    ui->button6->show();
    ui->label_5->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->label_9->show();
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
    ui->label_10->show();
    ui->lineEdit->setText("192.168.0.21");
    QString Ip = ui->lineEdit->text();
    ui->lineEdit->setText(Ip);
}


void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::information(this, "Подключение", "Доступ разрешен, вы подключены к компютеру 5.");
    ui->statusbar->showMessage("Вы подключены к компьютеру 5.");
    ui->button1->show();
    ui->button2->show();
    ui->button3->show();
    ui->button4->show();
    ui->button6->show();
    ui->label_5->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->label_9->show();
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
    ui->label_10->show();
    ui->lineEdit->setText("192.168.0.67");
    QString Ip = ui->lineEdit->text();
    ui->lineEdit->setText(Ip);
}


void MainWindow::on_pushButton_6_clicked()
{    
    QMessageBox::information(this, "Подключение", "Доступ разрешен, вы подключены к компютеру 6.");
    ui->statusbar->showMessage("Вы подключены к компьютеру 6.");
    ui->button1->show();
    ui->button2->show();
    ui->button3->show();
    ui->button4->show();
    ui->button6->show();
    ui->label_5->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->label_9->show();
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
    ui->label_10->show();
    ui->lineEdit->setText("192.168.0.43");
    QString Ip = ui->lineEdit->text();
    ui->lineEdit->setText(Ip);
}


void MainWindow::on_button1_clicked()
{
     QDesktopServices::openUrl(QUrl("file:///C:/Windows/System32/Taskmgr.exe", QUrl::TolerantMode));
}


void MainWindow::on_button2_clicked()
{
    QDesktopServices::openUrl(QUrl("file:///C:/Windows/System32/cmd.exe", QUrl::TolerantMode));
}


void MainWindow::on_button3_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Перезагрузка сети","Отправить команду на перезагруку соединения?",
                                                                 QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
     QMessageBox::information(this, "Перезагрузка сети","Команда была успешна отправлена.");
     ui->statusbar->showMessage("Команда успешно отправлена.");
    }
    else
    {
    QMessageBox::information(this, "Перезагрука сети","Команда не была отправлена");
    ui->statusbar->showMessage("Команда не была отправлена.");
}
}


void MainWindow::on_button4_clicked()
{
QMessageBox::StandardButton reply = QMessageBox::question(this,"Перезагрузка ПК","Отправить команду на перезагруку компьтера?",
                                                             QMessageBox::Yes | QMessageBox::No);
if(reply == QMessageBox::Yes){
 QMessageBox::information(this, "Перезагрузка","Команда была успешна отправлена.");
 ui->statusbar->showMessage("Команда успешно отправлена.");
}
else
{
QMessageBox::information(this, "Перезагрука","Команда не была отправлена");
ui->statusbar->showMessage("Команда не была отправлена.");
}

}


void MainWindow::on_button5_clicked()
{    
    QMessageBox reg;
    reg.setWindowTitle("Cообщение");
    QString data = ui->textEdit->toPlainText();
    reg.setText("Сообщение отправлено!\n" +data);
    reg.setFixedHeight(10);
    reg.setFixedWidth(10);
    reg.exec();
    ui->statusbar->showMessage("Сообщение успешно отправлено.");
    ui->textEdit->clear();

}


void MainWindow::on_action_2_triggered()
{
    ui->button1->hide();
    ui->button2->hide();
    ui->button3->hide();
    ui->button4->hide();
    ui->button6->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->label_10->hide();


}


void MainWindow::on_action_4_triggered()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->button1->hide();
    ui->button2->hide();
    ui->button3->hide();
    ui->button4->hide();
    ui->ExitButton->show();
    ui->UserEdit->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->passwordEdit->show();
    ui->button6->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->label_10->hide();
    ui->button5->hide();
    ui->textEdit->hide();
    ui->label->hide();
    ui->label1->hide();
    ui->label2->hide();
    ui->label3->hide();
    ui->label4->hide();
    ui->label5->hide();
    ui->label6->hide();
    ui->button8->hide();
    ui->button9->hide();
    ui->button10->hide();
    ui->button11->hide();
    ui->textEdit_2->hide();
     ui->widget->hide();


}


void MainWindow::on_action_5_triggered()
{
    QApplication::quit();
}


void MainWindow::on_action_6_triggered()
{

}


void MainWindow::on_button6_clicked()
{
   QMessageBox::StandardButton reply = QMessageBox::question(this, "Новые сетевые настроки", "Вы хотите изменитьсетевые настроики?",
                               QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
     QMessageBox::information(this,"Сетевые настроки", "Изменение сетевых настроек.");
     ui->statusbar->showMessage("Сетевые настроки измененны.");
    }
    else
    {
    QMessageBox::information(this, "Сетевые настроки","Настроки не изменинны.");

}
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->button1->hide();
    ui->button2->hide();
    ui->button3->hide();
    ui->button4->hide();
    ui->button6->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->label_10->hide();
}


void MainWindow::on_button9_clicked()
{
    QMessageBox::information(this, "Обновление","Обновление сетевых данных.");
    ui->statusbar->showMessage("Обновление сетевых данных успешно выполнена.");
}


void MainWindow::on_button8_clicked()
{
    QMessageBox::information(this, "Отчет","Отчет успешно отправлен.");
    ui->statusbar->showMessage("Отчет был успешно отправлен.");
}

void MainWindow::nosignal()
{
    QMessageBox::warning(this, "Ошибка ","Наблюдается сбой в работе сети!");
    ui->label1->setStyleSheet("background-color:red");
    ui->label5->setStyleSheet("background-color:red");
    ui->button10->show();
    ui->button11->show();
    ui->textEdit_2->show();
    ui->textEdit_2->setText("Наблюдается ошибка сети, нет сигнала с компютера 3 и 5. Просьба проверить соединение или перезагрузить его.");

    chrt = new QChart;
    ui->widget->setChart(chrt);
    chrt->setTitle("Состояние сети");
    QValueAxis *axiaX = new QValueAxis;
    axiaX->setRange(0, 1000);
    axiaX->setTickCount(10);
    axiaX->setLabelFormat("%g");

    QValueAxis *axiaY = new QValueAxis;
    axiaY->setRange(-1, 1);
    axiaY->setTickCount(3);
    axiaY->setLabelFormat("%g");

    QLineSeries *serias1 = new QLineSeries();
    QLineSeries *serias2 = new QLineSeries();
    serias1->setName("Качество подключения");
    serias2->setName("Помехи в соединении");

    for (int i=0; i<150;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);

    }
    for (int i=150; i<300;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);

    }
    for (int i=300; i<500;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);

    }
    for (int i=500; i<650;i++)
    {
        serias1->append(i, 0);
        serias2->append(i, 0);

    }
    for (int i=650; i<800;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);

    }
    for (int i=800; i<1000;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);

    }

    chrt->addSeries(serias1);
    chrt->addSeries(serias2);

    chrt->setAxisX(axiaX, serias1);
    chrt->setAxisY(axiaY, serias1);
    chrt->setAxisX(axiaX, serias2);
    chrt->setAxisY(axiaY, serias2);


}

void MainWindow::nosignal_2()
{
    QMessageBox::warning(this, "Ошибка ","Наблюдается сбой в работе сети!");
    ui->label3->setStyleSheet("background-color:red");
    ui->label2->setStyleSheet("background-color:red");
    ui->label6->setStyleSheet("background-color:red");
    ui->button10->show();
    ui->button11->show();
    ui->textEdit_2->show();
    ui->textEdit_2->setText("Наблюдается ошибка сети, нет сигнала с компютера 2, 1 и 6. Просьба проверить соединение или перезагрузить его.");

    chrt = new QChart;
    ui->widget->setChart(chrt);
    chrt->setTitle("Состояние сети");
    QValueAxis *axiaX = new QValueAxis;
    axiaX->setRange(0, 1000);
    axiaX->setTickCount(10);
    axiaX->setLabelFormat("%g");

    QValueAxis *axiaY = new QValueAxis;
    axiaY->setRange(-1, 1);
    axiaY->setTickCount(3);
    axiaY->setLabelFormat("%g");

    QLineSeries *serias1 = new QLineSeries();
    QLineSeries *serias2 = new QLineSeries();
    serias1->setName("Качество подключения");
    serias2->setName("Помехи в соединении");

    for (int i=0; i<150;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    for (int i=150; i<300;i++)
    {
        serias1->append(i, 0);
        serias2->append(i, 0);
    }
    for (int i=300; i<500;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    for (int i=500; i<650;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, -1);
    }
    for (int i=650; i<800;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    for (int i=800; i<1000;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    chrt->addSeries(serias1);
    chrt->addSeries(serias2);
    chrt->setAxisX(axiaX, serias1);
    chrt->setAxisY(axiaY, serias1);
    chrt->setAxisX(axiaX, serias2);
    chrt->setAxisY(axiaY, serias2);
}

void MainWindow::nosignal_3()
{
    QMessageBox::warning(this, "Ошибка ","Наблюдается сбой в работе сети!");
    ui->label1->setStyleSheet("background-color:red");
    ui->label4->setStyleSheet("background-color:red");
    ui->label2->setStyleSheet("background-color:red");
    ui->label6->setStyleSheet("background-color:red");
    ui->button10->show();
    ui->button11->show();
    ui->textEdit_2->show();
    ui->textEdit_2->setText("Наблюдается ошибка сети, нет сигнала с компютера 2, 1, 4 и 6 . Просьба проверить соединение или перезагрузить его.");
    chrt = new QChart;
    ui->widget->setChart(chrt);
    chrt->setTitle("Состояние сети");
    QValueAxis *axiaX = new QValueAxis;
    axiaX->setRange(0, 1000);
    axiaX->setTickCount(10);
    axiaX->setLabelFormat("%g");

    QValueAxis *axiaY = new QValueAxis;
    axiaY->setRange(-1, 1);
    axiaY->setTickCount(3);
    axiaY->setLabelFormat("%g");

    QLineSeries *serias1 = new QLineSeries();
    QLineSeries *serias2 = new QLineSeries();
    serias1->setName("Качество подключения");
    serias2->setName("Помехи в соединении");

    for (int i=0; i<150;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    for (int i=150; i<300;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    for (int i=300; i<500;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    for (int i=500; i<650;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    for (int i=650; i<800;i++)
    {
        serias1->append(i, 0);
        serias2->append(i, 0);
    }
    for (int i=800; i<1000;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    chrt->addSeries(serias1);
    chrt->addSeries(serias2);
    chrt->setAxisX(axiaX, serias1);
    chrt->setAxisY(axiaY, serias1);
    chrt->setAxisX(axiaX, serias2);
    chrt->setAxisY(axiaY, serias2);
}

void MainWindow::nosignal_4()
{
    QMessageBox::warning(this, "Ошибка ","Наблюдается сбой в работе сети!");
    ui->label1->setStyleSheet("background-color:red");
    ui->label2->setStyleSheet("background-color:red");
    ui->label3->setStyleSheet("background-color:red");
    ui->label4->setStyleSheet("background-color:red");
    ui->label5->setStyleSheet("background-color:red");
    ui->label6->setStyleSheet("background-color:red");
    ui->button10->show();
    ui->button11->show();
    ui->textEdit_2->show();
    ui->textEdit_2->setText("Наблюдается ошибка сети, сигнал полностью отсутствует. Просьба проверить соединение или перезагрузить его.");
    chrt = new QChart;
    ui->widget->setChart(chrt);
    chrt->setTitle("Состояние сети");
    QValueAxis *axiaX = new QValueAxis;
    axiaX->setRange(0, 1000);
    axiaX->setTickCount(10);
    axiaX->setLabelFormat("%g");

    QValueAxis *axiaY = new QValueAxis;
    axiaY->setRange(-1, 1);
    axiaY->setTickCount(3);
    axiaY->setLabelFormat("%g");

    QLineSeries *serias1 = new QLineSeries();
    QLineSeries *serias2 = new QLineSeries();
    serias1->setName("Качество подключения");
    serias2->setName("Помехи в соединении");

    for (int i=0; i<150;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    for (int i=150; i<300;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    for (int i=300; i<500;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    for (int i=500; i<650;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    for (int i=650; i<800;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    for (int i=800; i<1000;i++)
    {
        serias1->append(i, -1);
        serias2->append(i, 1);
    }
    chrt->addSeries(serias1);
    chrt->addSeries(serias2);
    chrt->setAxisX(axiaX, serias1);
    chrt->setAxisY(axiaY, serias1);
    chrt->setAxisX(axiaX, serias2);
    chrt->setAxisY(axiaY, serias2);
}



void MainWindow::on_button10_clicked()
{
    ui->button10->hide();
    ui->button11->hide();
    ui->textEdit_2->hide();
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Ошибка", "Начать перезагрузку сети?",
                                QMessageBox::Yes | QMessageBox::No);
     if(reply == QMessageBox::Yes){
     QMessageBox::information(this, "Ошибка","Сеть перезагружина.");
      ui->statusbar->showMessage("Сеть была успешно перезагружина.");
     ui->label1->setStyleSheet("background-color:green");
     ui->label2->setStyleSheet("background-color:green");
     ui->label3->setStyleSheet("background-color:green");
     ui->label4->setStyleSheet("background-color:green");
     ui->label5->setStyleSheet("background-color:green");
     ui->label6->setStyleSheet("background-color:green");
     }
     else
     {
     QMessageBox::information(this, "Ошибка","Отмена команды.");
      ui->statusbar->showMessage("Действие отменино.");}
     chrt = new QChart;
     ui->widget->setChart(chrt);
     chrt->setTitle("Состояние сети");
     QValueAxis *axiaX = new QValueAxis;
     axiaX->setRange(0, 1000);
     axiaX->setTickCount(10);
     axiaX->setLabelFormat("%g");

     QValueAxis *axiaY = new QValueAxis;
     axiaY->setRange(-1, 1);
     axiaY->setTickCount(3);
     axiaY->setLabelFormat("%g");

     QLineSeries *serias1 = new QLineSeries();
     QLineSeries *serias2 = new QLineSeries();
     serias1->setName("Качество подключения");
     serias2->setName("Помехи в соединении");

     for (int i=0; i<150;i++)
     {
         serias1->append(i, 1);
         serias2->append(i, 0);
     }
     for (int i=150; i<300;i++)
     {
         serias1->append(i, 1);
         serias2->append(i, -1);
     }
     for (int i=300; i<500;i++)
     {
         serias1->append(i, 0);
         serias2->append(i, -1);
     }
     for (int i=500; i<650;i++)
     {
         serias1->append(i, 0);
         serias2->append(i, 0);
     }
     for (int i=650; i<800;i++)
     {
         serias1->append(i, 1);
         serias2->append(i, -1);
     }
     for (int i=800; i<1000;i++)
     {
         serias1->append(i, 1);
         serias2->append(i, -1);
     }
     chrt->addSeries(serias1);
     chrt->addSeries(serias2);
     chrt->setAxisX(axiaX, serias1);
     chrt->setAxisY(axiaY, serias1);
     chrt->setAxisX(axiaX, serias2);
     chrt->setAxisY(axiaY, serias2);
}

void MainWindow::on_button11_clicked()
{
    ui->button10->hide();
    ui->button11->hide();
    ui->textEdit_2->hide();
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Ошибка", "Запустить процесс проверки обрудования?",
                                QMessageBox::Yes | QMessageBox::No);
     if(reply == QMessageBox::Yes){
     QMessageBox::information(this, "Ошибка","Оборудование проверина ошибки исправлены.");
      ui->statusbar->showMessage("Оборорудование проверино ошибки исправлены.");
     ui->label1->setStyleSheet("background-color:green");
     ui->label2->setStyleSheet("background-color:green");
     ui->label3->setStyleSheet("background-color:green");
     ui->label4->setStyleSheet("background-color:green");
     ui->label5->setStyleSheet("background-color:green");
     ui->label6->setStyleSheet("background-color:green");
     }
     else
     {
     QMessageBox::information(this, "Ошибка","Отмена команды.");
     ui->statusbar->showMessage("Действие отменино.");}
     chrt = new QChart;
     ui->widget->setChart(chrt);
     chrt->setTitle("Состояние сети");
     QValueAxis *axiaX = new QValueAxis;
     axiaX->setRange(0, 1000);
     axiaX->setTickCount(10);
     axiaX->setLabelFormat("%g");

     QValueAxis *axiaY = new QValueAxis;
     axiaY->setRange(-1, 1);
     axiaY->setTickCount(3);
     axiaY->setLabelFormat("%g");

     QLineSeries *serias1 = new QLineSeries();
     QLineSeries *serias2 = new QLineSeries();
     serias1->setName("Качество подключения");
     serias2->setName("Помехи в соединении");

     for (int i=0; i<150;i++)
     {
         serias1->append(i, 1);
         serias2->append(i, 0);
     }
     for (int i=150; i<300;i++)
     {
         serias1->append(i, 0);
         serias2->append(i, 0);
     }
     for (int i=300; i<500;i++)
     {
         serias1->append(i, 0);
         serias2->append(i, -1);
     }
     for (int i=500; i<650;i++)
     {
         serias1->append(i, 1);
         serias2->append(i, -1);
     }
     for (int i=650; i<800;i++)
     {
         serias1->append(i, 1);
         serias2->append(i, -1);
     }
     for (int i=800; i<1000;i++)
     {
         serias1->append(i, 1);
         serias2->append(i, 0);
     }
     chrt->addSeries(serias1);
     chrt->addSeries(serias2);
     chrt->setAxisX(axiaX, serias1);
     chrt->setAxisY(axiaY, serias1);
     chrt->setAxisX(axiaX, serias2);
     chrt->setAxisY(axiaY, serias2);
}
