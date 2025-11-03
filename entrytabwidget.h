#ifndef ENTRYTABWIDGET_H
#define ENTRYTABWIDGET_H

#include <QTabWidget>
#include <QWidget>

class EntryTabWidget : public QTabWidget {
    Q_OBJECT
public:
    explicit EntryTabWidget(QWidget *parent = nullptr);
    void setupTabs();

private:
    QWidget *tab1;
    QWidget *tab2;
};

#endif // ENTRYTABWIDGET_H
