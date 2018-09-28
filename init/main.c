/**
  ******************************************************************************
  * @file main.c
  * @author  leon.xie
  * @version v1.0.0
  * @date 2018-9-28 10:37:37
  * @brief  This file provides all the main functions. 
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
#include "diagnosis.h"
#include "types.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
#define MAX_CAN_FORMAT_DATA0 0x0000E0ffff030000
#define MAX_CAN_FORMAT_DATA1 0x00005555AAAA0000

/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

static void __can_format_auto(void)
{
	int i;
    UINT64 canData;
    UINT32 startBit;
    UINT32 bitLen;
    UINT64 result = 0;

    //测试一
    printf(PURPLE"=========================== Test1 ===========================\n"NONE);
    canData = MAX_CAN_FORMAT_DATA0;
    startBit = 45;
    bitLen = 21;
	for(i = 0;i < 21;i++)
	{
 		printf(GREEN"Input: canData=0x%llx,startBit=%u,bitLen=%u\n"NONE,canData,startBit,bitLen);
		can_format_motorola2userdata(canData,startBit,bitLen,&result);
		printf(YELLOW"Output: result=0x%llx\n"NONE,result);	
		bitLen--;
	}
    //测试二
    printf(PURPLE"=========================== Test2 ===========================\n"NONE);
    canData = MAX_CAN_FORMAT_DATA1;
    startBit = 40;
    bitLen = 32;
	for(i = 0;i < 32;i++)
	{
 		printf(GREEN"Input: canData=0x%llx,startBit=%u,bitLen=%u\n"NONE,canData,startBit,bitLen);
		can_format_motorola2userdata(canData,startBit,bitLen,&result);
		printf(YELLOW"Output: result=0x%llx\n"NONE,result);	
		bitLen--;
	}

}

//-----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    char *cmdName = NULL;
	
    if (argc < 2)
    {
        fprintf(stderr, RED"Usage: %s <cmd>\n"NONE, argv[0]);
        fprintf(stderr, RED"cmd: <auto/manual>\n"NONE);
        exit(EXIT_FAILURE);
    }
    cmdName = argv[1];
    RETURN_VAL_IF_FAIL(cmdName,-1);
    
	if(0 == strncmp(cmdName,"auto",strlen("auto")))
	{
		__can_format_auto();
	}
	else if(0 == strncmp(cmdName,"manual",strlen("manual")))
	{
	    if (argc < 5)
	    {
	        fprintf(stderr, RED"Usage: %s manual <can_data> <start_bit> <bit_len>\n"NONE, argv[0]);
	        exit(EXIT_FAILURE);
	    }
	    UINT64 canData;
	    UINT32 startBit;
	    UINT32 bitLen;
	    UINT64 result = 0;
	    RETURN_VAL_IF_FAIL(1 == sscanf(argv[2],"0x%llx",&canData), -1);
	    RETURN_VAL_IF_FAIL(1 == sscanf(argv[3],"%u",&startBit), -1);
	    RETURN_VAL_IF_FAIL(1 == sscanf(argv[4],"%u",&bitLen), -1);
	    printf(GREEN"Input: canData=0x%llx,startBit=%u,bitLen=%u\n"NONE,canData,startBit,bitLen);
		can_format_motorola2userdata(canData,startBit,bitLen,&result);
		printf(YELLOW"Output: result=0x%llx\n"NONE,result);
	}
	else
	{
        fprintf(stderr, RED"unknow cmd...\n"NONE);
	}
	
	return 0;
}

#ifdef  __cplusplus
}
#endif


