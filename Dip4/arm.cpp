#include "arm.h"
#include <qapplication.h>

MyWidget::MyWidget( QWidget *parent, const char *name ): QWidget( parent, name )
{	
	close = new QPushButton(QObject::tr("close"), this, "close" );
	close->setFont( QFont( "Times", 18, QFont::Bold ) );
	connect( close, SIGNAL(clicked()), qApp, SLOT(quit()) );
	close->setMaximumWidth (150);

	cannonField  = new CannonField( this, "cannonField" );

	combtest = new QComboBox( this );
	combtest->insertItem(QObject::tr("test:1"));
	combtest->insertItem(QObject::tr("test:2"));
	combtest->insertItem(QObject::tr("test:3"));
	combtest->setFont( QFont( "Times", 18, QFont::Bold ) );
	combtest->setMaximumWidth (130);
	connect( combtest, SIGNAL(activated ( int )),cannonField, SLOT(combtest_change(int)) );

	combpal = new QComboBox( this );
	combpal->insertItem(QObject::tr("palette:green"));
	combpal->insertItem(QObject::tr("palette:blue"));
	combpal->insertItem(QObject::tr("palette:grey"));
	combpal->setFont( QFont( "Times", 18, QFont::Bold ) );
	combpal->setMaximumWidth (300);
	connect( combpal, SIGNAL(activated ( int )),cannonField, SLOT(combpal_change(int)) );

	get= new QPushButton(QObject::tr("get frame"), this, "get" );
	get->setFont( QFont( "Times", 18, QFont::Bold ) );
	get->setMaximumWidth (300);
	connect( get, SIGNAL(clicked()), cannonField, SLOT(start_switchbut()) );
	connect( cannonField, SIGNAL(switchbutt(int)), this, SLOT(switchbut(int)) );

	next= new QPushButton(QObject::tr("next frame"), this, "next" );
	next->setFont( QFont( "Times", 18, QFont::Bold ) );
	next->setMaximumWidth (300);
	connect( next, SIGNAL(clicked()), cannonField, SLOT(senders()) );

	stor = new QLabel(QObject::tr("storage:"), this);
	stor->setFont( QFont( "Times", 18, QFont::Bold ) );

	combstor= new QComboBox( this );
	combstor->insertItem("1");
	combstor->insertItem("2");
	combstor->insertItem("4");
	combstor->insertItem("8");
	combstor->insertItem("16");
	combstor->setFont( QFont( "Times", 18, QFont::Bold ) );
	combstor->setMaximumWidth (50);
	connect( combstor, SIGNAL(activated ( int )),cannonField, SLOT(combstor_change(int)) );

	lim = new QLabel(QObject::tr("limit:"), this);
	lim->setFont( QFont( "Times", 18, QFont::Bold ) );

	spinl= new QSpinBox( this );
	spinl->setRange(0,255);
	spinl->setSuffix(" %");
	spinl->setLineStep ( 10 );
	spinl->setValue(0);
	spinl->setFont( QFont( "Times", 18, QFont::Bold ) );
	spinl->setFixedWidth(90);
	connect( spinl, SIGNAL(valueChanged(int)),cannonField, SLOT(setlim(int)) );

	con = new QLabel(QObject::tr("storage:"), this);
	con->setFont( QFont( "Times", 18, QFont::Bold ) );
	connect( cannonField, SIGNAL(con_ley()), this, SLOT(connect_serv()) );
	connect( cannonField, SIGNAL(nocon_ley()), this, SLOT(noconnect_serv()) );

	QVBoxLayout *pvbx = new QVBoxLayout(this);
	
	QHBoxLayout *phbx1 = new QHBoxLayout();
	QHBoxLayout *phbx2 = new QHBoxLayout();
	QHBoxLayout *phbx3 = new QHBoxLayout();
	QHBoxLayout *phbx4 = new QHBoxLayout();
	QHBoxLayout *phbx5 = new QHBoxLayout();
	phbx1->setMargin(65);
	phbx1->addWidget(cannonField);
	phbx2->addWidget(combtest);
	phbx2->addWidget(combpal);
	phbx2->addLayout(phbx3);
	phbx3->addWidget(stor);
	phbx3->addWidget(combstor);
	phbx3->setMargin(65);
	phbx2->addLayout(phbx4);
	phbx4->addWidget(lim);
	phbx4->addWidget(spinl);
	phbx4->setMargin(75);
	phbx5->addWidget(get);
	phbx5->addWidget(next);
	phbx5->setSpacing(50);
	phbx5->addWidget(close);
	phbx5->addWidget(con);
	
	pvbx->setMargin (20);
	pvbx->addLayout(phbx1);
	pvbx->addLayout(phbx2);
	pvbx->addLayout(phbx5);
}

void MyWidget::switchbut(int a)
{
	if(a)
		get->setText(QObject::tr("stop getting"));
	else
		get->setText(QObject::tr("get frame"));	
}
void MyWidget::connect_serv()
{
	con->setText(QObject::tr("Connected to server ip"));
}
void MyWidget::noconnect_serv()
{
	con->setText(QObject::tr("don't connect to server"));
}

