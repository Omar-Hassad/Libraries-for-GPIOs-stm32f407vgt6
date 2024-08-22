/**
  ******************************************************************************
  * @file    Lab-Libraries/gpio.c
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    28-04-2024
  *****************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

// Ajouter define pour RCC clock 
volatile unsigned short int *RCC_AHB1ENR = (unsigned short int*)(0x40023830); //(...+0x30)
// Ajouter define pour RCC reset
volatile unsigned short int *RCC_AHB1STR = (unsigned short int*)(0x40023810); //(...+0x10)


void GPIO_Enable(unsigned int * GPIO_X){
  if (GPIO_X==GPIO_A) {
    *RCC_AHB1ENR |=(1<<0);
  }else if (GPIO_X==GPIO_B) {
    *RCC_AHB1ENR |=(1<<1);
  }else if (GPIO_X==GPIO_C){ 
    *RCC_AHB1ENR |=(1<<2);
  }else if (GPIO_X==GPIO_D){ 
    *RCC_AHB1ENR |=(1<<3);
  }else if (GPIO_X==GPIO_E) {
    *RCC_AHB1ENR |=(1<<4);
  }else if (GPIO_X==GPIO_F){ 
    *RCC_AHB1ENR |=(1<<5);
  }else if (GPIO_X==GPIO_G){ 
    *RCC_AHB1ENR |=(1<<6);
  }else if (GPIO_X==GPIO_H){ 
    *RCC_AHB1ENR |=(1<<7);
  }else if (GPIO_X==GPIO_I){ 
    *RCC_AHB1ENR |=(1<<8);}
};

/**
* @brief Deinitializes the gpio_x peripheral registers to their default reset values.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @retval None
*/
void GPIO_DeInit(unsigned int* GPIO_X)
{
   if (GPIO_X==GPIO_A)  {
    *RCC_AHB1STR |=(1<<0);
    *RCC_AHB1STR &=~(1<<0); 
   }else if (GPIO_X==GPIO_B){
    *RCC_AHB1STR |=(1<<1);
    *RCC_AHB1STR &=~(1<<1);
   }else if (GPIO_X==GPIO_C){
    *RCC_AHB1STR |=(1<<2);
    *RCC_AHB1STR &=~(1<<2);
   }else if (GPIO_X==GPIO_D){
    *RCC_AHB1STR |=(1<<3);
    *RCC_AHB1STR &=~(1<<3);
   }else if (GPIO_X==GPIO_E){
    *RCC_AHB1STR |=(1<<4);
    *RCC_AHB1STR &=~(1<<4);
   }else if (GPIO_X==GPIO_F){
    *RCC_AHB1STR |=(1<<5);
    *RCC_AHB1STR &=~(1<<5);
   }else if (GPIO_X==GPIO_G){
    *RCC_AHB1STR |=(1<<6);
    *RCC_AHB1STR &=~(1<<6);
   }else if (GPIO_X==GPIO_H){
    *RCC_AHB1STR |=(1<<7);
    *RCC_AHB1STR &=~(1<<7);
   }else if (GPIO_X==GPIO_I){
    *RCC_AHB1STR |=(1<<8);
    *RCC_AHB1STR &=~(1<<8);}
};

void GPIO_Init(unsigned int * GPIO_X, char Mode, char typeOutput, short int pin)
{
    unsigned int mask = ~(0x3 << (pin * 2)); // Mask to force MODER x to 0
    *(GPIO_X + MODER) &= mask; // Force position pin*2 and pin*2+1 to 0
    *(GPIO_X + MODER) |= Mode << (pin * 2); // Apply the chosen mode
    
    mask = ~(0x1 << pin);
    if (typeOutput == PP) {
        *(GPIO_X + typeOutput) &= mask;
    } else {
        *(GPIO_X + typeOutput) |= ~mask;
    }
}



//** Lire la valeur dune seule PIN
unsigned char GPIO_ReadInputDataBit(unsigned int * GPIO_X, unsigned short int GPIO_Pin)
{
    unsigned char bit_status;
    
    if ((*(GPIO_X + IDR) & GPIO_Pin) != 0x00) {
        bit_status = 0x1;
    } else {
        bit_status = 0x0;
    }
    
    return bit_status;
}


//**Lire la valeur du Port
unsigned short int GPIO_ReadInputData(unsigned int * gpio_x){
return (*(gpio_x+IDR));
};
  


//**Mettre la valeur 1 ou 0 dans une seul PIN
void GPIO_WriteBit (unsigned int * GPIO_X, unsigned short int GPIO_Pin, char BitVal){
  if (BitVal != 0x0) {
   *(GPIO_X+ODR) |= GPIO_Pin ;
  }  else  {
    *(GPIO_X+ODR) &= ~ GPIO_Pin ;}
}


//**Mettre une valeur désiré dans un Port complet
void GPIO_Write(unsigned int * GPIO_X, unsigned short int PortVal){
*GPIO_X = PortVal;
};















/******************* (C) COPYRIGHT 2024 CSF *****END OF FILE*******************/

