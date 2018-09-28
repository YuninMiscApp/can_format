/**
  ******************************************************************************
  * @file log.h 
  * @author leon.xie
  * @version v1.0.0
  * @date 2018-9-28 10:52:54
  * @brief This file contains all the functions prototypes for the BOARD 
  *  log 
  ******************************************************************************
  * @attention
  *
  * File For Autocruis Software Team Only
  *
  * Copyright (C), 2017-2027, Autocruis Software Team
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __LOG_H
#define __LOG_H

/* Includes ------------------------------------------------------------------*/


#ifdef  __cplusplus
extern "C" {
#endif

/* Exported typedef ----------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void log_assert(const char *source
				   ,const char *expr
				   ,const char *filename
				   ,int linenr
				   ,const char *fmt, ...);



#ifdef  __cplusplus
}
#endif

#endif  /* __LOG_H */


