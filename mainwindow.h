/*
    Copyright (C) Oleg Ziakun
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "download.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void downloadButtonClicked();
    void chooseFolderClicked();

private:
    void init();
    void run();

private:
    Ui::MainWindow *ui;
    QScopedPointer<Download> download;
};

#endif // MAINWINDOW_H
