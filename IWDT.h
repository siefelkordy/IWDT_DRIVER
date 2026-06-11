/*
 * IWDT.h
 *
 *  Created on: May 16, 2026
 *      Author: Seif
 */

#ifndef INC_IWDT_H_
#define INC_IWDT_H_

#include "Std_Types.h"
#include"IWDT_Types.h"

void IWDT_vidInit(const IWDT_ConfigType*ConfigPtr);
void IWDT_vidService(void);
void IWDT_vidSetMode(IWDT_ModeType Mode);
void IWDT_vidClearStatus(void);
IWDT_StatusType IWDT_enGetResetCause(void);



#endif /* INC_IWDT_H_ */
