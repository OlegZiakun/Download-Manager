#ifndef DISPLAY_H
#define DISPLAY_H

#include <QObject>
#include <QTimer>
#include <QUrl>
#include <QStringList>
#include "progressbar.h"
#include "ui_mainwindow.h"

class Display : public QObject
{
    Q_OBJECT
public:
    explicit Display(Ui::MainWindow *mw, QObject *parent = 0);

    enum EDownloadButtonState { ERun, ECancel, ECount };

private slots:
    void update();

public:
    void setProgress(qint64 bytesReceived, qint64 bytesTotal);
    void unsetProgress();
    void setDownloadState(EDownloadButtonState state);
    EDownloadButtonState getDownloadButtonState() const;

private:
    void init();
    void resetCounters();
    void updateControls();

private:
    Ui::MainWindow *mainWindow;
    QScopedPointer<ProgressBar> progressBar;
    QScopedPointer<QTimer> speedTimer;
    QString downloadButtonStateText[ECount];
    EDownloadButtonState downloadButtonState = ERun;
    int interval;
    int totalUpdates = 0;
    qint64 totalSeconds = 0;
    qint64 bytesReceived;
    qint64 previousBytesReceived = 0;
    const qint64 timerCoefficient = 2;
    double mbTotal = 0.;
    qint64 kbPerSecVal;
    qint64 bytesTotal;
};

#endif // DISPLAY_H
