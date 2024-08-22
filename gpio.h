/**
  ******************************************************************************
  * @file    Lab-Libraries/gpio.h 
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    23-04-2024
  *****************************************************************************/

/* Includes ------------------------------------------------------------------*/


/*adresse de base de GPIOA *******/
#define GPIO_A (unsigned int*)(0x40020000)
#define GPIO_B (unsigned int*)(0x40020400)
#define GPIO_C (unsigned int*)(0x40020800)
#define GPIO_D (unsigned int*)(0x40020C00)
#define GPIO_E (unsigned int*)(0x40021000)
#define GPIO_F (unsigned int*)(0x40021400)
#define GPIO_G (unsigned int*)(0x40021800)
#define GPIO_H (unsigned int*)(0x40021C00)
#define GPIO_I (unsigned int*)(0x40022000)

//OFFSET
#define MODER    0X00
#define OTYPER   0X01 /*OFFSET OTYPER 4/4=1 CAR REF MANUEL "type CHAR" */
#define OSPEEDER 0X02
#define PUPDR    0X03
#define IDR      0X04
#define ODR      0X05
#define BSRR     0X06

//MODE FONCT
#define INPUT  0X00
#define OUTPUT 0X01
#define AF     0X02
#define AN     0X03

//types de sortie
#define PP          0x00  
#define OD          0x01  

//POSITION DES PINS
# define GPIO_PIN_0 ((unsigned  ) 0x0001) // uinut16_t = unsigned short
# define GPIO_PIN_1 ((unsigned  ) 0x0002)
# define GPIO_PIN_2 ((unsigned ) 0x0004)
# define GPIO_PIN_3 ((unsigned ) 0x0008)
# define GPIO_PIN_4 ((unsigned ) 0x0010)
# define GPIO_PIN_5 ((unsigned  ) 0x0020)
# define GPIO_PIN_6 ((unsigned  ) 0x0040)
# define GPIO_PIN_7 ((unsigned  ) 0x0080)
# define GPIO_PIN_8 ((unsigned  ) 0x0100)
# define GPIO_PIN_9 ((unsigned  ) 0x0200)
# define GPIO_PIN_10 ((unsigned  ) 0x0400)
# define GPIO_PIN_11 ((unsigned  ) 0x0800)
# define GPIO_PIN_12 ((unsigned  ) 0x1000)
# define GPIO_PIN_13 ((unsigned  ) 0x2000)
# define GPIO_PIN_14  ((unsigned  ) 0x4000)
# define GPIO_PIN_15 ((unsigned  ) 0x8000)
# define GPIO_PIN_A11 ((unsigned  ) 0xFFFF)



/* -----------------ajouter les protopyes des fonctions----------------------*/
void GPIO_Enable(unsigned int* GPIO_X);
void GPIO_DeInit(unsigned int * gpio_x);
void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin);
unsigned char GPIO_ReadInputDataBit(unsigned int * gpio_x, unsigned short int GPIO_Pin);
unsigned short int GPIO_ReadInputData(unsigned int * gpio_x);
void GPIO_WriteBit(unsigned int * gpio_x, unsigned short int GPIO_Pin, char BitVal);
void GPIO_Write(unsigned int * gpio_x, unsigned short int PortVal);





/******************* (C) COPYRIGHT 2019 CSF *****END OF FILE*******************/