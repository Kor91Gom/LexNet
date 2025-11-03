#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    comboBox = new ComboBoxIntegratedSearch(this);
    searchLineEdit = new SearchLineEdit(this);
    searchButton = new SearchButton(this);
    entryListW = new EntryListWidget(this);
    entrytabW = new EntryTabWidget(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
