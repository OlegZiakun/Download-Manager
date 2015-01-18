/*
    Copyright (C) Oleg Ziakun
*/

#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSslError>
#include <QUrl>

class NetworkManager: public QNetworkAccessManager
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject *parent = 0);
    virtual ~NetworkManager();

    friend class UnitTests;

protected slots:
    virtual void error(QNetworkReply::NetworkError error);
    virtual void sslErrors(const QList<QSslError> &);
    virtual void authenticationRequired(QNetworkReply*, QAuthenticator*);

public:
    virtual void cancel();

public:    
    void get(const QUrl &url);

private:
    void reset();
    void reconnectErrorHandlers();

protected:
    QNetworkReply *reply;
    QNetworkRequest request;
};

#endif // NETWORKMANAGER_H



