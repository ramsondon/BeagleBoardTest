/* BeagleBoardC4LedDriver.h
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

#ifndef LEDDRIVER_H_
#define LEDDRIVER_H_

#define U_LONG unsigned long
#define VOLATILE_U_LONG_PTR volatile U_LONG *
#define CAST_VOLATILE_U_LONG_PTR(var) ((VOLATILE_U_LONG_PTR)var)

#define GPIO5_OE 0x49054034       /* GPIO5 output enable address */
#define GPIO5_DATAOUT 0x4905603C  /* GPIO5 data out register address*/

#define SET_BIT(bit) (1<<bit)     /* Sets the specified bit to 1 */

/*
 * The built in LEDs of BeagleBoard RC4
 */
enum LedDevice
{
// Led USR0
  LED_DEVICE_USR0 = 22,
// Led USR1
  LED_DEVICE_USR1 = 21
};


class BeagleBoardC4LedDriver {
  private:
    void enable_output(LedDevice dev);

  public:
    BeagleBoardC4LedDriver();
    ~BeagleBoardC4LedDriver();
    void init(LedDevice dev);
    void turn_on(LedDevice dev);
    void turn_off(LedDevice dev);
    void toggle(LedDevice dev);
    bool is_on(LedDevice dev);
};

#endif /* LEDDRIVER_H_ */
