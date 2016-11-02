#include "stdafx.h"
#include "Timeless.h"

MYSQL *pg_conn; // MYSQL과 연결 담당
MYSQL_RES *pg_res; // 쿼리에 대한 결과를 받는 함수
MYSQL_ROW g_row; // 쿼리에 대한 실제 데이터 값이 들어 있는 변수
int g_query_stat; // 쿼리 리턴값 저장
char g_query[255]; // 실행할 쿼리
int g_i;

/* DB 명령어 */
/* database는 미리 생성되어 있어야함 (connection을 위해) */
/* Table 입력 */
BOOL input_table(const CONTEXT context, const time_t timer)
{
    /* send SQL g_query */
	/* mysql_g_query() 실행 후 반환값이 0이어야 성공 */

	/* 레코드 삽입 */
	sprintf(g_query, "insert into temp values('%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d')", timer, context.Eax, context.Ebx, context.Ecx, context.Edx, context.Ebp, context.Esp, context.Esi, context.Edi, context.Eip, context.EFlags);
	g_query_stat = mysql_query(pg_conn, g_query);
	if (g_query_stat !=0)
	{
        fprintf(stderr, "%s\n", mysql_error(pg_conn));
        return FALSE;
    }

	return TRUE;
}

/* Table 검색 */
BOOL search_table(char* string, DWORD value)
{
	if(string == NULL) {
		sprintf(g_query, "select * from temp");
		g_query_stat = mysql_query(pg_conn, g_query);
		if (g_query_stat !=0)
		{
			fprintf(stderr, "%s\n", mysql_error(pg_conn));
			return FALSE;
		}
	}
	else {
		sprintf(g_query, "select * from temp where %s=%08x", string, value);		//음..
		g_query_stat = mysql_query(pg_conn, g_query);
		if (g_query_stat !=0)
		{
			fprintf(stderr, "%s\n", mysql_error(pg_conn));
			return FALSE;
		}
	}

    pg_res = mysql_store_result(pg_conn); // 저장된 결과 값을 MYSQL_RES에 저장

	while ((g_row = mysql_fetch_row(pg_res)) != NULL) // ROW 1씩 얻어옴
	{
		printf("| %10s |\n", g_row[0]);
		for(g_i=1;g_i<=10;g_i++)
		{
			printf(" %10s |\b", g_row[g_i]);
		}
		printf("\n");
	}

	return TRUE;
}

BOOL drop_table(void)
{
	sprintf(g_query, "delete from temp"); // Table 이름 temp
	g_query_stat = mysql_query(pg_conn, g_query);
	if (g_query_stat !=0)
	{
        fprintf(stderr, "%s\n", mysql_error(pg_conn));
        return FALSE;
    }

	sprintf(g_query, "drop table temp"); // Table 이름 temp
	g_query_stat = mysql_query(pg_conn, g_query);
	if (g_query_stat !=0)
	{
        fprintf(stderr, "%s\n", mysql_error(pg_conn));
		return FALSE;
    }

	return TRUE;
}
/* DB 생성 및 초기화 */
BOOL Init_DB(void) {
	 /* 처음 시작 */
     pg_conn = mysql_init(NULL); // 초기화

     /* pg_connect to database */
     if (!mysql_real_connect(pg_conn, DB_HOST,
         DB_USER,
		 DB_PASS,
		 DB_NAME,
		 3306, NULL, 0))
	 {
        fprintf(stderr, "%s\n", mysql_error(pg_conn));
        return FALSE;
     }

	 /* 데이터 베이스 선택 */
	 if(mysql_select_db(pg_conn, DB_NAME))
	 {
		fprintf(stderr, "%s\n", mysql_error(pg_conn));
		return FALSE;
	 }

	 /* Table 이름 temp(count), record 형식 int */
	sprintf(g_query, "create table temp(Time int, EAX int, EBX int, ECX int, EDX int, EBP int, ESP int, ESI int, EDI int, EIP int, FLAG int)");
	g_query_stat = mysql_query(pg_conn, g_query);
	if (g_query_stat !=0)
	{
        fprintf(stderr, "%s\n", mysql_error(pg_conn));
        return FALSE;
    }

	 return TRUE;
}

/* DB 정리 */
BOOL Destroy_DB(void) {
	 if(!drop_table()) // Table 삭제
		 return FALSE;

    /* close pg_connection */
    mysql_free_result(pg_res); // 할당된 메모리 해제
    mysql_close(pg_conn);

	return TRUE;
}