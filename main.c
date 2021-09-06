/*
 * Name: Zackary McClamma
 * Course: ECE 532
 * Assignment: Homework 3
 * Date: 14 OCT 2019
 * File: main.c
 *
 * */

#include "hw3.h"

int main()
{
  for (int i = 0; i < 8; i++)
  {
	  *display[i] = display_values[0];
  }

  printf("Hello from Nios II!\n");
  timer_regs *timerPtr = TIMER_0_BASE;

  printf("Registering interrupt...\n");
  alt_ic_isr_register(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_0_IRQ, (void*)timer_isr, NULL, NULL);
  alt_ic_irq_enable(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_0_IRQ);

  printf("Setting timeout period...\n");
  timerPtr->periodl = (_250_MS_TICKS & 0x0000FFFF);
  timerPtr->periodh = (_250_MS_TICKS >> 16);

  printf("Enabling interrupt...\n");
  timerPtr->control = 0x07;

  while(1)
  {
  }
  return 0;
}

void increment(int idx)
{
	display_counter[idx]++;
	if(display_counter[idx] > 9)
		display_counter[idx] = 0;
	*display[idx] = display_values[display_counter[idx]];
}

void decrement (int idx)
{
	display_counter[idx]--;
	if(display_counter[idx] < 0)
		display_counter[idx] = 9;
	*display[idx] = display_values[display_counter[idx]];
}

int checkSwitch(int swtch)
{
	clock_t start = clock();
	clock_t end;
	int elapsed_msec;
	int* base = SWITCHES_BASE;

	//Check switch state
	if(*base & (1 << (swtch)))
	{
		increment(swtch);
	}
	else
	{
		decrement(swtch);
	}

	//Ensure task runs for the full duration
	end = clock();
	elapsed_msec = (end - start)/CLOCKS_PER_SEC;
	switch(swtch)
	{
	case 0:
		if(elapsed_msec < 1000)
		{
			usleep(1000 - elapsed_msec);
		}
		return(1);
	case 1:
		if(elapsed_msec < 1000)
			usleep(1000 - elapsed_msec);
		return(1);
	case 2:
		if(elapsed_msec < 1000)
			usleep(1000 - elapsed_msec);
		return(1);
	case 3:
		if(elapsed_msec < 1000)
			usleep(1000 - elapsed_msec);
		return(1);
	case 4:
		if(elapsed_msec < 500)
			usleep(500 - elapsed_msec);
		return(1);
	case 5:
		if(elapsed_msec < 500)
			usleep(500 - elapsed_msec);
		return(1);
	case 6:
		if(elapsed_msec < 500)
			usleep(500 - elapsed_msec);
		return(1);
	case 7:
		if(elapsed_msec < 500)
			usleep(500 - elapsed_msec);
		return(1);
	}
	return(1);
}

void timer_isr(void)
{
	timer_regs *timerPtr = TIMER_0_BASE;

	  switch(frame)
	  {
		  case 0:
			  checkSwitch(0);
			  checkSwitch(1);
			  checkSwitch(2);
			  checkSwitch(3);
			  checkSwitch(6);
			  break;
		  case 1:
			  checkSwitch(0);
			  checkSwitch(1);
			  checkSwitch(4);
			  checkSwitch(5);
			  checkSwitch(7);
			  break;
		  case 2:
			  checkSwitch(0);
			  checkSwitch(1);
			  checkSwitch(2);
			  checkSwitch(3);
			  break;
		  case 3:
			  checkSwitch(0);
			  checkSwitch(1);
			  checkSwitch(4);
			  checkSwitch(5);
			  break;
	  }
	  frame++;
	  if(frame == 4)
		  frame = 0;

	timerPtr->status = 0x01;

}
