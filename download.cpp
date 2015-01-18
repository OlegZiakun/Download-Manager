#include <QByteArray>
#include <QMessageBox>
#include <QDir>
#include "download.h"
#include "unittests.h"

Download::Download(Ui::MainWindow *mw, QObject *parent) :
    NetworkManager(parent)
{
    display.reset(new Display(mw, parent));
}

/* set file name and open file for writing */

void Download::resetFile(const QString &fileName)
{  
    file.setFileName(fileName);

    if(!file.isOpen())
        file.open(QIODevice::WriteOnly);    
}

void Download::resetConnections()
{
    disconnect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
    connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
}

/* send request, i.e. start download */

void Download::launch(const QUrl &url, const QString &fileName)
{
    resetFile(fileName);
    get(url);
    resetConnections();    
}

/* check if file exists , in case of confirmation of overwritten the file, this file removing  */

bool Download::checkFile(const QString &fileName)
{
    if(QFile::exists(fileName))
    {
        if(QMessageBox::question(0, tr("Download Manager"), tr("There already exists a file called %1 in " "the current directory. Overwrite?").arg(fileName), QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::No)
            return false;

        QFile::remove(fileName);
    }

    return true;
}

/* run checks anf if everything is OK start download */

void Download::run(const QUrl &url, const QString &fileName)
{
    if(display->getDownloadButtonState() != Display::ECancel)
    {
        if(isRequestValid(url))
        {
            if(isSchemeValid(url))
            {
                if(!checkFile(fileName))
                    return;

                QFileInfo fileInfo(fileName);

                if(QDir().exists(fileInfo.path()))
                {
                    launch(url, fileName);
                    display->setDownloadState(Display::ECancel);
                }
                else
                    QMessageBox::critical(0, tr("Error"),  fileInfo.path() + tr(" does not exists."), QMessageBox::Ok);
            }
            else
                QMessageBox::critical(0, tr("Error"),  tr("Protocol not supported."), QMessageBox::Ok);
        }
        else
            QMessageBox::critical(0, tr("Error"),  tr("This URL is not valid, please try again."), QMessageBox::Ok);
    }
    else
        cancel();
}

/* check if request is valid */

bool Download::isRequestValid(const QUrl &url)
{
    return  url.isValid();
}

/* check if scheme (protocol) is valid, it is possible  to forbid or allow any of protocols if needed */

bool Download::isSchemeValid(const QUrl &url)
{
    bool valid = false;
    QString scheme =  url.scheme();

    if(scheme == QString("http") || scheme == QString("https") || scheme == QString("ftp"))
        valid = true;

    return valid;
}

/* finishing download */

void Download::unset()
{
    if(file.isOpen())
        file.close();

    display->setDownloadState(Display::ERun);
    display->unsetProgress();
}

/* call when download is finished */

void Download::replyFinished(QNetworkReply *reply)
{
    unset();

    if(reply->error() == QNetworkReply::NoError)
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Download successfully comleted."));
        msgBox.exec();
    }
}

/* Whenever more data is received from the network and processed, the readyRead() signal is emitted and replyReadyRead() is called */

void Download::replyReadyRead()
{
    QByteArray bytes = reply->readAll();

    if(!bytes.isEmpty())
    {
        qint64 val = file.write(bytes);

        if(val > 0)
            file.flush();
    }
}

/* show download progress */

void Download::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    display->setProgress(bytesReceived, bytesTotal);
}

/* cancel downloading */

void Download::cancel()
{
    NetworkManager::cancel();

    unset();

    if(file.exists())
        file.remove();
}
