#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QString>
class Utils {
public:
    static void saveRating(const QString &filePath, int rating);
};

char charToHex(char H, char L);

QByteArray hexStr_To_Hexchar(QString data);

#endif // UTILS_H
