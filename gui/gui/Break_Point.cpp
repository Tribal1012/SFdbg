#include "stdafx.h"
#include "Break_Point.h"

Break_Table_Circle g_pbtc;

void Insert_Circle(PBreak_Table_Circle pbtc, DWORD new_opcode, DWORD new_mem_addr, DWORD new_list_offset) {
	PBreak_Table new_table = (PBreak_Table) malloc(sizeof(Break_Table));
	if(pbtc->header_table == NULL) {
		pbtc->header_table = new_table;
		pbtc->tailer_table = new_table;
		new_table->opcode = new_opcode;
		new_table->mem_addr = new_mem_addr;
		new_table->list_offset = new_list_offset;
		new_table->next_table = pbtc->tailer_table;
	} else {
		new_table->next_table = pbtc->header_table;
		new_table->opcode = new_opcode;
		new_table->mem_addr = new_mem_addr;
		new_table->list_offset = new_list_offset;
		pbtc->tailer_table->next_table = pbtc->header_table;
	}
}

DWORD Table_Count(const PBreak_Table_Circle pbtc) {
	DWORD count = 0;
	PBreak_Table temp = pbtc->header_table;

	if(temp == NULL) return count;

	do {
		count++;
		temp = temp->next_table;
	}while(temp != pbtc->tailer_table);

	return count;
}

BOOL Search_Circle(const PBreak_Table_Circle pbtc, const DWORD value, PDWORD popcode, PDWORD paddress) {
	PBreak_Table temp = pbtc->header_table;

	if(temp == NULL) return FALSE;

	do {
		if(temp->list_offset == value) {
			*popcode = temp->opcode;
			*paddress = temp->mem_addr;
			return TRUE;
		}
		temp = temp->next_table;
	} while(temp != pbtc->tailer_table);

	*popcode = NULL;
	*paddress = NULL;

	return FALSE;
}

void Delete_Circle(PBreak_Table_Circle pbtc, DWORD offset) {
	PBreak_Table temp;									// temp table ptr
	PBreak_Table Del_table = pbtc->header_table;		// Delete table ptr
	DWORD i = 0;

	for(i=0; i<Table_Count(pbtc); i++) {
		if(Del_table->list_offset == offset) break;		// Find offset
		else {
			temp = Del_table;
			Del_table = Del_table->next_table;
		}
	}
	temp->next_table = temp->next_table->next_table;	//sorting circle linked list

	Del_table->list_offset = NULL;
	Del_table->mem_addr = NULL;
	Del_table->opcode = NULL;
	Del_table->next_table = NULL;		// Zero Set

	free(Del_table);
}