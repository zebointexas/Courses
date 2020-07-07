#include <QtGui>

#include "slidersgroup.h"
#include "window.h"

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
     connect(slider, SIGNAL(valueChanged(int)),
             lcd, SLOT(display(int)));

     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(lcd);
     layout->addWidget(slider);
     setLayout(layout);
 }
 
/** Main windows **/
Window::Window()
{
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
         for (int column = 0; column < 2; ++column) {
             LCDRange *lcdRange = new LCDRange;
             grid->addWidget(lcdRange, row, column);
         }
     }
 
     QPushButton *quit = new QPushButton(tr("Exit"));
     quit->setFont(QFont("Helvetica", 20, QFont::Bold));
     connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
  
 
     layout->addWidget(AM);
     layout->addLayout(grid);


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
   
     setLayout(layout);

     minimumSpinBox->setValue(0);
     maximumSpinBox->setValue(200);
     valueSpinBox->setValue(39);

     setWindowTitle(tr("Radio Interface"));
}


/** controlsGroup classes **/
void Window::createControls(const QString &title)
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
