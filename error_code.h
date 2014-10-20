/**
# -*- coding:UTF-8 -*-
*/

#ifndef _ERROR_CODE_H_
#define _ERROR_CODE_H_

#include <errno.h>

/**
 * 0表示成功
 * linux系统错误码：0~255
 * windows系统错误码:0~20000
*/

enum ERRORCODE
{
SUCCESS = 0,

ERRCODE_BASE = 100000,
ERR_INVALID_REQUEST,
ERR_INVALID_PARAMETER,
ERR_INVALID_PATH,
ERR_INVALID_NAME,
ERR_BAD_READ,
ERR_BAD_WRITE,
ERR_NOT_FOUND,
ERR_TOO_LONG,
ERR_TOO_MANY,
ERR_NOT_ENOUGH_BUFFER,
ERR_BAD_ALLOC,
ERR_PROTOCOL,
ERR_INCOMPLETE,
};

#endif
