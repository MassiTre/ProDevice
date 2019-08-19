#ifndef LAYOUTAGGIUNGIPORTATILE_H
#define LAYOUTAGGIUNGIPORTATILE_H

#include <QWidget>
#include <QGridLayout>
#include <QFormLayout>
#include <QCheckBox>
#include <QLineEdit>

class LayoutAggiungiPortatile : public QWidget {
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
    LayoutAggiungiPortatile(QWidget* = nullptr);

    QCheckBox* getCheckEthernet() const;
    QCheckBox* getCheckWebcam() const;
    QCheckBox* getCheckLuceTastiera() const;
    QLineEdit* getLinePxWebcam() const;

    void ripristina() const;
public slots:
    void attivaLineWebcam() const;
};

#endif // LAYOUTAGGIUNGIPORTATILE_H
