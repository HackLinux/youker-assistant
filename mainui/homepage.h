/*
 * Copyright (C) 2013 ~ 2015 National University of Defense Technology(NUDT) & Kylin Ltd.
 *
 * Authors:
 *  Kobe Lee    xiangli@ubuntukylin.com/kobe24_lixiang@126.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

class MainWindow;
class SessionDispatcher;
#include "autostartwidget.h"
#include "cameramanager.h"

class HomePage : public QWidget
{
    Q_OBJECT
public:
    explicit HomePage(QWidget *parent = 0, const QString &version = "");
    ~HomePage();
    void setLanguage();
    void initBoxTool();
    void initConnect();
    void setSessionDbusProxy(SessionDispatcher *dispatcher) { sessionProxy = dispatcher;}
    void setParentWindow(MainWindow* window) { p_mainwindow = window;}
    void initUI();

public slots:
    void switchPageIndex(QString index);
    void checkLastestVersion();

private:
    QLabel *version_logo;
    QLabel *version_title;
    QLabel *version_tip;
    QPushButton *check_btn;
    QLabel *version_label;
    QLabel *box_logo;
    QLabel *box_title;
    QLabel *box_tip;
    QPushButton *more_text_btn;
    QPushButton *more_btn;
    SessionDispatcher *sessionProxy;
    MainWindow *p_mainwindow;
    AutoStartWidget *auto_start;
    CameraManager *camera_manager;
    QString current_version;
};

#endif // HOMEPAGE_H
