

/**
 ******************************************************************************
 *
 * @file        MG32x02z__IRQHandler.c
 * @brief       The demo IRQHandler C file.
 *
 * @par         Project
 *              MG32x02z
 * @version     V1.19
 * @date        2021/11/02
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




/* Includes ------------------------------------------------------------------*/
#include "MG32x02z_DRV.h"
#include "MG32x02z__IRQHandler.h"
#include "RTE_Components.h"

/* Wizard menu ---------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
#if defined(IRQHandler_Middleware_Level_)
    #include "MG32x02z_APB_MID.h"
    #include "MG32x02z_ADC_MID.h"
    #include "MG32x02z_CMP_MID.h"
    #include "MG32x02z_DMA_MID.h"
    #include "MG32x02z_TM_MID.h"
    #include "MG32x02z_RTC_MID.h"
    #include "MG32x02z_IWDT_MID.h"
    #include "MG32x02z_WWDT_MID.h"
    #include "MG32x02z_URT_MID.h"
    #include "MG32x02z_SPI_MID.h"
    #include "MG32x02z_EXIC_MID.h"
    #include "MG32x02z_PW_MID.h"
    #include "MG32x02z_I2C_MID.h"
    #include "MG32x02z_I2C_MID_ex.h"
    #include "MG32x02z_MEM_MID.h"
    #include "MG32x02z_CSC_MID.h"
    
    #if !defined(MG32_2ND)
        #include "MG32x02z_DAC_MID.h"
    #endif
    #if defined(MG32_1ST) || defined(MG32_3RD)
        #include "MG32x02z_EMB_MID.h"
    #endif
    #if defined(MG32_3RD)
        #include "MG32x02z_APX_MID.h"
    #endif
    
    #if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) /* ARM Compiler V6 */
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wmissing-variable-declarations"
            #if defined(MG32_3RD)
                __weak CCL_HandleTypeDef mCCL0;
                __weak CCL_HandleTypeDef mCCL1;
                __weak SDT_HandleTypeDef mSDT;
            #endif
            __weak MID_OBMx_HandleTypeDef   mOBMx;
            __weak ADC_HandleTypeDef        mADC;
            __weak CMP_HandleTypeDef        mCMP;
            __weak DMA_HandleTypeDef        mDMA;
            __weak TM_HandleTypeDef         mTM00;
            __weak TM_HandleTypeDef         mTM01;
            __weak TM_HandleTypeDef         mTM10;
            __weak TM_HandleTypeDef         mTM16;
            __weak TM_HandleTypeDef         mTM20;
            __weak TM_HandleTypeDef         mTM26;
            __weak TM_HandleTypeDef         mTM36;
            __weak RTC_HandleTypeDef        mRTC;
            __weak IWDT_HandleTypeDef       mIWDT;
            __weak URT_HandleTypeDef        mURT0;
            __weak URT_HandleTypeDef        mURT1;
            __weak URT_HandleTypeDef        mURT2;
            __weak URT_HandleTypeDef        mURT3;
            __weak SPI_HandleTypeDef        mUSPI0;
            __weak SPI_HandleTypeDef        mUSPI1;
            __weak SPI_HandleTypeDef        mUSPI2;
            __weak SPI_HandleTypeDef        mUSPI3;
            __weak URT_HandleTypeDef        mURT4;
            __weak URT_HandleTypeDef        mURT5;
            __weak URT_HandleTypeDef        mURT6;
            __weak URT_HandleTypeDef        mURT7;
            __weak SPI_HandleTypeDef        mSPI;
            __weak WWDT_HandleTypeDef       mWWDT;
            __weak EXIC_HandleTypeDef       mEXIC_PA; 
            __weak EXIC_HandleTypeDef       mEXIC_PB; 
            __weak EXIC_HandleTypeDef       mEXIC_PC; 
            __weak EXIC_HandleTypeDef       mEXIC_PD; 
            __weak I2C_HandleTypeDef        mI2C0;
            __weak I2C_HandleTypeDef        mI2C1;
            #if defined(MG32_1ST) || defined(MG32_3RD)
                __weak EMB_HandleTypeDef        mEMB;
            #endif
            #if !defined(MG32_2ND)
                __weak DAC_HandleTypeDef        mDAC;
            #endif
        #pragma clang diagnostic pop
    #else
        __weak MID_OBMx_HandleTypeDef   mOBMx;
        __weak ADC_HandleTypeDef        mADC;
        __weak CMP_HandleTypeDef        mCMP;
        __weak DMA_HandleTypeDef        mDMA;
        __weak TM_HandleTypeDef         mTM00;
        __weak TM_HandleTypeDef         mTM01;
        __weak TM_HandleTypeDef         mTM10;
        __weak TM_HandleTypeDef         mTM16;
        __weak TM_HandleTypeDef         mTM20;
        __weak TM_HandleTypeDef         mTM26;
        __weak TM_HandleTypeDef         mTM36;
        __weak RTC_HandleTypeDef        mRTC;
        __weak IWDT_HandleTypeDef       mIWDT;
        __weak URT_HandleTypeDef        mURT0;
        __weak URT_HandleTypeDef        mURT1;
        __weak URT_HandleTypeDef        mURT2;
        __weak URT_HandleTypeDef        mURT3;
        __weak SPI_HandleTypeDef        mUSPI0;
        __weak SPI_HandleTypeDef        mUSPI1;
        __weak SPI_HandleTypeDef        mUSPI2;
        __weak SPI_HandleTypeDef        mUSPI3;
        __weak URT_HandleTypeDef        mURT4;
        __weak URT_HandleTypeDef        mURT5;
        __weak URT_HandleTypeDef        mURT6;
        __weak URT_HandleTypeDef        mURT7;
        __weak SPI_HandleTypeDef        mSPI;
        __weak WWDT_HandleTypeDef       mWWDT;
        __weak EXIC_HandleTypeDef       mEXIC_PA; 
        __weak EXIC_HandleTypeDef       mEXIC_PB; 
        __weak EXIC_HandleTypeDef       mEXIC_PC; 
        __weak EXIC_HandleTypeDef       mEXIC_PD; 
        __weak I2C_HandleTypeDef        mI2C0;
        __weak I2C_HandleTypeDef        mI2C1;
        #if defined(MG32_1ST) || defined(MG32_3RD)
            __weak EMB_HandleTypeDef        mEMB;
        #endif
        #if !defined(MG32_2ND)
            __weak DAC_HandleTypeDef        mDAC;
        #endif
        #if defined(MG32_3RD)	
        __weak CCL_HandleTypeDef 	mCCL0;
        __weak CCL_HandleTypeDef 	mCCL1;
        __weak SDT_HandleTypeDef 	mSDT;
        #endif
    #endif
    
#endif

/* Private function prototypes -----------------------------------------------*/
void AccumulationA(uint32_t* ptr32);
void NMI_Handler(void);
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void WWDT_IRQHandler(void);
void SYS_IRQHandler(void);
void EXINT0_IRQHandler(void);
void EXINT1_IRQHandler(void);
void EXINT2_IRQHandler(void);
void EXINT3_IRQHandler(void);
void COMP_IRQHandler(void);
void DMA_IRQHandler(void);
void ADC_IRQHandler(void);
void DAC_IRQHandler(void);
void TM0x_IRQHandler(void);
void TM10_IRQHandler(void);
void TM1x_IRQHandler(void);
void TM20_IRQHandler(void);
void TM2x_IRQHandler(void);
void TM3x_IRQHandler(void);
//void URT0_IRQHandler(void);
void URT123_IRQHandler(void);
void URT4x_IRQHandler(void);
void SPI0_IRQHandler(void);
void I2C0_IRQHandler(void);
void I2Cx_IRQHandler(void);
void USB_IRQHandler(void);
void APX_IRQHandler(void);

/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/* External vairables --------------------------------------------------------*/
void IncTick(void);
void MID_IncTick(void);



/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
void NMI_Handler(void)
{    
    //to do......
}

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
void SVC_Handler(void)
{
    //to do......    
}
/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
void PendSV_Handler(void)
{
    //to do......    
}
/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
void SysTick_Handler(void)
{
    // ------------------------------------------------------------------------
    // SysTick ISR
    // ------------------------------------------------------------------------
    //to do......
    #if defined(IRQHandler_Middleware_Level_)
        MID_IncTick(); 
    #else
        IncTick();
    #endif
}

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_WWDT_IRQ_)
void WWDT_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // WWDT ISR
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        MID_WWDT_IRQHandler(&mWWDT);
    #else
        WWDT_IRQ();
    #endif
}
#endif
/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_SYS_IRQ_)
void SYS_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // IWDT ISR
    // ------------------------------------------------------------------------
    if(__DRV_EXIC_GET_ID1_SOURCE() & EXIC_SRC0_ID1_iwdt_b1)
    {
        // Middleware level interrupt routine
        #if defined(IRQHandler_Middleware_Level_)
            MID_IWDT_IRQHandler(&mIWDT);
        #else
            IWDT_IRQ();
        #endif
    }
    // ------------------------------------------------------------------------
    // PW ISR
    // ------------------------------------------------------------------------
    if(__DRV_EXIC_GET_ID1_SOURCE() & EXIC_SRC0_ID1_pw_b1)
    {
        // Middleware level interrupt routine
        #if defined(IRQHandler_Middleware_Level_)
            MID_PW_IRQHandler();
        #else
            PW_IRQ();
        #endif
    }
    // ------------------------------------------------------------------------
    // RTC ISR
    // ------------------------------------------------------------------------
    if(__DRV_EXIC_GET_ID1_SOURCE() & EXIC_SRC0_ID1_rtc_b1)
    {
        // Middleware level interrupt routine
        #if defined(IRQHandler_Middleware_Level_)
            MID_RTC_IRQHandler(&mRTC);
        #else
            RTC_IRQ();
        #endif
    }
    // ------------------------------------------------------------------------
    // CSC ISR
    // ------------------------------------------------------------------------
    if(__DRV_EXIC_GET_ID1_SOURCE() & EXIC_SRC0_ID1_csc_b1)
    {
        #if defined(IRQHandler_Middleware_Level_)
            MID_CSC_IRQHandler();
        #else
            CSC_IRQ();
        #endif
    }
    // ------------------------------------------------------------------------
    // APB ISR
    // ------------------------------------------------------------------------
    if(__DRV_EXIC_GET_ID1_SOURCE() & EXIC_SRC0_ID1_apb_b1)
    {
        // Middleware level interrupt routine
        #if defined(IRQHandler_Middleware_Level_)
            #if defined(MG32_1ST)
            if(__DRV_APB_GET_IT_SOURCE(APB_IT_OBM1))
                MID_OBMx_IRQHandler(&mOBMx);
            #endif
            #if defined(MG32_2ND)
            if((__DRV_APB_GET_IT_SOURCE(APB_IT_OBM0)) || (__DRV_APB_GET_IT_SOURCE(APB_IT_OBM1)))
                MID_OBMx_IRQHandler(&mOBMx);
            #endif
            #if defined(MG32_3RD)
            if((__DRV_APB_GET_IT_SOURCE(APB_IT_OBM0)) || (__DRV_APB_GET_IT_SOURCE(APB_IT_OBM1)))
                MID_OBMx_IRQHandler(&mOBMx);
            else
                MID_NCO_IRQHandler();            
            #endif
        #else
            APB_IRQ();
        #endif
    }
    // ------------------------------------------------------------------------
    // MEM ISR
    // ------------------------------------------------------------------------
    if(__DRV_EXIC_GET_ID1_SOURCE() & EXIC_SRC0_ID1_mem_b1)
    {
        #if defined(IRQHandler_Middleware_Level_)
            MID_MEM_IRQHandler();
        #else
            MEM_IRQ();
        #endif
    }
    // ------------------------------------------------------------------------
    // EMB ISR
    // ------------------------------------------------------------------------
    #if defined(MG32_1ST) || defined(MG32_3RD)
        if(__DRV_EXIC_GET_ID1_SOURCE() & EXIC_SRC0_ID1_emb_b1)
        {
            #if defined(IRQHandler_Middleware_Level_)
                MID_EMB_IRQHandler(&mEMB);
            #else
                EMB_IRQ();
            #endif
        }
    #endif
    
}

#endif

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
/*#if defined(MG32x02z_EXINT0_IRQ_)
void EXINT0_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // EXINT0 ISR
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        MID_EXIC_IRQHandler(&mEXIC_PA);
    #else
        EXINT0_IRQ();
    #endif
}
#endif
*/
/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
/*#if defined(MG32x02z_EXINT1_IRQ_)
void EXINT1_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // EXINT1 ISR
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        MID_EXIC_IRQHandler(&mEXIC_PB);
    #else
        EXINT1_IRQ();
    #endif
}
#endif
*/
/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_EXINT2_IRQ_)
void EXINT2_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // EXINT2 ISR
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        MID_EXIC_IRQHandler(&mEXIC_PC);
    #else
        EXINT2_IRQ();
    #endif
}
#endif
/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_EXINT3_IRQ_)
void EXINT3_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // EXINT3 ISR
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        MID_EXIC_IRQHandler(&mEXIC_PD);
    #else
        EXINT3_IRQ();
    #endif
}
#endif

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_COMP_IRQ_)
void COMP_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // COMP ISR
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        MID_CMP_IRQHandler(&mCMP);
    #else
        CMP_IRQ();
    #endif
}
#endif
/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_DMA_IRQ_)
void DMA_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // DMA ISR
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        MID_DMA_IRQHandler(&mDMA);
    #else
        DMA_IRQ();
    #endif
}
#endif
/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_ADC_IRQ_)
void ADC_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // ADC ISR
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        MID_ADC_IRQHandler(&mADC);
    #else
        ADC_IRQ();
    #endif
}
#endif
/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_DAC_IRQ_)
void DAC_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // DAC ISR
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        MID_DAC_IRQHandler(&mDAC);
    #else
        DAC_IRQ();
    #endif
}
#endif
/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_TM0x_IRQ_)
void TM0x_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // TM00 ISR
    // ------------------------------------------------------------------------
    if(__DRV_EXIC_GET_ID12_SOURCE() & EXIC_SRC3_ID12_tm00_b0 )
    {
        // Middleware level interrupt routine
        #if defined(IRQHandler_Middleware_Level_)
            MID_TM_IRQHandler(&mTM00);
        #else
            TM00_IRQ();
        #endif
    }

    // ------------------------------------------------------------------------
    // TM01 ISR
    // ------------------------------------------------------------------------
    if(__DRV_EXIC_GET_ID12_SOURCE() & EXIC_SRC3_ID12_tm01_b0)
    {
        // Middleware level interrupt routine
        #if defined(IRQHandler_Middleware_Level_)
            MID_TM_IRQHandler(&mTM01);
        #else
            TM01_IRQ();
        #endif
    }
}
#endif

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_TM10_IRQ_)
void TM10_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // TM10 ISR 
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        MID_TM_IRQHandler(&mTM10);
    #else
        TM10_IRQ();
    #endif
}
#endif

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_TM1x_IRQ_)
void TM1x_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // TM16 ISR 
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        MID_TM_IRQHandler(&mTM16);
    #else
        TM16_IRQ();
    #endif
}
#endif

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_TM20_IRQ_)
void TM20_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // TM20 ISR 
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        MID_TM_IRQHandler(&mTM20);
    #else
        TM20_IRQ();
    #endif
}
#endif

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_TM2x_IRQ_)
void TM2x_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // TM26 ISR 
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        MID_TM_IRQHandler(&mTM26);
    #else
        TM26_IRQ();
    #endif
}
#endif

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_TM3x_IRQ_)
void TM3x_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // TM36 ISR 
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        MID_TM_IRQHandler(&mTM36);
    #else
        TM36_IRQ();
    #endif
}
#endif

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
/*#if defined(MG32x02z_URT0_IRQ_)
void URT0_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // URT0 ISR 
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        if(IS_URT_SPIMODE(URT0)==SET)
        {
            MID_SPI_IRQHandler(&mUSPI0);
        }
        else
        {
            MID_URT_IRQHandler(&mURT0);
        }
    #else
        URT0_IRQ();
    #endif
}
#endif
*/
/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_URT123_IRQ_)
void URT123_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // URT1 ISR 
    // ------------------------------------------------------------------------
    // Apply MCU 
    //  MG32_1ST : MG32F02A132, MG32F02A072, MA862
    //  MG32_2ND : MG32F02A032
    //  MG32_3RD : MG32F02A128, MG32F02A064, MG32F02U128, MG32F02U064
    //  MG32_4TH : MG32F02V032
    // ------------------------------------------------------------------------
    if(__DRV_EXIC_GET_ID21_SOURCE() & EXIC_SRC5_ID21_urt1_b1)
    {
        #if defined(IRQHandler_Middleware_Level_)
            if(IS_URT_SPIMODE(URT1)==SET)
            {
                MID_SPI_IRQHandler(&mUSPI1);
            }
            else
            { 
                MID_URT_IRQHandler(&mURT1);
            }
        #else
            URT1_IRQ();
        #endif
    }
    // ------------------------------------------------------------------------
    // URT2 ISR
    // ------------------------------------------------------------------------
    // Apply MCU 
    //  MG32_1ST : MG32F02A132, MG32F02A072, MA862
    //  MG32_3RD : MG32F02A128, MG32F02A064, MG32F02U128, MG32F02U064
    // ------------------------------------------------------------------------
    #if defined(MG32_1ST) || defined(MG32_3RD) 
        if(__DRV_EXIC_GET_ID21_SOURCE() & EXIC_SRC5_ID21_urt2_b1)
        {
            #if defined(IRQHandler_Middleware_Level_)
                if(IS_URT_SPIMODE(URT2)==SET)
                {
                    MID_SPI_IRQHandler(&mUSPI2);
                }
                else
                { 
                    MID_URT_IRQHandler(&mURT2);
                } 
            #else
                URT2_IRQ();
            #endif
        }
    #endif
    // ------------------------------------------------------------------------
    // URT3 ISR
    // ------------------------------------------------------------------------
    // Apply MCU 
    //  MG32_1ST : MG32F02A132, MG32F02A072, MA862
    // ------------------------------------------------------------------------
    #if defined(MG32_1ST)
        if(__DRV_EXIC_GET_ID21_SOURCE() & EXIC_SRC5_ID21_urt3_b1)
        {
            #if defined(IRQHandler_Middleware_Level_)
                if(IS_URT_SPIMODE(URT3)==SET)
                {
                    MID_SPI_IRQHandler(&mUSPI3);
                }
                else
                { 
                    MID_URT_IRQHandler(&mURT3);
                }
            #else
                URT3_IRQ();
            #endif
        }
    #endif
    
}
#endif

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_URT4x_IRQ_)
void URT4x_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // URT4 ISR
    // ------------------------------------------------------------------------
    // Apply MCU 
    //  MG32_3RD : MG32F02A128, MG32F02A064, MG32F02U128, MG32F02U064
    //  MG32_4TH : MG32F02V032
    // ------------------------------------------------------------------------
    #if defined(MG32_3RD) 
        if(__DRV_EXIC_GET_ID22_SOURCE() & EXIC_SRC5_ID22_urt4_b2)
        {
            #if defined(IRQHandler_Middleware_Level_)
                MID_URT_IRQHandler(&mURT4);
            #else
                URT4_IRQ();
            #endif
        }
    #endif
    
    // ------------------------------------------------------------------------
    // URT5 ISR
    // ------------------------------------------------------------------------
    // Apply MCU 
    //  MG32_3RD : MG32F02A128, MG32F02A064, MG32F02U128, MG32F02U064
    // ------------------------------------------------------------------------
    #if defined(MG32_3RD)
        if( __DRV_EXIC_GET_ID22_SOURCE() & EXIC_SRC5_ID22_urt5_b2)
        {
            #if defined(IRQHandler_Middleware_Level_)
                MID_URT_IRQHandler(&mURT5);
            #else
                URT5_IRQ();
            #endif
        }
    #endif
    // ------------------------------------------------------------------------
    // URT6 ISR
    // ------------------------------------------------------------------------
    // Apply MCU 
    //  MG32_3RD : MG32F02A128, MG32F02A064, MG32F02U128, MG32F02U064
    // ------------------------------------------------------------------------
    #if defined(MG32_3RD)
        if( __DRV_EXIC_GET_ID22_SOURCE() & EXIC_SRC5_ID22_urt6_b2)
        {
            #if defined(IRQHandler_Middleware_Level_)
                MID_URT_IRQHandler(&mURT6);
            #else
                URT6_IRQ();
            #endif
        }
    #endif
    // ------------------------------------------------------------------------
    // URT7 ISR
    // ------------------------------------------------------------------------
    // Apply MCU 
    //  MG32_3RD : MG32F02A128, MG32F02A064, MG32F02U128, MG32F02U064
    // ------------------------------------------------------------------------
    #if defined(MG32_3RD)
        if( __DRV_EXIC_GET_ID22_SOURCE() & EXIC_SRC5_ID22_urt7_b2)
        {
            #if defined(IRQHandler_Middleware_Level_)
                MID_URT_IRQHandler(&mURT7);
            #else
                URT7_IRQ();
            #endif
        }
    #endif
    
}
#endif

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_SPI0_IRQ_)
void SPI0_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // SPI0 ISR
    // ------------------------------------------------------------------------
    #if defined(IRQHandler_Middleware_Level_)
        MID_SPI_IRQHandler(&mSPI);
    #else
        SPI0_IRQ();
    #endif
}
#endif

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_I2C0_IRQ_)
void I2C0_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // I2C0 ISR
    // ------------------------------------------------------------------------
    #if defined(IRQHandler_Middleware_Level_)
        MID_I2C_IRQHandler(&mI2C0);
    #else
        I2C0_IRQ();
    #endif
}
#endif

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_I2Cx_IRQ_)
void I2Cx_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // I2C1 ISR
    // ------------------------------------------------------------------------
    #if defined(IRQHandler_Middleware_Level_)
        MID_I2C_IRQHandler(&mI2C1);
    #else
        I2C1_IRQ();
    #endif
}
#endif

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_USB_IRQ_)
void USB_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // USB ISR
    // ------------------------------------------------------------------------
    USB_IRQ();
}

#endif

/**
 *******************************************************************************
 * @brief	    
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
#if defined(MG32x02z_APX_IRQ_)
void APX_IRQHandler(void)
{
    // ------------------------------------------------------------------------
    // APX ISR
    // ------------------------------------------------------------------------
    // Middleware level interrupt routine
    #if defined(IRQHandler_Middleware_Level_)
        if((__DRV_APX_GET_IT_SOURCE(APX_IT_CCL0)))
        {
            MID_APX_CCL_IRQHandler(&mCCL0);
        }
        else if ((__DRV_APX_GET_IT_SOURCE(APX_IT_CCL1)))
        {
            MID_APX_CCL_IRQHandler(&mCCL1);
        }
        else 
        {
            MID_APX_SDT_IRQHandler(&mSDT);            
        }
    #else
        APX_IRQ();
    #endif
    
}

#endif






