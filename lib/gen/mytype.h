#pragma once
#pragma once

#include <QObject>
#include <qqmlregistration.h>

class MyType : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    QML_ELEMENT

public:
    explicit MyType(QObject *parent = nullptr);
    QString name() const;
    void setName(const QString &name);
signals:
    void nameChanged();

private:
    QString m_name;
};
