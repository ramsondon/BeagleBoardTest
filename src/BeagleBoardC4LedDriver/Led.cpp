/* Led.cpp
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
#include <stdio.h>
#include "Led.h"

/*
 * constructor
 *
 * @param dev
 * @param driver
 */
Led::Led(LedDevice dev, BeagleBoardC4LedDriver* driver)
{
  deviceid_ = dev;

  // initialize the driver for specific led usage
  driver_ = driver;
  driver->init(deviceid_);

  // initialze the current state of the device
  state_ = driver->is_on(deviceid_);
}
/*
 * destructor
 */
Led::~Led()
{
  driver_ = NULL;
}
/*
 *  turns the led on
 */
void Led::set_on()
{
  driver_->turn_on(deviceid_);
  state_ = true;
}
/*
 *  turns the led off
 */
void Led::set_off()
{
  driver_->turn_off(deviceid_);
  state_ = false;
}
/*
 * toggles the current led's status
 */
void Led::toggle()
{
  driver_->toggle(deviceid_);
  state_ = (state_) ? false : true;
}
/*
 *  returns true if the led is turned on
 */
bool Led::is_on()
{
  /*
   * XXX: how would you implement this abstracted LED function?
   * Would you return the Led Object its status or would you question every
   * time the real device for that?
   */
  // return state_;
  return driver_->is_on(deviceid_);
}
