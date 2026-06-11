/*
 * IWDT_Cfg.c
 *
 *  Created on: May 21, 2026
 *      Author: Seif
 */
#include "IWDT.h"
#include "IWDT_Cfg.h"

const IWDT_ConfigType IWDT_Config =
{
    .Mode = IWDT_DEFAULT_MODE,
    .WindowMode = IWDT_DEFAULT_WINDOW_MODE,
    .Prescaler = IWDT_DEFAULT_PRESCALER,
    .WindowValue = IWDT_DEFAULT_WINDOW_VALUE
};



