#include <iostream>
#include <ctime>

#include <QString>
#include <QInputDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "solution.hpp"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    results = new ResultsModel();

    ui->resultsView->setModel(results);
    ui->resultsView->verticalHeader()->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete results;
}

void MainWindow::on_actionRun_test_Solution_triggered()
{
    //    std::cout << "0\t60\t3600\t3600000\t143412" << std::endl;
    //    std::cout << Solution::TimeToString(0) << std::endl;
    //    std::cout << Solution::TimeToString(3600) << std::endl;
    //    std::cout << Solution::TimeToString(3600000) << std::endl;
    //    std::cout << Solution::TimeToString(143412) << std::endl;
}

void MainWindow::on_actionRun_test_ResultsModel_triggered()
{
    Solution s(time(NULL), time(NULL) + 12454, "asdasd", "");
    results->addSolution(s);
    s.setStart(s.getEnd() + 1000);
    s.setEnd(s.getStart() + 10000);
    results->addSolution(s);
    results->addSolution(Solution(time(NULL) + 1400, time(NULL) + 5000));
    results->addSolution(Solution(time(NULL) + 1700, time(NULL) + 8500));
    results->addSolution(Solution(time(NULL) + 5000, time(NULL) + 10544));
}

void MainWindow::on_actionAdd_time_triggered()
{
    QString t = QInputDialog::getText(NULL, "ASD", "asd");
    long int tm = atoi(t.toStdString().c_str());
    results->addSolution(Solution(time(NULL) - tm, time(NULL)));
}
