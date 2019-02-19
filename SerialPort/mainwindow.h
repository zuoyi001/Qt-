#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QMainWindow>
#include <QProcess>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QMouseEvent>
#include <QEvent>
#include <QTimer>
#include <QTimerEvent>
#include <QLabel>
#include <QTime>

#include "serialport.h"
#include "thread.h"

#define PORTFILENAME "serialport.dat"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString getHexStr(QByteArray temp);
    char ConvertHexChar(char ch);
    char ConvertChar2Hex(char ch);

private slots:
    void showInRecvText(QString str);
    void SerialPortInitSlots();
    void autoScroll();
    void reLoadSerialPort();

    void on_openPushButton_clicked();
    void on_clearRecvPushButton_clicked();
    void on_sendPushButton1_clicked();
    void on_sendPushButton2_clicked();
    void on_sendLineEdit2_returnPressed();

    void sendLineEdit3();
    void sendLineEdit4();
    void sendLineEdit5();
    void sendLineEdit6();

    void timeOutEvent();
    void systemTimeUpdate();

    void on_autoSendCheckBox_clicked();

    void on_SendClearButton_clicked();

    void on_autoSendCheckBox_stateChanged(int arg1);

    void on_hexSendcheckBox_clicked();

    void on_hexSendcheckBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    SerialPort *seriport;
    bool openFlag;
    bool timerFlag;
    bool autosendFlag;
    Thread *thread;
    QTimer *timer;
    QTimer *systemTimer;
    QLabel *label;
    QLabel *systemLabel;
    QLabel *sendLable;
    QLabel *recvLable;
    double recvNum;
    double sendNum;

private:
    void SerialPortInit();

    QByteArray GetHexValue(QString str);

signals:
    void clickSerialPortCombobox();
};

#endif // MAINWINDOW_H
