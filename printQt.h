#ifndef PRINTQT_H
#define PRINTQT_H
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QString>
#include "api/Definitions.h"

class PrintQt {
public:
    void operator()(String printString, bool &showPrintDialog) {
        QPrinter printer;
        if (showPrintDialog) {
            QPrintDialog *dialog = new QPrintDialog(&printer);
            if (dialog->exec() != QDialog::Accepted) {
                return;
            }
        }
        printer.setOutputFormat(QPrinter::NativeFormat);
        QPainter painter;
        painter.begin(&printer);
        painter.drawText(50, 25, 500, 500, Qt::AlignLeft, QString::fromStdString(printString));
        painter.end();
    }
};

#endif // PRINTQT_H
