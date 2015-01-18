#ifndef WDOWNLOAD_H
#define WDOWNLOAD_H

#include <QFile>
#include <QFileInfo>
#include <QtTest/QtTest>
#include "networkmanager.h"
#include "display.h"
#include "ui_mainwindow.h"

class Download : public NetworkManager
{
    Q_OBJECT
public:
    explicit Download(Ui::MainWindow *mw, QObject *parent = 0);
    friend class UnitTests;

public:
    void run(const QUrl &url, const QString &fileName);
    void cancel() final;

private slots:
    void replyFinished(QNetworkReply*reply);
    void replyReadyRead();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void resetConnections();
    void unset();

private:
    void launch(const QUrl &url, const QString &fileName);

    bool checkFile(const QString &fileName);
    bool isRequestValid(const QUrl &url);
    bool isSchemeValid(const QUrl &url);
    void resetFile(const QString &fileName);

private:
    QScopedPointer<Display> display;
    QFile file;
};

#endif // WDOWNLOAD_H
