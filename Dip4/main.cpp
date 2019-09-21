#include <qapplication.h>
#include "arm.h"
int main( int argc, char **argv )
{
	QApplication a( argc, argv );
	
	QTranslator *ptranslator1= new QTranslator(0);	
	ptranslator1->load("main_ru.qm",".");
	a.installTranslator(ptranslator1);

	QTranslator *ptranslator2= new QTranslator(0);	
	ptranslator2->load("arm_ru.qm",".");
	a.installTranslator(ptranslator2);

	MyWidget w;
	a.setMainWidget( &w );
	w.setGeometry( 0,0, 1200, 900 );
	w.setCaption (QObject::tr("client"));
	w.show();
	return a.exec();
}