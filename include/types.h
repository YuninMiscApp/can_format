/**
  ******************************************************************************
  * @file types.h 
  * @author leon.xie
  * @version v1.0.0
  * @date 2018-8-16 9:33:51
  * @brief This file contains all the functions prototypes for the BOARD 
  *  types 
  ******************************************************************************
  * @attention
  *
  * File For Autocruis Software Team Only
  *
  * Copyright (C), 2017-2027, Autocruis Software Team
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __TYPES_H
#define __TYPES_H

/* Includes ------------------------------------------------------------------*/


#ifdef  __cplusplus
extern "C" {
#endif

typedef   double              FLOAT64;
typedef   float               FLOAT32;
typedef signed int            INT32;
typedef signed short          INT16;
typedef signed char           INT8;
typedef unsigned int          UINT32;
typedef unsigned short        UINT16;
typedef unsigned char         UINT8;
typedef signed long long 	  INT64;
typedef unsigned long long	  UINT64;

#undef SUCCESS
#define SUCCESS 0

#undef FAIL
#define FAIL -1



#ifdef  __cplusplus
}
#endif

#endif  /* __TYPES_H */


