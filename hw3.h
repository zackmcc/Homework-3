/*
 * Name: Zackary McClamma
 * Course: ECE 532
 * Assignment: Homework 3
 * Date: 14 OCT 2019
 * File: hw3.h
 *
 * */

#ifndef HW3_H_
#define HW3_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/alt_irq.h>
#include <sys/alt_timestamp.h>
#include <time.h>
#include "system.h"

#define _250_MS_TICKS 11500000

#define TIMER_IRQ 2

typedef struct str_timer_regs{
	unsigned int status;
	unsigned int control;
	unsigned int periodl;
	unsigned int periodh;
	unsigned int snapl;
	unsigned int snaph;
}timer_regs;

int frame = 0;
int display_values[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x00, 0x98};
int display_counter[] = {0,0,0,0,0,0,0,0};
int* display[] = {DISPLAY1_BASE, DISPLAY2_BASE, DISPLAY3_BASE,
		  	  	  DISPLAY4_BASE, DISPLAY5_BASE, DISPLAY6_BASE,
		  	  	  DISPLAY7_BASE, DISPLAY8_BASE};

void increment(int idx);
void decrement(int idx);
void timer_isr(void);
int checkSwitch(int swtch);


#endif /* HW3_H_ */
