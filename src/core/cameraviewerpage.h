/**************************************************************************
*   Copyright (C) 2008 by Leandro Emanuel López                           *
*   lopezlean@gmail.com                                                   *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/
#ifndef CAMERAVIEWERPAGE_H
#define CAMERAVIEWERPAGE_H

#include <QWidget>
class CameraLayout;

class CameraViewerPage : public QWidget{
    Q_OBJECT
public:
    CameraViewerPage( int rows, int columns, QWidget * parent = 0 );
    void appendCamera( QWidget * camera );
    bool hasSpace() const;
    void updateLayout();
    ~CameraViewerPage();
Q_SIGNALS:
    void newPageRequired();
protected:
    void resizeEvent ( QResizeEvent * event );
private:
    CameraLayout * m_cameraLayout;
};

#endif