/****************************************************************************
** MyWidget meta object code from reading C++ file 'arm.h'
**
** Created: Sat May 18 15:45:02 2019
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
    metaObj = QMetaObject::new_metaobject(
	"MyWidget", parentObject,
	0, 0,
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
    return QWidget::qt_invoke(_id,_o);
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
