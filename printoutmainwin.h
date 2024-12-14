#ifndef PRINTOUTMAINWIN_H
#define PRINTOUTMAINWIN_H

#include <QMainWindow>
#include <memory>

#include "api/Record.h"
#include "api/Printout.h"
#include "api/Definitions.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class PrintoutMainWin;
}
QT_END_NAMESPACE

class PrintoutMainWin : public QMainWindow
{
    Q_OBJECT
    IPrintout *backend;

public:
    PrintoutMainWin(QWidget *parent = nullptr);
    ~PrintoutMainWin();

private slots:
    void on_printBtn_clicked();

    void on_clearBtn_clicked();

    void on_fillIntoTableBtn_clicked();

    void on_openBtn_clicked();

    void on_excelExportBtn_clicked();

    void on_saveBtn_clicked();

private:
    void fillIntoTable();
    void resetAllFields();
    void fillFieldsFromRecord(const IRecord *record);
    const Record makeRecord() const;
    Ui::PrintoutMainWin *ui;
};
#endif // PRINTOUTMAINWIN_H
