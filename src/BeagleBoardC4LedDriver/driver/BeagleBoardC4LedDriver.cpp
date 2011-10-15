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

BeagleBoardC4LedDriver::BeagleBoardC4LedDriver() {}
BeagleBoardC4LedDriver::~BeagleBoardC4LedDriver() {}

void BeagleBoardC4LedDriver::init(LedDevice dev)
{
  enable_output(dev);
}

void BeagleBoardC4LedDriver::turn_on(LedDevice dev)
{
  *CAST_VOLATILE_U_LONG_PTR(GPIO5_DATAOUT) |= SET_BIT(dev);
}

void BeagleBoardC4LedDriver::turn_off(LedDevice dev)
{
  *CAST_VOLATILE_U_LONG_PTR(GPIO5_DATAOUT) &= SET_BIT(dev);
}

void BeagleBoardC4LedDriver::toggle(LedDevice dev)
{
  *CAST_VOLATILE_U_LONG_PTR(GPIO5_DATAOUT) ^= SET_BIT(dev);
}

bool BeagleBoardC4LedDriver::is_on(LedDevice dev)
{
  U_LONG state = *CAST_VOLATILE_U_LONG_PTR(GPIO5_DATAOUT);
  return (state | SET_BIT(dev) == state) ? true : false;
}

// enable output for LED 0,1
void BeagleBoardC4LedDriver::enable_output(LedDevice dev)
{
  *CAST_VOLATILE_U_LONG_PTR(GPIO5_OE) |= SET_BIT(dev);
}
