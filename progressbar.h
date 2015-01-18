/*
    Copyright (C) Oleg Ziakun
*/

#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QProgressBar>

class ProgressBar : public QProgressBar
{
public:
    explicit ProgressBar(QWidget *parent = 0);
    ~ProgressBar();

public:
    void setMaximum(qint64 value);
    void setValue(qint64 value);

private:
    int coefficient = 0;
};

#endif // PROGRESSBAR_H
