/**
  ******************************************************************************
  * @file    .cpp
  * @author  shentq
  * @version V1.2
  * @date    2016/08/14
  * @brief   
  ******************************************************************************
  * @attention
  *
  * No part of this software may be used for any commercial activities by any form 
  * or means, without the prior written consent of shentq. This specification is 
  * preliminary and is subject to change at any time without notice. shentq assumes
  * no responsibility for any errors contained herein.
  * <h2><center>&copy; Copyright 2015 shentq. All Rights Reserved.</center></h2>
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/

#include "ebox.h"

#include "USBmouse.h"
#include "USBHID.h"
USBMouse mouse;



void setup()
{
    ebox_init();
    uart1.begin(115200);
}


int main(void)
{
    setup();
    while(1)
    {
			mouse.move(20, 0);
			delay_ms(500);

    }


}








