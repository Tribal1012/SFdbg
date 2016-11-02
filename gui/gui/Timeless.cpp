#include "stdafx.h"
#include "Timeless.h"

MYSQL *pg_conn; // MYSQL�� ���� ���
MYSQL_RES *pg_res; // ������ ���� ����� �޴� �Լ�
MYSQL_ROW g_row; // ������ ���� ���� ������ ���� ��� �ִ� ����
int g_query_stat; // ���� ���ϰ� ����
char g_query[255]; // ������ ����
int g_i;

/* DB ��ɾ� */
/* database�� �̸� �����Ǿ� �־���� (connection�� ����) */
/* Table �Է� */
BOOL input_table(const CONTEXT context, const time_t timer)
{
    /* send SQL g_query */
	/* mysql_g_query() ���� �� ��ȯ���� 0�̾�� ���� */

	/* ���ڵ� ���� */
	sprintf(g_query, "insert into temp values('%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d')", timer, context.Eax, context.Ebx, context.Ecx, context.Edx, context.Ebp, context.Esp, context.Esi, context.Edi, context.Eip, context.EFlags);
	g_query_stat = mysql_query(pg_conn, g_query);
	if (g_query_stat !=0)
	{
        fprintf(stderr, "%s\n", mysql_error(pg_conn));
        return FALSE;
    }

	return TRUE;
}

/* Table �˻� */
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
		sprintf(g_query, "select * from temp where %s=%08x", string, value);		//��..
		g_query_stat = mysql_query(pg_conn, g_query);
		if (g_query_stat !=0)
		{
			fprintf(stderr, "%s\n", mysql_error(pg_conn));
			return FALSE;
		}
	}

    pg_res = mysql_store_result(pg_conn); // ����� ��� ���� MYSQL_RES�� ����

	while ((g_row = mysql_fetch_row(pg_res)) != NULL) // ROW 1�� ����
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
	sprintf(g_query, "delete from temp"); // Table �̸� temp
	g_query_stat = mysql_query(pg_conn, g_query);
	if (g_query_stat !=0)
	{
        fprintf(stderr, "%s\n", mysql_error(pg_conn));
        return FALSE;
    }

	sprintf(g_query, "drop table temp"); // Table �̸� temp
	g_query_stat = mysql_query(pg_conn, g_query);
	if (g_query_stat !=0)
	{
        fprintf(stderr, "%s\n", mysql_error(pg_conn));
		return FALSE;
    }

	return TRUE;
}
/* DB ���� �� �ʱ�ȭ */
BOOL Init_DB(void) {
	 /* ó�� ���� */
     pg_conn = mysql_init(NULL); // �ʱ�ȭ

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

	 /* ������ ���̽� ���� */
	 if(mysql_select_db(pg_conn, DB_NAME))
	 {
		fprintf(stderr, "%s\n", mysql_error(pg_conn));
		return FALSE;
	 }

	 /* Table �̸� temp(count), record ���� int */
	sprintf(g_query, "create table temp(Time int, EAX int, EBX int, ECX int, EDX int, EBP int, ESP int, ESI int, EDI int, EIP int, FLAG int)");
	g_query_stat = mysql_query(pg_conn, g_query);
	if (g_query_stat !=0)
	{
        fprintf(stderr, "%s\n", mysql_error(pg_conn));
        return FALSE;
    }

	 return TRUE;
}

/* DB ���� */
BOOL Destroy_DB(void) {
	 if(!drop_table()) // Table ����
		 return FALSE;

    /* close pg_connection */
    mysql_free_result(pg_res); // �Ҵ�� �޸� ����
    mysql_close(pg_conn);

	return TRUE;
}