#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QPainter>
#include <QSize>

#include "comboboxintegratedsearch.h"
#include "entrylistwidget.h"
#include "entrytabwidget.h"
#include "searchlineedit.h"
#include "searchbutton.h"
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSearchClicked();
    void setupStatusOption();

private:
    Ui::MainWindow *ui;

    ComboBoxIntegratedSearch *comboBox;
    SearchLineEdit *searchLineEdit;
    SearchButton *searchButton;
    EntryListWidget *entryListW;
    EntryTabWidget *entrytabW;

    QToolButton *settingsBtn = nullptr;     // 상태바 우측 설정 관련
    QWidget *settingsWindow = nullptr;      // 독립 창으로 동작하는 QWidget
    Settings *settingsWidget = nullptr;
};

#endif // MAINWINDOW_H
