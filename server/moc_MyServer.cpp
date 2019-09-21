/****************************************************************************
** MyServer meta object code from reading C++ file 'MyServer.h'
**
** Created: Tue Jun 4 12:52:05 2019
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "MyServer.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *MyServer::className() const
{
    return "MyServer";
}

QMetaObject *MyServer::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MyServer( "MyServer", &MyServer::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString MyServer::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MyServer", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MyServer::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MyServer", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MyServer::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QServerSocket::staticMetaObject();
    static const QUMethod slot_0 = {"slotReadClient", 0, 0 };
    static const QUMethod slot_1 = {"slotConnectionClosed", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotReadClient()", &slot_0, QMetaData::Public },
	{ "slotConnectionClosed()", &slot_1, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"message", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "message(const QString&)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"MyServer", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MyServer.setMetaObject( metaObj );
    return metaObj;
}

void* MyServer::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MyServer" ) )
	return this;
    return QServerSocket::qt_cast( clname );
}

// SIGNAL message
void MyServer::message( const QString& t0 )
{
    activate_signal(
      metaObject()!=staticMetaObject()?
      metaObject()->findSignal ( staticMetaObject()->signal(0,FALSE)->name, TRUE ) :
      staticMetaObject()->globalSignalIndex(0)
, t0 );
}

bool MyServer::qt_invoke( int _id, QUObject* _o )
{
    switch ( staticMetaObject()->localSlotIndex(
              metaObject()==staticMetaObject() ? _id : staticMetaObject()->findSlot(
				 metaObject()->slot(_id,TRUE)?metaObject()->slot(_id,TRUE)->name:0, TRUE ) ) )
    {
    case 0: slotReadClient(); break;
    case 1: slotConnectionClosed(); break;
    default:
	return QServerSocket::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool MyServer::qt_emit( int _id, QUObject* _o )
{
    switch ( staticMetaObject()->localSignalIndex(
              metaObject()==staticMetaObject() ? _id : staticMetaObject()->findSignal(
               metaObject()->signal(_id,TRUE)?metaObject()->signal(_id,TRUE)->name:0, TRUE ) ) )
    {
    case 0: message((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QServerSocket::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool MyServer::qt_property( int id, int f, QVariant* v)
{
    char buf[20]; buf[0]='\0';
    return QServerSocket::qt_property( id, f, v);
}
#endif // QT_NO_PROPERTIES
