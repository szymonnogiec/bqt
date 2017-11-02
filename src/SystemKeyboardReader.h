#pragma once

//Qt includes
#include <QObject>

//Windows includes
#include <Windows.h>

class SystemKeyboardReader : public QObject
{
	Q_OBJECT
public:
	static SystemKeyboardReader& getInstance()
	{
		static SystemKeyboardReader instance;
		return instance;
	}
	bool setConnected(bool state);

signals:
	void keyPressed(DWORD key);
	void keyReleased(DWORD key);
private:
	SystemKeyboardReader(void);
	~SystemKeyboardReader(void);

	SystemKeyboardReader(SystemKeyboardReader const&);
	SystemKeyboardReader(SystemKeyboardReader&&);
	SystemKeyboardReader& operator=(SystemKeyboardReader const &);
	SystemKeyboardReader& operator=(SystemKeyboardReader&&);

	HHOOK m_keyboardHook;
	static LRESULT CALLBACK keyboardProcedure(int nCode, WPARAM wParam, LPARAM lParam);
};

