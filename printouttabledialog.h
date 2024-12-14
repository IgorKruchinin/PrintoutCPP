#ifndef PRINTOUTTABLEDIALOG_H
#define PRINTOUTTABLEDIALOG_H

#include <QDialog>
#include <QTableView>
#include <QStandardItemModel>
#include <memory>
#include "api/Printout.h"

namespace Ui {
class PrintoutTableDialog;
}

class PrintoutTableDialog : public QDialog
{
    Q_OBJECT
    IPrintout *backend;
    Record *record;
    std::shared_ptr<serialContainer<Record>> records;
    QTableView *table;
    QStandardItemModel *tableModel;


public:
    explicit PrintoutTableDialog(QWidget *parent = nullptr, IPrintout *backend = nullptr, Record *record = nullptr);
    ~PrintoutTableDialog();

private:
    void rowClicked(const QModelIndex index);
    void loadFromBackend();
    Ui::PrintoutTableDialog *ui;
};

#endif // PRINTOUTTABLEDIALOG_H
