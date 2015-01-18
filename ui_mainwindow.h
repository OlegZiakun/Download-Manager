/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *currentGroupBox;
    QLCDNumber *currentSpeedLcdNum;
    QLabel *currentSpeedLabel;
    QGroupBox *averageGroupBox;
    QLabel *averageSpeedLabel;
    QLCDNumber *averageSpeedLcdNum;
    QGroupBox *settingsGroupBox;
    QPushButton *chooseFolderButton;
    QPushButton *downloadButton;
    QLineEdit *urlLineEdit;
    QLineEdit *folderLineEdit;
    QGroupBox *timeFromStartGroupBox;
    QLCDNumber *startSecLcdNum;
    QLabel *startSecLabel;
    QLabel *startMinLabel;
    QLCDNumber *startMinLcdNum;
    QLabel *startHourLabel;
    QLCDNumber *startHourLcdNum;
    QGroupBox *remainingTimeGroupBox;
    QLabel *remainingMinLabel;
    QLCDNumber *remainingMinLcdNum;
    QLabel *remainingHourLabel;
    QLCDNumber *remainingHourLcdNum;
    QGroupBox *receivedFileGroupBox;
    QLCDNumber *receivedFileLcdNum;
    QLabel *receivedFileLabel;
    QGroupBox *fileSizeGroupBox;
    QLCDNumber *fileSizeLcdNum;
    QLabel *fileSizeLabel;
    QGroupBox *remainingFileGroupBox;
    QLCDNumber *remainingFileLcdNum;
    QLabel *remainingFileLabel;
    QGroupBox *percentageGroupBox;
    QLCDNumber *percentageLcdNum;
    QLabel *percentageLabel;
    QLabel *label;
    QGroupBox *progressroupBox;
    QLabel *readyLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(402, 270);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(402, 270));
        MainWindow->setMaximumSize(QSize(402, 270));
        MainWindow->setWindowOpacity(1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        currentGroupBox = new QGroupBox(centralWidget);
        currentGroupBox->setObjectName(QStringLiteral("currentGroupBox"));
        currentGroupBox->setGeometry(QRect(155, 180, 116, 50));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Grande"));
        font.setPointSize(11);
        currentGroupBox->setFont(font);
        currentGroupBox->setLayoutDirection(Qt::LeftToRight);
        currentGroupBox->setAutoFillBackground(false);
        currentGroupBox->setFlat(false);
        currentGroupBox->setCheckable(false);
        currentSpeedLcdNum = new QLCDNumber(currentGroupBox);
        currentSpeedLcdNum->setObjectName(QStringLiteral("currentSpeedLcdNum"));
        currentSpeedLcdNum->setGeometry(QRect(6, 22, 61, 25));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        currentSpeedLcdNum->setFont(font1);
        currentSpeedLcdNum->setDigitCount(7);
        currentSpeedLcdNum->setSegmentStyle(QLCDNumber::Flat);
        currentSpeedLabel = new QLabel(currentGroupBox);
        currentSpeedLabel->setObjectName(QStringLiteral("currentSpeedLabel"));
        currentSpeedLabel->setGeometry(QRect(73, 24, 38, 20));
        QFont font2;
        font2.setPointSize(11);
        currentSpeedLabel->setFont(font2);
        averageGroupBox = new QGroupBox(centralWidget);
        averageGroupBox->setObjectName(QStringLiteral("averageGroupBox"));
        averageGroupBox->setGeometry(QRect(274, 180, 116, 50));
        averageGroupBox->setFont(font);
        averageSpeedLabel = new QLabel(averageGroupBox);
        averageSpeedLabel->setObjectName(QStringLiteral("averageSpeedLabel"));
        averageSpeedLabel->setGeometry(QRect(73, 24, 38, 20));
        averageSpeedLabel->setFont(font);
        averageSpeedLcdNum = new QLCDNumber(averageGroupBox);
        averageSpeedLcdNum->setObjectName(QStringLiteral("averageSpeedLcdNum"));
        averageSpeedLcdNum->setGeometry(QRect(6, 22, 61, 25));
        QFont font3;
        font3.setFamily(QStringLiteral("Lucida Grande"));
        font3.setBold(false);
        font3.setWeight(50);
        averageSpeedLcdNum->setFont(font3);
        averageSpeedLcdNum->setDigitCount(7);
        averageSpeedLcdNum->setSegmentStyle(QLCDNumber::Flat);
        settingsGroupBox = new QGroupBox(centralWidget);
        settingsGroupBox->setObjectName(QStringLiteral("settingsGroupBox"));
        settingsGroupBox->setGeometry(QRect(8, 100, 383, 81));
        settingsGroupBox->setFont(font);
        settingsGroupBox->setFocusPolicy(Qt::NoFocus);
        chooseFolderButton = new QPushButton(settingsGroupBox);
        chooseFolderButton->setObjectName(QStringLiteral("chooseFolderButton"));
        chooseFolderButton->setGeometry(QRect(292, 22, 91, 32));
        chooseFolderButton->setFont(font);
        chooseFolderButton->setCursor(QCursor(Qt::PointingHandCursor));
        chooseFolderButton->setFocusPolicy(Qt::NoFocus);
        downloadButton = new QPushButton(settingsGroupBox);
        downloadButton->setObjectName(QStringLiteral("downloadButton"));
        downloadButton->setGeometry(QRect(292, 50, 91, 32));
        downloadButton->setFont(font);
        downloadButton->setCursor(QCursor(Qt::PointingHandCursor));
        downloadButton->setFocusPolicy(Qt::NoFocus);
        urlLineEdit = new QLineEdit(settingsGroupBox);
        urlLineEdit->setObjectName(QStringLiteral("urlLineEdit"));
        urlLineEdit->setGeometry(QRect(8, 54, 280, 21));
        urlLineEdit->setFont(font);
        urlLineEdit->setFocusPolicy(Qt::ClickFocus);
        folderLineEdit = new QLineEdit(settingsGroupBox);
        folderLineEdit->setObjectName(QStringLiteral("folderLineEdit"));
        folderLineEdit->setGeometry(QRect(8, 26, 280, 21));
        folderLineEdit->setFont(font);
        folderLineEdit->setFocusPolicy(Qt::ClickFocus);
        chooseFolderButton->raise();
        downloadButton->raise();
        urlLineEdit->raise();
        folderLineEdit->raise();
        timeFromStartGroupBox = new QGroupBox(centralWidget);
        timeFromStartGroupBox->setObjectName(QStringLiteral("timeFromStartGroupBox"));
        timeFromStartGroupBox->setGeometry(QRect(8, 0, 195, 50));
        timeFromStartGroupBox->setFont(font);
        timeFromStartGroupBox->setLayoutDirection(Qt::LeftToRight);
        timeFromStartGroupBox->setAutoFillBackground(false);
        timeFromStartGroupBox->setFlat(false);
        timeFromStartGroupBox->setCheckable(false);
        startSecLcdNum = new QLCDNumber(timeFromStartGroupBox);
        startSecLcdNum->setObjectName(QStringLiteral("startSecLcdNum"));
        startSecLcdNum->setGeometry(QRect(128, 22, 39, 25));
        startSecLcdNum->setFont(font1);
        startSecLcdNum->setDigitCount(4);
        startSecLcdNum->setSegmentStyle(QLCDNumber::Flat);
        startSecLabel = new QLabel(timeFromStartGroupBox);
        startSecLabel->setObjectName(QStringLiteral("startSecLabel"));
        startSecLabel->setGeometry(QRect(173, 24, 19, 20));
        startSecLabel->setFont(font2);
        startMinLabel = new QLabel(timeFromStartGroupBox);
        startMinLabel->setObjectName(QStringLiteral("startMinLabel"));
        startMinLabel->setGeometry(QRect(106, 24, 19, 20));
        startMinLabel->setFont(font2);
        startMinLcdNum = new QLCDNumber(timeFromStartGroupBox);
        startMinLcdNum->setObjectName(QStringLiteral("startMinLcdNum"));
        startMinLcdNum->setGeometry(QRect(61, 22, 39, 25));
        startMinLcdNum->setFont(font1);
        startMinLcdNum->setDigitCount(4);
        startMinLcdNum->setSegmentStyle(QLCDNumber::Flat);
        startHourLabel = new QLabel(timeFromStartGroupBox);
        startHourLabel->setObjectName(QStringLiteral("startHourLabel"));
        startHourLabel->setGeometry(QRect(49, 24, 14, 20));
        startHourLabel->setFont(font2);
        startHourLcdNum = new QLCDNumber(timeFromStartGroupBox);
        startHourLcdNum->setObjectName(QStringLiteral("startHourLcdNum"));
        startHourLcdNum->setGeometry(QRect(4, 22, 39, 25));
        startHourLcdNum->setFont(font1);
        startHourLcdNum->setDigitCount(4);
        startHourLcdNum->setSegmentStyle(QLCDNumber::Flat);
        remainingTimeGroupBox = new QGroupBox(centralWidget);
        remainingTimeGroupBox->setObjectName(QStringLiteral("remainingTimeGroupBox"));
        remainingTimeGroupBox->setGeometry(QRect(261, 0, 131, 51));
        remainingTimeGroupBox->setFont(font);
        remainingTimeGroupBox->setLayoutDirection(Qt::LeftToRight);
        remainingTimeGroupBox->setAutoFillBackground(false);
        remainingTimeGroupBox->setFlat(false);
        remainingTimeGroupBox->setCheckable(false);
        remainingMinLabel = new QLabel(remainingTimeGroupBox);
        remainingMinLabel->setObjectName(QStringLiteral("remainingMinLabel"));
        remainingMinLabel->setGeometry(QRect(106, 24, 19, 20));
        remainingMinLabel->setFont(font2);
        remainingMinLcdNum = new QLCDNumber(remainingTimeGroupBox);
        remainingMinLcdNum->setObjectName(QStringLiteral("remainingMinLcdNum"));
        remainingMinLcdNum->setGeometry(QRect(61, 22, 39, 25));
        remainingMinLcdNum->setFont(font1);
        remainingMinLcdNum->setDigitCount(4);
        remainingMinLcdNum->setSegmentStyle(QLCDNumber::Flat);
        remainingHourLabel = new QLabel(remainingTimeGroupBox);
        remainingHourLabel->setObjectName(QStringLiteral("remainingHourLabel"));
        remainingHourLabel->setGeometry(QRect(49, 24, 14, 20));
        remainingHourLabel->setFont(font2);
        remainingHourLcdNum = new QLCDNumber(remainingTimeGroupBox);
        remainingHourLcdNum->setObjectName(QStringLiteral("remainingHourLcdNum"));
        remainingHourLcdNum->setGeometry(QRect(4, 22, 39, 25));
        remainingHourLcdNum->setFont(font1);
        remainingHourLcdNum->setDigitCount(4);
        remainingHourLcdNum->setSegmentStyle(QLCDNumber::Flat);
        receivedFileGroupBox = new QGroupBox(centralWidget);
        receivedFileGroupBox->setObjectName(QStringLiteral("receivedFileGroupBox"));
        receivedFileGroupBox->setGeometry(QRect(8, 50, 94, 50));
        receivedFileGroupBox->setFont(font);
        receivedFileGroupBox->setLayoutDirection(Qt::LeftToRight);
        receivedFileGroupBox->setAutoFillBackground(false);
        receivedFileGroupBox->setFlat(false);
        receivedFileGroupBox->setCheckable(false);
        receivedFileLcdNum = new QLCDNumber(receivedFileGroupBox);
        receivedFileLcdNum->setObjectName(QStringLiteral("receivedFileLcdNum"));
        receivedFileLcdNum->setGeometry(QRect(6, 22, 61, 25));
        receivedFileLcdNum->setFont(font1);
        receivedFileLcdNum->setSmallDecimalPoint(false);
        receivedFileLcdNum->setDigitCount(7);
        receivedFileLcdNum->setSegmentStyle(QLCDNumber::Flat);
        receivedFileLabel = new QLabel(receivedFileGroupBox);
        receivedFileLabel->setObjectName(QStringLiteral("receivedFileLabel"));
        receivedFileLabel->setGeometry(QRect(72, 24, 22, 20));
        receivedFileLabel->setFont(font2);
        fileSizeGroupBox = new QGroupBox(centralWidget);
        fileSizeGroupBox->setObjectName(QStringLiteral("fileSizeGroupBox"));
        fileSizeGroupBox->setGeometry(QRect(202, 50, 94, 50));
        fileSizeGroupBox->setFont(font);
        fileSizeGroupBox->setLayoutDirection(Qt::LeftToRight);
        fileSizeGroupBox->setAutoFillBackground(false);
        fileSizeGroupBox->setFlat(false);
        fileSizeGroupBox->setCheckable(false);
        fileSizeLcdNum = new QLCDNumber(fileSizeGroupBox);
        fileSizeLcdNum->setObjectName(QStringLiteral("fileSizeLcdNum"));
        fileSizeLcdNum->setGeometry(QRect(6, 22, 61, 25));
        fileSizeLcdNum->setFont(font1);
        fileSizeLcdNum->setDigitCount(7);
        fileSizeLcdNum->setSegmentStyle(QLCDNumber::Flat);
        fileSizeLabel = new QLabel(fileSizeGroupBox);
        fileSizeLabel->setObjectName(QStringLiteral("fileSizeLabel"));
        fileSizeLabel->setGeometry(QRect(72, 24, 22, 20));
        fileSizeLabel->setFont(font2);
        remainingFileGroupBox = new QGroupBox(centralWidget);
        remainingFileGroupBox->setObjectName(QStringLiteral("remainingFileGroupBox"));
        remainingFileGroupBox->setGeometry(QRect(105, 50, 94, 50));
        remainingFileGroupBox->setFont(font);
        remainingFileGroupBox->setLayoutDirection(Qt::LeftToRight);
        remainingFileGroupBox->setAutoFillBackground(false);
        remainingFileGroupBox->setFlat(false);
        remainingFileGroupBox->setCheckable(false);
        remainingFileLcdNum = new QLCDNumber(remainingFileGroupBox);
        remainingFileLcdNum->setObjectName(QStringLiteral("remainingFileLcdNum"));
        remainingFileLcdNum->setGeometry(QRect(6, 22, 61, 25));
        remainingFileLcdNum->setFont(font1);
        remainingFileLcdNum->setSmallDecimalPoint(false);
        remainingFileLcdNum->setDigitCount(7);
        remainingFileLcdNum->setSegmentStyle(QLCDNumber::Flat);
        remainingFileLabel = new QLabel(remainingFileGroupBox);
        remainingFileLabel->setObjectName(QStringLiteral("remainingFileLabel"));
        remainingFileLabel->setGeometry(QRect(72, 24, 22, 20));
        remainingFileLabel->setFont(font2);
        remainingFileLcdNum->raise();
        remainingFileLabel->raise();
        percentageGroupBox = new QGroupBox(centralWidget);
        percentageGroupBox->setObjectName(QStringLiteral("percentageGroupBox"));
        percentageGroupBox->setGeometry(QRect(298, 50, 94, 50));
        percentageGroupBox->setFont(font);
        percentageGroupBox->setLayoutDirection(Qt::LeftToRight);
        percentageGroupBox->setAutoFillBackground(false);
        percentageGroupBox->setFlat(false);
        percentageGroupBox->setCheckable(false);
        percentageLcdNum = new QLCDNumber(percentageGroupBox);
        percentageLcdNum->setObjectName(QStringLiteral("percentageLcdNum"));
        percentageLcdNum->setGeometry(QRect(6, 22, 61, 25));
        percentageLcdNum->setFont(font1);
        percentageLcdNum->setDigitCount(7);
        percentageLcdNum->setSegmentStyle(QLCDNumber::Flat);
        percentageLabel = new QLabel(percentageGroupBox);
        percentageLabel->setObjectName(QStringLiteral("percentageLabel"));
        percentageLabel->setGeometry(QRect(77, 24, 15, 20));
        percentageLabel->setFont(font2);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(212, 10, 41, 41));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        progressroupBox = new QGroupBox(centralWidget);
        progressroupBox->setObjectName(QStringLiteral("progressroupBox"));
        progressroupBox->setGeometry(QRect(8, 180, 141, 50));
        progressroupBox->setFont(font);
        progressroupBox->setLayoutDirection(Qt::LeftToRight);
        progressroupBox->setAutoFillBackground(false);
        progressroupBox->setFlat(false);
        progressroupBox->setCheckable(false);
        readyLabel = new QLabel(progressroupBox);
        readyLabel->setObjectName(QStringLiteral("readyLabel"));
        readyLabel->setGeometry(QRect(52, 24, 61, 20));
        readyLabel->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 402, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Download Manager", 0));
        currentGroupBox->setTitle(QApplication::translate("MainWindow", "[Current Speed]", 0));
        currentSpeedLabel->setText(QApplication::translate("MainWindow", "KB/sec", 0));
        averageGroupBox->setTitle(QApplication::translate("MainWindow", "[Average Speed]", 0));
        averageSpeedLabel->setText(QApplication::translate("MainWindow", "KB/sec", 0));
        settingsGroupBox->setTitle(QApplication::translate("MainWindow", "[Settings]", 0));
        chooseFolderButton->setText(QApplication::translate("MainWindow", "Set folder", 0));
        downloadButton->setText(QApplication::translate("MainWindow", "Download", 0));
        timeFromStartGroupBox->setTitle(QApplication::translate("MainWindow", "[Time From Start]", 0));
        startSecLabel->setText(QApplication::translate("MainWindow", "sec", 0));
        startMinLabel->setText(QApplication::translate("MainWindow", "min", 0));
        startHourLabel->setText(QApplication::translate("MainWindow", "h", 0));
        remainingTimeGroupBox->setTitle(QApplication::translate("MainWindow", "[Remaining Time]", 0));
        remainingMinLabel->setText(QApplication::translate("MainWindow", "min", 0));
        remainingHourLabel->setText(QApplication::translate("MainWindow", "h", 0));
        receivedFileGroupBox->setTitle(QApplication::translate("MainWindow", "[Received]", 0));
        receivedFileLabel->setText(QApplication::translate("MainWindow", "MB", 0));
        fileSizeGroupBox->setTitle(QApplication::translate("MainWindow", "[File Size]", 0));
        fileSizeLabel->setText(QApplication::translate("MainWindow", "MB", 0));
        remainingFileGroupBox->setTitle(QApplication::translate("MainWindow", "[Remaining]", 0));
        remainingFileLabel->setText(QApplication::translate("MainWindow", "MB", 0));
        percentageGroupBox->setTitle(QApplication::translate("MainWindow", "[Percentage]", 0));
        percentageLabel->setText(QApplication::translate("MainWindow", "%", 0));
        label->setText(QApplication::translate("MainWindow", "<>", 0));
        progressroupBox->setTitle(QApplication::translate("MainWindow", "[Progress]", 0));
        readyLabel->setText(QApplication::translate("MainWindow", "Ready", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
