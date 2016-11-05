#pragma once
#ifndef __BREAK_POINT_H
#define __BREAK_POINT_H

//break point single linked list table node
typedef struct _Break_Table {
	DWORD opcode;
	DWORD mem_addr;
	DWORD list_offset;
	struct _Break_Table *next_table;
} Break_Table, *PBreak_Table;

typedef struct _Break_Table_Circle {
	PBreak_Table header_table;
	PBreak_Table tailer_table;
} Break_Table_Circle, *PBreak_Table_Circle;

void Insert_Circle(PBreak_Table_Circle pbtc, DWORD new_opcode, DWORD new_mem_addr, DWORD new_list_offset);
DWORD Table_Count(const PBreak_Table_Circle pbtc);
BOOL Search_Circle(const PBreak_Table_Circle pbtc, const DWORD value, PDWORD popcode, PDWORD paddress);
void Delete_Circle(PBreak_Table_Circle pbtc, DWORD offset);

#endif