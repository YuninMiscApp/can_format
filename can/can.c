/**
  ******************************************************************************
  * @file can.c
  * @author  leon.xie
  * @version v1.0.0
  * @date 2018-9-28 10:37:46
  * @brief  This file provides all the can functions. 
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

#include "can.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/***************************************************
 * Function : can_format_motorola2intel
 * Author : leon.xie
 * Creat Date : 2018/09/28  10:44:22
 * Description : none
 * In-Parameter : as below
 * Return : as below
 * Modify : none
 **************************************************/
int can_format_motorola2intel(UINT64 srcData,UINT8 startBit,
	UINT32 bitLen,UINT64 *dstDataOutput)
{
	
    return 0;
}

/***************************************************
 * Function : can_format_intel2motorola
 * Author : leon.xie
 * Creat Date : 2018/09/28  10:45:54
 * Description : none
 * In-Parameter : as below
 * Return : as below
 * Modify : none
 **************************************************/
int can_format_intel2motorola(UINT64 srcData,UINT8 startBit,
	UINT32 bitLen,UINT64 *dstDataOutput)
{
    return 0;
}



#ifdef  __cplusplus
}
#endif


