#include "stm32f4xx.h"
#include "gpio.h"


/************************** Private define ********************************/
#define NOMBRE_BOUCLES 100
                                                       
/*************************** Private function prototypes*******************/
void Delay(volatile unsigned  int  nCount);


/*************************** Private functions*****************************/

int main(void)
{
  unsigned  int counter = 0x00;  

/*********************** Activer l'orloge pour le Port C******************/

GPIO_Enable(GPIO_D);

 /****************** re-intialiser les registers de port C**************/
GPIO_DeInit(GPIO_D);

  
/*************Configure PD12 et PD13 en mode Output Push pull**************/  
GPIO_Init(GPIO_D,OUTPUT, PP, 12 );
GPIO_Init(GPIO_D,OUTPUT, PP, 13 );


  for(counter=0; counter<NOMBRE_BOUCLES ; counter++)
  {
/******************** Turn On LD3 and LD4***********************************/
   GPIO_WriteBit(GPIO_D, GPIO_PIN_12,1);
   GPIO_WriteBit(GPIO_D, GPIO_PIN_13,1); 
    Delay(0x3FFFFF) ;
    
/******************* Turn off LD3 and LD4 *********************************/
  GPIO_WriteBit(GPIO_D, GPIO_PIN_12,0);
  GPIO_WriteBit(GPIO_D, GPIO_PIN_13,0); 
    Delay(0x3FFFFF) ;
           
  }
  while(1);
}

void Delay(volatile unsigned  int  nCount)
{
  for(; nCount != 0; nCount--);
}


