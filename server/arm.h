#ifndef _ARM_h_
#define _ARM_h_

#include <qpushbutton.h>

class MyWidget: public QWidget
{
	Q_OBJECT
	public:
    		MyWidget( QWidget *parent=0, const char *name=0 );
		~MyWidget();
		QPushButton *quit;
	public slots:

	signals:
	
	protected:

};

#endif //_ARM_h_
