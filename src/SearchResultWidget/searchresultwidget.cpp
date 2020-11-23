/*
 * Copyright (C) 2019 Tianjin KYLIN Information Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
 *
 */

#include "searchresultwidget.h"
#include "src/Style/style.h"
#include <QDebug>
#include <QHeaderView>

SearchResultWidget::SearchResultWidget(QWidget *parent) :
    QWidget(parent)
{
    initUi();
}

SearchResultWidget::~SearchResultWidget()
{
    delete m_ukuiMenuInterface;
}

void SearchResultWidget::initUi()
{
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_StyledBackground,true);
    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    this->setFixedSize(Style::defaultMainViewWidWidth,200);

    m_listView=new ListView(this,this->width()-6,this->height()-6,3);
    m_listView->setGeometry(QRect(6,0,this->width()-6,this->height()-6));
    m_listView->show();

    m_data.clear();
    m_listView->addData(m_data);//添加应用数据
    m_ukuiMenuInterface=new UkuiMenuInterface;

    connect(m_listView,&ListView::sendItemClickedSignal,this,&SearchResultWidget::execApplication);
}

/**
 * 执行应用程序
 */
void SearchResultWidget::execApplication(QStringList arg)
{
    QString desktopfp=arg.at(0);
    GDesktopAppInfo * desktopAppInfo=g_desktop_app_info_new_from_filename(desktopfp.toLocal8Bit().data());
    g_app_info_launch(G_APP_INFO(desktopAppInfo),nullptr, nullptr, nullptr);
    g_object_unref(desktopAppInfo);
}

void SearchResultWidget::updateAppListView(QVector<QStringList> arg)
{
    m_data.clear();
    Q_FOREACH(QStringList appinfo,arg)
        m_data.append(QStringList()<<appinfo.at(0)<<"1");

    m_listView->updateData(m_data);
    //根据获取的应用数量，刷新界面高度
    this->setFixedSize(Style::defaultMainViewWidWidth,m_data.size()*46);
}
