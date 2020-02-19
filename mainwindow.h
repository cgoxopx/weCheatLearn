#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void goNext();
    void goPre();

private slots:
    void on_pushButton_goPre_clicked();

    void on_pushButton_goNext_clicked();

    void goNextHandle();

    void on_pushButton_goNext_stop_clicked();

    void on_pushButton_goNext_start_clicked();

private:
    Ui::MainWindow *ui;
    QTimer * goNextTimer;
};

#endif // MAINWINDOW_H
