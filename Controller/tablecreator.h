#ifndef TABLECREATOR_H
#define TABLECREATOR_H

#include <QObject>

class TableCreator
{
public:
    bool makeDocumentsTable();
    bool makeItemsTable();
    bool makeVendorsTable();
    bool makeItemBoughtTable();
    bool makePaymentoutTable();
    bool makeCustomersTable();
    bool makeInvoicesTable();
    bool makeInvoiceDetailsTable();
    bool makePaymentsInTable();
    bool makeUserInformationTable();
    bool makeNoteTable();

private:
    bool excuteQuery(QString queryString, QString table);
};

#endif // TABLECREATOR_H
