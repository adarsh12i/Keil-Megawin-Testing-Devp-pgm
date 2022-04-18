#include "MG32x02z_ChipInit.h"
#include "MG32x02z_SYS_DRV.h"
#include "MG32x02z_GPIO.h"
#include "MG32x02z__Common_DRV.H"
#include "MG32x02z_URT_DRV.H"
#include "MG32x02z_CSC_init.h"

/********************************************************************************URT0*/

#define URTX    URT0
#define URT_TOTAL_DATA_LEN    256*4 
uint8_t URT_TX_TABLE[URT_TOTAL_DATA_LEN]; 
uint8_t URT_RX_TABLE[URT_TOTAL_DATA_LEN];
unsigned int delay;
void URT0_IRQHandler(void);
 
volatile uint8_t gURT0_First = 0;
int fputc(int ch, FILE *f)
{
    // UART0
    URT_SetTXData(URT0, 1, ch);
    while(URT_GetITSingleFlagStatus(URT0, URT_IT_TC) == DRV_UnHappened);
    URT_ClearITFlag(URT0, URT_IT_TC);
    return ch;
}

int fgetc(FILE *f)
{
    int ch;
    while(URT0->STA.MBIT.RXF == 0);
    ch = URT0->RDAT.B[0];
    return ch;
}

/********************************************************************************/
/********************************************************************************send data*/

int URT_SetTXDat( URT_Struct* URT , uint8_t Data_len , uint32_t URT_TDAT)
{ 
	switch(Data_len)
    {
        case 1:
                 URT->TDAT.B[0] = (uint8_t) URT_TDAT;
                 break;
        case 2:
                 URT->TDAT.H[0] = (uint16_t) URT_TDAT;
                 break;
        case 3:
                 URT->TDAT.B[0] = URT_TDAT;
                 break;
			}
}
/********************************************************************************/
/*******************************************************************************main begin*/
uint8_t URT_RDAT;
int main(void)
{  
	
	PIN_InitTypeDef        PINX_InitStruct;
    
    ChipInit();    
	
	 // uint32_t returnCode;
  
   //returnCode = SysTick_Config(Clock / 1000);      /* Configure SysTick to generate an interrupt every millisecond */
    
    InitTick(12000000UL, 0);
	
    #define tdelay  250                 
    #define LED1     PE13
    #define LED2     PE14
    #define LED3     PE15
		#define b1       PA1

	  #define b1SET    PINA(1)
    #define LED1SET  PINE(13)
    #define LED2SET  PINE(14)
    #define LED3SET  PINE(15)

    PINX_InitStruct.PINX_Mode				        = PINX_Mode_PushPull_O;
    PINX_InitStruct.PINX_Speed              = PINX_Speed_Low;                                   
    PINX_InitStruct.PINX_Alternate_Function = 0;

    GPIO_PinMode_Config(b1SET,&PINX_InitStruct);
    GPIO_PinMode_Config(LED1SET,&PINX_InitStruct);
    GPIO_PinMode_Config(LED2SET,&PINX_InitStruct);
    GPIO_PinMode_Config(LED3SET,&PINX_InitStruct);
 
	
void URT0_Init(void);
{
    URT_BRG_TypeDef              URT_BRG;
    URT_Data_TypeDef             DataDef;
  
    URT_ClearTXData(URTX);
    URT_ClearRXData(URTX);
    
    PIN_InitTypeDef PINX_InitStruct;

    UnProtectModuleReg(CSCprotect);                                         // Unprottect CSC Module Register
    CSC_PeriphProcessClockSource_Config(CSC_UART0_CKS, CK_APB);             // UART0 process clock select CK_APB
    CSC_PeriphOnModeClock_Config(CSC_ON_UART0,ENABLE);                      // UART0 module clock enable
    CSC_PeriphOnModeClock_Config(CSC_ON_PortB,ENABLE);                      // Port B module clock enable
    ProtectModuleReg(CSCprotect);                                           // Prottect CSC Module Register

    //==Set GPIO init
    //PB8 PPO TX ,PB9 ODO RX
    PINX_InitStruct.PINX_Mode                = PINX_Mode_PushPull_O;        // Pin select Push Pull mode
    PINX_InitStruct.PINX_PUResistant         = PINX_PUResistant_Enable;     // Enable pull up resistor
    PINX_InitStruct.PINX_Speed               = PINX_Speed_Low;              // Pin output low speed mode
    PINX_InitStruct.PINX_OUTDrive            = PINX_OUTDrive_Level0;        // Pin output driver full strength.
    PINX_InitStruct.PINX_FilterDivider       = PINX_FilterDivider_Bypass;   // Pin input deglitch filter clock divider bypass
    PINX_InitStruct.PINX_Inverse             = PINX_Inverse_Disable;        // Pin input data not inverse
    PINX_InitStruct.PINX_Alternate_Function  = 3;                           // Pin AFS = URT0_TX
    GPIO_PinMode_Config(PINB(8),&PINX_InitStruct);                          // TXD(MOSI) at PB8

    PINX_InitStruct.PINX_Mode                = PINX_Mode_OpenDrain_O;       // Pin select Open Drain mode
    PINX_InitStruct.PINX_Alternate_Function  = 3;                           // Pin AFS = URT0_RX
    GPIO_PinMode_Config(PINB(9),&PINX_InitStruct);                          // RXD(MISO) at PB9 

    //=====Set Clock=====//
    //---Set BaudRate---//
    URT_BRG.URT_InternalClockSource     = URT_BDClock_PROC;
    URT_BRG.URT_BaudRateMode            = URT_BDMode_Separated;
    URT_BRG.URT_PrescalerCounterReload  = 1;	            //Set PSR
    URT_BRG.URT_BaudRateCounterReload   = 12;	            //Set RLR
    URT_BaudRateGenerator_Config(URTX, &URT_BRG);		      //BR115200 = f(CK_URTx)/(PSR+1)/(RLR+1)/(OS_NUM+1)
    URT_BaudRateGenerator_Cmd(URTX, ENABLE);	            //Enable BaudRateGenerator
		
		//--------------------------------------------------------
        //Set Data character config
        DataDef.URT_TX_DataLength  = URT_DataLength_8;
        DataDef.URT_RX_DataLength  = URT_DataLength_8;
        DataDef.URT_TX_DataOrder   = URT_DataTyped_MSB;
        DataDef.URT_RX_DataOrder   = URT_DataTyped_MSB;
        DataDef.URT_TX_Parity      = URT_Parity_All_H;
        DataDef.URT_RX_Parity      = URT_Parity_All_H;
        DataDef.URT_TX_StopBits    = URT_StopBits_2_0;
        DataDef.URT_RX_StopBits    = URT_StopBits_2_0;
        DataDef.URT_TX_DataInverse = DISABLE;
        DataDef.URT_RX_DataInverse = DISABLE;
        URT_DataCharacter_Config(URTX, &DataDef);
		
    //---TX/RX Clock---//
    URT_TXClockSource_Select(URTX, URT_TXClock_Internal);	//URT_TX use BaudRateGenerator
    URT_RXClockSource_Select(URTX, URT_RXClock_Internal);	//URT_RX use BaudRateGenerator
    URT_TXOverSamplingSampleNumber_Select(URTX, 3);	      //Set TX OS_NUM
    URT_RXOverSamplingSampleNumber_Select(URTX, 3);	      //Set RX OS_NUM
    URT_RXOverSamplingMode_Select(URTX, URT_RXSMP_3TIME);
    URT_TX_Cmd(URTX,ENABLE);                              // Enable URT TX_EN.
    URT_RX_Cmd(URTX,ENABLE);                              // Enable URT RX_EN.
		
		  //---Set Mode Select---//
    URT_Mode_Select(URT0, URT_URT_mode);                        // 
    //---Set DataLine Select---//
    URT_DataLine_Select(URT0, URT_DataLine_2);                  // 
    
    //=====Set Data Control=====//
    URT_RXShadowBufferThreshold_Select(URT0, URT_RXTH_1BYTE);   //
    URT_IdlehandleMode_Select(URT0, URT_IDLEMode_No);           //
    URT_TXGuardTime_Select(URT0, 0);                            //
    
    //=====Enable URT Interrupt=====//
    URT_IT_Config(URT0, URT_IT_RX | URT_IT_TC, ENABLE);         // Enable UART0 URT_IT_RX and URT_IT_TC interrupt
    URT_ITEA_Cmd(URT0, ENABLE);                                 // Enable UART0 interrupt all enable 
    NVIC_EnableIRQ(URT0_IRQn);                                  // Enable UART0 interrupt of NVIC
  
    //=====Enable URT=====//
    URT_Cmd(URTX, ENABLE);// Enable UART0 module
   }


/********************************************************************************/
/*******************************************************************************main begin*/
 
 while(1){
	 char data = 'a';
	 URT_SetTXDat(URT0 , 1 , data); 
  }
 }
/********************************************************************************/
/*******************************************************************************main end*/




































