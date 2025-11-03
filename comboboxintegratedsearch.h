#ifndef COMBOBOXINTEGRATEDSEARCH_H
#define COMBOBOXINTEGRATEDSEARCH_H

#include <QComboBox>

class ComboBoxIntegratedSearch : public QComboBox {
    Q_OBJECT
public:
    explicit ComboBoxIntegratedSearch(QWidget *parent = nullptr);
    void initializeItems();
};

#endif // COMBOBOXINTEGRATEDSEARCH_H
