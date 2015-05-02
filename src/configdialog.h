#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStackedWidget>
#include <QLabel>
#include <QComboBox>
#include <QRadioButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QSettings>

class ConfigDialog : public QDialog {

    Q_OBJECT

public:
    ConfigDialog(QWidget *parent);

private:
    QSettings* settings;

    QListWidget* contentsWidget;
    QStackedWidget* stackedWidget;

    QPushButton* closeButton;
    QPushButton* okButton;

    QWidget* generalSettingsWidget;
    QWidget* appearanceSettingsWidget;

    QGroupBox* filesGroup;
    QCheckBox* openLastFilesCheck;


    QGroupBox* styleGroup;
    QLabel* styleLabel;
    QLabel* warningLabel;
    QComboBox* styleSelection;
    QGroupBox* iconsGroup;
    QButtonGroup* iconsSelection;
    QRadioButton* nativeIconsButton;
    QRadioButton* oxygenIconsButton;

    void createLayout();
    void createIcons();

private slots:
    void applyChanges();
    void changeLayout(QListWidgetItem* item);

};

#endif // CONFIGDIALOG_H
