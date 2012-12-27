/*
 * USBMouseDevice.h
 *
 * Copyright 2012 Hubert Denkmair (hubert.denkmair@germaneers.com)
 *
 * This file is part of libopenstella.
 *
 * libopenstella is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * libopenstella is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libopenstella.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef USBMOUSEDEVICE_H_
#define USBMOUSEDEVICE_H_

#include "USBHIDDevice.h"
#include <StellarisWare/inc/hw_types.h>
#include <StellarisWare/usblib/usblib.h>
#include <StellarisWare/usblib/usbhid.h>
#include <StellarisWare/usblib/device/usbdhid.h>
#include <StellarisWare/usblib/device/usbdhidmouse.h>

class USBMouseDevice : public USBHIDDevice {
public:
	typedef enum {
		button_1_pressed = 0x01,
		button_2_pressed = 0x02,
		button_3_pressed = 0x04
	} button_state_t;

	USBMouseDevice(USBController *controller=0);
	bool sendMouseEvent(int8_t deltaX, int8_t deltaY, uint8_t buttonState);
	virtual void enable();
	virtual void *compositeInit();
};

#endif /* USBMOUSEDEVICE_H_ */
