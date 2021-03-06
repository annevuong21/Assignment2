#include <iostream>
#include <Windows.h>
#include <xinput.h>
#include <math.h>
#include "XBoxController.h"
#include "XInputWrapper.h"


GamePad::XBoxController::XBoxController(XInputWrapper* xinput, DWORD id)
{
	this->xinput = xinput;
	userindex = id;
}

DWORD GamePad::XBoxController::GetControllerId()
{
	return userindex;
}

bool GamePad::XBoxController::IsConnected() 
{
	if (xinput->XInputGetState(userindex, &state) == ERROR_SUCCESS)
	{
		return 1;
	}
	else 
	{ 
		return 0;
	}
}

bool GamePad::XBoxController::PressedA()
{
	if (state.Gamepad.wButtons & (1 << 12))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool GamePad::XBoxController::PressedB()
{
	if (state.Gamepad.wButtons & (1 << 13))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool GamePad::XBoxController::PressedX()
{
	if (state.Gamepad.wButtons & (1 << 14))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool GamePad::XBoxController::PressedY()
{
	if (state.Gamepad.wButtons & (1 << 15))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool GamePad::XBoxController::PressedLeftShoulder()
{
	if (state.Gamepad.wButtons & (1 << 8))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool GamePad::XBoxController::PressedRightShoulder()
{
	if (state.Gamepad.wButtons & (1 << 9))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool GamePad::XBoxController::PressedLeftDpad()
{
	if (state.Gamepad.wButtons & (1 << 2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool GamePad::XBoxController::PressedRightDpad()
{
	if (state.Gamepad.wButtons & (1 << 3))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool GamePad::XBoxController::PressedUpDpad()
{
	if (state.Gamepad.wButtons & 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool GamePad::XBoxController::PressedDownDpad()
{
	if (state.Gamepad.wButtons & (1 << 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool GamePad::XBoxController::PressedStart()
{
	if (state.Gamepad.wButtons & (1 << 4))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool GamePad::XBoxController::PressedBack()
{
	if (state.Gamepad.wButtons & (1 << 5))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool GamePad::XBoxController::PressedLeftThumb()
{
	if (state.Gamepad.wButtons & (1 << 6))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool GamePad::XBoxController::PressedRightThumb()
{
	if (state.Gamepad.wButtons & (1 << 7))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

BYTE GamePad::XBoxController::LeftTriggerLocation()
{
	return state.Gamepad.bLeftTrigger;
}
BYTE GamePad::XBoxController::RightTriggerLocation()
{
	return state.Gamepad.bRightTrigger;
}

GamePad::Coordinate GamePad::XBoxController::LeftThumbLocation()
{
	// Use arctan to get angle between x and y
	double degree = atan2(state.Gamepad.sThumbLY, state.Gamepad.sThumbLX);
	
	// Distance between (0,0) and coordinate
	double distance = state.Gamepad.sThumbLY / sin(degree);
	
	double x, y;
	if (!this->If_in_Deadzone(state.Gamepad.sThumbLX, state.Gamepad.sThumbLY)) //If coordinate is out of deadzone
	{
		x = (distance - DeadZone) / (32767 - DeadZone) * 32767 * cos(degree); 
		y = (distance - DeadZone) / (32767 - DeadZone) * 32767 * sin(degree);
		
		if (x > 32767) // Determind if x is out of acceptable range
		{
			x = 32767;
		}
		else if (x < -32768)
		{
			x = -32768;
		}

		if (y > 32767) // Determind if y is out of acceptable range
		{
			y = 32767;
		}
		else if (y < -32768)
		{
			y = -32768;
		}

		return GamePad::Coordinate(x,y);
	}
	else
	{
		return  GamePad::Coordinate(0,0);
	}

}
GamePad::Coordinate GamePad::XBoxController::RightThumbLocation()
{
	// Use arctan to get angle between x and y
	double degree = atan2(state.Gamepad.sThumbRY, state.Gamepad.sThumbRX);

	// Distance between (0,0) and coordinate
	double distance = state.Gamepad.sThumbRY / sin(degree);

	double x, y;
	if (!this->If_in_Deadzone(state.Gamepad.sThumbRX, state.Gamepad.sThumbRY)) //If coordinate is out of deadzone
	{
		x = (distance - DeadZone) / (32767 - DeadZone) * 32767 * cos(degree);
		y = (distance - DeadZone) / (32767 - DeadZone) * 32767 * sin(degree);

		if (x > 32767) // Determind if x is out of acceptable range
		{
			x = 32767;
		}
		else if (x < -32768)
		{
			x = -32768;
		}

		if (y > 32767) // Determind if y is out of acceptable range
		{
			y = 32767;
		}
		else if (y < -32768)
		{
			y = -32768;
		}

		return GamePad::Coordinate(x, y);
	}
	else
	{
		return  GamePad::Coordinate(0, 0);
	}
}

void GamePad::XBoxController::Vibrate(WORD left, WORD right)
{
	vibrate.wLeftMotorSpeed = left;
	vibrate.wRightMotorSpeed = right;
	xinput->XInputSetState(userindex, &vibrate);
}

void GamePad::XBoxController::SetDeadzone( unsigned int radius )
{
	DeadZone = radius;
}

bool GamePad::XBoxController::If_in_Deadzone(SHORT x, SHORT y)
{
	if (x * x + y * y < DeadZone * DeadZone) // Circle equation of area of deadzone
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
