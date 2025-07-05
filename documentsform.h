#ifndef DOCUMENTSFORM_H
#define DOCUMENTSFORM_H

#include <QWidget>
#include <QThread>


namespace Ui {
class DocumentsForm;
}

class DocumentsForm : public QWidget
{
    Q_OBJECT


public:
    explicit DocumentsForm(QWidget *parent = nullptr);
    ~DocumentsForm();

    void setColumnsStretch();
    void resetColumnsToDefault();



private slots:
    //void saveFile();
    void viewFile();
    void deleteFile();

    void ShowContextMenu(const QPoint &);

    void on_DocumentsSearchLineEdit_returnPressed();

    void on_DocumentsSearchLineEdit_textChanged(const QString &arg1);

    void on_DocumentsSearchButton_clicked();

    void on_DocumentTableView_clicked(const QModelIndex &index);


    void on_viewButton_clicked();

    void on_deleteButton_clicked();

    void on_DownloadAsPDF_clicked();

    void viewOrDownload(int status);

private:
    Ui::DocumentsForm *ui;
    void setDocumentModel();

    QThread *thread;
};


#endif // DOCUMENTSFORM_H
