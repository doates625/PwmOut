/**
 * @brief PwmOut.h
 * @brief Class for Arduino and Mbed PWM outputs
 * @author Dan Oates (WPI Class of 2020)
 * 
 * This class implements the Mbed PwmOut class for Arduino to allow for
 * cross-platform libraries. This implementation does NOT include the period and
 * pulsewidth methods offered by Mbed as this level of control is not allowed by
 * the standard Arduino library.
 * 
 * Dependencies:
 * - Platform: https://github.com/doates625/Platform.git
 * - CppUtil: https://github.com/doates625/CppUtil.git
 * 
 * References:
 * - Mbed PwmOut: https://os.mbed.com/docs/mbed-os/v5.14/apis/pwmout.html
 */
#pragma once
#include <Platform.h>

#if defined(PLATFORM_ARDUINO)

/**
 * Class Declaration
 */
class PwmOut
{
public:
	PwmOut(PLATFORM_PIN_TYPE pin);
	void write(float duty_cycle);
	float read();
	PwmOut& operator=(float duty_cycle);
	operator float();
protected:
	PLATFORM_PIN_TYPE pin;
	float duty_cycle;
};

#endif