#include "entrytabwidget.h"

EntryTabWidget::EntryTabWidget(QWidget *parent) :
    QTabWidget(parent)
{
    setupTabs();
}

void EntryTabWidget::setupTabs() {
    tab1 = new QWidget(this);
    tab2 = new QWidget(this);

    addTab(tab1, "");
    addTab(tab2, "＋");
    setCurrentIndex(1);
}
