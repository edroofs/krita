/***************************************************************************
 * rubyinterpreter.cpp
 * This file is part of the KDE project
 * copyright (C)2005 by Cyrille Berger (cberger@cberger.net)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 * You should have received a copy of the GNU Library General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 ***************************************************************************/
#ifndef KROSS_RUBYRUBYEXTENSION_H
#define KROSS_RUBYRUBYEXTENSION_H

#include <ruby.h>

#include "../core/krossconfig.h"
//#include "../core/object.h"
#include <QList>
#include <QObject>

namespace Kross {

class RubyExtensionPrivate;

/**
 * This class wraps a QObject into the world of ruby.
 * @author Cyrille Berger
 */
class RubyExtension{
        friend class RubyInterpreter;
        friend class RubyModule;
        friend class RubyScript;
    public:
        /**
         * Constructor.
         *
         * @param object The QObject instance this extension provides access to.
         */
        RubyExtension(QObject* object);
        /**
         * Destructor.
         */
        ~RubyExtension();

#if 0

    private:
        /**
         * This function will catch functions that are undefined.
         */
        static VALUE method_missing(int argc, VALUE *argv, VALUE self);
        /**
         * This function will call a function in a Kross object
         * @param obj kross object which contains the function
         * @param argc the number of argument
         * @param argv the lists of arguments (the first argument is the Ruby ID of the function)
         */
        static VALUE call_method( QObject* obj, int argc, VALUE *argv);
        /**
         * This function is called by ruby to delete a RubyExtension object
         */
        static void delete_object(void* object);
        /**
         * This function is called by ruby to delete a RubyExtension object
         */
        static void delete_exception(void* object);
    private: // Tests
        /**
         * Test if the ruby object is an exception.
         */
        static bool isOfExceptionType(VALUE obj);
        /**
         * Test if the ruby object is an object
         */
        static bool isOfObjectType(VALUE obj);
    private: //Converting functions

        /**
         * Convert a ruby object to the exception type.
         * @return 0 if the object wasn't an exception.
         */
        static Kross::Exception* convertToException(VALUE obj);
        /**
         * Wrap an exception in a ruby object.
         */
        static VALUE convertFromException(Kross::Exception::Ptr exc);

        /**
         * This function iterats through a ruby hash
         */
        static int convertHash_i(VALUE key, VALUE value, VALUE vmap);
        /**
         * Converts a \a VALUE into a \a Kross::Object.
         * \param object The ruby VALUE to convert.
         * \return The to a Kross::Object converted Py::Object.
         */
        static Kross::Object* toObject(VALUE value);
        /**
         * Converts a QString to a VALUE. If
         * the QString isNull() then a "" will
         * be returned.
         * \param s The QString to convert.
         * \return The converted QString.
         */
        static VALUE toVALUE(const QString& s);

        /**
         * Converts a QStringList to a VALUE.
         * \param list The QStringList to convert.
         * \return The converted QStringList.
         */
        static VALUE toVALUE(QStringList list);

        /**
         * Converts a QMap to a VALUE.
         * \param map The QMap to convert.
         * \return The converted QMap.
         */
        static VALUE toVALUE(QMap<QString, QVariant> map);

        /**
         * Converts a QList to a VALUE.
         * \param list The QValueList to convert.
         * \return The converted QValueList.
         */
        static VALUE toVALUE(QList<QVariant> list);

        /**
         * Converts a QVariant to a VALUE.
         * \param variant The QVariant to convert.
         * \return The converted QVariant.
         */
        static VALUE toVALUE(const QVariant& variant);

        /**
         * Converts a \a Kross::Object to a VALUE.
         * \param object The Kross::Object to convert.
         * \return The converted Kross::Object.
         */
        static VALUE toVALUE(Kross::Object::Ptr object);

        /**
         * Converts a \a Kross::List into a VALUE.
         * \param list The Kross::List to convert.
         * \return The converted Kross::List.
         */
        static VALUE toVALUE(Kross::List::Ptr list);

#endif

    private:
        /// Private d-pointer.
        RubyExtensionPrivate* d;
 };

}

#endif
