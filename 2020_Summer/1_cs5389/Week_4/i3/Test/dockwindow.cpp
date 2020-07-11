#include <QtGui>
#include "dockwindow.h"
#include "slidersgroup.h"
#include "window.h"
#include "globj.h"

/** Class for LCD Range  **/
 class LCDRange : public QWidget
 {
	 public:
	     LCDRange(QWidget *parent = 0);
 };

 LCDRange::LCDRange(QWidget *parent)
     : QWidget(parent)
 { 
     QLCDNumber *lcd = new QLCDNumber(2);
     lcd->setSegmentStyle(QLCDNumber::Filled);

     QSlider *slider = new QSlider(Qt::Horizontal);
     slider->setRange(0, 99);
     slider->setValue(29);
     connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(lcd);
     layout->addWidget(slider);
     setLayout(layout);
 }
 





DockWindow::DockWindow(QWidget *parent) : QMainWindow(parent)
{
    textEdit = new QTextEdit;
    setCentralWidget(textEdit);
 
    createActions();
    createMenus();
    createToolBars();
    createStatusBars();
    createDockWindows();
 

 
    setWindowTitle(tr("Dock Zebo"));
}
 
void DockWindow::newFile()
{
    textEdit->clear();
    QMessageBox::about(this, tr("Dock Window"),
                       tr("you triggered the"
                          "\nnewFileSlot successfully"));
}
 
void DockWindow::save()
{
    QMessageBox::information(this, tr("Dock Window"),
                             tr("Save the file ?"),
                             QMessageBox::Ok | QMessageBox::No
                             | QMessageBox::Cancel);
}
 
void DockWindow::about()
{
    QMessageBox::warning(this, tr("Dock Window"),
                         tr("Thanks"),QMessageBox::Yes | QMessageBox::No);
}
 
void DockWindow::createActions()   // Define the actions, such as save, exit, new, etc
{
    newAction = new QAction(tr("&New"),this);
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("create a new file"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));
 
    saveAction = new QAction(tr("&Save"),this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("save a exist file"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));
 
    exitAction = new QAction(tr("E&xit"),this);
    exitAction->setShortcut(QKeySequence::Close);
    exitAction->setStatusTip(tr("quit the application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
 
    aboutAction = new QAction(tr("About"),this);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
}
 
void DockWindow::createMenus()  //make the top menu
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
 
    viewMenu = menuBar()->addMenu(tr("&View from GUI course"));
 
    helpMenu = menuBar()->addMenu(tr("&Hele from TXST"));
    helpMenu->addAction(aboutAction);
}
 
void DockWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(saveAction);
    fileToolBar->addAction(exitAction);
 
    viewToolBar = addToolBar(tr("&View"));
 
    helpToolBar = addToolBar(tr("&Help"));
    helpToolBar->addAction(aboutAction);
}
 
void DockWindow::createStatusBars()
{
    statusBar()->showMessage(tr("Ready"));
}
 
void DockWindow::createDockWindows()
{
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// --> Add draw windows
   
    GLobj *globj = new GLobj(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(globj);
    
    QDockWidget *draw = new QDockWidget(this);
    draw->setWindowTitle(tr("Draw"));
    draw->setAllowedAreas(Qt::TopDockWidgetArea);
    
    draw->setWidget(globj);
    addDockWidget(Qt::LeftDockWidgetArea,draw);  // add dock to top
    viewMenu->addAction(draw->toggleViewAction());  // let you view this option in "view" dropbox option
    viewToolBar->addAction(draw->toggleViewAction());   // Let you view the botton. Other, you cannot even find this "About her" botton
 


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// --> Add draw windows
   
    GLobj_2 *globj2 = new GLobj_2(this);
    QHBoxLayout *mainLayout2 = new QHBoxLayout(this);
    mainLayout2->addWidget(globj2);
   
    QDockWidget *draw2 = new QDockWidget(this);
    draw2->setWindowTitle(tr("Wave"));
    draw2->setAllowedAreas(Qt::TopDockWidgetArea);
    
    draw2->setWidget(globj2);
    addDockWidget(Qt::RightDockWidgetArea,draw2);  // add dock to top
    viewMenu->addAction(draw2->toggleViewAction());  // let you view this option in "view" dropbox option
    viewToolBar->addAction(draw2->toggleViewAction());   // Let you view the botton. Other, you cannot even find this "About her" botton

 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
///// --> Radio
    // Define the FM control Panel 
    horizontalSliders = new SlidersGroup(Qt::Horizontal, tr("FM - Horizontal"));
    verticalSliders = new SlidersGroup(Qt::Vertical, tr("FM - Vertical"));

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(horizontalSliders);
    stackedWidget->addWidget(verticalSliders);

    createControls(tr("Control Panel"));

    connect(horizontalSliders, SIGNAL(valueChanged(int)),
            verticalSliders, SLOT(setValue(int)));
    connect(verticalSliders, SIGNAL(valueChanged(int)),
            valueSpinBox, SLOT(setValue(int)));
    connect(valueSpinBox, SIGNAL(valueChanged(int)),
            horizontalSliders, SLOT(setValue(int)));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(controlsGroup);
    layout->addWidget(stackedWidget);
 

     QLabel *AM;
     QLabel *Bass;
     QLabel *Treble;
    
     // Define the AM control 
     AM = new QLabel(tr("AM:"));
     Bass = new QLabel(tr("Bass:"));
     Treble = new QLabel(tr("Treble:"));


     QGridLayout *grid = new QGridLayout;

     for (int row = 0; row < 2; ++row) {
         for (int column = 0; column < 1; ++column) {
             LCDRange *lcdRange = new LCDRange;
             grid->addWidget(lcdRange, row, column);
         }
     }
 
     QPushButton *quit = new QPushButton(tr("Exit"));
     quit->setFont(QFont("Helvetica", 20, QFont::Bold));
     connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
   
     layout->addWidget(AM);
     layout->addLayout(grid);
 
     QLCDNumber *lcd_2 = new QLCDNumber(2);
     lcd_2->setSegmentStyle(QLCDNumber::Filled);

     QSlider *slider_2 = new QSlider(Qt::Vertical);
     slider_2->setRange(0, 99);
     slider_2->setValue(29);
     connect(slider_2, SIGNAL(valueChanged(int)), lcd_2, SLOT(fre));
 
     layout->addWidget(lcd_2);
     layout->addWidget(slider_2);
       
     // Define the Treble control 
     QLCDNumber *lcd = new QLCDNumber(3);
     lcd->setSegmentStyle(QLCDNumber::Filled);

     QSlider *slider = new QSlider(Qt::Vertical);
     slider->setRange(0, 99);
     slider->setValue(0);

     connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
     connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
 
     layout->addWidget(Treble);
     layout->addWidget(lcd);
     layout->addWidget(slider);
 
     // Define the Bass control
     QLCDNumber *lcd_BASS = new QLCDNumber(2);
     lcd_BASS->setSegmentStyle(QLCDNumber::Filled);

     QSlider *slider_BASS = new QSlider(Qt::Vertical);
     slider_BASS->setRange(0, 99);
     slider_BASS->setValue(0);
 
     connect(slider_BASS, SIGNAL(valueChanged(int)), lcd_BASS, SLOT(display(int)));
 
     layout->addWidget(Bass);
     layout->addWidget(lcd_BASS);
     layout->addWidget(slider_BASS);
 
     layout->addWidget(quit);
   
    // setLayout(layout);

     minimumSpinBox->setValue(0);
     maximumSpinBox->setValue(200);
     valueSpinBox->setValue(39);

     setWindowTitle(tr("Radio Interface"));

    ///// --> add radio
 
    QDockWidget *radio = new QDockWidget(this);
    QWidget *multi = new QWidget();
	
    multi->setLayout(layout);

    radio->setWindowTitle(tr("Radio"));
    radio->setWidget(multi);
  
    radio->setFeatures(QDockWidget::AllDockWidgetFeatures);
    radio->setAllowedAreas(Qt::BottomDockWidgetArea);

    addDockWidget(Qt::BottomDockWidgetArea,radio);  //  add dock to bottom
    viewMenu->addAction(radio->toggleViewAction());
    viewToolBar->addAction(radio->toggleViewAction());
 
}
 
DockWindow::~DockWindow()
{
}



 

/** controlsGroup classes **/
void DockWindow::createControls(const QString &title)
{
    controlsGroup = new QGroupBox(title);

    minimumLabel = new QLabel(tr("Minimum:"));
    maximumLabel = new QLabel(tr("Maximum:"));
    valueLabel = new QLabel(tr("Current:"));
 
    minimumSpinBox = new QSpinBox;
    minimumSpinBox->setRange(0, 200);
    minimumSpinBox->setSingleStep(1);

    maximumSpinBox = new QSpinBox;
    maximumSpinBox->setRange(0, 200);
    maximumSpinBox->setSingleStep(1);

    valueSpinBox = new QSpinBox;
    valueSpinBox->setRange(0, 200);
    valueSpinBox->setSingleStep(1);

    orientationCombo = new QComboBox;
    orientationCombo->addItem(tr("FM - Horizontal Look"));
    orientationCombo->addItem(tr("FM - Vertical Look"));

    connect(orientationCombo, SIGNAL(activated(int)),
            stackedWidget, SLOT(setCurrentIndex(int)));
    connect(minimumSpinBox, SIGNAL(valueChanged(int)),
            horizontalSliders, SLOT(setMinimum(int)));
    connect(minimumSpinBox, SIGNAL(valueChanged(int)),
            verticalSliders, SLOT(setMinimum(int)));
    connect(maximumSpinBox, SIGNAL(valueChanged(int)),
            horizontalSliders, SLOT(setMaximum(int)));
    connect(maximumSpinBox, SIGNAL(valueChanged(int)),
            verticalSliders, SLOT(setMaximum(int)));
 
    QGridLayout *controlsLayout = new QGridLayout;
    controlsLayout->addWidget(minimumLabel, 0, 0);
    controlsLayout->addWidget(maximumLabel, 1, 0);

    controlsLayout->addWidget(valueLabel, 2, 0);

    controlsLayout->addWidget(minimumSpinBox, 0, 1);
    controlsLayout->addWidget(maximumSpinBox, 1, 1);

    controlsLayout->addWidget(valueSpinBox, 2, 1);
 
    controlsLayout->addWidget(orientationCombo, 3, 0, 1, 3);
    controlsGroup->setLayout(controlsLayout);
}









  
