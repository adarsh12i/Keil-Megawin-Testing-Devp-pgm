

/**
 ******************************************************************************
 *
 * @file        MG32x02z_ChipInit.c
 * @brief       The demo ChipInit C file.
 *
 * @par         Project
 *              MG32x02z
 * @version     V1.15
 * @date        2021/07/28
 * @author      Megawin Software Center
 * @copyright   Copyright (c) 2017 MegaWin Technology Co., Ltd.
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

#include "MG32x02z_ChipInit.h"
#include "MG32x02z.h"

/*
 *******************************************************************************
 * @brief	    Chip initial.  
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
void ChipInit(void)
{
    
    #ifdef MG32x02z_ConfigerWizard_PW
        PW_Init();
    #endif
    
    #ifdef MG32x02z_ConfigerWizard_CSC
        CSC_Init((uint32_t*) &CSC_InitConfig);
    #endif
    
    #ifdef MG32x02z_ConfigerWizard_RST
        RST_Init();
    #endif
    
    #ifdef MG32x02z_ConfigerWizard_GPIO
        GPIO_Init();
    #endif
    
    #ifdef MG32x02z_ConfigerWizard_TM
        TM_Init();
    #endif
    
    
    //=== Select initial outside Power & CSC & RST ... ====
    
    #ifdef MG32x02z_ConfigerWizard_EXIC
        EXIC_Init();
    #endif
        
    #ifdef MG32x02z_ConfigerWizard_EMB
        EMB_Initial();
    #endif
    
    #ifdef MG32x02z_ConfigerWizard_MEM
        MEM_Init();
    #endif
    
    #ifdef MG32x02z_ConfigerWizard_GPL
        GPL_Init();
    #endif
    
    #ifdef MG32x02z_ConfigerWizard_URT
        URT_Init();
    #endif
    
    #ifdef MG32x02z_ConfigerWizard_ADC
        ADC_Init();
    #endif
    
    #ifdef MG32x02z_ConfigerWizard_DAC
        DAC_Init();
    #endif
    
    #ifdef MG32x02z_ConfigerWizard_CMP
        CMP_ACx_Init();
    #endif
    
    #ifdef MG32x02z_ConfigerWizard_APB
        APB_Init();
    #endif
    
    #ifdef MG32x02z_ConfigerWizard_APX_CCL
        APX_CCL_Init();
    #endif
        
    #ifdef MG32x02z_ConfigerWizard_RTC
        RTC_Init();
    #endif
        
    //=== Enable NVIC interrupt ====
    
    #if defined(MG32x02z_WWDT_IRQ_)
        NVIC_EnableIRQ(WWDT_IRQn); 
    #endif
    #if defined(MG32x02z_IWDT_IRQ_)|defined(MG32x02z_PW_IRQ_)|defined(MG32x02z_RTC_IRQ_)|defined(MG32x02z_CSC_IRQ_)|defined(MG32x02z_APB_IRQ_)|defined(MG32x02z_MEM_IRQ_)
        NVIC_EnableIRQ(SYS_IRQn); 
    #endif
    #if defined(MG32x02z_EXINT0_IRQ_)
        NVIC_EnableIRQ(EXINT0_IRQn); 
    #endif
    #if defined(MG32x02z_EXINT1_IRQ_)
        NVIC_EnableIRQ(EXINT1_IRQn);
    #endif 
    #if defined(MG32x02z_EXINT2_IRQ_)
        NVIC_EnableIRQ(EXINT2_IRQn); 
    #endif
    #if defined(MG32x02z_EXINT3_IRQ_)
        NVIC_EnableIRQ(EXINT3_IRQn);
    #endif 
    #if defined(MG32x02z_COMP_IRQ_)
        NVIC_EnableIRQ(COMP_IRQn);
    #endif 
    #if defined(MG32x02z_DMA_IRQ_)
        NVIC_EnableIRQ(DMA_IRQn); 
    #endif
    #if defined(MG32x02z_ADC_IRQ_) 
        NVIC_EnableIRQ(ADC_IRQn); 
    #endif
    #if defined(MG32x02z_DAC_IRQ_)
        NVIC_EnableIRQ(DAC_IRQn);
    #endif
    #if defined(MG32x02z_TM00_IRQ_)|defined(MG32x02z_TM01_IRQ_)
        NVIC_EnableIRQ(TM0x_IRQn); 
    #endif
    #if defined(MG32x02z_TM10_IRQ_)
        NVIC_EnableIRQ(TM10_IRQn);
    #endif 
    #if defined(MG32x02z_TM16_IRQ_)
        NVIC_EnableIRQ(TM1x_IRQn);
    #endif 
    #if defined(MG32x02z_TM20_IRQ_)
        NVIC_EnableIRQ(TM20_IRQn); 
    #endif
    #if defined(MG32x02z_TM26_IRQ_)
        NVIC_EnableIRQ(TM2x_IRQn); 
    #endif
    #if defined(MG32x02z_TM36_IRQ_)
        NVIC_EnableIRQ(TM3x_IRQn); 
    #endif
    #if defined(MG32x02z_URT0_IRQ_)
        NVIC_EnableIRQ(URT0_IRQn);
    #endif   
    #if defined(MG32x02z_URT1_IRQ_)|defined(MG32x02z_URT2_IRQ_)|defined(MG32x02z_URT3_IRQ_)
        NVIC_EnableIRQ(URT123_IRQn);
    #endif 
    #if defined(MG32x02z_URT4_IRQ_)|defined(MG32x02z_URT5_IRQ_)|defined(MG32x02z_URT6_IRQ_)|defined(MG32x02z_URT7_IRQ_)
        NVIC_EnableIRQ(URT4x_IRQn);
    #endif     
    #if defined(MG32x02z_SPI0_IRQ_)
        NVIC_EnableIRQ(SPI0_IRQn);
    #endif 
    #if defined(MG32x02z_I2C0_IRQ_)
        NVIC_EnableIRQ(I2C0_IRQn);
    #endif 
    #if defined(MG32x02z_I2C1_IRQ_)
        NVIC_EnableIRQ(I2Cx_IRQn); 
    #endif    
	#if defined(MG32x02z_APX_IRQ_)
        NVIC_EnableIRQ(APX_IRQn);
    #endif 
	#if defined(MG32x02z_USB_IRQ_)
        NVIC_EnableIRQ(USB_IRQn);
    #endif 	
}









