#ifndef UNWINDER_H
#define UNWINDER_H

#include <QObject>
#include <QStringList>

#include <libunwind-x86_64.h>

class Unwinder : public QObject
{
    Q_OBJECT
public:
    explicit Unwinder(QObject *parent = 0);

signals:

public slots:

private:
    unw_accessors_t acc;

};

#endif // UNWINDER_H
