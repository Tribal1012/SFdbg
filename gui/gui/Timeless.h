#pragma once
#ifndef __TIMELESS_H
#define __TIMELESS_H
#include <mysql.h>
#include <stdio.h>
#include <time.h>

#define DB_HOST "localhost" // �ּ�
#define DB_USER "root" // mysql user
#define DB_PASS "asdf1234" // mysql password
#define DB_NAME "temp" // mysql db �̸�

/* DB ��ɾ� */
/* database�� �̸� �����Ǿ� �־���� (connection�� ����) */
BOOL input_table(const CONTEXT context, const time_t timer);	/* Table �Է� */
BOOL search_table(char* string, DWORD value);					/* Table �˻� */
BOOL drop_table(void);
BOOL Init_DB(void);												/* DB ���� �� �ʱ�ȭ */
BOOL Destroy_DB(void);											/* DB ���� */
#endif