

/**
 ******************************************************************************
 *
 * @file        BSP.h
 * @brief       BLE_MG126 BSP h Code. 
 *
 * @par         Project
 *              MG32x02z
 * @version     V1.01
 * @date        2021/01/19
 * @author      Megawin Software Center
 * @copyright   Copyright (c) 2021 MegaWin Technology Co., Ltd.
 *              All rights reserved.
 *
 ******************************************************************************* 
 * @par Disclaimer
 * The Demo software is provided "AS IS" without any warranty, either
 * expressed or implied, including, but not limited to, the implied warranties
 * of merchantability and fitness for a particular purpose. The author will
 * not be liable for any special, incidental, consequential or indirect
 * damages due to loss of data or any other reason.
 * These statements agree with the world wide and local dictated laws about
 * authorship and violence against these laws.
 *******************************************************************************
 *******************************************************************************
 */
 

#ifndef _BSP_H
#define _BSP_H

#include "MG32x02z_DRV.H"


/*! @name 
*/
/* @{ */
// TH188A_MGF02A072_132 LQFP-80_V20
// TH218A_MG32F02A128 LQFP-80_EV_V10
#if (defined(MG32_1ST) || defined(MG32_3RD))
#define LED1_CSC_ON_Port        CSC_ON_PortE        // 
#define LED1_PINSET             PINE(13)            //
#define LED1_PIN                PE13                //
#endif

// TH197B_MG32F02A032 LQFP48_EV_V11
#if defined(MG32_2ND)
#define LED1_CSC_ON_Port        CSC_ON_PortC        //
#define LED1_PINSET             PINC(0)             //
#define LED1_PIN                PC0                 //
#endif

// BLE used EXIC pin define
#define EXIC_CFG_PIN            PINB(10)            //
#define EXIC_TRGS_PINX          EXIC_TRGS_PIN10     //
#define EXIC_PX_PINX            EXIC_PX_PIN10       //
#define EXIC_PX_AND_MASK_PINX   EXIC_PX_PIN10       //
#define EXIC_PX_OR_MASK_PINX    EXIC_PX_PIN10       //
#define EXIC_PIN                PB10                //

// LED
#define LED_OFF                 1                   //
#define LED_ON                  0                   //

// SPI 
#define BLE_MODULE              SPI_SPI0            // BLE_MODULE used SPI0
//#define BLE_MODULE              SPI_URT1            // BLE_MODULE used URT1
#define SPI_NSS                 PB0                 // SPI_NSS(SPI) for all
//#define SPI_NSS                 PD6                 // SPI_NSS(UART1) for A132/A072
//#define SPI_NSS                 PC13                // SPI_NSS(UART1) for A032
//#define SPI_NSS                 PC7                 // SPI_NSS(UART1) for A128/A064/U128/U064

/* @} */

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

void BSP_Init(void);
void LED_Flash(void);
void IrqMcuGotoSleepAndWakeup(void);
DRV_Return SPIx_Init (uint32_t ProcessClockRate, uint32_t BLEClockRate);

#endif



