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
 #include <QGridLayout>
 #include <QPushButton>

 #include "cannonfield.h"
 #include "lcdrange.h"

 class MyWidget : public QWidget
 {
 public:
     MyWidget(QWidget *parent = 0);
 };

 MyWidget::MyWidget(QWidget *parent)
     : QWidget(parent)
 {
     QPushButton *quit = new QPushButton(tr("Quit"));
     quit->setFont(QFont("Times", 18, QFont::Bold));

     connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

     LCDRange *angle = new LCDRange;
     angle->setRange(5, 70);

     CannonField *cannonField = new CannonField;

     connect(angle, SIGNAL(valueChanged(int)),
             cannonField, SLOT(setAngle(int)));
     connect(cannonField, SIGNAL(angleChanged(int)),
             angle, SLOT(setValue(int)));

     QGridLayout *gridLayout = new QGridLayout;
     gridLayout->addWidget(quit, 0, 0);
     gridLayout->addWidget(angle, 1, 0);
     gridLayout->addWidget(cannonField, 1, 1, 2, 1);
     gridLayout->setColumnStretch(1, 10);
     setLayout(gridLayout);

     angle->setValue(60);
     angle->setFocus();
 }

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     MyWidget widget;
     widget.setGeometry(100, 100, 500, 355);
     widget.show();
     return app.exec();
 }
