#include<reg51.h>
#include<stdio.h>
#include<math.h>
#define lcddat P2
sbit rs = P3^0;
sbit en = P3^1;
#define keypad P1
void delay(unsigned int time);
void lcdcmd(unsigned int ch);
void lcddata(unsigned int ch);
void lcdstr(unsigned char *str);
unsigned int getkeypad(void);
void displayResult(int result) ;
   
void main()
{
	unsigned int i,x,y,operatr1,operatr2;
	unsigned int sum ,sub,mul,div;
	lcdcmd(0x38);
	lcdcmd(0x0E);
	lcdcmd(0x80);
	
	while(1)
	{
		lcdstr("simple:calculator");
		lcdcmd(0x01);
	  lcdcmd(0x80);
    lcdstr("enter 1st number");
	  lcdcmd(0xc0);
	  x = getkeypad();
	  lcddata(x);
		delay(200);
		
	  lcdcmd(0x01);
		lcdcmd(0x80);
	  lcdstr("enter 2nd number");
		lcdcmd(0xc0);
	  y = getkeypad();
	  lcddata(y);
	  delay(200);
	  lcdcmd(0x01);
	  lcddata(x);
		delay(200);
	  operatr1 = getkeypad();
	  lcddata(operatr1);
	  lcddata(y);
		delay(200);
	 operatr2 = getkeypad();
	 lcddata(operatr2);
  if(operatr2 == '=')
  {
		//sum
	   if(operatr1 == '+') 
		{
    sum = (x -'0') + (y-'0');
    displayResult(sum);
    }
		 lcdcmd(0x01);
		 
		//subtraction
		 if(operatr1 == '-')
		 {
		 sub =  (x -'0') - (y-'0')  ;
		 displayResult(sub);
	   }
		 lcdcmd(0x01);
		 //multiplication
		 if(operatr1 == '*')
		 {
		 mul = ( x -'0')* (y-'0');
		 displayResult(mul);
	   }
		 lcdcmd(0x01);
		 //division
		 
		 if(operatr1 == '/')
		 {
		 div= ( x -'0') / (y-'0') ;
		 displayResult(div);
	   }
		 lcdcmd(0x01);
   }
  
	lcdcmd(0x01);
 }
}

void delay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time ;i++)
	{
		for(j=0;j<1275;j++)
		{
		}
	}
}
void lcdcmd(unsigned int ch)
{
	lcddat = ch;
	rs = 0;
	en =1;
	delay(50);
	en = 0;
}
void lcddata(unsigned int ch)
{
 lcddat = ch;
	rs = 1;
	en = 1;
	delay(50);
	en = 0;
}
void lcdstr(unsigned char *str)
{
	unsigned loop ;
	for(loop = 0; str[loop] != '\0' ; loop++)
	{
		lcddata(str[loop]);
	}
}
//keypad


unsigned int getkeypad(void)
{
	unsigned int keyvalue = 0;
keypad = 0xFE;     //ROW =0
	if(keypad == 0xEE)
	{
		keyvalue = '7' ;
	}
	if(keypad == 0xDE)
	{
		keyvalue = '8';
	}
	if(keypad == 0xBE)
	{
		keyvalue = '9';
	}
	if(keypad == 0x7E)
	{
		keyvalue = '/';
	}
	
	
	keypad = 0xFD;     //ROW =1
	if(keypad == 0xED)
	{
		keyvalue = '4' ;
	}
	if(keypad == 0xDD)
	{
		keyvalue = '5';
	}
	if(keypad == 0xBD)
	{
		keyvalue = '6';
	}
	if(keypad == 0x7D)
	{
		keyvalue  = '*';
	}
	
	keypad = 0xFB;     //ROW =2
	if(keypad == 0xEB)
	{
		keyvalue = '1';
	}
	if(keypad == 0xDB)
	{
		keyvalue = '2' ;
	}
	if(keypad == 0xBB)
	{
		keyvalue = '3';
	}
	if(keypad == 0x7B)
	{
		keyvalue  = '-';
	}
	
	
	keypad = 0xF7;     //ROW =2
	
	if(keypad == 0xD7)
	{
		keyvalue = '0';
	}
	if(keypad == 0xE7)
	{
			keyvalue  = '%' ;
	}
	if(keypad == 0xB7)
	{
		keyvalue  = '=';
	}
	if(keypad == 0x77)
	{
			keyvalue  = '+';
	}
	return keyvalue;
}

void displayResult(int result)
	{
    char buffer[16]; // Assuming max displayable digits is 16

    // Convert integer to string
    sprintf(buffer, "%d", result);

    // Display the string
    lcdstr(buffer);
}
	
	

	
	
	


	
	