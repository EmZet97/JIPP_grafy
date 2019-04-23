#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graph.h"


using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //RefreshWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}
Graph g;
QString xmlcode="";
void MainWindow::RefreshWindow(){

    /*g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addEdge(1,2);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(1,1);
    g.addEdge(2,1);
    g.addEdge(2,0);
    g.addEdge(2,2);
    g.deleteEdge(2,0);
    g.deleteVertex(1);*/
    ui->textEdit->setText( g.showGraph());
    ui->XML_te->setText(g.getXML());
    xmlcode = g.getXML();
}
void MainWindow::on_actionWczytaj_graf_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Wybierz plik do otwarcia");
    QFile file(filename);
    currentFile = filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Nie mozna otworzyc pliku : " + file.errorString());
        return;
    }
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    //
    //
    //
    file.close();

}

void MainWindow::on_actionZapisz_graf_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,"Wybierz miejsce zapisu");
    QFile file(filename);

    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Nie mozna zapisac pliku : " + file.errorString());
        return;
    }
    currentFile = filename;
    setWindowTitle((filename));
    QTextStream out(&file);
    //
    QString text = xmlcode;
    //

    out<<text;
    file.close();

}

void MainWindow::on_CreateEdge_bt_clicked()
{
    g.addEdge(ui->from_sb->value(), ui->to_sb->value());
    RefreshWindow();
}
int s = 0;
void MainWindow::on_CreateVertex_bt_clicked()
{
    ui->from_sb->setEnabled(true);
    ui->to_sb->setEnabled(true);
    ui->CreateEdge_bt->setEnabled(true);
    ui->from_sb->setMaximum(s);
    ui->to_sb->setMaximum(s);
    g.addVertex();
    RefreshWindow();
    s++;
}
