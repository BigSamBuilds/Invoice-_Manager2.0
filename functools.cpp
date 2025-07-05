#include "functools.h"
#include "paginationmodel.h"
#include "Controller/database.h"
#include <QApplication>
#include <QMenu>
#include <QClipboard>
#include <QSqlTableModel>
#include <QSqlError>
#include <QDateTime>
#include <QVariant>

FuncTools::FuncTools() {}


QString FuncTools::generateInvoiceHTML(QMap<QString, QString> values) {
    QString html = R"(
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Invoice</title>
            <style>
                body {
                            font-family: Arial, sans-serif;
                            font-size: 12px;
                            background-color: #ffffff;
                            margin: 0;
                            padding: 20px;
                            color: #333333;
                        }

                        h1 {
                            font-size: 32px;
                            margin-bottom: 10px;
                            color: rgb(11, 0, 162);
                            font-family: 'Franklin Gothic Medium', 'Arial Narrow', Arial, sans-serif;
                            font-weight: bold;
                        }

                        .header {
                            margin-bottom: 20px;
                        }

                        .address {
                            margin-bottom: 20px;
                        }

                        .invoice-details {
                            display: flex;
                            justify-content: space-between;
                            margin-bottom: 20px;
                        }

                        .invoice-table {
                            width: 100%;
                            border-collapse: collapse;
                            margin-bottom: 20px;
                        }

                        .invoice-table th,
                        .invoice-table td {
                            border: 1px solid #cccccc;
                            padding: 8px;
                            text-align: left;
                        }

                        .invoice-table th {
                            background-color: #003166;
                            color: #ffffff;
                        }

                        .invoice-table tr:nth-child(even) {
                            background-color: #f2f2f2;
                        }

                        .invoice-total {
                            margin-top: 20px;
                        }

                        .invoice-total td {
                            padding: 8px;
                            text-align: right;
                        }

                        #description {
                            width: 55%;
                        }

                        .address,
                        .invoice-Account {
                            float: left;
                        }

                        .invoice-details,
                        .invoice-total {
                            float: right;
                        }

                        .space {
                            height: 100px;
                        }

                        .clear {
                            clear: both;
                        }

                        .address {
                            margin-bottom: 20px;
                        }

                        .address table {
                            border-collapse: collapse;
                            width: 100%;
                        }

                        .address td {
                            padding: 5px 0;
                        }

                        .address td:first-child {
                            padding-right: 10px;
                        }

                        .address tr:last-child td {
                            padding-bottom: 0;
                        }

                        textarea {
                            font-size: 16px;
                            width: 100%;
                            height: 100px;
                            resize: none;
                            padding: 5px;
                        }
                        .billToTextArea{
                            width: 200px;
                        }

                        .textAreaBankAddress {
                            border: none;
                        }

                        /* Page numbering */
                        @page {
                            margin: 10cm;
                            size: A4 portrait;
                            counter-increment: page;
                            @top-right {
                                content: "Page " counter(page);
                            }
                        }

                        /* Aligning quantity, rate, and left-aligned amount */

                        .invoice-table .amount {
                            text-align: left;
                        }
                        .invoice-table .quantity,
                        .invoice-table .rate,
                        .invoice-table .amount {
                            text-align: right;
                        }
            </style>
        </head>
        <body>
            <div class="container">
                <div class="header">
                    <h1>Stitch Alteration LTD</h1>
                </div>
                <div class="address">
                    <table class="address">
                        <tr>
                            <td>Address:</td>
                            <td>%1</td>
                        </tr>
                        <tr>
                            <td>Post Number:</td>
                            <td>%2</td>
                        </tr>
                        <tr>
                            <td>VAT Number:</td>
                            <td>%3</td>
                        </tr>
                        <tr>
                            <td>Mobile:</td>
                            <td>%4</td>
                        </tr>
                        <tr>
                            <td>Phone:</td>
                            <td>%5</td>
                        </tr>
                    </table>
                    <p>%6</p>
                    <p>%7</p>
                </div>
                <div class="invoice-details">
                    <table class="invoice-details">
                        <tr>
                            <td>Date:</td>
                            <td>%8</td>
                        </tr>
                        <tr>
                            <td>Invoice Number:</td>
                            <td>%9</td>
                        </tr>
                        <tr>
                            <td>Bills to:</td>
                            <td><textarea cols="30" rows="3" class="billToTextArea" >%10</textarea></td>
                        </tr>
                    </table>
                    <div></div>
                </div>
                <div class="clear"></div>
                <div class="tableBox">
                    <table class="invoice-table">
                        <thead>
                            <tr>
                                <th id="description">Description</th>
                                <th class="quantity">Quantity</th>
                                <th class="rate">Rate</th>
                                <th class="amount">Amount</th>
                            </tr>
                        </thead>
                        <tbody>
                            %11
                        </tbody>
                    </table>
                </div>
                <div class="invoice-Account">
                    <table>
                        <tr>
                            <td>Account:</td>
                            <td>%12</td>
                        </tr>
                        <tr>
                            <td><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></td>
                            <td><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></td>
                        </tr>
                        <tr>
                            <td><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></td>
                            <td><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></td>
                        </tr>
                        <tr>
                            <td>Sort Code.</td>
                            <td>%13</td>
                        </tr>
                        <tr>
                            <td>Bank</td>
                            <td>%14</td>
                        </tr>
                    </table>
                    <textarea cols="30" rows="5" class="textAreaBankAddress">%15</textarea>
                </div>
                <div class="invoice-total">
                    <table>
                        <tr>
                            <td>SUBTOTAL:</td>
                            <td>£%16</td>
                        </tr>
                        <tr>
                            <td>VAT %17%:</td>
                            <td>£%18</td>
                        </tr>
                        <tr>
                            <td>Discount:</td>
                            <td>%19%</td>
                        </tr>
                        <tr>
                            <td>Total Discount:</td>
                            <td>£%20</td>
                        </tr>
                        <tr>
                            <td></td>
                            <td></td>
                        </tr>
                        <tr>
                            <td></td>
                            <td></td>
                        </tr>
                        <tr>
                            <td>TOTAL:</td>
                            <td>£%21</td>
                        </tr>
                        <tr>
                            <td>Balance Due:</td>
                            <td>£%22</td>
                        </tr>
                    </table>
                </div>
                <div class="clear"></div>
            </div>
        </body>
        </html>
    )";

    html = html.arg(values.value("%1"))
               .arg(values.value("%2"))
               .arg(values.value("%3"))
               .arg(values.value("%4"))
               .arg(values.value("%5"))
               .arg(values.value("%6"))
               .arg(values.value("%7"))
               .arg(values.value("%8"))
               .arg(values.value("%9"))
               .arg(values.value("%10"))
               .arg(values.value("%11"))
               .arg(values.value("%12"))
               .arg(values.value("%13"))
               .arg(values.value("%14"))
               .arg(values.value("%15"))
               .arg(values.value("%16"))
               .arg(values.value("%17"))
               .arg(values.value("%18"))
               .arg(values.value("%19"))
               .arg(values.value("%20"))
               .arg(values.value("%21"))
               .arg(values.value("%22"));

    return html;
}


void FuncTools::defaultCallbackFunc(){
    //do nothing;
}

void FuncTools::addLastRow(int row, QTableWidget *table ){
    // Check if the clicked cell is in the last row and last column
    if (row == table->rowCount() - 1 ) {
        // Add a fixed number of rows (e.g., 10) when the last cell is clicked
        int numRowsToAdd = 1;
        table->setRowCount(table->rowCount() + numRowsToAdd);
    }
}


void FuncTools::filterTable(QTableWidget *tableWidget, const QString &searchString) {
    if(!searchString.isEmpty()){
        // Iterate over all rows
        for (int row = 0; row < tableWidget->rowCount(); ++row) {
            bool rowMatches = false;

            // Iterate over all columns in the current row
            for (int col = 0; col < tableWidget->columnCount(); ++col) {
                QTableWidgetItem *item = tableWidget->item(row, col);
                if (item && item->text().contains(searchString, Qt::CaseInsensitive)) {
                    rowMatches = true;
                    break; // No need to check further columns in this row
                }
            }

            // Hide the row if none of the columns match the search string
            tableWidget->setRowHidden(row, !rowMatches);
        }
    }
}

void FuncTools::filterTable(QTableView *tableView, const QString &searchQuery) {
    PaginationModel *model = qobject_cast<PaginationModel*>(tableView->model());
    if (model) {
        if (!searchQuery.isEmpty()) {
            // Apply the filter to the model
            model->setFilter(searchQuery);
        } else {
            // Clear the filter to show all rows
            model->setFilter("");
        }
    }
}
void FuncTools::showAll(QTableWidget *table){
    for (int row = 0; row < table->rowCount(); ++row) {
        for (int col = 0; col < table->columnCount(); ++col) {
            table->showRow(row);
        }
    }
}

void FuncTools::ShowContextMenu(const QPoint &pos, QTableWidget *table, QWidget *widget, const std::function<void()>& callback){
    QPoint adjustedPos = pos;
    QPoint globalPos = table->viewport()->mapToGlobal(adjustedPos);

    QMenu *menu = new QMenu(widget);

    menu->setStyleSheet("QMenu{color: white;} QMenu::item:selected{background-color: #3d3d3d;}");

    QAction* action0 = menu->addAction(
        QIcon(),
        QString("Copy")
        );
    QAction* action1 = menu->addAction(
        QIcon(),
        QString("Cut")
        );

    QAction* action2 = menu->addAction(
        QIcon(),
        QString("Paste")
        );

    // QAction* action3 = menu->addAction(
    //     QIcon(),
    //     QString("Delete")
    //     );

    menu->addSeparator();
    QAction* action4 = menu->addAction(
        QIcon(),
        QString("Delete Row")
        );
    QAction* action5 = menu->addAction(
        QIcon(),
        QString("Insert Row")
        );


    QAction* selected_action = menu->exec(globalPos);
    if(selected_action) {
        QClipboard *clipboard = QApplication::clipboard();
        if(selected_action == action0 || selected_action == action1 )
        {
            if(table->currentItem() != NULL){
                QString st = table->currentItem()->text();

                if(st != nullptr){
                    if(st.length() > 0){
                        clipboard->setText(st);
                    }
                }


                if(selected_action == action1)
                {
                    table->currentItem()->setText("");
                }
            }



        }
        else if(selected_action == action2)
        {
            QString st = clipboard->text();
            if(st != nullptr){
                if(st.length() > 0){
                    if(table->currentItem() == NULL){
                        QTableWidgetItem *qtw = new QTableWidgetItem();
                        table->setItem(table->currentRow(), table->currentColumn(), qtw);
                    }
                    table->currentItem()->setText(table->currentItem()->text()+st);

                }
            }

        }
        // else if(selected_action == action3)
        // {
        //     if(table->currentItem() != NULL){
        //         table->currentItem()->setText("");
        //     }

        // }
        else if(selected_action == action4)
        {
            table->removeRow(table->currentRow());
            if(table->rowCount() == 0){
                table->setRowCount(1);
            }
        }
        else if(selected_action == action5)
        {
            table->setRowCount(table->rowCount()+1);
        }

    }

     callback();
}

void FuncTools::ShowContextMenu(const QPoint &pos, QTableView *tableView, QWidget *widget, bool Section1Restriction, const std::function<void()>& callback) {
    QPoint adjustedPos = pos;
    QPoint globalPos = tableView->viewport()->mapToGlobal(adjustedPos);

    QMenu *menu = new QMenu(widget);
    menu->setStyleSheet("QMenu { color: white; } "
                        "QMenu::item:selected { background-color: #3d3d3d; } "
                        "QMenu::item:disabled { color: gray; }"); // Adjust the color for disabled items

    QAction* action0 = menu->addAction(QIcon(), QString("Copy"));
    QAction* action1 = menu->addAction(QIcon(), QString("Cut"));
    QAction* action2 = menu->addAction(QIcon(), QString("Paste"));
    QAction* action3 = menu->addAction(QIcon(), QString("Delete"));
    menu->addSeparator();
    QAction* action4 = menu->addAction(QIcon(), QString("Delete Row"));
    QAction* action5 = menu->addAction(QIcon(), QString("Insert Row"));
    menu->addSeparator();
    QAction* action6 = menu->addAction(QIcon(), QString("Refresh"));
    QAction* action7 = menu->addAction(QIcon(), QString("Next Page"));
    QAction* action8 = menu->addAction(QIcon(), QString("Previous Page"));

    if (Section1Restriction) {
        action1->setEnabled(false);
        action2->setEnabled(false);
        action3->setEnabled(false);
        action4->setEnabled(false);
        action5->setEnabled(false);
    }

    QAction* selected_action = menu->exec(globalPos);
    if (selected_action) {
        QClipboard *clipboard = QApplication::clipboard();
        QModelIndex currentIndex = tableView->currentIndex();
        PaginationModel *paginationModel = qobject_cast<PaginationModel*>(tableView->model());

        if (selected_action == action0) { // Copy
            qDebug() << "Copy action selected!";
            if (currentIndex.isValid()) {
                QString st = currentIndex.data().toString();
                if (!st.isEmpty()) {
                    clipboard->setText(st);
                    qDebug() << "Copied text:" << st;
                }
            }
        } else if (selected_action == action1) { // Cut
            qDebug() << "Cut action selected!";
            if (currentIndex.isValid()) {
                QString st = currentIndex.data().toString();
                if (!st.isEmpty()) {
                    clipboard->setText(st);
                    QVariant *idData = new QVariant();
                    idData->setValue("");
                    paginationModel->setData(currentIndex,*idData); // Set data to empty in the model
                    qDebug() << "Cut text:" << st << "at row:" << currentIndex.row() << "column:" << currentIndex.column();
                    paginationModel->refresh();
                }
            }
        } else if (selected_action == action2) { // Paste
            qDebug() << "Paste action selected!";
            QString st = clipboard->text();
            if (!st.isEmpty()) {
                if (currentIndex.isValid()) {
                    QString currentText = currentIndex.data().toString();
                    tableView->model()->setData(currentIndex, currentText + st); // Append text to current data
                    qDebug() << "Pasted text:" << st << "to row:" << currentIndex.row() << "column:" << currentIndex.column();
                } else {
                    QModelIndex newIndex = tableView->model()->index(tableView->model()->rowCount(), currentIndex.column());
                    tableView->setCurrentIndex(newIndex);
                    tableView->model()->setData(newIndex, st); // Set text at new index
                    qDebug() << "Pasted text:" << st << "to new row:" << newIndex.row() << "column:" << newIndex.column();
                }
            }
        }else if (selected_action == action3) { // Delete
            qDebug() << "Delete action selected!";
            if (currentIndex.isValid()) {
                QVariant *idData = new QVariant();
                idData->setValue("");
                paginationModel->setData(currentIndex, *idData); // Set data to empty in the model
                qDebug() << "Data deleted at row:" << currentIndex.row() << "column:" << currentIndex.column();
                paginationModel->refresh();
            }
        }
        else if (selected_action == action4) { // Delete row
            QModelIndexList selectedCells = tableView->selectionModel()->selectedIndexes();
            if (!selectedCells.isEmpty()) {
                QModelIndex selectedIndex = selectedCells.first();

                // Get row index of the selected cell
                int selectedRow = selectedIndex.row();

                // Assuming id column is at index 0, retrieve id from the model
                QVariant idData = paginationModel->data(paginationModel->index(selectedRow, 0));

                if (idData.isValid()) {
                    int idToRemove = idData.toInt(); // Convert QVariant to int

                    QString tableName = paginationModel->getTableName(); // Assuming tableName() returns the correct table name

                    // Construct the DELETE query
                    QString deleteQuery = QString("DELETE FROM %1 WHERE id = %2 ").arg(tableName, QString::number(idToRemove));
                    qDebug() << deleteQuery; // Check the constructed query in the debug output

                    // Prepare a QSqlQuery on the database associated with paginationModel
                    QSqlQuery query(deleteQuery);

                    // Execute the query
                    if (!query.exec()) {
                        qDebug() << "Error executing query:" << query.lastError().text();
                    } else {
                        qDebug() << "Row with ID" << idToRemove << "deleted successfully!";

                        // Optionally, refresh the model after deletion
                        paginationModel->refresh();
                        paginationModel->reload();
                    }
                } else {
                    qDebug() << "Invalid id data retrieved from model.";
                }
            } else {
                qDebug() << "No cell selected.";
            }
        } else if (selected_action == action5) { // insert new row
            QModelIndexList selectedCells = tableView->selectionModel()->selectedIndexes();
            if (!selectedCells.isEmpty()){
                QString tableName = paginationModel->getTableName(); // Assuming tableName() returns the correct table name
                QMap<QString, QString> maplist = paginationModel->getColumnNames();
                maplist.remove("id");
                for (auto it = maplist.begin(); it != maplist.end(); ++it) {
                    if (it.key().contains("date", Qt::CaseInsensitive) || it.key().contains("RecentChange", Qt::CaseInsensitive)) {
                        QDateTime date = QDateTime::currentDateTime();
                        QString formattedTime = date.toString("yyyy-MM-dd");
                        QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();
                        maplist[it.key()] = QString(" '%1' " ).arg(formattedTimeMsg);
                    }
                }
                // Construct the DELETE query
                QString insertquery = QString("INSERT INTO %1 %2  VALUES %3;").arg(tableName, "( "+maplist.keys().join(", ")+ " )", "( " + maplist.values().join(" ,") + " )");
                qDebug() << insertquery; // Check the constructed query in the debug output

                // Prepare a QSqlQuery on the database associated with paginationModel
                QSqlQuery query(Database::getDatabase());

                // Execute the query
                if (!query.exec(insertquery)) {
                    qDebug() << "Error executing query:" << query.lastError().text();
                } else {
                    qDebug() << "row added successfully!";

                    // Optionally, refresh the model after deletion
                    paginationModel->select();
                }
            }
        } else if (selected_action == action6) { // refresh row
            // Refresh
            if (paginationModel) {
                paginationModel->refresh();
            }
        } else if (selected_action == action7) {
            // Next page
            if (paginationModel) {
                paginationModel->nextPage();
                paginationModel->refresh(); // Refresh to show new page
            }
        } else if (selected_action == action8) {
            // Previous page
            if (paginationModel) {
                paginationModel->previousPage();
                paginationModel->refresh(); // Refresh to show previous page
            }
        }
    }

    callback();
}

