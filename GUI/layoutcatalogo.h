#ifndef LAYOUTCATALOGO_H
#define LAYOUTCATALOGO_H

#include <QPushButton>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QCheckBox>

#include "itemwidget.h"

class LayoutCatalogo : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    itemWidget* list;
public:
    LayoutCatalogo(QWidget* =nullptr);
    itemWidget *getLista() const;
};

#endif // LAYOUTCATALOGO_H
