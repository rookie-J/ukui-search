/*
 *
 * Copyright (C) 2020, KylinSoft Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Authors: zhangjiaping <zhangjiaping@kylinos.cn>
 *
 */
#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H
#include <QThread>
#include <QWaitCondition>
#include <QTimer>
#include "mainwindow.h"

class SearchResult : public QThread {
    Q_OBJECT
public:
    SearchResult(QObject * parent = nullptr);
    ~SearchResult();
protected:
    void run() override;

private:
    MainWindow * m_mainwindow = nullptr;
//    QTimer * m_timer = nullptr;

Q_SIGNALS:
    void searchResultFile(const QString&);
    void searchResultDir(const QString&);
//    void searchResultContent(const QString&, const QStringList&);
    void searchResultContent(const QPair<QString, QStringList>);

};
#endif // SEARCHRESULT_H
