#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "mineSweepScene.h"
#include <QMouseEvent>
#include "cellItem.h"


namespace Ui { class MainWindow; }


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void deleteOldScene();//删除旧场景
    void addNewScene();//布置新场景
    void adjustWindowsWH();//调整主窗口大小
    void block_blank(double px, double py, int x, int y);//一整块为空，全部翻起来，直到边缘为数字或遇到边界

    bool JudgeIsWin();//判赢

private slots:
    void on_actionNew_game_triggered();
    void on_actionConfig_triggered();
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();
    void on_actionInstructions_triggered();
private:
    Ui::MainWindow *ui;
    QGraphicsView *_view;
    mineSweepScene *_scene;

    cellItem *_cItem;
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
