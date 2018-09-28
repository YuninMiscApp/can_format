/**
  ******************************************************************************
  * @file log.c
  * @author  leon.xie
  * @version v1.0.0
  * @date 2018-9-28 10:52:33
  * @brief  This file provides all the log functions. 
  ******************************************************************************
  * @attention
  *
  * File For Autocruis Software Team Only
  *
  * Copyright (C), 2017-2027, Autocruis Software Team
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <pthread.h>

#include "log.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
#undef NONE
#define NONE  "\e[0m"
#undef RED
#define RED   "\e[0;31m"

/***************************************************
 * Function : log_assert
 * Author : leon.xie
 * Creat Date : 2018/09/19  10:52:27
 * Description : none
 * In-Parameter : as below
 * Return : as below
 * Modify : none
 **************************************************/
void log_assert(const char *source
				   ,const char *expr
				   ,const char *filename
				   ,int linenr
				   ,const char *fmt, ...)
{
	char _log_buffer[1024*8] = {0};
	char threadName[256] = {0};
	int len = 0;
	const char *colour = NULL;
		
	colour = RED;

	len += snprintf(_log_buffer+len,sizeof(_log_buffer)-len,"%s(%s): assertion failed %s: %d: %s "
	,colour?colour:""
	,source ? source : threadName,
	filename, linenr, expr?expr:"");
	
	//
	va_list args;
	va_start(args, fmt);
	len += vsnprintf(_log_buffer+len,sizeof(_log_buffer)-len,fmt, args);
	va_end(args);
	
	//
	len += snprintf(_log_buffer+len,sizeof(_log_buffer)-len,"%s\n",colour?NONE:"");
	//
	_log_buffer[sizeof(_log_buffer)-1] = 0;
    //output
	printf(_log_buffer);
	
}

#ifdef  __cplusplus
}
#endif


