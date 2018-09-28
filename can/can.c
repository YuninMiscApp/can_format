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
#include "diagnosis.h"
#include "util.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* Private typedef -----------------------------------------------------------*/
typedef union {
    UINT64 data;
    UINT8 buf[8];
}can_data_format_u;

/* Private macro -------------------------------------------------------------*/
#define CAN_FORMAT_START_BIT_M2I(sb) ((sb)%8 + (7 - (sb)/8)*8)
#define CAN_FORMAT_START_BIT_I2M(sb) CAN_FORMAT_START_BIT_M2I(sb)
/* Private variables ---------------------------------------------------------*/
#define CAN_DEBUG(args...)	printf(args)
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/***************************************************
 * Function : can_format_motorola2userdata
 * Author : leon.xie
 * Creat Date : 2018/09/28  10:44:22
 * Description : none
 * In-Parameter : as below
 * Return : as below
 * Modify : none
 **************************************************/
int can_format_motorola2userdata(UINT64 srcData,UINT8 startBit,
	UINT32 bitLen,UINT64 *dstDataOutput)
{
	RETURN_VAL_IF_FAIL(dstDataOutput, -1);
	RETURN_VAL_IF_FAIL(bitLen > 0 && bitLen <= 64, -1);
	RETURN_VAL_IF_FAIL(startBit < 64, -1);
	
	UINT8 intelStartBit = 0;
	int i;
	UINT64 mask = 0;
	UINT64 result = 0;
	can_data_format_u canDataFormat;
	UINT8 maxBitLen = 0;
	
	//检查非法输入条件
	maxBitLen = (8*(startBit/8)+(8 - startBit%8));
	RETURN_VAL_IF_FAIL(bitLen <= maxBitLen, -1);
	// 1. 转换起始位.
	intelStartBit = CAN_FORMAT_START_BIT_M2I(startBit);
	// 2. 逆序字节序.
	canDataFormat.data = srcData;
	for(i = 0;i < 4;i++)
	{
		byte_swap(&canDataFormat.buf[i],&canDataFormat.buf[7-i]);
	}
	
	// 3. 提取数据
	for(i = 0;i < bitLen;i++)
	{
		mask |= 1 << i;
	}

	result = (canDataFormat.data >> intelStartBit) & mask;

	*dstDataOutput = result;
	CAN_DEBUG("[%s,%d]: srcData=0x%llx, startBit=%u, intelStartBit=%u, bitLen=%u, mask=0x%llx, result=0x%llx, dstDataOutput=0x%llx \n",
	__func__,__LINE__,srcData,startBit,intelStartBit,bitLen,mask,result,*dstDataOutput);
    return 0;
}

/***************************************************
 * Function : can_format_intel2userdata
 * Author : leon.xie
 * Creat Date : 2018/09/28  10:45:54
 * Description : none
 * In-Parameter : as below
 * Return : as below
 * Modify : none
 **************************************************/
int can_format_intel2userdata(UINT64 srcData,UINT8 startBit,
	UINT32 bitLen,UINT64 *dstDataOutput)
{
	RETURN_VAL_IF_FAIL(dstDataOutput, -1);
	RETURN_VAL_IF_FAIL((startBit+bitLen) <= 64, -1);
	
	int i;
	UINT64 mask = 0;
	UINT64 result = 0;

	for(i = 0;i < bitLen;i++)
	{
		mask |= 1 << i;
	}
	
	result = (srcData >> startBit) & mask;

	*dstDataOutput = result;
	CAN_DEBUG("[%s,%d]: srcData=0x%llx, startBit=%u, bitLen=%u, mask=0x%llx, result=0x%llx, dstDataOutput=0x%llx \n",
	__func__,__LINE__,srcData,startBit,bitLen,mask,result,*dstDataOutput);	
	
    return 0;
}


/***************************************************
 * Function : can_format_userdata2motorola
 * Author : leon.xie
 * Creat Date : 2018/09/28  13:56:17
 * Description : none
 * In-Parameter : as below
 * Return : as below
 * Modify : none
 **************************************************/
int can_format_userdata2motorola(UINT64 srcData,UINT8 startBit,
	UINT32 bitLen,UINT64 *dstDataInOut)
{
	RETURN_VAL_IF_FAIL(dstDataInOut, -1);
	RETURN_VAL_IF_FAIL(bitLen > 0 && bitLen <= 64, -1);
	RETURN_VAL_IF_FAIL(startBit < 64, -1);
	
	int i;
	UINT64 mask = 0;
	UINT64 result = *dstDataInOut;
	can_data_format_u canDataFormat;
	UINT8 maxBitLen = 0;
	
	//检查非法输入条件
	maxBitLen = (8*(startBit/8)+(8 - startBit%8));
	RETURN_VAL_IF_FAIL(bitLen <= maxBitLen, -1);
	//
	memset(&canDataFormat,0,sizeof(canDataFormat));
	
	for(i = 0;i < bitLen;i++)
	{
		mask |= 1 << i;
	}

	canDataFormat.data = (srcData & mask) << startBit;
	// 2. 逆序字节序.
	for(i = 0;i < 4;i++)
	{
		byte_swap(&canDataFormat.buf[i],&canDataFormat.buf[7-i]);
	}
	
	//
	result |= canDataFormat.data;
	*dstDataInOut = result;
	CAN_DEBUG("[%s,%d]: srcData=0x%llx, startBit=%u,  bitLen=%u, mask=0x%llx, result=0x%llx, dstDataInOut=0x%llx \n",
	__func__,__LINE__,srcData,startBit,bitLen,mask,result,*dstDataInOut);
    return 0;
}

/***************************************************
 * Function : can_format_userdata2intel
 * Author : leon.xie
 * Creat Date : 2018/09/28  13:57:2
 * Description : none
 * In-Parameter : as below
 * Return : as below
 * Modify : none
 **************************************************/
int can_format_userdata2intel(UINT64 srcData,UINT8 startBit,
	UINT32 bitLen,UINT64 *dstDataInOut)
{
	RETURN_VAL_IF_FAIL(dstDataInOut, -1);
	RETURN_VAL_IF_FAIL((startBit+bitLen) <= 64, -1);
	int i;
	UINT64 mask = 0;
	UINT64 result = *dstDataInOut;
	
	for(i = 0;i < bitLen;i++)
	{
		mask |= 1 << i;
	}

	result |= (srcData & mask) << startBit;
	*dstDataInOut = result;
	CAN_DEBUG("[%s,%d]: srcData=0x%llx, startBit=%u, bitLen=%u, mask=0x%llx, result=0x%llx, dstDataInOut=0x%llx \n",
	__func__,__LINE__,srcData,startBit,bitLen,mask,result,*dstDataInOut);	
    return 0;
}


#ifdef  __cplusplus
}
#endif


