#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "comboboxintegratedsearch.h"
#include "entrylistwidget.h"
#include "entrytabwidget.h"
#include "searchlineedit.h"
#include "searchbutton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ComboBoxIntegratedSearch *comboBox;
    SearchLineEdit *searchLineEdit;
    SearchButton *searchButton;
    EntryListWidget *entryListW;
    EntryTabWidget *entrytabW;
};
#endif // MAINWINDOW_H
