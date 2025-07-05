#include "documentsform.h"
#include "ui_documentsform.h"
#include "functools.h"
#include "Controller/database.h"
#include "paginationmodel.cpp"

#include <QFileDialog>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QStyledItemDelegate>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QPdfWriter>
#include <QMessageBox>
#include <QDebug>


DocumentsForm::DocumentsForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DocumentsForm)
{
    ui->setupUi(this);

    ui->DocumentTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->DocumentTableView, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(ShowContextMenu(const QPoint &)));


    //connect(ui->saveButton, &QPushButton::clicked, this, &DocumentsForm::saveFile);
    // connect(ui->uploadButton, &QPushButton::clicked, this, &DocumentsForm::uploadFile);
    connect(ui->viewButton, &QPushButton::clicked, this, &DocumentsForm::viewFile);
    connect(ui->deleteButton, &QPushButton::clicked, this, &DocumentsForm::deleteFile);

    setDocumentModel();
}

DocumentsForm::~DocumentsForm()
{
    delete ui;
}


// void DocumentsForm::saveFile() {
//     // Implement save file logic
// }


void DocumentsForm::viewFile() {
    // Implement view file logic
}

void DocumentsForm::deleteFile() {
    // Implement delete file logic
}

void DocumentsForm::ShowContextMenu(const QPoint &pos){
    FuncTools::ShowContextMenu(pos, ui->DocumentTableView, this, true);
}

void DocumentsForm::on_DocumentsSearchLineEdit_returnPressed()
{
    //filter the the table
    FuncTools::filterTable(ui->DocumentTableView, QString("ID LIKE '%%1%' OR FileName LIKE '%%1%' OR FileSize LIKE '%%1%' OR FileDate LIKE '%%1%'").arg(ui->DocumentsSearchLineEdit->text()));
}


void DocumentsForm::on_DocumentsSearchLineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        //filter the the table
        FuncTools::filterTable(ui->DocumentTableView, QString("ID LIKE '%%1%' OR FileName LIKE '%%1%' OR FileSize LIKE '%%1%' OR FileDate LIKE '%%1%'").arg(arg1));
    }else{
        FuncTools::filterTable(ui->DocumentTableView, ""); //show all rows
    }

}


void DocumentsForm::on_DocumentsSearchButton_clicked()
{
    //filter the the table
    FuncTools::filterTable(ui->DocumentTableView, QString("ID LIKE '%%1%' OR FileName LIKE '%%1%' OR FileSize LIKE '%%1%' OR FileDate LIKE '%%1%'").arg(ui->DocumentsSearchLineEdit->text()));
}


void DocumentsForm::setColumnsStretch() {
    // ui->fileTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->DocumentTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void DocumentsForm::resetColumnsToDefault() {
    // ui->fileTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->DocumentTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
}

// void DocumentsForm::on_fileTableWidget_cellClicked(int row, int column)
// {
//     resetColumnsToDefault();
// }

void DocumentsForm::on_DocumentTableView_clicked(const QModelIndex &index)
{
    Q_UNUSED(index);
    resetColumnsToDefault();
}

class CustomItemDelegate : public QStyledItemDelegate {
public:
    CustomItemDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        // Disable editing for columns ID (0), File Size (2), and File Date (3)
        if (index.column() == 0 || index.column() == 2 || index.column() == 3) {
            return nullptr; // Return nullptr to disable editing
        }
        return QStyledItemDelegate::createEditor(parent, option, index);
    }
};

void DocumentsForm::setDocumentModel() {
    PaginationModel *model = new PaginationModel("Documents", Database::getDatabase(), nullptr, true, 4, QString(R"(SELECT ID AS ID, FileName AS "File Name", FileSize AS "File Size", FileDate AS "File Date" FROM Documents )"));

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("File Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("File Size (bytes)"));
    model->setHeaderData(3, Qt::Horizontal, tr("File Date"));

    model->removeColumn(4);

    ui->DocumentTableView->setModel(model);
    model->setStatusLabelOnPageUpdate(ui->PageStatusLabelDocument);
    model->refresh();

    CustomItemDelegate *delegate = new CustomItemDelegate(ui->DocumentTableView);
    ui->DocumentTableView->setItemDelegate(delegate);
}

void DocumentsForm::on_viewButton_clicked()
{
    viewOrDownload(0);
}

void DocumentsForm::on_deleteButton_clicked()
{

    QItemSelectionModel *selectionModel = ui->DocumentTableView->selectionModel();
    QModelIndexList selectedIndexes = selectionModel->selectedIndexes();

    if (selectedIndexes.isEmpty() || !selectedIndexes.first().isValid()) {
        QMessageBox::warning(this, "No Selection", "Please select a row to view.");
        return;
    }

    PaginationModel *model = qobject_cast<PaginationModel*>(ui->DocumentTableView->model());
    bool ok;
    int id = model->data(model->index(selectedIndexes.first().row(), 0)).toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Error", "Failed to retrieve the selected document ID.");
        return;
    }

    QMessageBox msgBox(this);
    msgBox.setText(QString("Are you sure you want delete file with id = : %1 ?").arg(id));
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::Cancel);

    int ret = msgBox.exec();

    if (ret == QMessageBox::Cancel) {
        // Cancel was pressed, return immediately
        return;
    }

    QSqlQuery query(Database::getDatabase());
    QString queryString = QString("Delete from Documents WHERE id = %1").arg(id);

    if (!query.exec(queryString)) {
        QMessageBox::warning(this, "Error", "Could not load the document data.");
        return;
    }
    model->select();
}

void DocumentsForm::on_DownloadAsPDF_clicked()
{
    viewOrDownload(1);
}

void DocumentsForm::viewOrDownload(int status){

    try {
        // QApplication::setOverrideCursor(Qt::WaitCursor);
        // QApplication::processEvents();
        QItemSelectionModel *selectionModel = ui->DocumentTableView->selectionModel();
        QModelIndexList selectedIndexes = selectionModel->selectedIndexes();

        if (selectedIndexes.isEmpty() || !selectedIndexes.first().isValid()) {
            QMessageBox::warning(this, "No Selection", "Please select a row to view.");
            return;
        }

        QWebEngineView *view = new QWebEngineView();
        view->setWindowTitle("Viewing Document");
        view->setWindowIcon(QIcon(":/images/Icon.png")); // Ensure this path is correct
        view->setMinimumSize(600, 1200);
        QWebEnginePage *page = view->page();

        PaginationModel *model = qobject_cast<PaginationModel*>(ui->DocumentTableView->model());
        bool ok;
        int id = model->data(model->index(selectedIndexes.first().row(), 0)).toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Error", "Failed to retrieve the selected document ID.");
            return;
        }

        QSqlQuery query(Database::getDatabase());
        QString queryString = QString("SELECT FileData FROM Documents WHERE id = %1").arg(id);

        if (!query.exec(queryString)) {
            QMessageBox::warning(this, "Error", "Could not load the document data.");
            return;
        }

        QString html = "";
        if (query.next()) {
            html = query.value("FileData").toString();
        } else {
            QMessageBox::warning(this, "No Data", "No data found for the selected document.");
            return;
        }

        view->page()->setHtml(html);
        if (status == 1) {
            QString fileName = QFileDialog::getSaveFileName(this, "Save File", model->data(model->index(selectedIndexes.first().row(), 1)).toString(), "PDF Files (*.pdf)");
            if (!fileName.isEmpty()) {
                page->printToPdf(fileName);
                view->page()->printToPdf(fileName);
                QApplication::restoreOverrideCursor();
            } else {
                qDebug() << "No file name provided.";
                QApplication::restoreOverrideCursor();
                return;
            }
        }
        if (status == 0) {
            view->showNormal();
            QApplication::restoreOverrideCursor();
        }

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString("An error occurred: %1").arg(e.what()));
    }
}
