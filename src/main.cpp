#include <QtCore/QCoreApplication>

#include "SystemKeyboardReader.h"
#include "KeysReceiver.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	SystemKeyboardReader::getInstance().setConnected(true);
	KeysReceiver keysReceiver;
	QObject::connect(&SystemKeyboardReader::getInstance(), SIGNAL(keyPressed(DWORD)),
		&keysReceiver, SLOT(onKeyPressed(DWORD)));

	return a.exec();
}
