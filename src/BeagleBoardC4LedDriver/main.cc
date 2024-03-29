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

#include "test/driver/BeagleBoardC4LedDriverTest.h"

/*
 * BeagleBoard LED HardwareTest.
 * The Toggle does not appear as a smooth toggle between USR0 and USR1 on the
 * BeagleBoard. The reason for this is that both LEDs toggle independently
 * from each other.
 *
 * This test is for a single LED Object and not for combined hardware actions.
 */
int main(int argc, char **argv) {

  printf("start test cases\n");

  HardwareTest* ledDriverTest = new BeagleBoardC4LedDriverTest();

  ledDriverTest->run();

  delete ledDriverTest;
  /* end of BeagleBoardC4LedDriverTest program */
  return 0;
}
