#ifndef BOOLEANCOMBOBOXDELEGATE_H
#define BOOLEANCOMBOBOXDELEGATE_H

#include <QStyledItemDelegate>

class BooleanComboBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit BooleanComboBoxDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QString displayText(const QVariant &value, const QLocale &locale) const override;

};

#endif // BOOLEANCOMBOBOXDELEGATE_H
