#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "resultsmodel.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionRun_test_Solution_triggered();

    void on_actionRun_test_ResultsModel_triggered();

    void on_actionAdd_time_triggered();

private:
    Ui::MainWindow *ui;
    ResultsModel *results;
};

#endif // MAINWINDOW_H
