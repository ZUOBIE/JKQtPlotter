#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jkqtplotter/graphs/jkqtplines.h"
#include "jkqtplotter/jkqtplotter.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    JKQTPlotter *plot;   // 成员指针，生命周期跟随 MainWindow
};
#endif // MAINWINDOW_H
