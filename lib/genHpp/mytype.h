#line 6 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/QtQmlExample.hpp"
#pragma once

#include <QObject>
#include <qqmlregistration.h>

#line 12 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/QtQmlExample.hpp"
class MyType : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    QML_ELEMENT

public:
#line 20 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/QtQmlExample.hpp"
    explicit MyType(QObject *parent = nullptr);
#line 26 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/QtQmlExample.hpp"
    QString name() const;
#line 33 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/QtQmlExample.hpp"
    void setName(const QString &name);
#line 41 "/Volumes/RAM_Disk_4G/TestHppGenerator/lib/QtQmlExample.hpp"
signals:
    void nameChanged();

private:
    QString m_name;
};
