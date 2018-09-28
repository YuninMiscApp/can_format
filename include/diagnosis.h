/**
  ******************************************************************************
  * @file diagnosis.h 
  * @author leon.xie
  * @version v1.0.0
  * @date 2018-8-16 15:38:33
  * @brief This file contains all the functions prototypes for the BOARD 
  *  diagnosis 
  ******************************************************************************
  * @attention
  *
  * File For Autocruis Software Team Only
  *
  * Copyright (C), 2017-2027, Autocruis Software Team
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __DIAGNOSIS_H
#define __DIAGNOSIS_H

/* Includes ------------------------------------------------------------------*/

#include "types.h"

#ifdef  __cplusplus
extern "C" {
#endif

extern void log_assert(const char *source
   ,const char *expr
   ,const char *filename
   ,int linenr
   ,const char *fmt, ...);


#undef ASSERT
#define ASSERT(expr) if(!(expr)) log_assert(NULL,#expr,__FILE__, __LINE__,NULL)

#undef ASSERT_ERRNO
#define ASSERT_ERRNO(expr,errno) if(!(expr)) log_assert(NULL,#expr,__FILE__, __LINE__,"with errno: %f(%d,%x)",(float)errno,errno,errno)


#define RETURN_IF_FAIL(expr)  ({ \
    if(!(expr)) \
    {\
        ASSERT(expr); \
        return; \
    }\
})

#define RETURN_VAL_IF_FAIL(expr,val)  ({ \
        if(!(expr)) \
        {\
            ASSERT(expr); \
            return (val); \
        }\
    })

#define RETURN_VAL_IF_FAIL_WITH_ERRNO(expr,val,errno)  ({ \
        if(!(expr)) \
        {\
            ASSERT_ERRNO(expr,errno); \
            return (val); \
        }\
    })


#define CONTINUE_IF_FAIL(expr)  ({ \
	if(!(expr)) \
	{\
		ASSERT(expr); \
		continue; \
	}\
})


#define GOTO_LABEL_IF_FAIL(expr,label)  ({ \
        if(!(expr)) \
        {\
            ASSERT(expr); \
            goto label; \
        }\
    })

#define GOTO_LABEL_IF_FAIL_WITH_ERRNO(expr,label,errno)  ({ \
        if(!(expr)) \
        {\
            ASSERT_ERRNO(expr,errno); \
            goto label; \
        }\
    })



#ifdef  __cplusplus
}
#endif

#endif  /* __DIAGNOSIS_H */


