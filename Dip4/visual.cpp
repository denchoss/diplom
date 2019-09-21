#include "visual.h"
#include <qpainter.h>
#include <qimage.h>

int ntest=1;
int pall=1;
int limit=0;
int rr;
int iread=0;
int storage=1;
int START_switchbut=0;
int j=0;
int i=0;

int d2[1024*512];
int d4[1024*512];
int c[20][1024*512];
int d8[1024*512];
int d16[1024*512];

QImage img(1024,512,32);
QRgb rgb_fk0=qRgb(255,0,0);

struct client_serv
{
	int test;
}  client;

struct serv_client
{
	int a1[1024*512];
}serv;

CannonField::CannonField( QWidget *parent, const char *name ): QWidget( parent, name )
{
	m_psocket=new QSocket(this);
	m_psocket->connectToHost("Localhost", 2323);
	connect(m_psocket, SIGNAL(error(int)), SLOT(slotError()));
	connect(m_psocket, SIGNAL(connected()), SLOT(slotConnected()));
	connect(m_psocket, SIGNAL(readyRead()), SLOT(slotreadyRead()));
}

void CannonField::combtest_change(int cbb)
{
	iread=0;
	switch(cbb)
	{
		case 0:
			ntest=1;
			break;
		case 1:
			ntest=2;
			break;
		case 2:
			ntest=3;
			break;
		default:
			break;
	}
	draw();
}

void CannonField::paintEvent( QPaintEvent * )
{	
	draw();
}

void CannonField::combpal_change(int cbb)
{
	switch(cbb)
	{
		case 0:
			pall=1;
			break;
		case 1:
			pall=2;
			break;
		case 2:
			pall=3;
			break;
		default:
			break;
	}
	draw();
}

void CannonField::setlim( int degrees1 )
{    
	limit=degrees1;
	draw();
}

void CannonField::combstor_change(int cbb)
{
	switch(cbb)
	{
		case 0:
			storage=1;
			break;
		case 1:
			storage=2;
			break;
		case 2:
			storage=4;
			break;
		case 3:
			storage=8;
			break;
		case 4:
			storage=16;
			break;
		default:
			break;
	}
	draw();
}

void CannonField::start_switchbut()
{
	if(START_switchbut)
		START_switchbut=0;
	else
	{
		START_switchbut=1;
		senders();
	}
	emit switchbutt(START_switchbut);
}

void CannonField::senders()
{
	client.test=ntest;
	m_psocket->writeBlock( (const char*) &client, sizeof( struct client_serv) );
}

void CannonField::draw(void)
{
	QPainter  p1(this);
	img.fill (0);
	for(j=0;j<512;j++)
		for(i=0;i<1024;i++)
		{
			if(serv.a1[i+j*1024]>=limit)
				switch(pall)
				{
					case 1:
						switch(storage)
						{
							case 1:
								img.setPixel(i,j,qRgb(0,serv.a1[i+j*1024],0));
								break;
							case 2: 
								img.setPixel(i,j,qRgb(0,d2[i+j*1024],0));
								break;
							case 4:
								img.setPixel(i,j,qRgb(0,d4[i+j*1024],0));
								break;
							case 8:
								img.setPixel(i,j,qRgb(0,d8[i+j*1024],0));
								break;
							case 16:
								img.setPixel(i,j,qRgb(0,d16[i+j*1024],0));
								break;
						}
							break;
					case 2:
						switch(storage)
						{
							case 1:
								img.setPixel(i,j,qRgb(0,0,serv.a1[i+j*1024]));
								break;
							case 2: 
								img.setPixel(i,j,qRgb(0,0,d2[i+j*1024]));
								break;
							case 4:
								img.setPixel(i,j,qRgb(0,0,d4[i+j*1024]));
								break;
							case 8:
								img.setPixel(i,j,qRgb(0,0,d8[i+j*1024]));
								break;
							case 16:
								img.setPixel(i,j,qRgb(0,0,d16[i+j*1024]));
								break;
						}
						break;
					case 3:
						switch(storage)
						{
							case 1:
								img.setPixel(i,j,qRgb(serv.a1[i+j*1024],serv.a1[i+j*1024],serv.a1[i+j*1024]));
								break;
							case 2: 
								img.setPixel(i,j,qRgb(d2[i+j*1024],d2[i+j*1024],d2[i+j*1024]));
								break;
							case 4:
								img.setPixel(i,j,qRgb(d4[i+j*1024],d4[i+j*1024],d4[i+j*1024]));
								break;
							case 8:
								img.setPixel(i,j,qRgb(d8[i+j*1024],d8[i+j*1024],d8[i+j*1024]));
								break;
							case 16:
								img.setPixel(i,j,qRgb(d16[i+j*1024],d16[i+j*1024],d16[i+j*1024]));
								break;
						}
						break;
				}
		}
	QPixmap pix(img);
	p1.drawPixmap(0,0,pix);
}

void CannonField::slotConnected()
{	    
	printf("Connected to server ip\n");
	emit con_ley();	
}

void CannonField::slotError()
{	    
	printf("Can not find server \n");
	emit nocon_ley();	
}

void CannonField::slotreadyRead()
{
	rr=m_psocket->readBlock( (char *) &serv+iread, sizeof(struct serv_client)-iread );
	iread+=rr;
	if(iread==sizeof(struct serv_client))
	{
		for(i=0;i<1024*512;i++)
		{
			c[15][i]=c[14][i];
			c[14][i]=c[13][i];
			c[13][i]=c[12][i];
			c[12][i]=c[11][i];
			c[11][i]=c[10][i];
			c[10][i]=c[9][i];
			c[9][i]=c[8][i];
			c[8][i]=c[7][i];
			c[7][i]=c[6][i];
			c[6][i]=c[5][i];
			c[5][i]=c[4][i];
			c[4][i]=c[3][i];
			c[3][i]=c[2][i];
			c[2][i]=c[1][i];
			c[1][i]=c[0][i];
			c[0][i]=serv.a1[i];
			d2[i]=c[0][i]+c[1][i];
			d2[i]=d2[i]/2;
			d4[i]=c[0][i]+c[1][i]+c[2][i]+c[3][i];
			d4[i]=d4[i]/4;
			d8[i]=c[0][i]+c[1][i]+c[2][i]+c[3][i]+c[4][i]+c[5][i]+c[6][i]+c[7][i];
			d8[i]=d8[i]/8;
			d16[i]=c[0][i]+c[1][i]+c[2][i]+c[3][i]+c[4][i]+c[5][i]+c[6][i]+c[7][i]+c[8][i]+c[9][i]+c[10][i]+c[11][i]+c[12][i]+c[13][i]+c[14][i]+c[15][i];
			d16[i]=d16[i]/16;
		}
		draw();
		iread=0;	
		if(START_switchbut==1)
			senders();
	}	
}

