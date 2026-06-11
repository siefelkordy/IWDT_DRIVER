/*
 * IWDT_Cfg.h
 *
 *  Created on: May 18, 2026
 *      Author: Seif
 */

#ifndef INC_IWDT_CFG_H_
#define INC_IWDT_CFG_H_

#include "IWDT_Types.h"
//Service key and window values
#define IWDT_SERVICE_KEY1                      0X0055U
#define IWDT_SERVICE_KEY2                      0X00AAU
#define IWDT_DEFAULT_WINDOW_VALUE              0X00FFU
//Default modes
#define IWDT_DEFAULT_MODE                      IWDT_RESET_MODE
#define IWDT_DEFAULT_PRESCALER                 IWDT_PRESCALER_1
#define IWDT_DEFAULT_WINDOW_MODE               IWDT_NORMAL_MODE
//Config IWDT struct
extern const IWDT_ConfigType IWDT_Config;

#endif /* INC_IWDT_CFG_H_ */
