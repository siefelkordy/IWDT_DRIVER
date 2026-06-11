/*
 * main.c
 *
 *  Created on: May 20, 2026
 *      Author: Seif
 */
#include "IWDT.h"
#include "IWDT_Types.h"
#include "IWDT_Cfg.h"

int main(void)
{

    IWDT_vidInit(&IWDT_Config);

    while(1)
    {
        IWDT_vidService();
    }
}



