#include "entrylistwidget.h"

EntryListWidget::EntryListWidget(QWidget *parent)
    : QListWidget(parent) {
    setLayoutDirection(Qt::RightToLeft);
}

void EntryListWidget::populateEntries(const QStringList &entries) {
    clear();
    for (const QString &entry : entries)
    {
        addItem(entry);
    }
}
