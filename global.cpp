#include "global.h"

#include <QDateTime>

QString global::getCurrentTimeString()
{
    return "\t[" + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") + "]";
}
