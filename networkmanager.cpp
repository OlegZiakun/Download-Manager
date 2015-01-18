/*
    Copyright (C) Oleg Ziakun
*/

#include <QMessageBox>
#include "networkmanager.h"

NetworkManager::NetworkManager(QObject *parent) :
    QNetworkAccessManager(parent)
{
}

void NetworkManager::reset()
{    
    request.setUrl(QUrl());
    disconnect(this, SIGNAL(finished(QNetworkReply*)), 0, 0);
}

NetworkManager::~NetworkManager()
{
}

/* Returns the error that was found during the processing of this request. If no error was found, returns NoError. */

void NetworkManager::error(QNetworkReply::NetworkError error)
{
    // all other errors can be handled here
    if(error == QNetworkReply::HostNotFoundError)
        QMessageBox::critical(0, tr("Host Not Found Error"),  tr("Please check your internet connection."), QMessageBox::Ok);
    else if(error != QNetworkReply::OperationCanceledError)
        QMessageBox::critical(0, tr("Error"),  tr("A network error occured. Please try again."), QMessageBox::Ok);
}

/* Returns the SSL/TLS session encountered errors during the set up, including certificate verification errors. The errors parameter contains the list of errors. */

void NetworkManager::sslErrors(const QList<QSslError>&)
{
     // all the errors can be handled here
    QMessageBox::critical(0, tr("SSL"),  tr("SSL error occured."), QMessageBox::Ok);
}

void NetworkManager::reconnectErrorHandlers()
{
    disconnect(reply, SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(error(QNetworkReply::NetworkError)));
    disconnect(reply, SIGNAL(sslErrors(const QList<QSslError>&)),this, SLOT(sslErrors(const QList<QSslError>&)));
    connect(this, SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)), this, SLOT(authenticationRequired(QNetworkReply*, QAuthenticator*)));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(error(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(sslErrors(const QList<QSslError>&)),this, SLOT(sslErrors(const QList<QSslError>&)));
    connect(this, SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)), this, SLOT(authenticationRequired(QNetworkReply*, QAuthenticator*)));
}

/* call when  authentication required */

void NetworkManager::authenticationRequired(QNetworkReply*, QAuthenticator*)
{
    QMessageBox::critical(0, tr("Authentication"),  tr("Authentication required. This feature is not supported."), QMessageBox::Ok);
    cancel();
}

/* cancel a request */

void NetworkManager::cancel()
{
    if(reply->isRunning())
        reply->abort();
}

/*
   Posts a request to obtain the contents of the target request,
   QNetworkAccessManager::get returns a new QNetworkReply object opened for reading which emits the readyRead() signal whenever new data arrives.
   The contents as well as associated headers will be downloaded.
*/

void NetworkManager::get(const QUrl &url)
{
    if(!url.isEmpty())
    {
        reset();

        request.setUrl(url);
        reply = QNetworkAccessManager::get(request);

        connect(this, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
        disconnect(reply, SIGNAL(readyRead()), this, SLOT(replyReadyRead()));
        connect(reply, SIGNAL(readyRead()), this, SLOT(replyReadyRead()));

        reconnectErrorHandlers();
    }
}
