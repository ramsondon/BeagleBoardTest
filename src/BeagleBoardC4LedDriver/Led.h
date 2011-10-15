/* Led.h
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

#ifndef LED_H_
#define LED_H_

#include "driver/BeagleBoardC4LedDriver.h"

/*
 * Class Led
 *
 * A specific Led Device for the BeagleBoard C4
 */
class Led {
  protected:
    bool state_;
    LedDevice deviceid_;
    BeagleBoardC4LedDriver* driver_;

  public:
//    constructor
    Led(LedDevice dev, BeagleBoardC4LedDriver* driver);
//    deconstructor
    ~Led();
//    turns the led on
    void set_on();
//    turns the led off
    void set_off();
//    toggles the current led status
    void toggle();
//    returns true if the led is turned on
    bool is_on();

};

#endif /* LED_H_ */
