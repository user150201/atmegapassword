#include <avr/io.h> 
#include<util/delay.h> 
void cmd(int); 
void data(char); 
void display(const char*); 
char key();
void main() 
{ 
    int i;
    char pass[]="1234",inp[]="0000",count;
    DDRD=0XFF; 
    DDRC=0XFF; 
    DDRB=0XFF;
    
    DDRA=0X0F; 
     
     
     
    cmd(0X38); 
    cmd(0X80); 
    cmd(0X01); 
    cmd(0X06); 
    cmd(0X0E); 
    
    
    display("Enter password");
    cmd(0XC0);
    
    for( i=0;i<4;i++)
    {
        inp[i]=key();
        data(inp[i]);
    }
    
    for(count=0;count<4;count++)
    {
        if(inp[count]!=pass[count])
        {
            break;
    }
    }
     
    if(count==4)
    {
        cmd(0X01);
        display("VALID PASSWORD");
        
        PORTB=0X02;
        _delay_ms(10000);
        PORTB=0X00;
        
        
        for(i=0;i<10;i++)
        {
        _delay_ms(100);
            cmd(0X08);
        
        _delay_ms(100);
        cmd(0X0E);
        }
    }
    else
    {
        cmd(0X01);
        display("INCORRET PASSWORD");
    }
    
} 
char key()
{
    while(1) 
    { 
      
       
      PORTA=0X0E;
     
    if((PINA&0X80)==0) 
        
     
    { 
         
         return('0'); 
         
         
    } 
     
    else if((PINA&0X40)==0) 
    { 
         
         
         data('9'); 
          
          
          
    } 
     
    else if((PINA&0X20)==0) 
    { 
         
          
         return('8'); 
         
          
          
    } 
    
       else if((PINA&0X10)==0) 
    { 
         
          
         return('7'); 
         
          
          
    } 
     
     
     
     
      PORTA=0X0D;
     
     if((PINA&0X80)==0) 
        
     
    { 
         
         return('4'); 
         
         
    } 
     
    else if((PINA&0X40)==0) 
    { 
         
         
         return('6'); 
          
          
          
    } 
     
    else if((PINA&0X20)==0) 
    { 
         
          
         return('5'); 
         
          
          
    } 
    
       else if((PINA&0X10)==0) 
    { 
         
          
         return('4'); 
         
          
          
    } 
     
     
     
     
      PORTA=0X0B;
     
     if((PINA&0X80)==0) 
        
     
    { 
         
         return('8'); 
         
         
    } 
     
    else if((PINA&0X40)==0) 
    { 
         
         
         return('3'); 
          
          
          
    } 
     
    else if((PINA&0X20)==0) 
    { 
         
          
         return('2'); 
         
          
          
    } 
    
       else if((PINA&0X10)==0) 
    { 
         
          
         return('1'); 
         
          
          
    } 
     
     
     
      PORTA=0X07;
     if((PINA&0X88)==0) 
        
     
    { 
         
         return('C'); 
         
         
    } 
     
    else if((PINA&0X48)==0) 
    { 
         
         
         return('#'); 
          
          
          
    } 
     
    else if((PINA&0X28)==0) 
    { 
         
          
         return('0'); 
         
          
          
    } 
    
       else if((PINA&0X18)==0) 
    { 
         
          
         return('*'); 
         
          
          
    } 
     
     
     
     
     
     
        
    } 
}
void cmd(int a) 
{ 
    PORTD=a; 
    PORTC=0X02; 
     
    _delay_ms(1); 
    PORTC=0X00; 
     _delay_ms(3); 
     
} 
void data(char b) 
{ 
    PORTD=b; 
    PORTC=0X03; 
     
    _delay_ms(1); 
   PORTC=0X01; 
    _delay_ms(3); 
    while((PINA&0XF0)!=0XF0);
   
        
} 

void display(const char*p) 
{ 
    while(*p) 
         
    { 
        data(*p); 
        p++; 
    } 
}