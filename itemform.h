#ifndef ITEMFORM_H
#define ITEMFORM_H

#include <QWidget>

namespace Ui {
class ItemForm;
}

class ItemForm : public QWidget
{
    Q_OBJECT

public:
    explicit ItemForm(QWidget *parent = nullptr);
    ~ItemForm();

    void setColumnsStretch();
    void resetColumnsToDefault();

private slots:

    void on_ItemsSearchButton_clicked();

    void on_ItemsLineEditSearch_returnPressed();

    void on_ItemsLineEditSearch_textChanged(const QString &arg1);

    void ShowContextMenu(const QPoint &pos);

    void on_ItemsTableView_activated(const QModelIndex &index);

private:
    Ui::ItemForm *ui;

    void setTableModel();

};

#endif // ITEMFORM_H
