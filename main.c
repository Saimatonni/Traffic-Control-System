#include "stm32f446xx.h"
#include "CLOCK.h"
#include "SYS_INIT.h"
#include "GPIO.h"

static GPIO_PinState high 	= GPIO_PIN_SET;
static GPIO_PinState low 	  = GPIO_PIN_RESET;
#define GPIO_MODE_OUTPUT  ((uint32_t)0x01)



int random(){
int end = 3, start = 0;
return (rand() % (end - start + 1)) + start;

}


void delay (uint32_t time)	
{
	while(time--);
}


void Right_load(int loadRight, GPIO_PinState PinState){
	
	GPIO_InitTypeDef PA5 = {5, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW}; 
	GPIO_Init(GPIOA, &PA5);
	GPIO_InitTypeDef PA6 = {6, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOA, &PA6);
	GPIO_InitTypeDef PA7 = {7, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOA, &PA7);
	if(loadRight == 3){
			GPIO_WritePin(GPIOA, PA7.Pin,  high);
			
			GPIO_WritePin(GPIOA, PA6.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOA, PA5.Pin,  high);
		}
		else if(loadRight == 2){
			GPIO_WritePin(GPIOA, PA7.Pin,  low);
			GPIO_WritePin(GPIOA, PA6.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOA, PA5.Pin,  high);
		}
		else{
			GPIO_WritePin(GPIOA, PA7.Pin,  low);
			GPIO_WritePin(GPIOA, PA6.Pin,  low);
			GPIO_WritePin(GPIOA, PA5.Pin,  high);
		}
	
}

void Left_load(int loadLeft, GPIO_PinState PinState){
	
	GPIO_InitTypeDef PB13 = {13, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW}; 
	GPIO_Init(GPIOB, &PB13);
	GPIO_InitTypeDef PB14 = {14, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOB, &PB14);
	GPIO_InitTypeDef PB15 = {15, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOB, &PB15);
	
	if(loadLeft == 3){
			GPIO_WritePin(GPIOB, PB15.Pin,  high);
			
      GPIO_WritePin(GPIOB, PB14.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOB, PB13.Pin,  high);
		}
		else if(loadLeft == 2){
			GPIO_WritePin(GPIOB, PB15.Pin,  low);
      GPIO_WritePin(GPIOB, PB14.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOB, PB13.Pin,  high);
		}
		else{
			GPIO_WritePin(GPIOB, PB15.Pin,  low);
      GPIO_WritePin(GPIOB, PB14.Pin,  low);
			GPIO_WritePin(GPIOB, PB13.Pin,  high);
		}
	
	
}


void Up_load(int loadUp, GPIO_PinState PinState){
	GPIO_InitTypeDef PC13 = {13, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW}; 
	GPIO_Init(GPIOC, &PC13);
	GPIO_InitTypeDef PC10 = {10, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOC, &PC10);
	GPIO_InitTypeDef PC12 = {12, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOC, &PC12);
	if(loadUp == 3){
      GPIO_WritePin(GPIOC, PC12.Pin,  high);
			//ms_delay(250);
      GPIO_WritePin(GPIOC, PC10.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOC, PC13.Pin,  high);
		}
		else if(loadUp == 2){
			GPIO_WritePin(GPIOC, PC12.Pin,  low);
      GPIO_WritePin(GPIOC, PC10.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOC, PC13.Pin,  high);
		
		}
		else{
			GPIO_WritePin(GPIOC, PC12.Pin,  low);
      GPIO_WritePin(GPIOC, PC10.Pin,  low);
			GPIO_WritePin(GPIOC, PC13.Pin,  high);
			
		}
		
	
}

void Down_load(int loadDown, GPIO_PinState PinState){
	
	GPIO_InitTypeDef PA9 = {9, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
  GPIO_Init(GPIOA, &PA9);	
	GPIO_InitTypeDef PA11 = {11, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOA, &PA11);
	GPIO_InitTypeDef PA12 = {12, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOA, &PA12);
	if(loadDown == 3){
      GPIO_WritePin(GPIOA, PA9.Pin,  high);
			//ms_delay(250);
      GPIO_WritePin(GPIOA, PA11.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOA, PA12.Pin,  high);

		}
		else if(loadDown == 2){
			GPIO_WritePin(GPIOA, PA9.Pin,  low);
      GPIO_WritePin(GPIOA, PA11.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOA, PA12.Pin,  high);
			
		}
		else{
			GPIO_WritePin(GPIOA, PA9.Pin,  low);
      GPIO_WritePin(GPIOA, PA11.Pin,  low);
			GPIO_WritePin(GPIOA, PA12.Pin,  high);
		
		}
}

void left_right_ani(int time){
	//car right
	GPIO_InitTypeDef PA5 = {5, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW}; 
	GPIO_Init(GPIOA, &PA5);
	GPIO_InitTypeDef PA6 = {6, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOA, &PA6);
	GPIO_InitTypeDef PA7 = {7, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOA, &PA7);
	GPIO_InitTypeDef carRight[] = {PA5, PA6, PA7};
	
	//car LEFT
	GPIO_InitTypeDef PB13 = {13, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW}; 
	GPIO_Init(GPIOB, &PB13);
	GPIO_InitTypeDef PB14 = {14, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOB, &PB14);
	GPIO_InitTypeDef PB15 = {15, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOB, &PB15);
  GPIO_InitTypeDef carLeft[] = {PB15, PB14, PB13};
	
	int it = time/1000;
	int i;
  for(i=1;i<=it;i++){
		GPIO_WritePin(GPIOA, PA7.Pin,  high);
		GPIO_WritePin(GPIOB, PB15.Pin,  high);
		
		ms_delay(333);
		
    GPIO_WritePin(GPIOA, PA7.Pin,  low);
		GPIO_WritePin(GPIOB, PB15.Pin,  low);
		
		GPIO_WritePin(GPIOA, PA6.Pin,  high);
		GPIO_WritePin(GPIOB, PB14.Pin,  high);
		
		ms_delay(333);
		
		GPIO_WritePin(GPIOA, PA6.Pin,  low);
		GPIO_WritePin(GPIOB, PB14.Pin,  low);
		
		GPIO_WritePin(GPIOA, PA5.Pin,  high);
		GPIO_WritePin(GPIOB, PB13.Pin,  high);
		
		ms_delay(334);
		
		GPIO_WritePin(GPIOA, PA5.Pin,  low);
		GPIO_WritePin(GPIOB, PB13.Pin,  low);
	}		
	
}

void up_down_ani(int time){
	//car down
	GPIO_InitTypeDef PA9 = {9, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
  GPIO_Init(GPIOA, &PA9);	
	GPIO_InitTypeDef PA11 = {11, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOA, &PA11);
	GPIO_InitTypeDef PA12 = {12, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOA, &PA12);
	GPIO_InitTypeDef carDown[] = {PA9, PA11, PA12};

	
	
	//car up
	GPIO_InitTypeDef PC13 = {13, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW}; 
	GPIO_Init(GPIOC, &PC13);
	GPIO_InitTypeDef PC10 = {10, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOC, &PC10);
	GPIO_InitTypeDef PC12 = {12, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOC, &PC12);
	GPIO_InitTypeDef carUp[] = {PC13, PC10, PC12};
	
	int it = time/1000;
	int i;
  for(i=1;i<=it;i++){
		GPIO_WritePin(GPIOA, PA12.Pin,  high);
		GPIO_WritePin(GPIOC, PC12.Pin,  high);
		
		ms_delay(333);
		
		GPIO_WritePin(GPIOA, PA12.Pin,  low);
		GPIO_WritePin(GPIOC, PC12.Pin,  low);
		
		GPIO_WritePin(GPIOA, PA11.Pin,  high);
		GPIO_WritePin(GPIOC, PC10.Pin,  high);
		
		ms_delay(333);
		
		GPIO_WritePin(GPIOA, PA11.Pin,  low);
		GPIO_WritePin(GPIOC, PC10.Pin,  low);
		
		GPIO_WritePin(GPIOA, PA9.Pin,  high);
		GPIO_WritePin(GPIOC, PC13.Pin,  high);
		
		ms_delay(334);

		GPIO_WritePin(GPIOA, PA9.Pin,  low);
		GPIO_WritePin(GPIOC, PC13.Pin,  low);
	}		
	
}

int main(void)
{
	
	initClock();
	sysInit();
	RCC->AHB1ENR |= 1; 
	RCC->AHB1ENR |= 1<<1;
	RCC->AHB1ENR |= 1 << 2;
	
	
	//car right
	GPIO_InitTypeDef PA5 = {5, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW}; 
	GPIO_Init(GPIOA, &PA5);
	GPIO_InitTypeDef PA6 = {6, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOA, &PA6);
	GPIO_InitTypeDef PA7 = {7, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOA, &PA7);
	GPIO_InitTypeDef carRight[] = {PA5, PA6, PA7};
	
	GPIO_InitTypeDef IN_LoadR  =  {3, GPIO_MODE_INPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW, GPIOB}; GPIO_Init(GPIOB, &IN_LoadR);
	
	
	//car LEFT
	GPIO_InitTypeDef PB13 = {13, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW}; 
	GPIO_Init(GPIOB, &PB13);
	GPIO_InitTypeDef PB14 = {14, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOB, &PB14);
	GPIO_InitTypeDef PB15 = {15, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOB, &PB15);
  GPIO_InitTypeDef carLeft[] = {PB15, PB14, PB13};
	
	GPIO_InitTypeDef IN_LoadL  =  {5, GPIO_MODE_INPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW, GPIOB}; GPIO_Init(GPIOB, &IN_LoadL);
	
	//car down
	GPIO_InitTypeDef PA9 = {9, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
  GPIO_Init(GPIOA, &PA9);	
	GPIO_InitTypeDef PA11 = {11, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOA, &PA11);
	GPIO_InitTypeDef PA12 = {12, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOA, &PA12);
	GPIO_InitTypeDef carDown[] = {PA9, PA11, PA12};

	GPIO_InitTypeDef IN_LoadD  =  {10, GPIO_MODE_INPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW, GPIOB}; GPIO_Init(GPIOB, &IN_LoadR); // C1
	
	//car up
	GPIO_InitTypeDef PC13 = {13, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW}; 
	GPIO_Init(GPIOC, &PC13);
	GPIO_InitTypeDef PC10 = {10, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOC, &PC10);
	GPIO_InitTypeDef PC12 = {12, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOC, &PC12);
	GPIO_InitTypeDef carUp[] = {PC13, PC10, PC12};
	
	GPIO_InitTypeDef IN_LoadU  =  {4, GPIO_MODE_INPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW, GPIOB}; GPIO_Init(GPIOB, &IN_LoadU); // C12

	
	//signal left to right
	GPIO_InitTypeDef G1_PC5 = {5, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW}; 
	GPIO_Init(GPIOC, &G1_PC5);
	GPIO_InitTypeDef Y1_PC6 = {6, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOC, &Y1_PC6);
	GPIO_InitTypeDef R1_PC8 = {8, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOC, &R1_PC8);
	
	//GPIO_InitTypeDef IN_RedLR    =  {2, GPIO_MODE_INPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW, GPIOB}; GPIO_Init(GPIOB, &IN_RedLR); // B2
	GPIO_InitTypeDef IN_GreenLR  =  {1, GPIO_MODE_INPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW, GPIOB}; GPIO_Init(GPIOB, &IN_GreenLR); // B1
	
	
	//signal up to down
	GPIO_InitTypeDef G2_PA0 = {0, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW}; 
	GPIO_Init(GPIOA, &G2_PA0);
	GPIO_InitTypeDef Y2_PA1 = {1, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOA, &Y2_PA1);
	GPIO_InitTypeDef R2_PA4 = {4, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
	GPIO_Init(GPIOA, &R2_PA4);
	
	//GPIO_InitTypeDef IN_RedUD    =  {3, GPIO_MODE_INPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW, GPIOC}; GPIO_Init(GPIOC, &IN_RedUD); // C3
	GPIO_InitTypeDef IN_GreenUD  =  {2, GPIO_MODE_INPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW, GPIOC}; GPIO_Init(GPIOC, &IN_GreenUD); // C2
	
	
	// CAR LEFT
		GPIO_WritePin(GPIOB, PB13.Pin,  low);
		GPIO_WritePin(GPIOB, PB14.Pin,  low);
		GPIO_WritePin(GPIOB, PB15.Pin,  low);
		
		// CAR RIGHT
		GPIO_WritePin(GPIOA, PA5.Pin,  low);
		GPIO_WritePin(GPIOA, PA6.Pin,  low);
		GPIO_WritePin(GPIOA, PA7.Pin,  low);
		
		// CAR DOWN
		GPIO_WritePin(GPIOA, PA9.Pin,  low);
		GPIO_WritePin(GPIOA, PA11.Pin,  low);
		GPIO_WritePin(GPIOA, PA12.Pin,  low);
		
		// CAR UO
		GPIO_WritePin(GPIOC, PC13.Pin,  low);
		GPIO_WritePin(GPIOC, PC10.Pin,  low);
		GPIO_WritePin(GPIOC, PC12.Pin,  low);
		
		GPIO_WritePin(GPIOC, G1_PC5.Pin,  low);
		GPIO_WritePin(GPIOC, Y1_PC6.Pin,  low);
		GPIO_WritePin(GPIOC, R1_PC8.Pin,  low);
		
		GPIO_WritePin(GPIOA, G2_PA0.Pin,  low);
		GPIO_WritePin(GPIOA, Y2_PA1.Pin,  low);
		GPIO_WritePin(GPIOA, R2_PA4.Pin,  low);
	


	
	while(1){
			uint16_t loadLeft = rand()%4;
	    uint16_t loadRight = rand()%4;
	    uint16_t loadUp = rand()%4;
	    uint16_t loadDown = rand()%4;
	//uint16_t loop = 20;
	   int loadi, loadLeftRight, loadUpDown;
		
		 loadLeftRight = loadLeft + loadRight;
		 loadUpDown = loadUp + loadDown;
		
		
		
		
		
		if(loadRight == 3){
			GPIO_WritePin(GPIOA, PA7.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOA, PA6.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOA, PA5.Pin,  high);
		}
		else if(loadRight == 2){
			GPIO_WritePin(GPIOA, PA7.Pin,  low);
			GPIO_WritePin(GPIOA, PA6.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOA, PA5.Pin,  high);
		}
		else{
			GPIO_WritePin(GPIOA, PA7.Pin,  low);
			GPIO_WritePin(GPIOA, PA6.Pin,  low);
			GPIO_WritePin(GPIOA, PA5.Pin,  high);
		}
		if(loadLeft == 3){
			GPIO_WritePin(GPIOB, PB15.Pin,  high);
			//ms_delay(250);
      GPIO_WritePin(GPIOB, PB14.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOB, PB13.Pin,  high);
		}
		else if(loadLeft == 2){
			GPIO_WritePin(GPIOB, PB15.Pin,  low);
      GPIO_WritePin(GPIOB, PB14.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOB, PB13.Pin,  high);
		}
		else{
			GPIO_WritePin(GPIOB, PB15.Pin,  low);
      GPIO_WritePin(GPIOB, PB14.Pin,  low);
			GPIO_WritePin(GPIOB, PB13.Pin,  high);
		}
		if(loadUp == 3){
      GPIO_WritePin(GPIOC, PC12.Pin,  high);
			//ms_delay(250);
      GPIO_WritePin(GPIOC, PC10.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOC, PC13.Pin,  high);
		}
		else if(loadUp == 2){
			GPIO_WritePin(GPIOC, PC12.Pin,  low);
      GPIO_WritePin(GPIOC, PC10.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOC, PC13.Pin,  high);
		
		}
		else{
			GPIO_WritePin(GPIOC, PC12.Pin,  low);
      GPIO_WritePin(GPIOC, PC10.Pin,  low);
			GPIO_WritePin(GPIOC, PC13.Pin,  high);
			
		}
		
		if(loadDown == 3){
      GPIO_WritePin(GPIOA, PA9.Pin,  high);
			//ms_delay(250);
      GPIO_WritePin(GPIOA, PA11.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOA, PA12.Pin,  high);

		}
		else if(loadDown == 2){
			GPIO_WritePin(GPIOA, PA9.Pin,  low);
      GPIO_WritePin(GPIOA, PA11.Pin,  high);
			//ms_delay(250);
			GPIO_WritePin(GPIOA, PA12.Pin,  high);
			
		}
		else{
			GPIO_WritePin(GPIOA, PA9.Pin,  low);
      GPIO_WritePin(GPIOA, PA11.Pin,  low);
			GPIO_WritePin(GPIOA, PA12.Pin,  high);
		
		}
		
	
		
		if((GPIO_ReadPin(IN_LoadL) == 1) || (GPIO_ReadPin(IN_LoadR) == 1)){ 

			GPIO_WritePin(GPIOC, G1_PC5.Pin,  high);
			GPIO_WritePin(GPIOA, R2_PA4.Pin,  high);
			//if(GPIO_ReadPin(IN_GreenLR)==1){
				left_right_ani(10000);
			//}
				Right_load(loadRight, high);
			Left_load(loadLeft, high);
		  GPIO_WritePin(GPIOC, G1_PC5.Pin,  low);
			GPIO_WritePin(GPIOA, R2_PA4.Pin,  low);
			GPIO_WritePin(GPIOA, Y2_PA1.Pin, high);
			ms_delay(1000);
			GPIO_WritePin(GPIOA, Y2_PA1.Pin, low);
		}
		else if((GPIO_ReadPin(IN_LoadU)==1 ) || (GPIO_ReadPin(IN_LoadD) == 1)){
			// LEFT RIGHT GREEN OFF, RED On
			GPIO_WritePin(GPIOC, R1_PC8.Pin,  high);

			GPIO_WritePin(GPIOA, G2_PA0.Pin,  high);
			//if(GPIO_ReadPin(IN_GreenUD)==1){
				up_down_ani(10000);
			//}
				Up_load(loadUp, high);
		  	Down_load(loadDown, high);
			
      GPIO_WritePin(GPIOC, R1_PC8.Pin,  low);
			GPIO_WritePin(GPIOC, Y1_PC6.Pin,  high);
			ms_delay(1000);
			GPIO_WritePin(GPIOC, Y1_PC6.Pin,  low);
			GPIO_WritePin(GPIOA, G2_PA0.Pin,  low);
		}
			
		
	}
	
}


