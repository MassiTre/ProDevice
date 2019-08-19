#ifndef LAYOUTMODIFICAPORTATILE_H
#define LAYOUTMODIFICAPORTATILE_H

#include <QWidget>
#include <QGridLayout>
#include <QFormLayout>
#include <QCheckBox>
#include <QLineEdit>

class LayoutModificaPortatile : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    /*** layout principale (griglia) ***/
    QGridLayout* grid;
    /*** widget ***/
    QCheckBox* checkEthernet;
    QCheckBox* checkWebcam;
    QCheckBox* checkLuceTastiera;
    QFormLayout* formPxWebcam; // layout Pixel webcam
    QLineEdit* linePxWebcam; // widget Pixel webcam
public:
    LayoutModificaPortatile(QWidget* = nullptr);

    QCheckBox* getCheckEthernet() const;
    QCheckBox* getCheckWebcam() const;
    QCheckBox* getCheckLuceTastiera() const;
    QLineEdit* getLinePxWebcam() const;
public slots:
    void attivaLineWebcam() const;
};

#endif // LAYOUTMODIFICAPORTATILE_H
