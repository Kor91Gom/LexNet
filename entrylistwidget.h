#ifndef ENTRYLISTWIDGET_H
#define ENTRYLISTWIDGET_H

#include <QListWidget>

class EntryListWidget : public QListWidget {
    Q_OBJECT
public:
    explicit EntryListWidget(QWidget *parent = nullptr);
    void populateEntries(const QStringList &entries);
};

#endif // ENTRYLISTWIDGET_H
