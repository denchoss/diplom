#include "arm.h"
#include <qapplication.h>

MyWidget::MyWidget( QWidget *parent, const char *name )
        : QWidget( parent, name )
{	
	quit = new QPushButton(QObject::tr("close"), this, "quit" );
	quit->setFont( QFont( "Times", 14, QFont::Bold ) );
	connect( quit, SIGNAL(clicked()), qApp, SLOT(quit()) );
	quit->setFixedWidth(100);	
}

MyWidget::~MyWidget()
{
	
}




