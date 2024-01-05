#ifndef TIME_RECORD_H
#define TIME_RECORD_H

#include <QWidget>

#include<QUrl>
#include<QDebug>
#include<QMessageBox>
#include<QTime>
#include<QTimer>
#include<QJsonObject>
#include<QJsonDocument>
#include<QFile>
#include<QMessageBox>
#include<QMediaPlayer>
#include<QDir>
#include<QDockWidget>
#include<QListView>

#include"Global.hpp" //这种也可以帮助我们区分是否有包含自带的头文件
#include"mythread.h"
#include"closethread.h"
#include"timer_Countdown/progess.h"
#include"timer_Countdown/progessson.h"
namespace Ui {
class Time_record;
}

class Time_record : public QWidget
{
    Q_OBJECT

public:
    explicit Time_record(QWidget *parent = nullptr);
    ~Time_record();


//public slots:
//    void setCircleProgressBar(int value,int remain_time);
//    void Session_setCircleProgressBar(int value);
signals:
    void send_json(Init_Json json);
    void ToSetCircleProgressBar(int value,int remain_time);
    void ToSession_setCircleProgressBar(int value);

private slots:
    void on_OpenUrl_clicked();

    void on_Settings_clicked();


    void on_additional_widget_clicked();

    void on_track_time_clicked();
    void UpdateTime();
    void convey_init(Init_Json json); //用来初始化json数据的，设置组件的默认状态
    void on_AutoConverSation_clicked();

    void on_notice_voice_clicked();

    void on_track_PushButton_clicked();


    void on_spinBox_3_valueChanged(int arg1);


    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Time_record *ui;
//    Progess *Progess_Bar;
    ProgessSon *Progess_Bar;
    ProgessSon *Progess_BarSon;
    QListView * MyView=nullptr;
    bool cutover=true;
    bool WhetherFirstPlay=false;
    QTimer *m_timer=nullptr;
    int remainingTime; //后面要利用json，保存到本地，进行一个读取
    int change_time; //默认5分钟

    int rest_change_time;
    int remain_rest_time;

    int Number_of_sessions;
    int rest_time;
    MyThread* new_thread_read=nullptr;
    CloseThread* new_thread_write=nullptr;
    MyThread* new_thread_init=nullptr;
    Init_Json json;
    bool Rest_or_Study=false;  //false默认是study，rest默认是休息
    bool FirstEnter=false;
    int StudyDivisor=3;
    int RestDivisor=3;
    QMediaPlayer *FinishPlayer=nullptr;
    QDockWidget *dock=nullptr;

private:
    void my_init();
    void init_thread();
    void ui_init();
    void decide_AutoConverSation();
    void decide_notice_voice();
    void decide_track_PushButton();
    void CancelEdit();
    void RevertEdit();

protected:
    void paintEvent(QPaintEvent *event)override;

};

#endif // TIME_RECORD_H
