#include<stdio.h>
#include "Status.h"

Boolean debug = FALSE;

/*
 * 按下回车继续运行代码
 */
void PressEnterToContinue(Boolean debug){
	fflush(stdin);
	
	if(debug){
		printf("\nPress Enter to Continue...");
		getchar();
	} else {
		printf("\n");
	}
	fflush(stdin);
}

/**
 * 让函数暂停一段时间
 */
void Wait(long time){
	double i;
	
	if(time < 0){
		time = -time;
	}
	for(i = 0.01; i<100000.0 * time; i+= 0.01){
	}
}
