#include "tablecreator.h"
#include "database.h"
#include "functiontools.h"


#include <QSqlQuery>
#include <QSqlError>
#include <iostream>

bool TableCreator::excuteQuery(QString queryString, QString table){
    try{
        QSqlDatabase db = Database::getDatabase();
        QSqlQuery query(db);
        if(!query.exec(queryString)){
            FunctionTools::messageBox("Document table creating", "Couldn't create the "+table+" table: "+ (QString)query.lastError().text(), QMessageBox::Critical);
            return false;
        }
        return true;
    }catch(const std::runtime_error &e){
        FunctionTools::messageBox("Document table creating", "Couldn't create the "+table+" table: " + (QString)e.what(), QMessageBox::Critical);
        return false;
    }
}

bool TableCreator::makeDocumentsTable(){
    QString queryString = R"(
        CREATE TABLE IF NOT EXISTS Documents (
            ID INTEGER PRIMARY KEY AUTOINCREMENT,
            FileName TEXT NOT NULL,
            FileSize REAL,
            FileDate TEXT,
            FileData BLOB
        );
    )";
    return excuteQuery(queryString, "");
}

bool TableCreator::makeItemsTable(){
    QString queryString = R"(
            CREATE TABLE IF NOT EXISTS Items (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                item TEXT NOT NULL,
                location TEXT,
                comment TEXT,
                date TEXT
            );
        )";
    return excuteQuery(queryString, "Documents");
}

bool TableCreator::makeVendorsTable(){
    QString queryString = R"(
            CREATE TABLE IF NOT EXISTS Vendors (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT NOT NULL,
                address TEXT,
                email TEXT,
                RecentChange TEXT
            );
       )";
    return excuteQuery(queryString, "Vendors");
}

bool TableCreator::makePaymentoutTable(){
    QString queryString = R"(
            CREATE TABLE IF NOT EXISTS PaymentOut (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                vendor_id INTEGER NOT NULL,
                date TEXT NOT NULL,
                TotalAmount REAL DEFAULT 0,  -- Corrected syntax for default value
                paid BOOLEAN NOT NULL,
                FOREIGN KEY (vendor_id) REFERENCES Vendors(id) ON DELETE CASCADE
            );
         )";
    return excuteQuery(queryString, "Payment out");
}

bool TableCreator::makeItemBoughtTable(){
    QString queryString = R"(
        CREATE TABLE IF NOT EXISTS ItemBought (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            item_id INTEGER NOT NULL,
            quantity INTEGER NOT NULL,
            rate REAL NOT NULL,
            amount REAL NOT NULL,
            date TEXT NOT NULL,
            comment TEXT,
            payment_id INTEGER NOT NULL,
            FOREIGN KEY (item_id) REFERENCES Items(id) ON DELETE CASCADE,
            FOREIGN KEY (payment_id) REFERENCES PaymentOut(id) ON DELETE CASCADE
        );
        )";
    return excuteQuery(queryString, "Item Bought");
}

bool TableCreator::makeCustomersTable(){
    QString queryString = R"(
            CREATE TABLE IF NOT EXISTS Customers (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT NOT NULL,
                address TEXT,
                email TEXT,
                comment TEXT
            );
        )";
    return excuteQuery(queryString, "Customers");
}

bool TableCreator::makeInvoicesTable(){
    QString queryString = R"(
        CREATE TABLE IF NOT EXISTS Invoices (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            customer_id INTEGER NOT NULL,
            date TEXT NOT NULL,
            invoice_id TEXT NOT NULL,
            vat REAL NOT NULL,
            discount REAL NOT NULL,
            total_discount REAL NOT NULL,
            total REAL NOT NULL,
            FOREIGN KEY (customer_id) REFERENCES Customers(id) ON DELETE CASCADE
        );
    )";
    return excuteQuery(queryString, "Invoices");
}

bool TableCreator::makeInvoiceDetailsTable(){
    QString queryString = R"(
        CREATE TABLE IF NOT EXISTS InvoiceDetails (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            invoice_id INTEGER NOT NULL,
            products TEXT NOT NULL,
            quantity INTEGER NOT NULL,
            rate REAL NOT NULL,
            amount REAL NOT NULL,
            comment TEXT,
            FOREIGN KEY (invoice_id) REFERENCES Invoices(id) ON DELETE CASCADE
        );
    )";
    return excuteQuery(queryString, "InvoiceDetails");
}

bool TableCreator::makePaymentsInTable(){
    QString queryString = R"(
        CREATE TABLE IF NOT EXISTS PaymentsIn (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            invoice_id INTEGER NOT NULL,
            date TEXT NOT NULL,
            paid BOOLEAN NOT NULL,
            FOREIGN KEY (invoice_id) REFERENCES Invoices(id) ON DELETE CASCADE
        );
    )";
    return excuteQuery(queryString, "Paymentsin");
}

bool TableCreator::makeUserInformationTable(){
    QString quaryString = R"(
            CREATE TABLE IF NOT EXISTS userInformation(
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    address TEXT,
                    post_number TEXT,
                    vat_number TEXT,
                    mobile TEXT,
                    phone TEXT,
                    email TEXT,
                    website TEXT,
                    accountNumber TEXT,
                    sort_code TEXT,
                    bank_name TEXT,
                    bank_address TEXT
            );
        )";
    return excuteQuery(quaryString, "UserInformation");
}

bool TableCreator::makeNoteTable(){
    QString quaryString = R"(
                    CREATE TABLE IF NOT EXISTS OverviewNotes (
                        id INTEGER PRIMARY KEY AUTOINCREMENT,
                        document_note TEXT,
                        item_note TEXT,
                        vendors_note TEXT,
                        payments_out_note TEXT,
                        customers_note TEXT,
                        invoices_note TEXT,
                        payments_in_note TEXT
                    );
        )";
    return excuteQuery(quaryString, "MakeNoteTable");
}







