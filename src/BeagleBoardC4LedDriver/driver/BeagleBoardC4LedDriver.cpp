/* BeagleBoardC4LedDriver.cpp
 * 
 * Copyright (c) 2011 The BeagleBoardC4LedDriver project.
 *
 * This work is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2.1 of the License, or (at your option)
 * any later version.
 * 
 * This work is distributed in the hope that it will be useful, but without
 * any warranty; without even the implied warranty of merchantability or
 * fitness for a particular purpose. See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 *
 *  Created on: Oct 15, 2011
 *      Author: Matthias Schmid <m.schmid@students.fhv.at>
 */

#include "BeagleBoardC4LedDriver.h"
#include <stdio.h>
BeagleBoardC4LedDriver::BeagleBoardC4LedDriver() {
}
BeagleBoardC4LedDriver::~BeagleBoardC4LedDriver() {
}

void BeagleBoardC4LedDriver::init(LedDevice dev) {
  enable_output(dev);
}

void BeagleBoardC4LedDriver::turn_on(LedDevice dev) {
  // sets the dev bit of GPIO5_DATAOUT to 1
  *CAST_VOLATILE_U_LONG_PTR(GPIO5_DATAOUT) |= SET_BIT(dev);
}

void BeagleBoardC4LedDriver::turn_off(LedDevice dev) {
  // sets the dev bit of GPIO5_DATAOUT to 0
  *CAST_VOLATILE_U_LONG_PTR(GPIO5_DATAOUT) &= ~SET_BIT(dev);
}

void BeagleBoardC4LedDriver::toggle(LedDevice dev) {
  // inverts the dev bit of GPIO5_DATAOUT
  *CAST_VOLATILE_U_LONG_PTR(GPIO5_DATAOUT) ^= SET_BIT(dev);
}

void BeagleBoardC4LedDriver::toggle(LedDevice dev1, LedDevice dev2) {
  // inverts the dev1 and dev2 bit of GPIO5_DATAOUT
  U_LONG state = *CAST_VOLATILE_U_LONG_PTR(GPIO5_DATAOUT);
  *CAST_VOLATILE_U_LONG_PTR(GPIO5_DATAOUT) = ((state ^ SET_BIT(dev1)
      ^ SET_BIT(dev2)));
}

bool BeagleBoardC4LedDriver::is_on(LedDevice dev) {
  // FIXME: Check if here is somewhere a bug
  U_LONG state = *CAST_VOLATILE_U_LONG_PTR(GPIO5_DATAOUT);
  return (static_cast<U_LONG>(state | SET_BIT(dev)) == state) ? true : false;
}

void BeagleBoardC4LedDriver::enable_output(LedDevice dev) {
  // enable output for LED 0,1
  *CAST_VOLATILE_U_LONG_PTR(GPIO5_OE) |= SET_BIT(dev);
}
