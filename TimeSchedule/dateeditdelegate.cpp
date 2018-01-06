#include "dateeditdelegate.h"

DateEditDelegate::DateEditDelegate(QObject * parent) :QItemDelegate(parent)
{

}

QWidget * DateEditDelegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const{

    QDateEdit * dateEdit = new QDateEdit(parent);
    dateEdit->setDate(QDate::currentDate());
    dateEdit->setCalendarPopup(true);
    return dateEdit;
}


void DateEditDelegate::setEditorData(QWidget * editor, const QModelIndex & index) const{
    QString date = index.model()->data(index, Qt::EditRole).toString();
    QDateEdit * dateEdit = static_cast<QDateEdit*> (editor);
    if(date == "" || date == NULL){
        dateEdit->setDate(QDate::currentDate());
    }else{
        dateEdit->setDate(QDate::fromString(date, "yyyy-mm-dd"));
    }

}

//将widget的数据展示到Item中
void DateEditDelegate::setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const{
    QDateEdit * dateEdit = static_cast<QDateEdit*> (editor);
    QString date = dateEdit->date().toString(Qt::ISODate);
    model->setData(index, QVariant(date));
}

//确保widget能够正确显示到view中
void DateEditDelegate::updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index) const{
    editor->setGeometry(option.rect);
}
