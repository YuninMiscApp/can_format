/**
  ******************************************************************************
  * @file can.h 
  * @author leon.xie
  * @version v1.0.0
  * @date 2018-9-28 10:37:49
  * @brief This file contains all the functions prototypes for the BOARD 
  *  can 
  ******************************************************************************
  * @attention
  *
  * File For Autocruis Software Team Only
  *
  * Copyright (C), 2017-2027, Autocruis Software Team
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __CAN_H
#define __CAN_H

/* Includes ------------------------------------------------------------------*/
#include "types.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* Exported typedef ----------------------------------------------------------*/


/* Exported variables --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
int can_format_motorola2userdata(UINT64 srcData,UINT8 startBit,
	UINT32 bitLen,UINT64 *dstDataOutput);
int can_format_intel2userdata(UINT64 srcData,UINT8 startBit,
	UINT32 bitLen,UINT64 *dstDataOutput);
int can_format_userdata2motorola(UINT64 srcData,UINT8 startBit,
	UINT32 bitLen,UINT64 *dstDataInOut);
int can_format_userdata2intel(UINT64 srcData,UINT8 startBit,
	UINT32 bitLen,UINT64 *dstDataInOut);

#ifdef  __cplusplus
}
#endif

#endif  /* __CAN_H */


