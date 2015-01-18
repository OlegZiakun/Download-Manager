/*
    Copyright (C) Oleg Ziakun
*/

#include "progressbar.h"

ProgressBar::ProgressBar(QWidget *parent) :
    QProgressBar(parent)
{
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::setMaximum(qint64 value)
{
    int max;

    if(value > INT_MAX)
    {
        coefficient = value / INT_MAX + 1;
        max = value / coefficient;
    }
    else
    {
        coefficient = 0;
        max = value;
    }

    QProgressBar::setMaximum(max);
}

void ProgressBar::setValue(qint64 value)
{
    if(coefficient > 0)
        value /= coefficient;

    QProgressBar::setValue(value);
}
