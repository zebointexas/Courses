 /****************************************************************************
 **
 ** Copyright (C) 2005-2008 Nokia Corporation and/or its subsidiary(-ies). All rights reserved.
 **
 ** This file is part of the documentation of the Qt Toolkit.
 **
 ** Licensees holding a valid Qt License Agreement may use this file in
 ** accordance with the rights, responsibilities and obligations
 ** contained therein.  Please consult your licensing agreement or
 ** contact qt-sales@nokia.com if any conditions of this licensing
 ** agreement are not clear to you.
 **
 ** Further information about Qt licensing is available at:
 ** http://trolltech.com/products/appdev/licensing.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 **
 ****************************************************************************/

 #include <QApplication>
 #include <QFont>
 #include <QPushButton>
 #include <QWidget>

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);

     QWidget window;
     window.resize(200, 120);

     QPushButton quit("Quit", &window);
     quit.setFont(QFont("Times", 18, QFont::Bold));
     quit.setGeometry(10, 40, 180, 40);
     QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

     window.show();
     return app.exec();
 }
