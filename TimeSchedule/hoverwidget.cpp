#include "hoverwidget.h"
#include "ui_hoverwidget.h"

HoverWidget::HoverWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HoverWidget)
{
    ui->setupUi(this);
}

HoverWidget::~HoverWidget()
{
    delete ui;
}
