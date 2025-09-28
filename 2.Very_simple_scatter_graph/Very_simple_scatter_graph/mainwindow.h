#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jkqtplotter/jkqtplotter.h"
#include "jkqtplotter/graphs/jkqtplines.h"
#include <jkqtplotter/graphs/jkqtpscatter.h>
#include <iostream>
#include <random>
// #include "jkqtplotter/graphs/"


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
    JKQTPlotter* plot;
};
#endif // MAINWINDOW_H
