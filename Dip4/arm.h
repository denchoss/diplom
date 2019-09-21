#ifndef _ARM_h_
#define _ARM_h_
#include <qpushbutton.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include "visual.h"

class MyWidget: public QWidget
{
	Q_OBJECT
	public:
    		MyWidget( QWidget *parent=0, const char *name=0 );
		QPushButton *close;   
		CannonField *cannonField;
		QComboBox * combtest;
		QComboBox * combpal;
		QLabel * stor;
		QLabel * con;
		QComboBox * combstor;
		QLabel * lim;
		QSpinBox *spinl;
		QPushButton * get;
		QPushButton * next;
	public slots:
		void switchbut(int);
		void connect_serv();
		void noconnect_serv();
	signals:

	protected:
				
};

#endif //_ARM_h_