//-define-file body mytype.cpp
//-define-file header mytype.h
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
    //- {fn}
    explicit MyType(QObject *parent = nullptr)
        //-only-file body
        : QObject{parent}
    {}

    //- {fn}
    QString name() const
    //-only-file body
    {
        return "FROM BACKEND";
    };

    //- {fn}
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
