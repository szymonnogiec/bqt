#pragma once

//Qt includes
#include <QObject>
#include <QDebug>

//Windows includes
#include <Windows.h>

class KeysReceiver : public QObject
{
	Q_OBJECT
public:
	KeysReceiver(void);
	~KeysReceiver(void);

public slots:
	void onKeyPressed(DWORD key);
	void onKeyReleased(DWORD key);
};

