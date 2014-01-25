#include "Xbox360.h"

XINPUT_STATE xb360::GetState()
{
	XINPUT_STATE controllerState;
	ZeroMemory(&controllerState, sizeof(XINPUT_STATE));

	XInputGetState(0, &controllerState);
	return controllerState;
}

bool xb360::IsConnected()
{
	XINPUT_STATE controllerState;
	ZeroMemory(&controllerState, sizeof(XINPUT_STATE));

	DWORD result = XInputGetState(0, &controllerState);

	if(result == ERROR_SUCCESS)
		return true;
	else
		return false;
}

bool xb360::APressed()
{
	return (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A);
}

bool xb360::BPressed()
{
	return (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B);
}

bool xb360::XPressed()
{
	return (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X);
}

bool xb360::YPressed()
{
	return (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y);
}

bool xb360::DPadUp()
{
	return (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP);
}

bool xb360::DPadDown()
{
	return (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN);
}

bool xb360::DPadLeft()
{
	return (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT);
}

bool xb360::DPadRight()
{
	return (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT);
}

bool xb360::LeftThumbUp()
{
	return (GetState().Gamepad.sThumbLY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
}

bool xb360::LeftThumbDown()
{
	return (GetState().Gamepad.sThumbLY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
}

bool xb360::LeftThumbLeft()
{
	return (GetState().Gamepad.sThumbLX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
}

bool xb360::LeftThumbRight()
{
	return (GetState().Gamepad.sThumbLX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
}

bool xb360::LeftThumbNeut()
{
	return (!LeftThumbDown() && !LeftThumbUp() && !LeftThumbLeft() && !LeftThumbRight());
}


