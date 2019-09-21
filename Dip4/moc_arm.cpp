/****************************************************************************
** MyWidget meta object code from reading C++ file 'arm.h'
**
** Created: Thu Jun 6 11:38:49 2019
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "arm.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *MyWidget::className() const
{
    return "MyWidget";
}

QMetaObject *MyWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MyWidget( "MyWidget", &MyWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString MyWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MyWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MyWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MyWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MyWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"switchbut", 1, param_slot_0 };
    static const QUMethod slot_1 = {"connect_serv", 0, 0 };
    static const QUMethod slot_2 = {"noconnect_serv", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "switchbut(int)", &slot_0, QMetaData::Public },
	{ "connect_serv()", &slot_1, QMetaData::Public },
	{ "noconnect_serv()", &slot_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"MyWidget", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MyWidget.setMetaObject( metaObj );
    return metaObj;
}

void* MyWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MyWidget" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool MyWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( staticMetaObject()->localSlotIndex(
              metaObject()==staticMetaObject() ? _id : staticMetaObject()->findSlot(
				 metaObject()->slot(_id,TRUE)?metaObject()->slot(_id,TRUE)->name:0, TRUE ) ) )
    {
    case 0: switchbut((int)static_QUType_int.get(_o+1)); break;
    case 1: connect_serv(); break;
    case 2: noconnect_serv(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool MyWidget::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool MyWidget::qt_property( int id, int f, QVariant* v)
{
    char buf[20]; buf[0]='\0';
    return QWidget::qt_property( id, f, v);
}
#endif // QT_NO_PROPERTIES
