#ifndef TIMEEDITDELEGATE_H
#define TIMEEDITDELEGATE_H

#include <QObject>
#include <QItemDelegate>
class TimeEditDelegate : public QItemDelegate
{
public:
    TimeEditDelegate(QObject * parent);

    //返回改变Model数据的widget，该widget是经过定制行为的Widget
    QWidget *createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const;

    //将可操作的数据提供给widget
    void setEditorData(QWidget * editor, const QModelIndex & index) const;

    //将widget的数据展示到Item中
    void setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const;
};

#endif // TIMEEDITDELEGATE_H
