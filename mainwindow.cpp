#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    comboBox = qobject_cast<ComboBoxIntegratedSearch *>(ui->comboBoxIntegratedSearch);
    searchLineEdit = qobject_cast<SearchLineEdit *>(ui->searchLineEdit);
    searchButton = qobject_cast<SearchButton *>(ui->searchButton);
    entryListW = qobject_cast<EntryListWidget *>(ui->entryListW);
    entrytabW = qobject_cast<EntryTabWidget *>(ui->entrytabW);

    if (searchButton) connect(searchButton, &QPushButton::clicked, this, &MainWindow::onSearchClicked); // 검색 버튼 연결 (안전 검사)
    setupStatusOption();    // 상태바 우측에 설정 버튼 추가
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onSearchClicked() {
    QString keyword = searchLineEdit->text();
    QString category = comboBox->currentText();

    QStringList dummyResults;
    dummyResults << category + ": " + keyword + " 결과 1"
                 << category + ": " + keyword + " 결과 2"
                 << category + ": " + keyword + " 결과 3";

    entryListW->clear();
    entryListW->addItems(dummyResults);
}

void MainWindow::setupStatusOption()
{
    if (!ui)
        return;

    // 1) 버튼 생성
    settingsBtn = new QToolButton(this);
    settingsBtn->setToolTip(tr("설정"));
    settingsBtn->setAutoRaise(true);
    settingsBtn->setCursor(Qt::PointingHandCursor);

    // 2) 항상 회색 원 픽스맵을 만들어 아이콘으로 사용 (파일/리소스 전혀 사용하지 않음)
    const int iconSize = 18; // 실제 픽스맵 내부 크기
    QPixmap fallback(iconSize, iconSize);
    fallback.fill(Qt::transparent);

    QPainter painter(&fallback);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QColor grayColor(160, 160, 160); // 회색 값 (원하는 색으로 변경 가능)
    painter.setBrush(grayColor);
    painter.setPen(Qt::NoPen);
    // 원 그리기 (전체 영역에 약간의 패딩을 남김)
    int pad = 1;
    painter.drawEllipse(pad, pad, iconSize - 2*pad, iconSize - 2*pad);
    painter.end();

    settingsBtn->setIcon(QIcon(fallback));
    settingsBtn->setIconSize(QSize(iconSize, iconSize));
    settingsBtn->setFixedSize(iconSize + 12, iconSize + 12);        // 버튼 크기 확보 (아이콘 + 패딩)

    if (ui->statusBarSetting) {
        ui->statusBarSetting->addPermanentWidget(settingsBtn, 0);
    } else {
        statusBar()->addPermanentWidget(settingsBtn, 0);
    }

    settingsWindow = new QWidget(nullptr); // 독립 창으로 동작
    settingsWindow->setWindowTitle(tr("설정"));
    settingsWindow->setAttribute(Qt::WA_DeleteOnClose, false);
    settingsWindow->setWindowFlags(settingsWindow->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    settingsWidget = new Settings(settingsWindow);

    QVBoxLayout *v = new QVBoxLayout(settingsWindow);
    v->setContentsMargins(6, 6, 6, 6);
    v->addWidget(settingsWidget);
    settingsWindow->setLayout(v);
    settingsWindow->resize(520, 420);
    settingsWindow->hide();

    connect(settingsBtn, &QToolButton::clicked, this, [this]() {
        if (!settingsWindow)
            return;
        if (settingsWindow->isVisible()) {
            settingsWindow->raise();
            settingsWindow->activateWindow();
        } else {
            settingsWindow->show();
            settingsWindow->raise();
            settingsWindow->activateWindow();
        }
    });
}
