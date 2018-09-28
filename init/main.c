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

/*
 ./can_app auto
 ./can_app manual m2u  0x0000E0ffff030000 45 21 //最终结果 0x1fffff
 ./can_app manual i2u  0x0000E0ffff030000 16 32 //最终结果 0xe0ffff03
 ./can_app manual u2m  0x1fffff 45 21			//最终结果 0xe0ffff030000
 ./can_app manual u2i  0x1fffff 16 21			//最终结果 0x1fffff0000
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

static int __can_format_auto(void)
{
	int i;
    UINT64 canData;
    UINT32 startBit;
    UINT32 bitLen;
    UINT64 result = 0;

    //Motorola2UserData 测试一
    result = 0;
    printf(PURPLE"=========================== Motorola2UserData Test1 ===========================\n"NONE);
    canData = MAX_CAN_FORMAT_DATA0;
    startBit = 45;
    bitLen = 21;
	for(i = 0;i < 21;i++)
	{
 		printf(GREEN"Input: canData=0x%llx,startBit=%u,bitLen=%u\n"NONE,canData,startBit,bitLen);
		RETURN_VAL_IF_FAIL(0 == can_format_motorola2userdata(canData,startBit,bitLen,&result),-1);
		printf(YELLOW"Output: result=0x%llx\n"NONE,result);	
		bitLen--;
	}
    //Motorola2UserData 测试二
    result = 0;
    printf(PURPLE"=========================== Motorola2UserData Test2 ===========================\n"NONE);
    canData = MAX_CAN_FORMAT_DATA1;
    startBit = 40;
    bitLen = 32;
	for(i = 0;i < 32;i++)
	{
 		printf(GREEN"Input: canData=0x%llx,startBit=%u,bitLen=%u\n"NONE,canData,startBit,bitLen);
		RETURN_VAL_IF_FAIL(0 == can_format_motorola2userdata(canData,startBit,bitLen,&result),-1);
		printf(YELLOW"Output: result=0x%llx\n"NONE,result);	
		bitLen--;
	}
	
    //Intel2UserData 测试一
    result = 0;
    printf(PURPLE"=========================== Intel2UserData Test1 ===========================\n"NONE);
    canData = MAX_CAN_FORMAT_DATA0;
    startBit = 16;
    bitLen = 32;
	for(i = 0;i < 32;i++)
	{
 		printf(GREEN"Input: canData=0x%llx,startBit=%u,bitLen=%u\n"NONE,canData,startBit,bitLen);
		RETURN_VAL_IF_FAIL(0 == can_format_intel2userdata(canData,startBit,bitLen,&result),-1);
		printf(YELLOW"Output: result=0x%llx\n"NONE,result);	
		bitLen--;
	}
    //Intel2UserData 测试二
    result = 0;
    printf(PURPLE"=========================== Intel2UserData Test2 ===========================\n"NONE);
    canData = MAX_CAN_FORMAT_DATA1;
    startBit = 16;
    bitLen = 32;
	for(i = 0;i < 32;i++)
	{
 		printf(GREEN"Input: canData=0x%llx,startBit=%u,bitLen=%u\n"NONE,canData,startBit,bitLen);
		RETURN_VAL_IF_FAIL(0 == can_format_intel2userdata(canData,startBit,bitLen,&result),-1);
		printf(YELLOW"Output: result=0x%llx\n"NONE,result);	
		bitLen--;
	}

    //UserData2Motorola 测试一
    result = 0;
    printf(PURPLE"=========================== UserData2Motorola Test1 ===========================\n"NONE);
    canData = 0x1fffff;
    startBit = 45;
    bitLen = 21;
	printf(GREEN"Input: canData=0x%llx,startBit=%u,bitLen=%u\n"NONE,canData,startBit,bitLen);
	RETURN_VAL_IF_FAIL(0 == can_format_userdata2motorola(canData,startBit,bitLen,&result),-1);
	printf(YELLOW"Output: result=0x%llx\n"NONE,result);	
	//
    canData = 0xff;
    startBit = 18;
    bitLen = 8;
	printf(GREEN"Input: canData=0x%llx,startBit=%u,bitLen=%u\n"NONE,canData,startBit,bitLen);
	RETURN_VAL_IF_FAIL(0 == can_format_userdata2motorola(canData,startBit,bitLen,&result),-1);
	printf(YELLOW"Output: result=0x%llx\n"NONE,result);	
	
    //UserData2Motorola 测试二
    result = 0;
    printf(PURPLE"=========================== UserData2Motorola Test2 ===========================\n"NONE);
    canData = 0xaaaa5555;
    startBit = 40;
    bitLen = 32;
	printf(GREEN"Input: canData=0x%llx,startBit=%u,bitLen=%u\n"NONE,canData,startBit,bitLen);
	RETURN_VAL_IF_FAIL(0 == can_format_userdata2motorola(canData,startBit,bitLen,&result),-1);
	printf(YELLOW"Output: result=0x%llx\n"NONE,result);	

    //UserData2Motorola 测试一
    result = 0;
    printf(PURPLE"=========================== UserData2Intel Test1 ===========================\n"NONE);
    canData = 0x1fffff;
    startBit = 16;
    bitLen = 21;
	printf(GREEN"Input: canData=0x%llx,startBit=%u,bitLen=%u\n"NONE,canData,startBit,bitLen);
	RETURN_VAL_IF_FAIL(0 == can_format_userdata2intel(canData,startBit,bitLen,&result),-1);
	printf(YELLOW"Output: result=0x%llx\n"NONE,result);	
	
    canData = 0xAA55;
    startBit = 0;
    bitLen = 16;
	printf(GREEN"Input: canData=0x%llx,startBit=%u,bitLen=%u\n"NONE,canData,startBit,bitLen);
	RETURN_VAL_IF_FAIL(0 == can_format_userdata2intel(canData,startBit,bitLen,&result),-1);
	printf(YELLOW"Output: result=0x%llx\n"NONE,result);	
	
	return 0;
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
	    if (argc < 6)
	    {
	        fprintf(stderr, RED"Usage: %s manual <type> <can_data> <start_bit> <bit_len>\n"NONE, argv[0]);
	        fprintf(stderr, RED"type: <m2u/i2u/u2m/u2i>\n"NONE);
	        exit(EXIT_FAILURE);
	    }
	    UINT64 canData;
	    UINT32 startBit;
	    UINT32 bitLen;
	    UINT64 result = 0;
	    const char *type = NULL;
	    type = argv[2];
	    RETURN_VAL_IF_FAIL(1 == sscanf(argv[3],"0x%llx",&canData), -1);
	    RETURN_VAL_IF_FAIL(1 == sscanf(argv[4],"%u",&startBit), -1);
	    RETURN_VAL_IF_FAIL(1 == sscanf(argv[5],"%u",&bitLen), -1);
	    
	    printf(GREEN"Input: type=%s,canData=0x%llx,startBit=%u,bitLen=%u\n"NONE,
	    type,canData,startBit,bitLen);

	    if(0 == strncmp(type,"m2u",strlen("m2u")))
		{
			RETURN_VAL_IF_FAIL(0 == can_format_motorola2userdata(canData,startBit,bitLen,&result),-1);
		}
		else if(0 == strncmp(type,"i2u",strlen("i2u")))
		{
			RETURN_VAL_IF_FAIL(0 == can_format_intel2userdata(canData,startBit,bitLen,&result),-1);
		}
		else if(0 == strncmp(type,"u2m",strlen("u2m")))
		{
			RETURN_VAL_IF_FAIL(0 == can_format_userdata2motorola(canData,startBit,bitLen,&result),-1);
		}
		else if(0 == strncmp(type,"u2i",strlen("u2i")))
		{
			RETURN_VAL_IF_FAIL(0 == can_format_userdata2intel(canData,startBit,bitLen,&result),-1);
		}
		else
		{
	        fprintf(stderr, RED"unknow type... please use type: <m2u/i2u/u2m/u2i>\n"NONE);
	        return -1;
		}
		
		printf(YELLOW"Output: result=0x%llx\n"NONE,result);
	}
	else
	{
        fprintf(stderr, RED"unknow cmd..., please use cmd: <auto/manual>\n"NONE);
        return -1;
	}
	
	return 0;
}

#ifdef  __cplusplus
}
#endif


