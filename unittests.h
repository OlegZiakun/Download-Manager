#ifndef UNITTESTS_H
#define UNITTESTS_H

#include <QtTest/QtTest>
#include <QObject>
#include "ui_mainwindow.h"
#include "download.h"

class UnitTests : public QObject
{
    Q_OBJECT
public:
    explicit UnitTests(Ui::MainWindow *ui, QObject *parent = 0) : QObject(parent), mainWindow(ui) { }

private slots:
    void testDownload()
    {
        QScopedPointer<Download> download;
        download.reset(new Download(mainWindow));
        QStringList validLinks;
        QStringList notValidLinks;
        QStringList notValidScheme;

        validLinks << "http://client.cdn.gamigo.com/bp/eu/com/110a/BPClientSetup-2a.bin"
                   << "ftp://176.37.214.174/pub/video/doc/Wonders%20of%20the%20Universe.2011/BBC.Wonders.of.the.Universe.04.2011.DUAL.BDRip.XviD.AC3.-HELLYWOOD.avi"
                   << "https://sites.google.com/site/opzproject/home/CV%20PM%20C%2B%2B%20Software%20Engineer%20Oleg%20Ziakun.pdf?attredirects=0&d=1"
                      "http://google.com";

        notValidLinks << "://client.cdn.gamigo.com/bp/eu/com/"
                      << ":pub/video/doc/Wonders%20of%20the%20Universe.2011/BBC.Wonders.of.the.Universe.04.2011.DUAL.BDRip.XviD.AC3.-HELLYWOOD.avi"
                      << "::sites.google.com/site/opzproject/home/CV%20PM%20C%2B%2B%20Software%20Engineer%20Oleg%20Ziakun.pdf?attredirects=0&d=1"
                      << "";

        notValidScheme << "smb:://client.cdn.gamigo.com/bp/eu/com/"
                      << "www::pub/video/doc/Wonders%20of%20the%20Universe.2011/BBC.Wonders.of.the.Universe.04.2011.DUAL.BDRip.XviD.AC3.-HELLYWOOD.avi"
                      << "www.sites.google.com/site/opzproject/home/CV%20PM%20C%2B%2B%20Software%20Engineer%20Oleg%20Ziakun.pdf?attredirects=0&d=1"
                      << "";

        foreach (auto link, validLinks)
        {
            QVERIFY(download->isRequestValid(QUrl(link)));
            QVERIFY(download->isSchemeValid(QUrl(link)));
        }

        foreach (auto link, notValidLinks)
        {
            QCOMPARE(download->isRequestValid(QUrl(link)),  false);
            QCOMPARE(download->isSchemeValid(QUrl(link)),  false);
        }

        foreach (auto link, notValidScheme)
            QCOMPARE(download->isSchemeValid(QUrl(link)),  false);
    }
private:
    Ui::MainWindow *mainWindow;
};

#endif // UNITTESTS_H
