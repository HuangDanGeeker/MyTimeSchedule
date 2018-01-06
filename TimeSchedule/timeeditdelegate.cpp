#include "timeeditdelegate.h"
#include <QTime>
#include <QTimeEdit>

TimeEditDelegate::TimeEditDelegate(QObject * parten) : QItemDelegate(parten)
{

}


QWidget * TimeEditDelegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const{

    QTimeEdit * timeEdit = new QTimeEdit(parent);
    timeEdit->setDisplayFormat("yyyy-MM-dd");
    timeEdit->setTime(QTime::currentTime());
    timeEdit->setCalendarPopup(true);
//    timeEdit->installEventFilter(const_cast<TimeEditDelegate*>(this));
    return timeEdit;
}


void TimeEditDelegate::setEditorData(QWidget * editor, const QModelIndex & index) const{
    QString time = index.model()->data(index, Qt::EditRole).toString();

    QTimeEdit * dateEdit = static_cast<QTimeEdit*> (editor);
    if(time == "" || time == NULL){
        dateEdit->setTime(QTime::currentTime());
    }
    else{
        dateEdit->setTime(QTime::fromString(time, "HH:mm"));
    }

}

//将widget的数据展示到Item中
void TimeEditDelegate::setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const{
    QTimeEdit * timeEdit = static_cast<QTimeEdit*> (editor);
    QString time = timeEdit->time().toString("HH:mm");
    model->setData(index, QVariant(time));
}

//确保widget能够正确显示到view中
void TimeEditDelegate::updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        editor->setGeometry(option.rect);
    }
