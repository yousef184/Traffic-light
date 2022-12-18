/*
 * timer.c
 *
 * Created: 11/14/2022 9:26:56 PM
 *  Author: YousefElsayed
 */ 
#include "timer.h"
#include <math.h>

#define READ_BIT(REG,NUM) ((REG&(1<<NUM))>>NUM)
#define SET_BIT(REG,NUM) REG|=(1<<NUM)

void timer_init(){
	TCCR0 = 0x00; //normal mode
}
void timer_delay(uint16_t millisec){
	uint16_t Noverflows,TimerInitial;
	double Tmaxdelay,Ttick;
	uint32_t overFlowcnt=0;
	Ttick = 256.0/1000.0;
	Tmaxdelay= 65.536; 
	if(millisec<Tmaxdelay){
		TimerInitial = (Tmaxdelay-millisec)/Ttick;
		Noverflows = 1;
		
		}else if(millisec == (int)Tmaxdelay){
		TimerInitial=0;
		Noverflows=1;
		}else{
		Noverflows = ceil((double)millisec/Tmaxdelay);
		TimerInitial = (1<<8) - ((double)millisec/Ttick)/Noverflows;
		
	}
	TCNT0 = TimerInitial;
	TCCR0 |= (1<<2); 
	while(overFlowcnt<Noverflows){
		while(READ_BIT(TIFR,0)==0);
		SET_BIT(TIFR,0);
		overFlowcnt++;
	}
	//Timer stop
	TCCR0 = 0x00;
}