#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVector<double> X,Y;
    for(int x=-20;x<20;x++)
    {
        X << x;
        Y << 2*pow(x,2) - 4*x + 1;
    }

    plot = new JKQTPlotter(this);
    setCentralWidget(plot);
    JKQTPXYLineGraph* ga =  new JKQTPXYLineGraph(plot);
    JKQTPDatastore* pl = plot->getDatastore();
    ga->setXYColumns(pl->addCopiedColumn(X,"x"),pl->addCopiedColumn(Y,"y"));
    plot->addGraph(ga);
    plot->zoomToFit();
}

MainWindow::~MainWindow()
{
    delete ui;
}
