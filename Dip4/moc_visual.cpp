/****************************************************************************
** CannonField meta object code from reading C++ file 'visual.h'
**
** Created: Thu Jun 6 11:38:51 2019
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "visual.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CannonField::className() const
{
    return "CannonField";
}

QMetaObject *CannonField::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CannonField( "CannonField", &CannonField::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CannonField::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CannonField", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CannonField::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CannonField", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CannonField::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "cbb", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"combtest_change", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "cbb", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"combpal_change", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "cbb", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"combstor_change", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"setlim", 1, param_slot_3 };
    static const QUMethod slot_4 = {"start_switchbut", 0, 0 };
    static const QUMethod slot_5 = {"slotConnected", 0, 0 };
    static const QUMethod slot_6 = {"slotError", 0, 0 };
    static const QUMethod slot_7 = {"slotreadyRead", 0, 0 };
    static const QUMethod slot_8 = {"senders", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "combtest_change(int)", &slot_0, QMetaData::Public },
	{ "combpal_change(int)", &slot_1, QMetaData::Public },
	{ "combstor_change(int)", &slot_2, QMetaData::Public },
	{ "setlim(int)", &slot_3, QMetaData::Public },
	{ "start_switchbut()", &slot_4, QMetaData::Public },
	{ "slotConnected()", &slot_5, QMetaData::Public },
	{ "slotError()", &slot_6, QMetaData::Public },
	{ "slotreadyRead()", &slot_7, QMetaData::Public },
	{ "senders()", &slot_8, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"switchbutt", 1, param_signal_0 };
    static const QUMethod signal_1 = {"con_ley", 0, 0 };
    static const QUMethod signal_2 = {"nocon_ley", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "switchbutt(int)", &signal_0, QMetaData::Public },
	{ "con_ley()", &signal_1, QMetaData::Public },
	{ "nocon_ley()", &signal_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CannonField", parentObject,
	slot_tbl, 9,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CannonField.setMetaObject( metaObj );
    return metaObj;
}

void* CannonField::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CannonField" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL switchbutt
void CannonField::switchbutt( int t0 )
{
    activate_signal(
      metaObject()!=staticMetaObject()?
      metaObject()->findSignal ( staticMetaObject()->signal(0,FALSE)->name, TRUE ) :
      staticMetaObject()->globalSignalIndex(0)
, t0 );
}

// SIGNAL con_ley
void CannonField::con_ley()
{
    activate_signal(
      metaObject()!=staticMetaObject()?
      metaObject()->findSignal ( staticMetaObject()->signal(1,FALSE)->name, TRUE ) :
      staticMetaObject()->globalSignalIndex(1)
 );
}

// SIGNAL nocon_ley
void CannonField::nocon_ley()
{
    activate_signal(
      metaObject()!=staticMetaObject()?
      metaObject()->findSignal ( staticMetaObject()->signal(2,FALSE)->name, TRUE ) :
      staticMetaObject()->globalSignalIndex(2)
 );
}

bool CannonField::qt_invoke( int _id, QUObject* _o )
{
    switch ( staticMetaObject()->localSlotIndex(
              metaObject()==staticMetaObject() ? _id : staticMetaObject()->findSlot(
				 metaObject()->slot(_id,TRUE)?metaObject()->slot(_id,TRUE)->name:0, TRUE ) ) )
    {
    case 0: combtest_change((int)static_QUType_int.get(_o+1)); break;
    case 1: combpal_change((int)static_QUType_int.get(_o+1)); break;
    case 2: combstor_change((int)static_QUType_int.get(_o+1)); break;
    case 3: setlim((int)static_QUType_int.get(_o+1)); break;
    case 4: start_switchbut(); break;
    case 5: slotConnected(); break;
    case 6: slotError(); break;
    case 7: slotreadyRead(); break;
    case 8: senders(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CannonField::qt_emit( int _id, QUObject* _o )
{
    switch ( staticMetaObject()->localSignalIndex(
              metaObject()==staticMetaObject() ? _id : staticMetaObject()->findSignal(
               metaObject()->signal(_id,TRUE)?metaObject()->signal(_id,TRUE)->name:0, TRUE ) ) )
    {
    case 0: switchbutt((int)static_QUType_int.get(_o+1)); break;
    case 1: con_ley(); break;
    case 2: nocon_ley(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CannonField::qt_property( int id, int f, QVariant* v)
{
    char buf[20]; buf[0]='\0';
    return QWidget::qt_property( id, f, v);
}
#endif // QT_NO_PROPERTIES
