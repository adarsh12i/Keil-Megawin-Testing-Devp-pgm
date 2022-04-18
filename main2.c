#include "MG32x02z_ChipInit.h"
#include "MG32x02z_SYS_DRV.h"

#define LED_OFF               1
#define LED_ON                0

int main(void)
{    
    PIN_InitTypeDef        PINX_InitStruct;
    
    ChipInit();    
    
   // InitTick(12000000UL, 0); 
	
	
#if defined(MG32_1ST) || defined(MG32_3RD)                     
    #define LED1     PE13
    #define LED2     PE14
    #define LED3     PE15
		#define b1       PA1

	  #define b1SET    PINA(1)
    #define LED1SET  PINE(13)
    #define LED2SET  PINE(14)
    #define LED3SET  PINE(15)
	
#endif	

    PINX_InitStruct.PINX_Mode				        = PINX_Mode_PushPull_O;
    PINX_InitStruct.PINX_Speed              = PINX_Speed_Low;                                   
    PINX_InitStruct.PINX_Alternate_Function = 0;

    GPIO_PinMode_Config(b1SET,&PINX_InitStruct);
    GPIO_PinMode_Config(LED1SET,&PINX_InitStruct);
    GPIO_PinMode_Config(LED2SET,&PINX_InitStruct);
    GPIO_PinMode_Config(LED3SET,&PINX_InitStruct);
	
#if defined(MG32x02z_EXINT0_IRQ_)

		#define EXIC_CFG_PIN            PINA(2)            //
		#define EXIC_TRGS_PINX          EXIC_TRGS_PIN2     //
		#define EXIC_PX_PINX            EXIC_PX_PIN2       //
		#define EXIC_PX_AND_MASK_PINX   EXIC_PX_PIN2       //
		#define EXIC_PX_OR_MASK_PINX    EXIC_PX_PIN2       //
		#define EXIC_PIN                PA2
		
#endif

		/*while(1){if(b1==0){
        while(b1==0)		
        LED1 = LED_ON;LED2 = LED_OFF;LED3 = LED_OFF;  
        Delay(250);
        LED1= LED_OFF;LED2= LED_OFF;LED3 = LED_OFF;			
        Delay(250);
				}   
    if(b1==1){
     LED1= LED_OFF;LED2= LED_OFF;LED3 = LED_OFF;						
	  }}*/
		
		 while(1){
			 if(EXIC_PIN==0){
        if(b1==0){			 
        LED1 = LED_ON;LED2 = LED_OFF;LED3 = LED_OFF;  
        Delay(250);
        LED1= LED_OFF;LED2= LED_OFF;LED3 = LED_OFF;			
        Delay(250);}
				else{
				LED1= LED_OFF;LED2= LED_OFF;LED3 = LED_OFF;			
       }
				EXIC_PIN=1;	
     }
	 }
		 void EXINT0_IRQHandler (void);{
		      EXIC_ClearPxTriggerEventFlag(EXIC_PA, EXIC_PX_PINX );            // Clear 
          EXIC_ClearPxTriggerITFlag(EXIC_PA_ITF,EXIC_PX_OF | EXIC_PX_AF);
          while(1){
						if(EXIC_PIN==1){
							  LED1 = LED_OFF;LED2 = LED_ON;LED3 = LED_OFF;
		}
	}
}
}
