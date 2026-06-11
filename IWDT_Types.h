/*
 * IWDT_Types.h
 *
 *  Created on: May 16, 2026
 *      Author: Seif
 */


#ifndef INC_IWDT_TYPES_H_
#define INC_IWDT_TYPES_H_

#include "Std_Types.h"

typedef enum
{
    IWDT_RESET_MODE = 0U,
    IWDT_INTERRUPT_MODE
}IWDT_ModeType;

typedef enum
{
    IWDT_NORMAL_MODE = 0U,
    IWDT_WINDOW_MODE
}IWDT_WindowModeType;

typedef enum
{
    IWDT_PRESCALER_1 = 1U,
    IWDT_PRESCALER_2,
    IWDT_PRESCALER_4,
    IWDT_PRESCALER_8,
    IWDT_PRESCALER_16,
    IWDT_PRESCALER_32,
    IWDT_PRESCALER_64
}IWDT_PrescalerType;

typedef enum
{
    IWDT_STATUS_OK = 0U,
    IWDT_STATUS_TIMEOUT,
    IWDT_STATUS_WINDOW_ERROR,
    IWDT_STATUS_INVALID_CONFIG
}IWDT_StatusType;

typedef struct
{
    IWDT_ModeType Mode;
    IWDT_WindowModeType WindowMode;
    IWDT_PrescalerType Prescaler;
    uint16 WindowValue;
}IWDT_ConfigType;

#endif /* INC_IWDT_TYPES_H_ */
