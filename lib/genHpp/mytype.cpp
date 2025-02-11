#line 4 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/QtQmlExample.hpp"
#include "mytype.h"
   MyType::MyType(QObject * parent) 
#line 22 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/QtQmlExample.hpp"
        : QObject{parent}
    {}

    QString MyType::name() const 
#line 28 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/QtQmlExample.hpp"
    {
        return "FROM BACKEND";
    };

    void MyType::setName(const QString &name) 
#line 35 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/QtQmlExample.hpp"
    {
        m_name = name;
        emit nameChanged();
    }

