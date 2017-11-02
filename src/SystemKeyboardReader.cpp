#include "SystemKeyboardReader.h"

bool SystemKeyboardReader::setConnected(bool state)
{
	if (state && !m_keyboardHook)
	{
		m_keyboardHook = SetWindowsHookEx
			(WH_KEYBOARD_LL, keyboardProcedure, GetModuleHandle(nullptr), 0);
		return m_keyboardHook != nullptr;
	}

	UnhookWindowsHookEx(m_keyboardHook);
	m_keyboardHook = nullptr;
	return false;
}

SystemKeyboardReader::SystemKeyboardReader(void)
{
	m_keyboardHook = nullptr;
}

SystemKeyboardReader::~SystemKeyboardReader(void)
{
}

LRESULT CALLBACK SystemKeyboardReader::keyboardProcedure(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION)
	{
		if (wParam == WM_KEYDOWN)
		{
			KBDLLHOOKSTRUCT* lKeyboard = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
			emit getInstance().keyPressed(lKeyboard->vkCode);
		}
		else if (wParam == WM_KEYUP)
		{
			KBDLLHOOKSTRUCT* lKeyboard = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
			emit getInstance().keyReleased(lKeyboard->vkCode);
		}
		getInstance().setConnected(false);
		getInstance().setConnected(true);
	}
	return false;
}
