/* BeagleBoardC4LedDriverTest.h
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

#ifndef BEAGLEBOARDC4LEDDRIVERTEST_H_
#define BEAGLEBOARDC4LEDDRIVERTEST_H_

#include "../HardwareTest.h"
#include "../../driver/BeagleBoardC4LedDriver.h"

class BeagleBoardC4LedDriverTest : public HardwareTest {
  private:
    BeagleBoardC4LedDriver* driver_;

  protected:
  public:
    BeagleBoardC4LedDriverTest();
    ~BeagleBoardC4LedDriverTest();
    void run();
};

#endif /* BEAGLEBOARDC4LEDDRIVERTEST_H_ */
