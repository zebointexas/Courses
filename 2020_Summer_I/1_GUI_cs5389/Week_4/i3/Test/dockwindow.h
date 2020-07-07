#ifndef DOCKWINDOW_H
#define DOCKWINDOW_H
 
#include <QMainWindow>
#include "window.h"
#include <QWidget>
 
class QMenu;
class QToolBar;
class QAction;
class QTextEdit;
 
class DockWindow : public QMainWindow
{
    Q_OBJECT
	    
	public:
	    DockWindow(QWidget *parent = 0);
	    ~DockWindow();
	    int fre; 
	 
	private slots:
	    void newFile();
	    void save();
	    void about();
	 
	private:
	    void createMenus();
	    void createActions();
	    void createToolBars();
	    void createStatusBars();
	    void createDockWindows();

	   
	 
	    QMenu *fileMenu;
	    QMenu *viewMenu;
	    QMenu *helpMenu;
	 
	    QToolBar *fileToolBar;
	    QToolBar *viewToolBar;
	    QToolBar *helpToolBar;
	 
	    QAction *newAction;
	    QAction *saveAction;
	    QAction *exitAction;
	    QAction *aboutAction;
	 
	    QTextEdit *textEdit;

		void createControls(const QString &title);

		SlidersGroup *horizontalSliders;
		SlidersGroup *verticalSliders;
		QStackedWidget *stackedWidget;

		QGroupBox *controlsGroup;
		QLabel *minimumLabel;
		QLabel *maximumLabel;
		QLabel *valueLabel;
		QLabel *AM;
		QLabel *Bass;
		QLabel *Treble;





		QCheckBox *invertedAppearance;
		QCheckBox *invertedKeyBindings;
		QSpinBox *minimumSpinBox;
		QSpinBox *maximumSpinBox;
		QSpinBox *valueSpinBox;
		QComboBox *orientationCombo;

};
 
#endif // DOCKWINDOW_H
