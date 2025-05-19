#include "scontro.h"

SControl::SControl(QWidget *parent)
    : QObject{parent}
{

}

void SControl::COMMark(SSerial *serial)
{
    if(serial != nullptr && serial->IsOpen() && !m_mark_data.isEmpty())
    {
        serial->WriteByteArray(m_mark_data);
    }
}

void SControl::SetMarkData(QByteArray mark_data)
{
    m_mark_data = mark_data;
}

SControl::~SControl()
{

}

