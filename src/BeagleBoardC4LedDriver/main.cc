/* BeagleBoardC4LedDriver.cc
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

#include "driver/BeagleBoardC4LedDriver.h"
#include "Led.h"


/*
 * BeagleBoard LED Test.
 * The Toggle does not appear as a smooth toggle between USR0 and USR1 on the
 * BeagleBoard. The reason for this is that both LEDs toggle independently
 * from each other.
 *
 * This test is for a single LED Object and not for combined hardware actions.
 */
int main(int argc, char **argv) {

  bool finished = false;
  BeagleBoardC4LedDriver* driver = new BeagleBoardC4LedDriver();
  Led* usr0 = new Led(LED_DEVICE_USR0, driver);
  Led* usr1 = new Led(LED_DEVICE_USR1, driver);


  usr0->set_off();
  usr1->set_on();

  printf("start set on/off test\n");

  printf("usr0 status: %d\n", usr0->is_on());
  printf("usr1 status: %d\n", usr1->is_on());

  printf("start endless toggling LEDs\n");

  do {
//     usr0->toggle();
//     printf("usr0 status: %d\n", usr0->is_on());
//     usr1->toggle();
//     printf("usr1 status: %d\n", usr1->is_on());

    driver->toggle(LED_DEVICE_USR0, LED_DEVICE_USR1);
    printf("usr0 status: %d\n", usr0->is_on());
    printf("usr1 status: %d\n", usr1->is_on());
  } while (!finished);

  /* end of BeagleBoardC4LedDriverTest program */
  delete usr0;
  delete usr1;
  delete driver;

  return 0;
}
