// Copyright � 2010-2014 The CefSharp Project. All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.

#pragma once

#include "Stdafx.h"
#include "include/cef_v8.h"

#include "JavascriptMethodWrapper.h"
#include "JavascriptPropertyWrapper.h"

using namespace System::Runtime::Serialization;
using namespace System::Linq;
using namespace System::Collections::Generic;

using namespace CefSharp::Internals;

namespace CefSharp
{
    public ref class JavascriptObjectWrapper
    {
    private:
        JavascriptObject^ _object;
        List<JavascriptMethodWrapper^>^ _wrappedMethods;
        List<JavascriptPropertyWrapper^>^ _wrappedProperties;

    internal:
        MCefRefPtr<CefV8Value> V8Value;

    public:
        JavascriptObjectWrapper(JavascriptObject^ object)
        {
            _object = object;

            //_wrappedMethods = gcnew List<JavascriptMethodWrapper^>();
            _wrappedProperties = gcnew List<JavascriptPropertyWrapper^>();
        }

        void Bind()
        {
            //for each (JavascriptMethod^ method in Enumerable::OfType<JavascriptMethod^>(_object->Methods))
            //{
            //    //auto wrappedMethod = gcnew JavascriptMethodWrapper(method, _object->Id);
            //    //wrappedMethod->V8Value = V8Value;
            //    //wrappedMethod->Bind();

            //    //_wrappedMethods->Add(wrappedMethod);
            //}

            for each (JavascriptProperty^ prop in Enumerable::OfType<JavascriptProperty^>(_object->Properties))
            {
                auto wrappedproperty = gcnew JavascriptPropertyWrapper(prop, _object->Id);
                //wrappedproperty->V8Value = V8Value;
                wrappedproperty->Bind();

                _wrappedProperties->Add(wrappedproperty);
            }
        }
    };
}