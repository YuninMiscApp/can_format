/**
  ******************************************************************************
  * @file util.c
  * @author  leon.xie
  * @version v1.0.0
  * @date 2018-9-28 11:24:21
  * @brief  This file provides all the util functions. 
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

#include <sched.h>
#include <sys/prctl.h>
#include <ctype.h>

#include "util.h"
#include "diagnosis.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void byte_swap(unsigned char *a, unsigned char *b)
{
	RETURN_IF_FAIL(a && b);
	unsigned char t = *a;
	*a = *b;
	*b = t;
}


void system_thread_get_name (const char *name)
{
#ifdef PR_GET_NAME
    prctl (PR_GET_NAME, name, 0, 0, 0, 0);
#endif
}

#ifdef  __cplusplus
}
#endif


