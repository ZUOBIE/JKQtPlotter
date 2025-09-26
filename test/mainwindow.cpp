#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建绘图窗口并嵌入主界面
    plot = new JKQTPlotter(this);
    setCentralWidget(plot);

    // 获取内部数据存储指针，后续添加数据使用
    JKQTPDatastore* ds = plot->getDatastore();

    // 准备正弦曲线数据
    QVector<double> X, Y;
    const int Ndata = 100;
    for (int i = 0; i < Ndata; i++) {
        double x = double(i) / double(Ndata) * 8.0 * M_PI;
        X << x;
        Y << sin(x);
    }

    // 将数据复制到内部存储，返回列索引
    size_t columnX = ds->addCopiedColumn(X, "x");
    size_t columnY = ds->addCopiedColumn(Y, "y");

    // 创建线图对象并绑定数据列
    JKQTPXYLineGraph* graph1 = new JKQTPXYLineGraph(plot);
    graph1->setXColumn(columnX);
    graph1->setYColumn(columnY);
    graph1->setTitle(QObject::tr("sine graph"));

    // // 把图加入绘图器并自动缩放
    plot->addGraph(graph1);
    plot->zoomToFit();
}

MainWindow::~MainWindow()
{
    delete ui;
}
