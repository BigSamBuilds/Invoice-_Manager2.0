#include "booleancomboboxdelegate.h"
#include "paginationmodel.h"

#include <QSqlRelationalTableModel>
#include <QComboBox>

#include <QStyledItemDelegate>
#include <QPainter>
#include <QComboBox>

class CenteredComboBoxDelegate : public QStyledItemDelegate {
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        // Center the text
        opt.displayAlignment = Qt::AlignCenter;

        QStyledItemDelegate::paint(painter, opt, index);
    }
};


BooleanComboBoxDelegate::BooleanComboBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *BooleanComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *editor = new QComboBox(parent);
    editor->addItem("Pending", false);
    editor->addItem("Fullfilled", true);
    editor->setItemDelegate(new CenteredComboBoxDelegate());
    return editor;
}

void BooleanComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
    if (!comboBox)
        return;

    bool value = index.model()->data(index).toBool();
    comboBox->setCurrentIndex(value ? 1 : 0);
}

void BooleanComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
    if (!comboBox)
        return;

    bool value = comboBox->currentIndex() == 1;
    model->setData(index, value, Qt::EditRole);
    model->submit();
}

void BooleanComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

QString BooleanComboBoxDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
    bool paid = value.toBool();
    return paid ? "Fulfilled" : "Pending";
}


