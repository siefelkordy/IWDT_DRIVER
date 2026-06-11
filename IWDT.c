/*
 * IWDT.c
 *
 *  Created on: May 16, 2026
 *      Author: Seif
 */
#include "Std_Types.h"
#include "IWDT.h"
#include "IWDT_Reg.h"
#include "IWDT_Types.h"
#include "IWDT_Cfg.h"

static uint16 IWDT_u16WindowValue;
static IWDT_StatusType IWDT_LastStatus;
//Initializing WD

void IWDT_vidInit(const IWDT_ConfigType*ConfigPtr)
{
    /* NULL pointer protection */
    if(ConfigPtr == NULL_PTR)
    {
        IWDT_LastStatus = IWDT_STATUS_INVALID_CONFIG;
        return;
    }
    /* Enable writing to WDDIS by setting WDOVERRIDE to 1 */
    SCSR.b.WDOVERRIDE = TRUE;
    /* Disable watchdog before configuration*/
    WDCR.U =
     (ConfigPtr->Prescaler << WDCR_WDPS_BIT_POS)|
     (IWDT_WDCHK_KEY << WDCR_WDCHK_BIT_POS)|
     (TRUE << WDCR_WDDIS_BIT_POS);
    /* Configure Mode */
    SCSR.b.WDENINT = ConfigPtr->Mode;
    /* Configure minimum allowed value of window if mode is window Mode */
    if(ConfigPtr->WindowMode == IWDT_WINDOW_MODE)
    {
        /* Window Mode */
        WDWCR.b.MIN = ConfigPtr->WindowValue;
        IWDT_u16WindowValue = ConfigPtr->WindowValue;
    }
    else
    {
        /* Normal Mode */
        WDWCR.b.MIN = FALSE;
    }
    /* Clear previous watchdog status flags */
    RESC |= RESC_WDRSn_BIT;
    /* Disable watchdog before configuration*/
    WDCR.U =
     (ConfigPtr->Prescaler << WDCR_WDPS_BIT_POS)|
     (IWDT_WDCHK_KEY << WDCR_WDCHK_BIT_POS)|
     (FALSE << WDCR_WDDIS_BIT_POS);
    IWDT_LastStatus = IWDT_STATUS_OK;
}
//Service Key Sequence

void IWDT_vidService(void)
{
    /* Check window condition */
    if(WDCNTR.b.CNTR < IWDT_u16WindowValue)
    {
        IWDT_LastStatus = IWDT_STATUS_WINDOW_ERROR;
    }
    else
    {
        WDKEY = IWDT_SERVICE_KEY1;
        WDKEY = IWDT_SERVICE_KEY2;

        IWDT_LastStatus = IWDT_STATUS_OK;
    }
}
//Set watchdog operating mode

void IWDT_vidSetMode(IWDT_ModeType Mode)
{
    if(Mode == IWDT_INTERRUPT_MODE)
    {
        /* Interrupt mode */
        SCSR.b.WDENINT = TRUE;
    }
    else
    {
        /* Reset mode */
        SCSR.b.WDENINT = FALSE;
    }
}

void IWDT_vidClearStatus(void)
{
    /* Clear watchdog reset flag */
    RESC |= RESC_WDRSn_BIT;
}

IWDT_StatusType IWDT_enGetResetCause(void)
{

    if((RESC & RESC_WDRSn_BIT) != FALSE)
    {
        IWDT_LastStatus = IWDT_STATUS_TIMEOUT;
    }

    return IWDT_LastStatus;

}



