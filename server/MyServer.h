#include <qapplication.h>
#include <qsocket.h>
#include <qserversocket.h>
#include "arm.h"

int rr_s;
int i;
int j;
int k=0;

struct client_serv
{
	int test;
}  client1;

struct serv_client
{
	int dd[1024*512];
}serv1;

class MyServer : public QServerSocket 
{
	Q_OBJECT
	public:
		MyServer( int nPort, int nBacklog=0, QObject* pobj=0 ): QServerSocket( nPort, nBacklog, pobj )
		{
			if(!ok())
			{
				exit(1);
			}
		}
	virtual void newConnection(int nSocketId)
	{
		QSocket* socket = new QSocket(this);
		socket->setSocket(nSocketId);
		connect(socket,SIGNAL(delayedCloseFinished()),SLOT(slotConnectionClosed()));
		connect(socket,SIGNAL(readyRead()),SLOT(slotReadClient()));
	}
	signals:
		void message(const QString&);
	public slots:
		void slotReadClient()
		{ 
			QSocket* socket=(QSocket*)sender();
			rr_s=socket->readBlock( (char*) & client1, sizeof( struct client_serv) );
			switch(client1.test){
				case 2:
					for(j=0;j<512;j++)    
					{
						k=j%256;
						for( i=0;i<1024;i++)
						{
							if( ((i+j*1024)%4)==0 && (i+j*1024)>0 && i!=0 )
								k++;
							if(k>255)k=255;
								serv1.dd[i+j*1024]=k;
						}
					}
					rr_s=socket->writeBlock( (const char*) &serv1, sizeof( struct serv_client) );
					k=0;
					break;
				case 3:
					for(j=0;j<512;j++)
					{
						for( i=0;i<1024;i++)
						{
							serv1.dd[i+j*1024]=0;
							if(((i>=99) && (i<=109) && (j>=370) && (j<=380) && (k==0))||
							((i>=129) && (i<=139) && (j>=347) && (j<=357) && (k==1))||
							((i>=163) && (i<=173) && (j>=315) && (j<=325) && (k==2))||
							((i>=194) && (i<=204) && (j>=289) && (j<=299) && (k==3))||
							((i>=227) && (i<=237) && (j>=261) && (j<=271) && (k==4))||
							((i>=259) && (i<=269) && (j>=234) && (j<=244) && (k==5))||
							((i>=285) && (i<=295) && (j>=205) && (j<=215) && (k==6))||
							((i>=315) && (i<=325) && (j>=182) && (j<=192) && (k==7))||
							((i>=350) && (i<=360) && (j>=159) && (j<=169) && (k==8))||
							((i>=387) && (i<=397) && (j>=139) && (j<=149) && (k==9))||
							((i>=434) && (i<=444) && (j>=139) && (j<=149) && (k==10))||
							((i>=462) && (i<=472) && (j>=162) && (j<=172) && (k==11))||
							((i>=490) && (i<=500) && (j>=201) && (j<=211) && (k==12))||
							((i>=515) && (i<=525) && (j>=231) && (j<=241) && (k==13))||
							((i>=541) && (i<=551) && (j>=258) && (j<=268) && (k==14))||
							((i>=565) && (i<=575) && (j>=283) && (j<=293) && (k==15))||
							((i>=594) && (i<=604) && (j>=306) && (j<=316) && (k==16))||
							((i>=630) && (i<=640) && (j>=334) && (j<=344) && (k==17))||
							((i>=667) && (i<=677) && (j>=357) && (j<=367) && (k==18))||
							((i>=701) && (i<=711) && (j>=387) && (j<=397) && (k==19)))
							{
								serv1.dd[i+j*1024]=255;
							}
						}
					}
					rr_s=socket->writeBlock( (const char*) &serv1, sizeof( struct serv_client) );
					k++;
					if(k==20)
						k=0;
					break;
				case 1:
					for(j=0;j<512;j++) 
					{
						for( i=0;i<1024;i++)
						{
							serv1.dd[i+j*1024]=0;
							if(i>=200 && i<=800 && j>=100 && j<=400)
								serv1.dd[i+j*1024]=150;
							if((i>=230 && i<= 240 && j>=130 && j<=140)||(i>= 460 && i<=470 && j>=300 && j<=310))
								serv1.dd[i+j*1024]=255;		
						}
	
					}
					rr_s=socket->writeBlock( (const char*) &serv1, sizeof( struct serv_client) );
					k=0;
					break;
			}
		}
		void slotConnectionClosed()
		{
			QSocket* socket=(QSocket*)sender();
			delete socket;
		}
};

int main( int argc, char** argv )
{
	QApplication app( argc, argv );

	QTranslator *ptranslator1= new QTranslator(0);	
	ptranslator1->load("MyServer_ru.qm",".");
	app.installTranslator(ptranslator1);

	QTranslator *ptranslator2= new QTranslator(0);	
	ptranslator2->load("arm_ru.qm",".");
	app.installTranslator(ptranslator2);

	MyServer server(2323);
	MyWidget w;
 	w.setGeometry( 0,0,100,30);
	w.setCaption (QObject::tr("server"));
	w.show();	
	return app.exec();
}