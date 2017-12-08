#ifndef HOVERWIDGET_H
#define HOVERWIDGET_H

#include <QWidget>

namespace Ui {
class HoverWidget;
}

class HoverWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HoverWidget(QWidget *parent = 0);
    ~HoverWidget();

private:
    Ui::HoverWidget *ui;
};

#endif // HOVERWIDGET_H
