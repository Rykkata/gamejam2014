#pragma once

#include <windows.h>
#include <Xinput.h>

#pragma comment(lib, "XInput9_1_0.lib")

namespace xb360
{
	XINPUT_STATE GetState();
	bool IsConnected();
	// Button
	bool APressed();
	bool BPressed();
	bool XPressed();
	bool YPressed();
	// D-Pad
	bool DPadUp();
	bool DPadDown();
	bool DPadLeft();
	bool DPadRight();
	// Thumbstick, maybe switch to short and handle velocity that way?
	bool LeftThumbUp();
	bool LeftThumbDown();
	bool LeftThumbLeft();
	bool LeftThumbRight();
	bool LeftThumbNeut();
}