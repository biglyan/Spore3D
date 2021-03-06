// *********************************************************************
//     ____                       _____ ____
//    / ___| _ __   ___  _ __ ___|___ /|  _ \  ___ ___  _ __ ___
//    \___ \| '_ \ / _ \| '__/ _ \ |_ \| | | |/ __/ _ \| '_ ` _ \
//     ___) | |_) | (_) | | |  __/___) | |_| | (_| (_) | | | | | |
//    |____/| .__/ \___/|_|  \___|____/|____(_)___\___/|_| |_| |_|
//          |_|
//
//  Spore3D
//      -- High performance , Lightweight 3D Game Engine
//  --------------------------------------------------------------------
//
//  Copyright (C) 2016 Shannon Xu
//
//  This software is distributed under the terms of the MIT License.
//  A copy of the license may be obtained at: https://opensource.org/licenses/MIT
//
// .--. --. -.. -. .. -. ..-. --.-. --. -- .- .. .-.. .-.-.- -.-. --- --

#ifndef _cObject_h_
#define _cObject_h_

#include <set>
#include <map>
#include <string>

#include "uTypes.h"
#include "uHash.h"


namespace Spore3D {
    
    class ObjectManager;
    
    class CoreObject {
        friend ObjectManager;
    public:
        static CoreObject *Create(const std::string &name);
        static void Destory(CoreObject *cObject);
        
        virtual CObjectId getInstanceId() const;
        virtual std::string toString() const;
        
        virtual void init();
        virtual void deinit();
    
    protected:
        CoreObject(const std::string &name);
        virtual ~CoreObject();
    
    private:
        
        std::string m_Name;
        Hash *m_InstanceID = nullptr;
        
        static uint32 _InstanceNumber;
        
    };
    
    typedef CoreObject* (*CreationMethod)(const std::string &);
    typedef void (*DestructionMethod)(CoreObject *);
    
}

#endif /* _cObject_h_ */
