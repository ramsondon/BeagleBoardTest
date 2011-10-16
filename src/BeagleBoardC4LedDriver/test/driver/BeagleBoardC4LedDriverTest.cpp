/* BeagleBoardC4LedDriverTest.cpp
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
 *  Created on: Oct 16, 2011
 *      Author: Matthias Schmid <m.schmid@students.fhv.at>
 */

#include <assert.h>

#include "BeagleBoardC4LedDriverTest.h"
#include "../../driver/BeagleBoardC4LedDriver.h"



BeagleBoardC4LedDriverTest::BeagleBoardC4LedDriverTest() {
  driver_ = new BeagleBoardC4LedDriver();
  driver_->init(LED_DEVICE_USR0);
  driver_->init(LED_DEVICE_USR1);
}

BeagleBoardC4LedDriverTest::~BeagleBoardC4LedDriverTest() {
  delete driver_;
  driver_ = 0;
}

void BeagleBoardC4LedDriverTest::run()
{
  driver_->turn_on(LED_DEVICE_USR0);
  assert(driver_->is_on(LED_DEVICE_USR0) == true);

  driver_->turn_off(LED_DEVICE_USR1);
  assert(driver_->is_on(LED_DEVICE_USR1) == false);

  driver_->toggle(LED_DEVICE_USR0, LED_DEVICE_USR1);
  assert(driver_->is_on(LED_DEVICE_USR0) == false);
  assert(driver_->is_on(LED_DEVICE_USR1) == true);

  driver_->toggle(LED_DEVICE_USR0);
  assert(driver_->is_on(LED_DEVICE_USR0) == true);

  driver_->toggle(LED_DEVICE_USR1);
  assert(driver_->is_on(LED_DEVICE_USR1) == false);

  driver_->turn_off(LED_DEVICE_USR0);
  assert(driver_->is_on(LED_DEVICE_USR0) == false);
}

