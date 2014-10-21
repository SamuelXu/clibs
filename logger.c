/**
# -*- coding:UTF-8 -*-
*/

#include <ctype.h>
#include <stdio.h>
#include "logger.h"
#include "string_utility.h"

#ifdef __cplusplus
extern "C" 
{
#endif

static Logger _default_logger = {STDOUT_FILENO, LOGGER_ALL, 0, 0, "", 0, 0};

Logger* default_logger = &_default_logger;

#define	LOG_FILE_NAME_FORMAT(file,name,num)	snprintf(file, sizeof(file), "%s.%d", name, num);


time_t last_logger_time = 0;
char logger_time_string_buffer[24];
void logger_update_time_string()
{
	struct tm _lg_tm;
	time_t _lg_t = time(NULL);
	if (_lg_t != last_logger_time)
	{
		last_logger_time = _lg_t;
		localtime_r(&_lg_t, &_lg_tm);
		sprintf(logger_time_string_buffer, "[%04u-%02u-%02u %02u:%02u:%02u]", _lg_tm.tm_year + 1900, _lg_tm.tm_mon + 1, _lg_tm.tm_mday, _lg_tm.tm_hour, _lg_tm.tm_min, _lg_tm.tm_sec);
	}
}

int32_t logger_impl(/*const */Logger* self, const char* buf, uint32_t l)
{
	return write(self->fd, buf, l);
}

#ifdef __cplusplus
}

#endif

