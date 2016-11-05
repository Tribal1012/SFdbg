// SFdbg Disassembler Header
#pragma once
#ifndef __DISASSEM_H
#define __DISASSEM_H
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef unsigned long       DWORD;
typedef unsigned short      WORD;
typedef unsigned char       BYTE;
typedef unsigned long*      PDWORD;
typedef unsigned short*     PWORD;
typedef unsigned char*      PBYTE;

//Print
BOOL Print_float(const BYTE opcode, const BYTE modrm, char* szText);
void Print_Prefix(const BYTE Opcode, char* szText);
void Print_DIS(const BYTE bit, char* szText);
void Print_IMM(const BYTE bit, char* szText);
void Print_SIB(const BYTE sib, char* szText);
void Print_REG(const BYTE modrm, const BYTE bit, char* szText);
void Size_directive(const BYTE bit, char* szText);
void Print_ModRM(const BYTE modrm, const BYTE bit, char* szText);
void PrintDisassem(CListCtrl* m_list, LVITEM* lItem);
//Setting
BOOL Check_Prefix(const BYTE Opcode);
int Set_IF_SIB(const BYTE modrm, unsigned char* psmBase);
int Set_IF_DIS(const BYTE modrm, unsigned char* psmBase, const BYTE bit);
int Set_IF_IMM(const BYTE bit,unsigned char* psmBase);
int Set_ARPL_DIS(const BYTE modrm, unsigned char* psmBase);
unsigned char* Disassemble(const BYTE Code, unsigned char* psmBase);
BOOL Init_Disassemble(const unsigned char* psmBase, const DWORD smSize, CListCtrl* m_list);
BOOL Init_Disassemble(const DWORD Base, const DWORD count, CListCtrl* m_list);
void Reset_iif(void);

//
// Intel Instruction Format Structure
//

typedef struct _INTEL_INSTRUCTION_FORMAT
{
	BYTE Instruction_Prefixes;				// Support Opcode
	union {
            BYTE One_ByteOpcode;
            WORD Two_ByteOpcode;
			BYTE Three_ByteOpcode[3];
    } Opcode;								// Opcode(1~3 Byte)
	BYTE ModRM;								// Addressing-form specifier consisting (if required)
	BYTE SIB;								// Scale-Index-Base
	union {
            BYTE ByteDisplacement;
            WORD WordDisplacement;
			DWORD DWordDisplacement;
    } Displacement;							// (if required)
	union {
            BYTE ByteImmediate;
            WORD WordImmediate;
			DWORD DWordImmediate;
    } Immediate;							// Immediate data field (if required)
} INTEL_INSTRUCTION_FORMAT;

typedef struct _INSTRUCTION_STATUS
{
	BOOL Prefix_OpcodeSize;
	BOOL Prefix_AddressSize;
} INSTRUCTION_STATUS;

static INSTRUCTION_STATUS g_is;
static INTEL_INSTRUCTION_FORMAT g_iif;
static char* Base_Address;

#define IF_PRE(x) ((x).Instruction_Prefixes)
#define IF_OP(x) ((x).Opcode.One_ByteOpcode)
#define IF_OP2(x) ((x).Opcode.Two_ByteOpcode)
#define IF_OP3(x) ((x).Opcode.Three_ByteOpcode)
#define IF_MOD(x) ((x).ModRM)
#define IF_SIB(x) ((x).SIB)
#define IF_DIS8(x) ((x).Displacement.ByteDisplacement)
#define IF_DIS16(x) ((x).Displacement.WordDisplacement)
#define IF_DIS32(x) ((x).Displacement.DWordDisplacement)
#define IF_IMM8(x) ((x).Immediate.ByteImmediate)
#define IF_IMM16(x) ((x).Immediate.WordImmediate)
#define IF_IMM32(x) ((x).Immediate.DWordImmediate)
#endif