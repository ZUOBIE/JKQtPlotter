#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建绘图窗口并嵌入主界面
    plot = new JKQTPlotter(this);//创建"绘图器"并构建链接
    setCentralWidget(plot);//让绘图器占满主窗口中间区域

    // 获取内部数据存储指针，后续添加数据使用
    // 库内部有个“Excel 表”式的数据仓库；
    // 拿它的指针  ds  → 后面只要把数据“丢进仓库”，任何图都能复用同一批数。
    JKQTPDatastore* ds = plot->getDatastore();

    // 准备正弦曲线数据
    QVector<double> X, Y;//坐标点向量
    const int Ndata = 100;//最大数值
    for (int i = 0; i < Ndata; i++) {
        double x = double(i) / double(Ndata) * 8.0 * M_PI;//归一化数据到8pi
        X << x;//等价于push_back，qt的写法
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
