#ifndef _ENCODING_CVT_H_
#define _ENCODING_CVT_H_

#include "iconv.h" //depend on libiconv
#include <stdint.h>

//convert charset encoding among utf8, gbk and big5

/**
 *如果不能转换，返回-1，不对参数作任何改变
 *如果in已经是目标字符集，则将in复制到out
 *out不是C字符串(没有结尾的0)，必须保证其内存足够大
 */

/****************** thread unsafe *********************/
typedef struct s_encoding_cvt_t
{
	iconv_t gbk_to_utf8;
	iconv_t big5_to_utf8;
	iconv_t big5_to_gbk;
	iconv_t utf8_to_gbk;
	iconv_t gbk_to_big5;
	iconv_t utf8_to_big5;
}EncodingCvt;

int32_t encoding_cvt_initialize(EncodingCvt* self);
int32_t encoding_cvt_finalize(EncodingCvt* self);

typedef int32_t (*encoding_cvt_func_t)(EncodingCvt* self, const char* in, uint32_t in_len, char* out, uint32_t* out_len);

int32_t encoding_cvt_to_utf8(EncodingCvt* self, const char* in, uint32_t in_len, char* out, uint32_t* out_len);
int32_t encoding_cvt_to_gbk(EncodingCvt* self, const char* in, uint32_t in_len, char* out, uint32_t* out_len);
int32_t encoding_cvt_to_big5(EncodingCvt* self, const char* in, uint32_t in_len, char* out, uint32_t* out_len);

int32_t encoding_cvt_gbk_to_utf8(EncodingCvt* self, const char* in, uint32_t in_len, char* out, uint32_t* out_len);
int32_t encoding_cvt_big5_to_utf8(EncodingCvt* self, const char* in, uint32_t in_len, char* out, uint32_t* out_len);
int32_t encoding_cvt_utf8_to_gbk(EncodingCvt* self, const char* in, uint32_t in_len, char* out, uint32_t* out_len);
int32_t encoding_cvt_big5_to_gbk(EncodingCvt* self, const char* in, uint32_t in_len, char* out, uint32_t* out_len);
int32_t encoding_cvt_gbk_to_big5(EncodingCvt* self, const char* in, uint32_t in_len, char* out, uint32_t* out_len);
int32_t encoding_cvt_utf8_to_big5(EncodingCvt* self, const char* in, uint32_t in_len, char* out, uint32_t* out_len);


/********************* thread safe *********************/
typedef int32_t (*encoding_cvt_s_func_t)(const char* in, uint32_t in_len, char* out, uint32_t* out_len);

int32_t to_utf8_s(const char* in, uint32_t in_len, char* out, uint32_t* out_len);
int32_t to_gbk_s(const char* in, uint32_t in_len, char* out, uint32_t* out_len);
int32_t to_big5_s(const char* in, uint32_t in_len, char* out, uint32_t* out_len);

int32_t gbk_to_utf8_s(const char* in, uint32_t in_len, char* out, uint32_t* out_len);
int32_t big5_to_utf8_s(const char* in, uint32_t in_len, char* out, uint32_t* out_len);
int32_t utf8_to_gbk_s(const char* in, uint32_t in_len, char* out, uint32_t* out_len);
int32_t big5_to_gbk_s(const char* in, uint32_t in_len, char* out, uint32_t* out_len);
int32_t gbk_to_big5_s(const char* in, uint32_t in_len, char* out, uint32_t* out_len);
int32_t utf8_to_big5_s(const char* in, uint32_t in_len, char* out, uint32_t* out_len);


/*********************************************/
int32_t encoding_cvt_copy_input(const char* in, uint32_t in_len, char* out, uint32_t* out_len);


/**
 *将utf8序列转换为本机字节序的ucs4字符
 *如果endptr!=NULL，则指向原序列的下一个字符
 @return 成功返回ucs4字符，失败返回0
 */
uint32_t translate_utf8_char_to_ucs4(const char* s, const char** endptr);

#endif
