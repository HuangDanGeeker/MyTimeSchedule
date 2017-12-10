#ifndef DATEEDITDELEGATE_H
#define DATEEDITDELEGATE_H

#include <QObject>
#include <QDate>
#include <qitemdelegate.h>
#include <QDateEdit>
class DateEditDelegate : public QItemDelegate
{
public:
    DateEditDelegate(QObject * parent = 0);
    //返回改变Model数据的widget，该widget是经过定制行为的Widget
    QWidget *createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const;

    //将可操作的数据提供给widget
    void setEditorData(QWidget * editor, const QModelIndex & index) const;

    //将widget的数据展示到Item中
    void setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const;

    //确保widget能够正确显示到view中
    void updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index) const;
};

#endif // DATEEDITDELEGATE_H
