#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
QString currentFile;
public:
    explicit MainWindow(QWidget *parent = 0);
    void RefreshWindow();
    ~MainWindow();

private slots:
    void on_actionWczytaj_graf_triggered();

    void on_actionZapisz_graf_triggered();

    void on_CreateEdge_bt_clicked();

    void on_CreateVertex_bt_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
