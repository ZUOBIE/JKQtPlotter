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
    for(int x=-20;x<20;x++)
    {
        *(colXInserter++) = x;
        *(colYInserter++) = 2*pow(x,2)-4*x+1;
    }
    JKQTPXYScatterGraph* Sca = new JKQTPXYScatterGraph(plot);
    Sca->setXYColumns(columnX,columnY);
    Sca->setSymbolType(JKQTPFilledCharacterSymbol+QChar(0x2665).unicode());
    Sca->setSymbolSize(20);
    Sca->setSymbolColor(QColor("black"));
    Sca->setSymbolFillColor(QColor("red"));
    Sca->setSymbolLineWidth(0.5);
    Sca->setTitle(QObject::tr("hearts"));
    plot->addGraph(Sca);
    plot->zoomToFit();
}

MainWindow::~MainWindow()
{
    delete ui;
}
