#ifndef VISUAL_H
#define VISUAL_H

#include <qsocket.h>
#include <qscrollview.h>

class CannonField : public QWidget
{
    Q_OBJECT
	public:
   		CannonField( QWidget *parent=0, const char *name=0 );
		QSocket* m_psocket;
	public slots:
		void combtest_change(int cbb);	
		void combpal_change(int cbb);	
		void combstor_change(int cbb);
		void setlim(int);
		void start_switchbut();
		void slotConnected();
		void slotError();
		void slotreadyRead();	
		void senders();
	signals:
		void switchbutt(int);
		void con_ley();
		void nocon_ley();
	protected:
   		void paintEvent( QPaintEvent * );
		void draw(void);
	private:

};

#endif // VISUAL_H