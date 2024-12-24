#include "mytype.h"
     MyType::MyType(QObject *parent) 
        : QObject{parent}
    {}

    QString MyType::name() const 
    {
        return "FROM BACKEND";
    };

    void MyType::setName(const QString &name) 
    {
        m_name = name;
        emit nameChanged();
    }

