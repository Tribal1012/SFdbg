#pragma once
#ifndef __TIMELESS_H
#define __TIMELESS_H
#include <mysql.h>
#include <stdio.h>
#include <time.h>

#define DB_HOST "localhost" // 주소
#define DB_USER "root" // mysql user
#define DB_PASS "asdf1234" // mysql password
#define DB_NAME "temp" // mysql db 이름

/* DB 명령어 */
/* database는 미리 생성되어 있어야함 (connection을 위해) */
BOOL input_table(const CONTEXT context, const time_t timer);	/* Table 입력 */
BOOL search_table(char* string, DWORD value);					/* Table 검색 */
BOOL drop_table(void);
BOOL Init_DB(void);												/* DB 생성 및 초기화 */
BOOL Destroy_DB(void);											/* DB 정리 */
#endif