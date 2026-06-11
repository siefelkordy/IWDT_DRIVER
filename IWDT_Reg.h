/*
 * IWDT_Reg.h
 *
 *  Created on: May 16, 2026
 *      Author: Seif
 */

#ifndef REG_IWDT_REG_H_
#define REG_IWDT_REG_H_

#include "Std_Types.h"
//BASE ADDRESSES
#define WD_REGS_BASE_ADDRESS            0x00007000U
#define NMI_INTRUPT_REGS                0x00007060U
#define CPU_SYS_REGS_BASE_ADDRESS       0x0005D300U
//OFFSET ADDRESSES
#define SCSR_OFFSET                     0X22U
#define WDCNTR_OFFSET                   0X23U
#define WDKEY_OFFSET                    0X25U
#define WDCR_OFFSET                     0X29U
#define WDWCR_OFFSET                    0X2AU
#define RESC_OFFSET                     0X80U
//WDRS bit in RESC Register
#define RESC_WDRSn_BIT                  (1U << 3)
//WDCHK bit in WDCR Register
#define IWDT_WDCHK_KEY                  0X5U
//Bit positions
#define WDCR_WDPS_BIT_POS               0U
#define WDCR_WDCHK_BIT_POS              3U
#define WDCR_WDDIS_BIT_POS              6U
//SCSR Register Bit field & union definition
typedef struct
{
uint16 WDOVERRIDE : 1;
uint16 WDENINT : 1;
uint16 WDINTS : 1;
uint16 RESERVED : 13; //Reserved

}SCSR_Bits_t;

typedef union
{
    uint16 U;
    SCSR_Bits_t b;
}SCSR_Reg_t;
//WDCNTR Register Bit field & union definition
typedef struct
{
uint16 CNTR : 8;
uint16 RESERVED : 8; //Reserved

}WDCNTR_Bits_t;

typedef union
{
    uint16 U;
    WDCNTR_Bits_t b;
}WDCNTR_Reg_t;
//WDCR Register Bit field & union definition
typedef struct
{
uint16 WDPS : 3;
uint16 WDCHK : 3;
uint16 WDDIS : 1;
uint16 RESERVED : 9; //Reserved

}WDCR_Bits_t;

typedef union
{
    uint16 U;
    WDCR_Bits_t b;
}WDCR_Reg_t;
//WDWCR Register Bit field & union definition
typedef struct
{
uint16 MIN : 8;
uint16 FIRSTKEY : 1;
uint16 RESERVED : 7; //Reserved

}WDWCR_Bits_t;

typedef union
{
    uint16 U;
    WDWCR_Bits_t b;
}WDWCR_Reg_t;

//Memory mapped access to WD registers
#define SCSR              (*(volatile SCSR_Reg_t*)(WD_REGS_BASE_ADDRESS + SCSR_OFFSET))
#define WDCNTR            (*(volatile WDCNTR_Reg_t*)(WD_REGS_BASE_ADDRESS + WDCNTR_OFFSET))
#define WDKEY             (*(volatile uint16*)(WD_REGS_BASE_ADDRESS + WDKEY_OFFSET))
#define WDCR              (*(volatile WDCR_Reg_t*)(WD_REGS_BASE_ADDRESS + WDCR_OFFSET))
#define WDWCR             (*(volatile WDWCR_Reg_t*)(WD_REGS_BASE_ADDRESS + WDWCR_OFFSET))
#define RESC              (*(volatile uint16*)(CPU_SYS_REGS_BASE_ADDRESS + RESC_OFFSET))
#endif /* REG_IWDT_REG_H_ */
