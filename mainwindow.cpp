#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "drawarea.h"
#include <qtimer.h>
#include "constants.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->draw_area = std::make_unique<DrawArea>();

    auto timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [this]() {
        draw_area->update();
    });
    timer->start(tau);

    ui->verticalLayout->addWidget(draw_area.get());

    QWidget::setWindowTitle("Position-based-dynamic");

    QObject::connect(ui->actionR_initialiser, &QAction::triggered,
                    this, [this]() { draw_area->resetContext();
                                    QMessageBox::information(this, "Réinitialisation", "Le contexte a été réinitialisé !");});
}

MainWindow::~MainWindow()
{
    delete ui;
}
