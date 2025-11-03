#include "comboboxintegratedsearch.h"

ComboBoxIntegratedSearch::ComboBoxIntegratedSearch(QWidget *parent)
    : QComboBox(parent) {
    initializeItems();
}

void ComboBoxIntegratedSearch::initializeItems() {
    addItem("통합검색");
    addItem("부동산");
    addItem("영어");
}
