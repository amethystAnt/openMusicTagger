#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtCore>

#include "audiofile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<AudioFile*> listOfFiles;
    void updateViews();
    void updateEditor();
    bool isFileOnList(QString path);
    AudioFile* openedFile;

public slots:
    void openFile();
    void openFolder();
    void openInEditor(QTreeWidgetItem* file);

};

#endif // MAINWINDOW_H
