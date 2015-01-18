#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QtTest/QtTest>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "unittests.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    download.reset(new Download(ui));

    connect(ui->downloadButton, SIGNAL(clicked()),this, SLOT(downloadButtonClicked()));
    connect(ui->chooseFolderButton, SIGNAL(clicked()),this, SLOT(chooseFolderClicked()));

#ifdef QT_DEBUG
     QTest::qExec(new UnitTests(ui));
     QTest::qExec(new NetworkManager);
#endif
}

void MainWindow::run()
{
    download->run(ui->urlLineEdit->text(), ui->folderLineEdit->text() + QDir::separator() + QUrl(ui->urlLineEdit->text()).fileName());
}

void MainWindow::downloadButtonClicked()
{
    QMessageBox msgBox(this);
    bool allowed = true;

    if(ui->urlLineEdit->text().isEmpty())
    {
        msgBox.setText(tr("Please specify an URL"));
        allowed = false;
    }
    else if(ui->folderLineEdit->text().isEmpty())
    {
        msgBox.setText(tr("Please specify a folder to download"));
        allowed = false;
    }

    if(allowed)
        run();
    else
        msgBox.exec();
}

void MainWindow::chooseFolderClicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->folderLineEdit->setText(dir);
}


