#ifndef PROCESSBARDELEGATE_H
#define PROCESSBARDELEGATE_H

#include <QApplication>
#include <QItemDelegate>
class ProcessBarDelegate : public QItemDelegate
{
public:
    ProcessBarDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // PROCESSBARDELEGATE_H
