
#include <bcm2835.h>
#include <stdio.h>

//A Motor Pins define
#define IN1_A RPI_GPIO_P1_11
#define IN2_A RPI_GPIO_P1_13
//B Motor Pins define
#define IN4_B RPI_GPIO_P1_16
#define IN3_B RPI_GPIO_P1_18
//C Motor Pins define
#define IN5_C RPI_GPIO_P1_8
#define IN6_C RPI_GPIO_P1_10

void goingForward()
{
	printf("\u2191\n");

		//MOTOR A	
        bcm2835_gpio_write(IN1_A, HIGH);    
        bcm2835_gpio_write(IN2_A, LOW);

		//MOTOR B	
        bcm2835_gpio_write(IN3_B, HIGH);    
        bcm2835_gpio_write(IN4_B, LOW);
		//MOTOR C	
        bcm2835_gpio_write(IN3_B, LOW);    
        bcm2835_gpio_write(IN4_B, LOW);
		

}

void goingBackward()
{
	printf("\u2193\n");
	
		//MOTOR A	
        bcm2835_gpio_write(IN1_A, LOW);    
        bcm2835_gpio_write(IN2_A, HIGH);

		//MOTOR B	
        bcm2835_gpio_write(IN3_B, LOW);    
        bcm2835_gpio_write(IN4_B, HIGH);
		//MOTOR C	
        bcm2835_gpio_write(IN3_B, LOW);    
        bcm2835_gpio_write(IN4_B, LOW);
}

void terningLeft()
{
	printf("\u2190\n");

  		//MOTOR A	
        bcm2835_gpio_write(IN1_A, LOW);    
        bcm2835_gpio_write(IN2_A, LOW);

		//MOTOR B	
        bcm2835_gpio_write(IN3_B, HIGH);    
        bcm2835_gpio_write(IN4_B, LOW);
		//MOTOR C	
        bcm2835_gpio_write(IN3_B, HIGH);    
        bcm2835_gpio_write(IN4_B, LOW);
}

void terningRight()
{
	printf("\u2192\n");

 		//MOTOR A	
        bcm2835_gpio_write(IN1_A, HIGH);    
        bcm2835_gpio_write(IN2_A, LOW);

		//MOTOR B	
        bcm2835_gpio_write(IN3_B, LOW);    
        bcm2835_gpio_write(IN4_B, LOW);
		//MOTOR C	
        bcm2835_gpio_write(IN3_B, HIGH);    
        bcm2835_gpio_write(IN4_B, LOW);
}

void stopMotors()
{	
		//MOTOR A	
        bcm2835_gpio_write(IN1_A, LOW);    
        bcm2835_gpio_write(IN2_A, LOW);

		//MOTOR B	
        bcm2835_gpio_write(IN3_B, LOW);    
        bcm2835_gpio_write(IN4_B, LOW);
		//MOTOR C	
        bcm2835_gpio_write(IN3_B, LOW);    
        bcm2835_gpio_write(IN4_B, LOW);
}
int main(int argc, char **argv)
{




    if (!bcm2835_init())
      return 1;

    // Set the pin to be an output Motor A

    bcm2835_gpio_fsel(IN1_A, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(IN2_A, BCM2835_GPIO_FSEL_OUTP);
       // Set the pin to be an output Motor B
    bcm2835_gpio_fsel(IN3_B, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(IN4_B, BCM2835_GPIO_FSEL_OUTP);
	    // Set the pin to be an output Motor C
    bcm2835_gpio_fsel(IN5_C, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(IN6_C, BCM2835_GPIO_FSEL_OUTP);


	//set the pins LOW Motor A
    bcm2835_gpio_write(PIN2_IN1, HIGH);
    bcm2835_gpio_write(PIN7_IN2, HIGH);
   	//set the pins LOW Motor B
    bcm2835_gpio_write(PIN10_IN3, HIGH);
    bcm2835_gpio_write(PIN15_IN4, HIGH);
	//set the pins LOW Motor C
    bcm2835_gpio_write(PIN10_IN3, HIGH);
    bcm2835_gpio_write(PIN15_IN4, HIGH);


char c;
   
    while (1){
	
	do{

	switch(c){

	
	case 'w':
	goingForward();
	break;
  
	
	case 'a':
	terningLeft();
	break;

	
	case 'd':
	terningRight();
	break;

	case ' ':	
	stopMotors();
	break;
	
	
	case 's':
	goingBackward();
	break;
	}
}


while(getchar());
    }
    bcm2835_close();
    return 0;
}
