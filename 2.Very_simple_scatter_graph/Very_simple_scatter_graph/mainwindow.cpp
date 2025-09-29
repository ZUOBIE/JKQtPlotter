#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //第一种写法
    // QVector<double> X,Y;
    // for(int x=-20;x<20;x++)
    // {
    //     X<<x;
    //     Y<<2*pow(x,2)-4*x+1;
    // }
    // plot = new JKQTPlotter(this);
    // setCentralWidget(plot);
    // JKQTPDatastore* ds = plot->getDatastore();
    // JKQTPXYScatterGraph* Sca = new JKQTPXYScatterGraph(plot);
    // Sca->setColor(QColor(0,0,0));
    // Sca->setXYColumns(ds->addCopiedColumn(X,"x"),ds->addCopiedColumn(Y,"y"));
    // Sca->setTitle("y = 2x^2-4*x+1");
    // plot->addGraph(Sca);
    // plot->zoomToFit();
    //第二种写法，使用迭代器
    plot = new JKQTPlotter(this);
    setCentralWidget(plot);
    JKQTPDatastore* ds = plot->getDatastore();
    size_t columnX=ds->addColumn("x");
    auto colXInserter=ds->backInserter(columnX);
    size_t columnY=ds->addColumn("y");
    auto colYInserter=ds->backInserter(columnY);
    for(int x=-20;x<20;x++)
    {
        *(colXInserter++) = x;
        *(colYInserter++) = 2*pow(x,2)-4*x+1;
    }
    JKQTPXYScatterGraph* Sca = new JKQTPXYScatterGraph(plot);
    Sca->setXYColumns(columnX,columnY);
    plot->addGraph(Sca);
    plot->zoomToFit();
}

MainWindow::~MainWindow()
{
    delete ui;
}
