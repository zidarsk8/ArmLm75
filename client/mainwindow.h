#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define DATA_LENGTH 100

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent*); //Added this line

private:
    Ui::MainWindow *ui;
    void send_cmd(int s, struct cmd_t cmd);

private slots:
    void on_clearButton_clicked();
    void on_getLastTempButton_clicked();
    void on_getTempButton_clicked();
    void on_getTempAllButton_clicked();
    void DataReceived(QString text);
    void ConnectError();
    void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H
