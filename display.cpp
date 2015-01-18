#include <QDebug>
#include "display.h"

Display::Display(Ui::MainWindow *mw, QObject *parent) :
    QObject(parent) ,
    mainWindow(mw)
{
    init();
}

void Display::init()
{ 
    progressBar.reset(new ProgressBar(mainWindow->centralWidget));
    speedTimer.reset(new QTimer(this));

    progressBar->setGeometry(12, 206, 132, 26);
    progressBar->hide();
    mainWindow->readyLabel->setVisible(true);

    interval = 1000 / timerCoefficient;
    kbPerSecVal = 1024 / timerCoefficient;

    downloadButtonStateText[ERun] = tr("Download");
    downloadButtonStateText[ECancel] = tr("Cancel");

    setDownloadState(downloadButtonState);

    connect(speedTimer.data(), SIGNAL(timeout()), this, SLOT(update()));
}

/* display progress */

void Display::setProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    this->bytesReceived = bytesReceived;
    this->bytesTotal = bytesTotal;

    if(!speedTimer->isActive())
    {
        speedTimer->start(interval);
        progressBar->show();
        mainWindow->readyLabel->setVisible(false);
    }

    progressBar->setMaximum(bytesTotal);
    progressBar->setValue(bytesReceived);
}

void Display::resetCounters()
{
    mainWindow->currentSpeedLcdNum->display(QString::number(0));
    mainWindow->averageSpeedLcdNum->display(QString::number(0));
    mainWindow->startSecLcdNum->display(QString::number(0));
    mainWindow->startMinLcdNum->display(QString::number(0));
    mainWindow->startHourLcdNum->display(QString::number(0));
    mainWindow->remainingMinLcdNum->display(QString::number(0));
    mainWindow->remainingHourLcdNum->display(QString::number(0));
    mainWindow->receivedFileLcdNum->display(QString::number(0));
    mainWindow->fileSizeLcdNum->display(QString::number(0));
    mainWindow->percentageLcdNum->display(QString::number(0));
    mainWindow->remainingFileLcdNum->display(QString::number(0));
}

void Display::unsetProgress()
{
    progressBar->hide();
    progressBar->reset();
    speedTimer->stop();

    mainWindow->readyLabel->setVisible(true);

    resetCounters();

    totalUpdates = 0;
    totalSeconds = 0;
    previousBytesReceived = 0;
    mbTotal = 0.;
}

void Display::setDownloadState(EDownloadButtonState state)
{
    downloadButtonState = state;
    mainWindow->downloadButton->setText(downloadButtonStateText[state]);

    if(state == ERun)
        mainWindow->chooseFolderButton->setEnabled(true);
    else if(state == ECancel)
        mainWindow->chooseFolderButton->setEnabled(false);
}

Display::EDownloadButtonState Display::getDownloadButtonState() const
{
    return downloadButtonState;
}

void Display::update()
{
    ++totalUpdates;

    totalSeconds = totalUpdates /  timerCoefficient;

    if(previousBytesReceived != 0)
        updateControls();

    previousBytesReceived = bytesReceived;
}

void Display::updateControls()
{
    qint64  currentSpeedValue = (bytesReceived - previousBytesReceived)  / kbPerSecVal;
    qint64  averageSpeedValue = (bytesReceived / totalUpdates)  / kbPerSecVal;
    qint64 remainingBytes = bytesTotal  - bytesReceived;
    qint64 remainingSec = (remainingBytes / kbPerSecVal) / averageSpeedValue;

    mainWindow->currentSpeedLcdNum->display(QString::number(currentSpeedValue));
    mainWindow->averageSpeedLcdNum->display(QString::number(averageSpeedValue));

    mainWindow->startSecLcdNum->display(QString::number(totalSeconds % 60));
    mainWindow->startMinLcdNum->display(QString::number((totalSeconds /  60) % 60));
    mainWindow->startHourLcdNum->display(QString::number(totalSeconds / 3600));

    mainWindow->remainingMinLcdNum->display(QString::number((remainingSec / 60) % 60 ));
    mainWindow->remainingHourLcdNum->display(QString::number(remainingSec / 3600));

    double mbReceived = static_cast<double> (bytesReceived) / 1024. / 1024.;

    if(mainWindow->fileSizeLcdNum->value() == 0)
    {
        mbTotal = static_cast<double> (bytesTotal) / 1024. / 1024.;
        mainWindow->fileSizeLcdNum->display(QString::number(mbTotal, 'f', 2));
    }

    mainWindow->receivedFileLcdNum->display(QString::number(mbReceived, 'f', 2));
    mainWindow->percentageLcdNum->display(QString::number(mbReceived / (mbTotal / 100), 'f', 2));

    if(mbTotal > 0)
        mainWindow->remainingFileLcdNum->display(QString::number((mbTotal - mbReceived), 'f', 2));
}
