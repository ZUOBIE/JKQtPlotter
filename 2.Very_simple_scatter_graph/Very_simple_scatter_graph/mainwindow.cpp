#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QVector<double> X,Y;
    for(int x=-20;x<20;x++)
    {
        X<<x;
        Y<<2*pow(x,2)-4*x+1;
    }
    ui->setupUi(this);
    plot = new JKQTPlotter(this);
    setCentralWidget(plot);
    JKQTPDatastore* ds = plot->getDatastore();
    JKQTPXYScatterGraph* Sca = new JKQTPXYScatterGraph(plot);
    Sca->setColor(QColor(0,0,0));
    Sca->setXYColumns(ds->addCopiedColumn(X,"x"),ds->addCopiedColumn(Y,"y"));
    Sca->setTitle("y = 2x^2-4*x+1");
    plot->addGraph(Sca);
    plot->zoomToFit();
}

MainWindow::~MainWindow()
{
    delete ui;
}
