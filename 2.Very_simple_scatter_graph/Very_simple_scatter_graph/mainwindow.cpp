#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    plot = new JKQTPlotter(this);
    setCentralWidget(plot);
    JKQTPDatastore* ds = plot->getDatastore();

    size_t columnX=ds->addColumn("x");
    auto colXInserter=ds->backInserter(columnX);
    size_t columnY=ds->addColumn("y");
    auto colYInserter=ds->backInserter(columnY);

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0,0.5);
    const int Ndata=100;
    for (int i=0; i<Ndata; i++) {
        // put data
        const double x=double(i)/double(Ndata)*8.0*JKQTPSTATISTICS_PI;
        *colXInserter=x;
        *colYInserter=sin(x)+distribution(generator);
        // advance back-inserters
        colXInserter++;
        colYInserter++;
    }

    JKQTPXYScatterGraph* graph1=new JKQTPXYScatterGraph(plot);
    graph1->setXColumn(columnX);
    graph1->setYColumn(columnY);
    graph1->setTitle(QObject::tr("sine graph"));

    plot->addGraph(graph1);
    plot->zoomToFit();
}

MainWindow::~MainWindow()
{
    delete ui;
}
