//-define-file body gen/mytype.cpp
//-define-file header gen/mytype.h
//-only-file body //-
//- #include "mytype.h"
//-only-file header
#pragma once

#include <QObject>
#include <qqmlregistration.h>

//-var {PRE} MyType::
class MyType : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    QML_ELEMENT

public:
    //-only-file body //-
    //- {PRE}
    //- MyType(QObject *parent)
    //-only-file header ;
    explicit MyType(QObject *parent = nullptr)
        //-only-file body
        : QObject{parent}
    {}

    //- {function} 0 1
    QString name() const
    //-only-file body
    {
        return "FROM BACKEND";
    };

    //- {function} 0 1
    void setName(const QString &name)
    //-only-file body
    {
        m_name = name;
        emit nameChanged();
    }

    //-only-file header
signals:
    void nameChanged();

private:
    QString m_name;
};
