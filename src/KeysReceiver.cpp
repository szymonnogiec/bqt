#include "KeysReceiver.h"


KeysReceiver::KeysReceiver(void)
{
}


KeysReceiver::~KeysReceiver(void)
{
}

void KeysReceiver::onKeyPressed(DWORD key)
{
	qDebug() << "Key pressed: " <<char(key);
}

void KeysReceiver::onKeyReleased(DWORD key)
{
	qDebug() << "Key released: " << key;
}
