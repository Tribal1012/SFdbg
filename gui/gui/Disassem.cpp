#include "stdafx.h"
#include "Disassem.h"

int ModRMTable[] = {
/*        0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F   */
/* -----------------------------------------------------------------------*/
/*00*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*10*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*20*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*30*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*40*/    8,  9, 10, 11, 12, 13, 14, 15,  8,  9, 10, 11, 12, 13, 14, 15,
/*50*/    8,  9, 10, 11, 12, 13, 14, 15,  8,  9, 10, 11, 12, 13, 14, 15,
/*60*/    8,  9, 10, 11, 12, 13, 14, 15,  8,  9, 10, 11, 12, 13, 14, 15,
/*70*/    8,  9, 10, 11, 12, 13, 14, 15,  8,  9, 10, 11, 12, 13, 14, 15,
/*80*/   16, 17, 18, 19, 20, 21, 22, 23, 16, 17, 18, 19, 20, 21, 22, 23,
/*90*/   16, 17, 18, 19, 20, 21, 22, 23, 16, 17, 18, 19, 20, 21, 22, 23,
/*A0*/   16, 17, 18, 19, 20, 21, 22, 23, 16, 17, 18, 19, 20, 21, 22, 23,
/*B0*/   16, 17, 18, 19, 20, 21, 22, 23, 16, 17, 18, 19, 20, 21, 22, 23,
/*C0*/   24, 25, 26, 27, 28, 29, 30, 31, 24, 25, 26, 27, 28, 29, 30, 31,
/*D0*/   24, 25, 26, 27, 28, 29, 30, 31, 24, 25, 26, 27, 28, 29, 30, 31,
/*E0*/   24, 25, 26, 27, 28, 29, 30, 31, 24, 25, 26, 27, 28, 29, 30, 31,
/*F0*/   24, 25, 26, 27, 28, 29, 30, 31, 24, 25, 26, 27, 28, 29, 30, 31};
/* -----------------------------------------------------------------------*/

int RegTable[] = {
/*        0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F   */
/* -----------------------------------------------------------------------*/
/*00*/    0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,
/*10*/    2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,
/*20*/    4,  4,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  5,  5,  5,  5,
/*30*/    6,  6,  6,  6,  6,  6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,
/*40*/    0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,
/*50*/    2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,
/*60*/    4,  4,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  5,  5,  5,  5,
/*70*/    6,  6,  6,  6,  6,  6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,
/*80*/    0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,
/*90*/    2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,
/*A0*/    4,  4,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  5,  5,  5,  5,
/*B0*/    6,  6,  6,  6,  6,  6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,
/*C0*/    0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,
/*D0*/    2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,
/*E0*/    4,  4,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  5,  5,  5,  5,
/*F0*/    6,  6,  6,  6,  6,  6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7};
/* -----------------------------------------------------------------------*/

int SITable[] = {
/*        0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F   */
/* -----------------------------------------------------------------------*/
/*00*/    0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,
/*10*/    2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,
/*20*/    4,  4,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  5,  5,  5,  5,
/*30*/    6,  6,  6,  6,  6,  6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,
/*40*/    8,  8,  8,  8,  8,  8,  8,  8,  9,  9,  9,  9,  9,  9,  9,  9,
/*50*/   10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11,
/*60*/   12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13,
/*70*/   14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15,
/*80*/   16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17,
/*90*/   18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19,
/*A0*/   20, 20, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21, 21, 21,
/*B0*/   22, 22, 22, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 23, 23, 23,
/*C0*/   24, 24, 24, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 25, 25, 25,
/*D0*/   26, 26, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 27, 27, 27,
/*E0*/   28, 28, 28, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 29, 29, 29,
/*F0*/   30, 30, 30, 30, 30, 30, 30, 30, 31, 31, 31, 31, 31, 31, 31, 31};
/* -----------------------------------------------------------------------*/

int BaseTable[] = {
/*        0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F   */
/* -----------------------------------------------------------------------*/
/*00*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*10*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*20*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*30*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*40*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*50*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*60*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*70*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*80*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*90*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*A0*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*B0*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*C0*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*D0*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*E0*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7,
/*F0*/    0,  1,  2,  3,  4,  5,  6,  7,  0,  1,  2,  3,  4,  5,  6,  7};
/* -----------------------------------------------------------------------*/

char* reg8string[]={"al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"};
char* reg16string[]={"ax", "cx", "dx", "bx", "sp", "bp", "si", "di"};
char* reg32string[]={"eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"};
char* reg64string[]={"mm0", "mm1", "mm2", "mm3", "mm4", "mm5", "mm6", "mm7"};
char* reg128string[]={"xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7"};
char* modrm16string[]={"bx+si", "bx+di", "bp+si", "bp+di", "si", "di", "bp", "bx"};

BOOL Print_float(const BYTE opcode, const BYTE modrm, char* szText)
{
	DWORD reg = RegTable[modrm];

	if(opcode==0xD8) {
		if((ModRMTable[modrm]/8)==3) {
			if(reg==0) {
				sprintf(szText, "fadd st, st(%u)", modrm%8);
				return 	TRUE;
			}
			else if(reg==1) {
				sprintf(szText, "fmul st, st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==2) {
				sprintf(szText, "fcom st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==3) {
				sprintf(szText, "fcomp st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==4) {
				sprintf(szText, "fsub st, st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==5) {
				sprintf(szText, "fsubr st, st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==6) {
				sprintf(szText, "fdiv st, st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==7) {
				sprintf(szText, "fdivr st, st(%u)", modrm%8);
				return TRUE;
			}
			else sprintf(szText, "???");
		}
		else {
			switch(reg) {
			case 0: sprintf(szText, "fadd"); Print_ModRM(modrm, 32, szText); break;
			case 1: sprintf(szText, "fmul"); Print_ModRM(modrm, 32, szText); break;
			case 2: sprintf(szText, "fcom"); Print_ModRM(modrm, 32, szText); break;
			case 3: sprintf(szText, "fcomp"); Print_ModRM(modrm, 32, szText); break;
			case 4: sprintf(szText, "fsub"); Print_ModRM(modrm, 32, szText); break;
			case 5: sprintf(szText, "fsubr"); Print_ModRM(modrm, 32, szText); break;
			case 6: sprintf(szText, "fdiv"); Print_ModRM(modrm, 32, szText); break;
			case 7: sprintf(szText, "fdivr"); Print_ModRM(modrm, 32, szText); break;
			}
		}
	}
	else if(opcode==0xD9) {
		if((ModRMTable[modrm]/8)==3) {
			switch(modrm) {
			case 0xD0: sprintf(szText, "fnop"); return TRUE;
			case 0xE0: sprintf(szText, "fchs"); return TRUE;
			case 0xE1: sprintf(szText, "fabs"); return TRUE;
			case 0xE4: sprintf(szText, "ftst"); return TRUE;
			case 0xE5: sprintf(szText, "fxam"); return TRUE;
			case 0xE8: sprintf(szText, "fld1"); return TRUE;
			case 0xE9: sprintf(szText, "fldl2t"); return TRUE;
			case 0xEA: sprintf(szText, "fldl2e"); return TRUE;
			case 0xEB: sprintf(szText, "fldpi"); return TRUE;
			case 0xEC: sprintf(szText, "fldlg2"); return TRUE;
			case 0xED: sprintf(szText, "fldln2"); return TRUE;
			case 0xEE: sprintf(szText, "fldz"); return TRUE;
			case 0xF0: sprintf(szText, "f2xm1"); return TRUE;
			case 0xF1: sprintf(szText, "fvl2x"); return TRUE;
			case 0xF2: sprintf(szText, "fptan"); return TRUE;
			case 0xF3: sprintf(szText, "fpatan"); return TRUE;
			case 0xF4: sprintf(szText, "fxtract"); return TRUE;
			case 0xF5: sprintf(szText, "fprem1"); return TRUE;
			case 0xF6: sprintf(szText, "fdecstp"); return TRUE;
			case 0xF7: sprintf(szText, "fincstp"); return TRUE;
			case 0xF8: sprintf(szText, "fprem"); return TRUE;
			case 0xF9: sprintf(szText, "fvl2xp1"); return TRUE;
			case 0xFA: sprintf(szText, "fsqrt"); return TRUE;
			case 0xFB: sprintf(szText, "fsincos"); return TRUE;
			case 0xFC: sprintf(szText, "fpndint"); return TRUE;
			case 0xFD: sprintf(szText, "fscale"); return TRUE;
			case 0xFE: sprintf(szText, "fsin"); return TRUE;
			case 0xFF: sprintf(szText, "fcos"); return TRUE;
			default: break;
			}
			if(reg==0) {
				sprintf(szText, "fld st(%u)", modrm%8);
				return 	TRUE;
			}
			else if(reg==1) {
				sprintf(szText, "fxch st(%u)", modrm%8);
				return 	TRUE;
			}
			else if(reg==2) {
				sprintf(szText, "fst %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else if(reg==3) {
				sprintf(szText, "fstp %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else if(reg==4) {
				sprintf(szText, "fldenv %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else if(reg==5) {
				sprintf(szText, "fldcw %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else sprintf(szText, "???");
		}
		else {
			switch(reg) {
			case 0: sprintf(szText, "fld"); Print_ModRM(modrm, 32, szText); break;
			case 1: sprintf(szText, "???"); break;
			case 2: sprintf(szText, "fst"); Print_ModRM(modrm, 32, szText); break;
			case 3: sprintf(szText, "fstp"); Print_ModRM(modrm, 32, szText); break;
			case 4: sprintf(szText, "fldenv"); Print_ModRM(modrm, 32, szText); break;//
			case 5: sprintf(szText, "fldcw"); Print_ModRM(modrm, 16, szText); break;
			case 6: sprintf(szText, "fldenv"); Print_ModRM(modrm, 32, szText); break;//
			case 7: sprintf(szText, "fldcw"); Print_ModRM(modrm, 16, szText);  break;
			}
		}
	}
	else if(opcode==0xDA) {
		if((ModRMTable[modrm]/8)==3) {
			if(reg==0) {
				sprintf(szText, "fcmovb st, st(%u)", modrm%8);
				return 	TRUE;
			}
			else if(reg==1) {
				sprintf(szText, "fcomve st, st(%u)", modrm%8);
				return 	TRUE;
			}
			else if(reg==2) {
				sprintf(szText, "fcmovbe st, st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==3) {
				sprintf(szText, "fcmovu st, st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==4) {
				sprintf(szText, "fisub %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else if(reg==5) {
				if(modrm==0xE9) {
					sprintf(szText, "fucompp");
					return TRUE;
				}
				sprintf(szText, "fisubr %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else if(reg==6) {
				sprintf(szText, "fidiv %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else if(reg==7) {
				sprintf(szText, "fidivr %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else sprintf(szText, "???");
		}
		else {
			switch(reg) {
			case 0: sprintf(szText, "fiadd"); Print_ModRM(modrm, 32, szText); break;
			case 1: sprintf(szText, "fimul"); Print_ModRM(modrm, 32, szText); break;
			case 2: sprintf(szText, "ficom"); Print_ModRM(modrm, 32, szText); break;
			case 3: sprintf(szText, "ficomp"); Print_ModRM(modrm, 32, szText); break;
			case 4: sprintf(szText, "fisub"); Print_ModRM(modrm, 32, szText); break;
			case 5: sprintf(szText, "fisubr"); Print_ModRM(modrm, 32, szText); break;
			case 6: sprintf(szText, "fidiv"); Print_ModRM(modrm, 32, szText); break;
			case 7: sprintf(szText, "fidivr"); Print_ModRM(modrm, 32, szText); break;
			}
		}
	}
	else if(opcode==0xDB) {
		if((ModRMTable[modrm]/8)==3) {
			if(reg==0) {
				sprintf(szText, "fcmovnb st, st(%u)", modrm%8);
				return 	TRUE;
			}
			else if(reg==1) {
				sprintf(szText, "fcomvne st, st(%u)", modrm%8);
				return 	TRUE;
			}
			else if(reg==2) {
				sprintf(szText, "fcmovnbe st, st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==3) {
				sprintf(szText, "fcmovnu st, st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==4) {
				switch(modrm) {
				case 0xE0: sprintf(szText, "feni"); return TRUE;
				case 0xE1: sprintf(szText, "fdisi"); return TRUE;
				case 0xE2: sprintf(szText, "fclex"); return TRUE;
				case 0xE3: sprintf(szText, "finit"); return TRUE;
				case 0xE4: sprintf(szText, "fsetpm"); return TRUE;
				default: sprintf(szText, "???"); return TRUE;
				}
			}
			else if(reg==5) {
				sprintf(szText, "fucomi st, st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==6) {
				sprintf(szText, "fcomi st, st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==7) {
				sprintf(szText, "fstp %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else sprintf(szText, "???");
		}
		else {
			switch(reg) {
			case 0: sprintf(szText, "fild"); Print_ModRM(modrm, 32, szText);break;
			case 1: sprintf(szText, "???"); break;
			case 2: sprintf(szText, "fist"); Print_ModRM(modrm, 32, szText); break;
			case 3: sprintf(szText, "fistp"); Print_ModRM(modrm, 32, szText); break;
			case 4: sprintf(szText, "???"); break;
			case 5: sprintf(szText, "fld"); Print_ModRM(modrm, 128, szText); break;
			case 6: sprintf(szText, "???"); break;
			case 7: sprintf(szText, "fstp"); Print_ModRM(modrm, 128, szText); break;
			}
		}
	}
	else if(opcode==0xDC) {
		if((ModRMTable[modrm]/8)==3) {
			if(reg==0) {
				sprintf(szText, "fadd st(%u), st", modrm%8);
				return 	TRUE;
			}
			else if(reg==1) {
				sprintf(szText, "fmul st(%u), st", modrm%8);
				return TRUE;
			}
			else if(reg==2) {
				sprintf(szText, "fcom %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else if(reg==3) {
				sprintf(szText, "fcomp %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else if(reg==4) {
				sprintf(szText, "fsubr st(%u), st", modrm%8);
				return TRUE;
			}
			else if(reg==5) {
				sprintf(szText, "fsub st(%u), st", modrm%8);
				return TRUE;
			}
			else if(reg==6) {
				sprintf(szText, "fdivr st(%u), st", modrm%8);
				return TRUE;
			}
			else if(reg==7) {
				sprintf(szText, "fdiv st(%u), st", modrm%8);
				return TRUE;
			}
			else sprintf(szText, "???");
		}
		else {
			switch(reg) {
			case 0: sprintf(szText, "fadd"); Print_ModRM(modrm, 64, szText); break;
			case 1: sprintf(szText, "fmul"); Print_ModRM(modrm, 64, szText); break;
			case 2: sprintf(szText, "fcom"); Print_ModRM(modrm, 64, szText); break;
			case 3: sprintf(szText, "fcomp"); Print_ModRM(modrm, 64, szText); break;
			case 4: sprintf(szText, "fsub"); Print_ModRM(modrm, 64, szText); break;
			case 5: sprintf(szText, "fsubr"); Print_ModRM(modrm, 64, szText); break;
			case 6: sprintf(szText, "fdiv"); Print_ModRM(modrm, 64, szText); break;
			case 7: sprintf(szText, "fdivr"); Print_ModRM(modrm, 64, szText); break;
			}
		}
	}
	else if(opcode==0xDD) {
		if((ModRMTable[modrm]/8)==3) {
			if(reg==0) {
				sprintf(szText, "ffree st(%u)", modrm%8);
				return 	TRUE;
			}
			else if(reg==1) {
				sprintf(szText, "???");
				return TRUE;
			}
			else if(reg==2) {
				sprintf(szText, "fst st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==3) {
				sprintf(szText, "fstp st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==4) {
				sprintf(szText, "fucom st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==5) {
				sprintf(szText, "fucomp st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==6) {
				sprintf(szText, "fsave %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else if(reg==7) {
				sprintf(szText, "fstsw %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else sprintf(szText, "???");
		}
		else {
			switch(reg) {
			case 0: sprintf(szText, "fld"); Print_ModRM(modrm, 64, szText); break;
			case 1: sprintf(szText, "???"); break;
			case 2: sprintf(szText, "fst"); Print_ModRM(modrm, 64, szText); break;
			case 3: sprintf(szText, "fstp"); Print_ModRM(modrm, 64, szText); break;
			case 4: sprintf(szText, "frstor"); Print_ModRM(modrm, 64, szText); break;//
			case 5: sprintf(szText, "???"); break;
			case 6: sprintf(szText, "fsave"); Print_ModRM(modrm, 64, szText); break;//
			case 7: sprintf(szText, "fstsw"); Print_ModRM(modrm, 16, szText); break;
			}
		}
	}
	else if(opcode==0xDE) {
		if((ModRMTable[modrm]/8)==3) {
			if(reg==0) {
				sprintf(szText, "faddp st(%u), st", modrm%8);
				return 	TRUE;
			}
			else if(reg==1) {
				sprintf(szText, "fmulp st(%u), st", modrm%8);
				return TRUE;
			}
			else if(reg==2) {
				sprintf(szText, "ficom %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else if(reg==3) {
				if(modrm==0xD9) {
					sprintf(szText, "fcompp");
					return TRUE;
				}
				sprintf(szText, "ficomp %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else if(reg==4) {
				sprintf(szText, "fsubrp st(%u), st", modrm%8);
				return TRUE;
			}
			else if(reg==5) {
				sprintf(szText, "fsubp st(%u), st", modrm%8);
				return TRUE;
			}
			else if(reg==6) {
				sprintf(szText, "fdivrp st(%u), st", modrm%8);
				return TRUE;
			}
			else if(reg==7) {
				sprintf(szText, "fdivp st(%u), st", modrm%8);
				return TRUE;
			}
			else sprintf(szText, "???");
		}
		else {
			switch(reg) {
			case 0: sprintf(szText, "fild"); Print_ModRM(modrm, 16, szText); break;
			case 1: sprintf(szText, "fimul"); Print_ModRM(modrm, 16, szText); break;
			case 2: sprintf(szText, "ficom"); Print_ModRM(modrm, 16, szText); break;
			case 3: sprintf(szText, "ficomp"); Print_ModRM(modrm, 16, szText); break;
			case 4: sprintf(szText, "fisub"); Print_ModRM(modrm, 16, szText); break;
			case 5: sprintf(szText, "fisubr"); Print_ModRM(modrm, 16, szText); break;
			case 6: sprintf(szText, "fidiv"); Print_ModRM(modrm, 16, szText); break;
			case 7: sprintf(szText, "fidivr"); Print_ModRM(modrm, 16, szText); break;
			}
		}
	}
	else if(opcode==0xDF) {
		if((ModRMTable[modrm]/8)==3) {
			if(reg==0) {
				sprintf(szText, "ffreep st(%u)", modrm%8);
				return 	TRUE;
			}
			else if(reg==1) {
				sprintf(szText, "???");
				return TRUE;
			}
			else if(reg==2) {
				sprintf(szText, "fist %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else if(reg==3) {
				sprintf(szText, "fistp %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else if(reg==4) {
				if(modrm==0xE0) {
					sprintf(szText, "fstsw ax");
					return TRUE;
				}
				sprintf(szText, "fbld %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else if(reg==5) {
				sprintf(szText, "fucomip st, st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==6) {
				sprintf(szText, "fcomip st, st(%u)", modrm%8);
				return TRUE;
			}
			else if(reg==7) {
				sprintf(szText, "fistp %s", (g_is.Prefix_OpcodeSize)?reg16string[modrm%8]:reg32string[modrm%8]);
				return TRUE;
			}
			else sprintf(szText, "???");
		}
		else {
			switch(reg) {
			case 0: sprintf(szText, "fild"); Print_ModRM(modrm, 16, szText); break;
			case 1: sprintf(szText, "???"); break;
			case 2: sprintf(szText, "fist"); Print_ModRM(modrm, 16, szText); break;
			case 3: sprintf(szText, "fistp"); Print_ModRM(modrm, 16, szText); break;
			case 4: sprintf(szText, "fbld"); Print_ModRM(modrm, 128, szText); break;
			case 5: sprintf(szText, "fild"); Print_ModRM(modrm, 64, szText); break;
			case 6: sprintf(szText, "fbstp"); Print_ModRM(modrm, 128, szText); break;
			case 7: sprintf(szText, "fistp"); Print_ModRM(modrm, 64, szText); break;
			}
		}
	}

	return FALSE;
}

void Print_Prefix(const BYTE Opcode, char* szText)
{
	if(Opcode == 0x26) sprintf(szText, "ES: ");
	else if(Opcode == 0x2E) sprintf(szText, "CS: ");
	else if(Opcode == 0x36) sprintf(szText, "SS: ");
	else if(Opcode == 0x3E) sprintf(szText, "DS: ");
	else if(Opcode == 0x64) sprintf(szText, "FS: ");
	else if(Opcode == 0x65) sprintf(szText, "GS: ");
	else if(Opcode == 0xF0) sprintf(szText, "LOCK: ");
	else if(Opcode == 0xF2) sprintf(szText, "REPNE: ");
	else if(Opcode == 0xF3) sprintf(szText, "REP: ");
}

void Print_DIS(const BYTE bit, char* szText)
{
	switch(bit) {
	case 8: sprintf(szText, "%s0x%02x", szText, IF_DIS8(g_iif)); break;
	case 16: sprintf(szText, "%s0x%04x", szText, IF_DIS16(g_iif)); break;
	case 32: sprintf(szText, "%s0x%08x", szText, IF_DIS32(g_iif)); break;
	default: break;
	}
}

void Print_IMM(const BYTE bit, char* szText)
{
	switch(bit) {
	case 8: sprintf(szText, "%s0x%02x", szText, IF_IMM8(g_iif)); break;
	case 16: sprintf(szText, "%s0x%04x", szText, IF_IMM16(g_iif)); break;
	case 32: sprintf(szText, "%s0x%08x", szText, IF_IMM32(g_iif)); break;
	default: break;
	}
}

void Print_SIB(const BYTE sib, char* szText)
{
	if(!((BaseTable[sib]!=5)?sprintf(szText, "%s%s+", szText, reg32string[BaseTable[sib]]):FALSE))
		(ModRMTable[IF_MOD(g_iif)]!=4)?sprintf(szText, "%sebp+", szText):Print_DIS(32, szText);

	switch(SITable[sib]%8) {
	case 4: break;
	case 0:
	case 1:
	case 2:
	case 3:
	case 5:
	case 6:
	case 7: (SITable[sib]!=0)?sprintf(szText, "%s%s*%u+", szText, reg32string[SITable[sib]%8], 1<<(SITable[sib]/8)):sprintf(szText, "%s%s", szText, reg32string[SITable[sib]%8]); break;
	}
}

void Print_REG(const BYTE modrm, const BYTE bit, char* szText)
{
	if(bit==8) sprintf(szText, "%s%s", szText, reg8string[RegTable[modrm]]);
	else if(bit==16) sprintf(szText, "%s%s", szText, reg16string[RegTable[modrm]]);
	else if(bit==32) sprintf(szText, "%s%s", szText, (g_is.Prefix_OpcodeSize)?reg16string[RegTable[modrm]]:reg32string[RegTable[modrm]]);
	else if(bit==64) sprintf(szText, "%s%s", szText, reg64string[RegTable[modrm]]);
	else if(bit==128) sprintf(szText, "%s%s", szText, reg128string[RegTable[modrm]]);
}

void Size_directive(const BYTE bit, char* szText)
{
	switch(bit) {
	case 8: sprintf(szText, "%sbyte ptr ", szText); break;
	case 16: sprintf(szText, "%sword ptr ", szText); break;
	case 32: sprintf(szText, "%sdword ptr ", szText); break;
	case 64: sprintf(szText, "%sqword ptr ", szText); break;
	case 128: sprintf(szText, "%stbyte ptr ", szText); break;
	default: break;
	}
}

void Print_ModRM(const BYTE modrm, const BYTE bit, char* szText)
{
	DWORD value = ModRMTable[modrm];

	switch(value) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 7:Size_directive(bit, szText); sprintf(szText, "%s[%s]", szText, (g_is.Prefix_AddressSize)?modrm16string[value]:reg32string[value]); break;
	case 4:Size_directive(bit, szText); sprintf(szText, "%s[", szText); (g_is.Prefix_AddressSize)? sprintf(szText, "%s%s+", szText, modrm16string[value]):Print_SIB(IF_SIB(g_iif), szText); sprintf(szText, "%s]", szText); break;
	case 5:Size_directive(bit, szText); sprintf(szText, "%s[", szText); (g_is.Prefix_AddressSize)? sprintf(szText, "%s+", modrm16string[value]):Print_DIS(32, szText); sprintf(szText, "%s]", szText); break;
	case 6: Size_directive(bit, szText); (g_is.Prefix_AddressSize)? Print_DIS(16, szText):sprintf(szText, "%s[%s]", szText, reg32string[value]); break;
	case 8:
	case 9:
	case 10:
	case 11:
	case 13:
	case 14:
	case 15:Size_directive(bit, szText); sprintf(szText, "%s[%s+", szText, (g_is.Prefix_AddressSize)?modrm16string[value%8]:reg32string[value%8]); Print_DIS(8, szText); sprintf(szText, "%s]", szText); break;
	case 12:Size_directive(bit, szText); sprintf(szText, "%s[", szText); (g_is.Prefix_AddressSize)? sprintf(szText, "%s%s+", szText, modrm16string[value%8]):Print_SIB(IF_SIB(g_iif), szText); Print_DIS(8, szText); sprintf(szText, "%s]", szText); break;
	case 16:
	case 17:
	case 18:
	case 19:
	case 21:
	case 22:
	case 23:Size_directive(bit, szText); sprintf(szText, "%s[%s]", szText, (g_is.Prefix_AddressSize)?modrm16string[value%8]:reg32string[value%8]); Print_DIS(32, szText); break;
	case 20:Size_directive(bit, szText); sprintf(szText, "%s[", szText); (g_is.Prefix_AddressSize)? sprintf(szText, "%s%s+", szText, modrm16string[value%8]):Print_SIB(IF_SIB(g_iif), szText); Print_DIS(32, szText); sprintf(szText, "%s]", szText); break;
	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
	case 31:
		if(bit==8) sprintf(szText, "%s%s", szText, reg8string[value%8]);
		else if(bit==16) sprintf(szText, "%s%s", szText, reg16string[value%8]);
		else if(bit==32) sprintf(szText, "%s%s", szText, reg32string[value%8]);
		else if(bit==64) sprintf(szText, "%s%s", szText, reg64string[value%8]);
		else if(bit==128) sprintf(szText, "%s%s", szText, reg128string[value%8]);
		break;
	default: break;
	}
}

void PrintDisassem(CListCtrl* m_list, LVITEM* lItem)		//This Function put string in List Control's SubItem
{
	char szText[MAX_PATH] = {0};

	Print_Prefix(IF_PRE(g_iif), szText);

	switch(IF_OP(g_iif))
	{
	case 0x0F:/*TWOBYTE*/
	/* Opcode + 8bit MOD */
	case 0x00:sprintf_s(szText, "add "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 8, szText); break;//add Eb, Gb
	case 0x01:sprintf_s(szText, "add "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 32, szText); break;//add Ev, Gv
	case 0x02:sprintf_s(szText, "add "); Print_REG(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 8, szText); break;//add Gb, Eb
	case 0x03:sprintf_s(szText, "add "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); break;//add Gv, Ev
	case 0x08:sprintf_s(szText, "or "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 8, szText); break;//or Eb, Gb
	case 0x09:sprintf_s(szText, "or "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 32, szText); break;//or Ev, Gv
	case 0x0A:sprintf_s(szText, "or "); Print_REG(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 8, szText); break;//or Gb, Eb
	case 0x0B:sprintf_s(szText, "or "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); break;//or Gv, Ev
	case 0x10:sprintf_s(szText, "adc "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 8, szText); break;//adc Eb, Gb
	case 0x11:sprintf_s(szText, "adc "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 32, szText); break;//adc Ev, Gv
	case 0x12:sprintf_s(szText, "adc "); Print_REG(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 8, szText); break; //adc Gb, Eb
	case 0x13:sprintf_s(szText, "adc "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); break;//adc Gv, Ev
	case 0x18:sprintf_s(szText, "sbb "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 8, szText); break;//sbb Eb, Gb
	case 0x19:sprintf_s(szText, "sbb "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 32, szText); break;//sbb Ev, Gv
	case 0x1A:sprintf_s(szText, "sbb "); Print_REG(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 8, szText); break; //sbb Gb, Eb
	case 0x1B:sprintf_s(szText, "sbb "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); break;//sbb Gv, Ev
	case 0x20:sprintf_s(szText, "and "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 8, szText); break;//and Eb, Gb
	case 0x21:sprintf_s(szText, "and "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 32, szText); break;//and Ev, Gv
	case 0x22:sprintf_s(szText, "and "); Print_REG(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 8, szText); break; //and Gb, Eb
	case 0x23:sprintf_s(szText, "and "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); break;//and Gv, Ev
	case 0x28:sprintf_s(szText, "sub "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 8, szText); break;//sub Eb, Gb
	case 0x29:sprintf_s(szText, "sub "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 32, szText); break;//sub Ev, Gv
	case 0x2A:sprintf_s(szText, "sub "); Print_REG(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 8, szText); break; //sub Gb, Eb
	case 0x2B:sprintf_s(szText, "sub "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); break;//sub Gv, Ev
	case 0x30:sprintf_s(szText, "xor "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 8, szText); break;//xor Eb, Gb
	case 0x31:sprintf_s(szText, "xor "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 32, szText); break;//xor Ev, Gv
	case 0x32:sprintf_s(szText, "xor "); Print_REG(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 8, szText); break; //xor Gb, Eb
	case 0x33:sprintf_s(szText, "xor "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); break;//xor Gv, Ev
	case 0x38:sprintf_s(szText, "cmp "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 8, szText); break;//cmp Eb, Gb
	case 0x39:sprintf_s(szText, "cmp "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 32, szText); break;//cmp Ev, Gv
	case 0x3A:sprintf_s(szText, "cmp "); Print_REG(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 8, szText); break; //cmp Gb, Eb
	case 0x3B:sprintf_s(szText, "cmp "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); break;//cmp Gv, Ev
	case 0x62:sprintf_s(szText, "bound "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); break;//BOUND
	case 0x84:sprintf_s(szText, "test "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 8, szText); break;//test Eb, Gb
	case 0x85:sprintf_s(szText, "test "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 32, szText); break;//test Ev, Gv
	case 0x86:sprintf_s(szText, "xchg "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 8, szText); break;//xchg Eb, Gb
	case 0x87:sprintf_s(szText, "xchg "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 32, szText); break;//xchg Ev, Gv
	case 0x88:sprintf_s(szText, "mov "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 8, szText); break;//mov Eb, Gb
	case 0x89:sprintf_s(szText, "mov "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 32, szText); break;//mov Ev, Gv
	case 0x8A:sprintf_s(szText, "mov "); Print_REG(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 8, szText); break; //mov Gb, Eb
	case 0x8B:sprintf_s(szText, "mov "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); break;//mov Gv, Ev
	case 0x8C:sprintf_s(szText, "mov "); Print_ModRM(IF_MOD(g_iif), 16, szText); sprintf_s(szText, "%s, ", szText); Print_REG(IF_MOD(g_iif), 16, szText); break;//mov Ew, Sw
	case 0x8D:sprintf_s(szText, "lea "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); break;//lea Gv, M
	case 0x8E:sprintf_s(szText, "mov "); Print_REG(IF_MOD(g_iif), 16, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 16, szText); break;//mov Sw, Ew
	case 0x8F:sprintf_s(szText, "pop "); (RegTable[IF_MOD(g_iif)]==0)?Print_ModRM(IF_MOD(g_iif), 32, szText):sprintf_s(szText, "%s???", szText); break;//pop Ev Reg가 0으로 고정됨(2 ~ 6)
	case 0xC4:sprintf_s(szText, "les "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); break;//les Gv, Mp(lea처럼 좀 복잡)
	case 0xC5:sprintf_s(szText, "lds "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); break;//lds Gv, Mp
	case 0xD0:sprintf_s(szText, "rol "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); sprintf_s(szText, "%s1", szText); break;//rol Eb, 1
	case 0xD1:sprintf_s(szText, "rol "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); sprintf_s(szText, "%s1", szText); break;//ro1 Ev, 1
	case 0xD2:sprintf_s(szText, "rol "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); sprintf_s(szText, "%scl", szText); break;//rol Eb, CL
	case 0xD3:sprintf_s(szText, "rol "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); sprintf_s(szText, "%scl", szText); break;//rol Ev, CL
	case 0xFE:sprintf_s(szText, "inc "); Print_ModRM(IF_MOD(g_iif), 8, szText); break;//inc, dec 8bit
	case 0xFF:sprintf_s(szText, "inc "); Print_ModRM(IF_MOD(g_iif), 32, szText); break;//inc, dec 32bit
	/* Opcode + 8bit MOD + 8bit IMM */
	case 0x6B:sprintf_s(szText, "imul "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_IMM(8, szText); break;//IMUL Gv Ev Ib
	case 0x80:sprintf_s(szText, "add "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_IMM(8, szText); break;//add Eb, Ib
	case 0x82:sprintf_s(szText, "sub "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_IMM(8, szText); break;//sub Eb, Ib
	case 0x83:sprintf_s(szText, "sub "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_IMM(8, szText); break;//sub Ev, Ib
	case 0xC0:sprintf_s(szText, "ror "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_IMM(8, szText); break;//ROR Eb, Ib
	case 0xC1:sprintf_s(szText, "ror "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_IMM(8, szText); break;//ROR Ev, Ib
	case 0xC6:sprintf_s(szText, "mov "); if(RegTable[IF_MOD(g_iif)]==0) { Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_IMM(8, szText); break; }
							  else { sprintf_s(szText, "%s???", szText); break; }//mov Eb, Ib Reg가 0으로 고정됨(2 ~ 6)
	case 0xF6:sprintf_s(szText, "test "); Print_ModRM(IF_MOD(g_iif), 8, szText); sprintf_s(szText, "%s, ", szText); Print_IMM(8, szText); break;//test Eb
	/* Opcode + 8bit MOD + 32bit IMM */
	case 0x81:sprintf_s(szText, "add "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_IMM(32, szText); break;//add Ev Iv
	case 0x69:sprintf_s(szText, "imul "); Print_REG(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_IMM(32, szText); break;//IMUL Gv Ev Iv
	case 0xC7:sprintf_s(szText, "mov "); if(RegTable[IF_MOD(g_iif)]==0) { Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_IMM(32, szText); break; }
							  else { sprintf_s(szText, "%s???", szText); break; }//mov Ev, Iv Reg가 0으로 고정됨(2 ~ 6)
	case 0xF7:sprintf_s(szText, "test "); Print_ModRM(IF_MOD(g_iif), 32, szText); sprintf_s(szText, "%s, ", szText); Print_IMM(32, szText); break;//test Ev
	/* Opcode + 8bit IMM */
	case 0x04:sprintf_s(szText, "add "); sprintf_s(szText, "%sal, ", szText); Print_IMM(8, szText); break;//add AL, Ib
	case 0x0C:sprintf_s(szText, "or "); sprintf_s(szText, "%sal, ", szText); Print_IMM(8, szText); break;//or AL, ib
	case 0x14:sprintf_s(szText, "adc "); sprintf_s(szText, "%sal, ", szText); Print_IMM(8, szText); break;//adc AL, Ib
	case 0x1C:sprintf_s(szText, "sbb "); sprintf_s(szText, "%sal, ", szText); Print_IMM(8, szText); break;//sbb AL, Ib
	case 0x24:sprintf_s(szText, "and "); sprintf_s(szText, "%sal, ", szText); Print_IMM(8, szText); break;//and AL, Ib
	case 0x2C:sprintf_s(szText, "sub "); sprintf_s(szText, "%sal, ", szText); Print_IMM(8, szText); break;//sub AL, Ib
	case 0x34:sprintf_s(szText, "xor "); sprintf_s(szText, "%sal, ", szText); Print_IMM(8, szText); break;//xor AL, Ib
	case 0x3C:sprintf_s(szText, "cmp "); sprintf_s(szText, "%sal, ", szText); Print_IMM(8, szText); break;//cmp AL, Ib
	case 0x6A:sprintf_s(szText, "push "); Print_IMM(8, szText); break;//push Ib
	case 0xA8:sprintf_s(szText, "test "); sprintf_s(szText, "%sal, ", szText); Print_IMM(8, szText); break;//test AL, Ib
	case 0xB0:sprintf_s(szText, "mov "); sprintf_s(szText, "%sal, ", szText); Print_IMM(8, szText); break;//mov AL, Ib
	case 0xB1:sprintf_s(szText, "mov "); sprintf_s(szText, "%scl, ", szText); Print_IMM(8, szText); break;//mov CL, Ib
	case 0xB2:sprintf_s(szText, "mov "); sprintf_s(szText, "%sdl, ", szText); Print_IMM(8, szText); break;//mov DL, Ib
	case 0xB3:sprintf_s(szText, "mov "); sprintf_s(szText, "%sbl, ", szText); Print_IMM(8, szText); break;//mov BL, Ib
	case 0xB4:sprintf_s(szText, "mov "); sprintf_s(szText, "%sah, ", szText); Print_IMM(8, szText); break;//mov AH, Ib
	case 0xB5:sprintf_s(szText, "mov "); sprintf_s(szText, "%sch, ", szText); Print_IMM(8, szText); break;//mov CH, Ib
	case 0xB6:sprintf_s(szText, "mov "); sprintf_s(szText, "%sdh, ", szText); Print_IMM(8, szText); break;//mov DH, Ib
	case 0xB7:sprintf_s(szText, "mov "); sprintf_s(szText, "%sbh, ", szText); Print_IMM(8, szText); break;//mov BH, Ib
	case 0xCD:sprintf_s(szText, "int "); Print_IMM(8, szText); break;//int Ib
	case 0xD4:sprintf_s(szText, "aam "); Print_IMM(8, szText); break;//aam Ib
	case 0xD5:sprintf_s(szText, "aad "); Print_IMM(8, szText); break;//aad Ib
	case 0xE3:sprintf_s(szText, "jcxz "); Print_IMM(8, szText); break;//jcxz
	case 0xE4:sprintf_s(szText, "in "); sprintf_s(szText, "%sal, ", szText); Print_IMM(8, szText); break;//in AL, Ib
	case 0xE5:sprintf_s(szText, "in "); sprintf_s(szText, "%seax, ", szText); Print_IMM(8, szText); break;//in eAX, Ib
	case 0xE6:sprintf_s(szText, "out "); Print_IMM(8, szText); sprintf_s(szText, "%s, ", szText); sprintf_s(szText, "%sal", szText); break;//out Ib, AL
	case 0xE7:sprintf_s(szText, "out "); Print_IMM(8, szText); sprintf_s(szText, "%s, ", szText); sprintf_s(szText, "%seax, ", szText); break;//out Ib, eAX
	/* Opcode + 16bit IMM*/
	case 0xC2:sprintf_s(szText, "retn "); Print_IMM(16, szText); break;//retn lw
	case 0xCA:sprintf_s(szText, "retf "); Print_IMM(16, szText); sprintf_s(szText, "%s, ", szText); break;//retf lw
	/* Opcode + 24bit IMM*/
	case 0xC8:sprintf_s(szText, "enter "); sprintf_s(szText, "%s0x%04x", szText, (IF_IMM32(g_iif)&0x0000ffff)); sprintf_s(szText, "%s, ", szText); sprintf_s(szText, "%s0x%02x", szText, IF_IMM32(g_iif)>>16); break;//enter Iw Ib
	/* Opcode + 32bit IMM */
	case 0x05:sprintf_s(szText, "add "); sprintf_s(szText, "%seax, ", szText); Print_IMM(32, szText); break;//add eAX, Iv
	case 0x0D:sprintf_s(szText, "or "); sprintf_s(szText, "%seax, ", szText); Print_IMM(32, szText); break;//or eAx, Iv
	case 0x15:sprintf_s(szText, "adc "); sprintf_s(szText, "%seax, ", szText); Print_IMM(32, szText); break;//adc eAX, Iv
	case 0x1D:sprintf_s(szText, "adc "); sprintf_s(szText, "%seax, ", szText); Print_IMM(32, szText); break;//adc eAX, Iv
	case 0x25:sprintf_s(szText, "and "); sprintf_s(szText, "%seax, ", szText); Print_IMM(32, szText); break;//and eAX, Iv
	case 0x2D:sprintf_s(szText, "sub "); sprintf_s(szText, "%seax, ", szText); Print_IMM(32, szText); break;//sub eAX, Iv
	case 0x35:sprintf_s(szText, "xor "); sprintf_s(szText, "%seax, ", szText); Print_IMM(32, szText); break;//xor eAX, Iv
	case 0x3D:sprintf_s(szText, "cmp "); sprintf_s(szText, "%seax, ", szText); Print_IMM(32, szText); break;//cmp eAX, Iv
	case 0x68:sprintf_s(szText, "push "); break;//push Iv
	case 0xA9:sprintf_s(szText, "test "); sprintf_s(szText, "%seax, ", szText); Print_IMM(32, szText); break;//test eAX, Iv
	case 0xB8:sprintf_s(szText, "mov "); sprintf_s(szText, "%seax, ", szText); Print_IMM(32, szText); break;//mov eAX, Iv
	case 0xB9:sprintf_s(szText, "mov "); sprintf_s(szText, "%secx, ", szText); Print_IMM(32, szText); break;//mov eCX, Iv
	case 0xBA:sprintf_s(szText, "mov "); sprintf_s(szText, "%sedx, ", szText); Print_IMM(32, szText); break;//mov eDX, Iv
	case 0xBB:sprintf_s(szText, "mov "); sprintf_s(szText, "%sebx, ", szText); Print_IMM(32, szText); break;//mov eBX, Iv
	case 0xBC:sprintf_s(szText, "mov "); sprintf_s(szText, "%sesp, ", szText); Print_IMM(32, szText); break;//mov eSP, Iv
	case 0xBD:sprintf_s(szText, "mov "); sprintf_s(szText, "%sebp, ", szText); Print_IMM(32, szText); break;//mov eBP, Iv
	case 0xBE:sprintf_s(szText, "mov "); sprintf_s(szText, "%sesi, ", szText); Print_IMM(32, szText); break;//mov eSI, Iv
	case 0xBF:sprintf_s(szText, "mov "); sprintf_s(szText, "%sedi, ", szText); Print_IMM(32, szText); break;//mov eDI, Iv
	/* Opcode + 8bit DIS */
	case 0x70:sprintf_s(szText, "jo "); Print_DIS(8, szText); break;//jo Jb
	case 0x71:sprintf_s(szText, "jno "); Print_DIS(8, szText); break;//jno Jb
	case 0x72:sprintf_s(szText, "jb "); Print_DIS(8, szText); break;//jb Jb
	case 0x73:sprintf_s(szText, "jnb "); Print_DIS(8, szText); break;//jnb Jb
	case 0x74:sprintf_s(szText, "jz "); Print_DIS(8, szText); break;//jz Jb
	case 0x75:sprintf_s(szText, "jnz "); Print_DIS(8, szText); break;//jnz Jb
	case 0x76:sprintf_s(szText, "jbe "); Print_DIS(8, szText); break;//jbe Jb
	case 0x77:sprintf_s(szText, "ja "); Print_DIS(8, szText); break;//ja Jb
	case 0x78:sprintf_s(szText, "js "); Print_DIS(8, szText); break;//js Jb
	case 0x79:sprintf_s(szText, "jns "); Print_DIS(8, szText); break;//jns Jb
	case 0x7A:sprintf_s(szText, "jp "); Print_DIS(8, szText); break;//jp Jb
	case 0x7B:sprintf_s(szText, "jnp "); Print_DIS(8, szText); break;//jnp Jb
	case 0x7C:sprintf_s(szText, "jl "); Print_DIS(8, szText); break;//jl Jb
	case 0x7D:sprintf_s(szText, "jnl "); Print_DIS(8, szText); break;//jnl Jb
	case 0x7E:sprintf_s(szText, "jle "); Print_DIS(8, szText); break;//jle Jb
	case 0x7F:sprintf_s(szText, "jnle "); Print_DIS(8, szText); break;//jnle Jb
	case 0xE0:sprintf_s(szText, "loopnz "); Print_DIS(8, szText); break;//loopnz Jb
	case 0xE1:sprintf_s(szText, "loopz "); Print_DIS(8, szText); break;//loopz Jb
	case 0xE2:sprintf_s(szText, "loop "); Print_DIS(8, szText); break;//loop Jb
	case 0xEB:sprintf_s(szText, "jmp "); Print_DIS(8, szText); break;//jmp Jb
	/* Opcode + 32bit DIS */
	case 0xA0:sprintf_s(szText, "mov "); sprintf_s(szText, "%sal, ", szText); Size_directive(8, szText); sprintf_s(szText, "%s[", szText); Print_DIS(32, szText); sprintf_s(szText, "%s]", szText); break;//mov AL, Ob
	case 0xA1:sprintf_s(szText, "mov "); sprintf_s(szText, "%seax, ", szText); Size_directive(32, szText); sprintf_s(szText, "%s[", szText); Print_DIS(32, szText); sprintf_s(szText, "%s]", szText); break;//mov eAX, Ov
	case 0xA2:sprintf_s(szText, "mov "); Size_directive(8, szText); sprintf_s(szText, "%s[", szText); Print_DIS(32, szText); sprintf_s(szText, "%s]", szText); sprintf_s(szText, "%s, al", szText); break;//mov Ob, AL
	case 0xA3:sprintf_s(szText, "mov "); Size_directive(32, szText); sprintf_s(szText, "%s[", szText); Print_DIS(32, szText); sprintf_s(szText, "%s]", szText); sprintf_s(szText, "%s, eax", szText); break;//mov Ov, eAX
	case 0xE8:sprintf_s(szText, "call "); Print_DIS(32, szText); break;//call Jz
	case 0xE9:sprintf_s(szText, "jmp "); Print_DIS(32, szText); break;//jmp Jz
	/* Opcode */
	case 0x06:sprintf_s(szText, "push es"); break;
	case 0x07:sprintf_s(szText, "pop es"); break;
	case 0x0E:sprintf_s(szText, "push ss"); break;
	case 0x16:sprintf_s(szText, "push ss"); break;
	case 0x17:sprintf_s(szText, "pop ss"); break;
	case 0x1E:sprintf_s(szText, "push ds"); break;
	case 0x1F:sprintf_s(szText, "pop ds"); break;
	case 0x27:sprintf_s(szText, "daa"); break;
	case 0x2F:sprintf_s(szText, "das"); break;
	case 0x37:sprintf_s(szText, "aaa"); break;
	case 0x3F:sprintf_s(szText, "aas"); break;
	case 0x40:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "inc ax"):sprintf_s(szText, "inc eax"); break;
	case 0x41:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "inc cx"):sprintf_s(szText, "inc ecx"); break;
	case 0x42:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "inc dx"):sprintf_s(szText, "inc edx"); break;
	case 0x43:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "inc bx"):sprintf_s(szText, "inc ebx"); break;
	case 0x44:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "inc sp"):sprintf_s(szText, "inc esp"); break;
	case 0x45:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "inc bp"):sprintf_s(szText, "inc ebp"); break;
	case 0x46:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "inc si"):sprintf_s(szText, "inc esi"); break;
	case 0x47:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "inc di"):sprintf_s(szText, "inc edi"); break;
	case 0x48:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "dex ax"):sprintf_s(szText, "dec eax"); break;
	case 0x49:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "dex cx"):sprintf_s(szText, "dec ecx"); break;
	case 0x4A:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "dex dx"):sprintf_s(szText, "dec edx"); break;
	case 0x4B:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "dex bx"):sprintf_s(szText, "dec ebx"); break;
	case 0x4C:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "dex sp"):sprintf_s(szText, "dec esp"); break;
	case 0x4D:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "dex bp"):sprintf_s(szText, "dec ebp"); break;
	case 0x4E:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "dex si"):sprintf_s(szText, "dec esi"); break;
	case 0x4F:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "dex di"):sprintf_s(szText, "dec edi"); break;
	case 0x50:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "push ax"):sprintf_s(szText, "push eax"); break;
	case 0x51:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "push cx"):sprintf_s(szText, "push ecx"); break;
	case 0x52:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "push dx"):sprintf_s(szText, "push edx"); break;
	case 0x53:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "push bx"):sprintf_s(szText, "push ebx"); break;
	case 0x54:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "push sp"):sprintf_s(szText, "push esp"); break;
	case 0x55:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "push bp"):sprintf_s(szText, "push ebp"); break;
	case 0x56:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "push si"):sprintf_s(szText, "push esi"); break;
	case 0x57:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "push di"):sprintf_s(szText, "push edi"); break;
	case 0x58:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "pop ax"):sprintf_s(szText, "pop eax"); break;
	case 0x59:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "pop cx"):sprintf_s(szText, "pop ecx"); break;
	case 0x5A:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "pop dx"):sprintf_s(szText, "pop edx"); break;
	case 0x5B:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "pop bx"):sprintf_s(szText, "pop ebx"); break;
	case 0x5C:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "pop sp"):sprintf_s(szText, "pop esp"); break;
	case 0x5D:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "pop bp"):sprintf_s(szText, "pop ebp"); break;
	case 0x5E:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "pop si"):sprintf_s(szText, "pop esi"); break;
	case 0x5F:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "pop di"):sprintf_s(szText, "pop edi"); break;
	case 0x60:sprintf_s(szText, "pusha"); break;
	case 0x61:sprintf_s(szText, "popa"); break;
	case 0x6C:sprintf_s(szText, "insb "); Size_directive(8, szText); (g_is.Prefix_AddressSize)?sprintf_s(szText, "%s[di], dx", szText):sprintf_s(szText, "%s[edi], dx", szText); break;
	case 0x6D:sprintf_s(szText, "insw "); Size_directive(16, szText); (g_is.Prefix_AddressSize)?sprintf_s(szText, "%s[di], dx", szText):sprintf_s(szText, "%s[edi], dx", szText); break;
	case 0x6E:sprintf_s(szText, "outsb "); sprintf_s(szText, "%sdx, ", szText); Size_directive(8, szText); (g_is.Prefix_AddressSize)?sprintf_s(szText, "%s[di]", szText):sprintf_s(szText, "%s[edi]", szText); break;
	case 0x6F:sprintf_s(szText, "outsw "); sprintf_s(szText, "%sdx, ", szText); Size_directive(16, szText); (g_is.Prefix_AddressSize)?sprintf_s(szText, "%s[di]", szText):sprintf_s(szText, "%s[edi]", szText); break;
	case 0x90:sprintf_s(szText, "nop"); break;
	case 0x91:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "xchg ax, cx"):sprintf_s(szText, "xchg eax, ecx"); break;
	case 0x92:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "xchg ax, dx"):sprintf_s(szText, "xchg eax, edx"); break;
	case 0x93:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "xchg ax, bx"):sprintf_s(szText, "xchg eax, ebx"); break;
	case 0x94:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "xchg ax, sp"):sprintf_s(szText, "xchg eax, esp"); break;
	case 0x95:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "xchg ax, bp"):sprintf_s(szText, "xchg eax, ebp"); break;
	case 0x96:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "xchg ax, si"):sprintf_s(szText, "xchg eax, esi"); break;
	case 0x97:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "xchg ax, di"):sprintf_s(szText, "xchg eax, edi"); break;
	case 0x98:sprintf_s(szText, "cbw"); break;
	case 0x99:sprintf_s(szText, "cwd"); break;
	case 0x9B:sprintf_s(szText, "wait"); break;
	case 0x9C:sprintf_s(szText, "pushfd"); break;
	case 0x9D:sprintf_s(szText, "popfd"); break;
	case 0x9E:sprintf_s(szText, "sahf"); break;
	case 0x9F:sprintf_s(szText, "lahf"); break;
	case 0xA4:sprintf_s(szText, "movsb Xb, Yb"); Size_directive(8, szText); (g_is.Prefix_AddressSize)?sprintf_s(szText, "%s[si],", szText):sprintf_s(szText, "%s[esi], ", szText); Size_directive(8, szText); (g_is.Prefix_AddressSize)?sprintf_s(szText, "%s[di]", szText):sprintf_s(szText, "%s[edi]", szText); break;
	case 0xA5:sprintf_s(szText, "movsw Xv, Yv"); Size_directive(32, szText); (g_is. Prefix_AddressSize)?sprintf_s(szText, "%s[si],", szText):sprintf_s(szText, "%s[esi], ", szText); Size_directive(32, szText); (g_is.Prefix_AddressSize)?sprintf_s(szText, "%s[di]", szText):sprintf_s(szText, "%s[edi]", szText); break;
	case 0xA6:sprintf_s(szText, "cmpsb Xb, Yb"); Size_directive(8, szText); (g_is. Prefix_AddressSize)?sprintf_s(szText, "%s[si],", szText):sprintf_s(szText, "%s[esi], ", szText); Size_directive(8, szText); (g_is.Prefix_AddressSize)?sprintf_s(szText, "%s[di]", szText):sprintf_s(szText, "%s[edi]", szText); break;
	case 0xA7:sprintf_s(szText, "cmpsw Xv, Yv"); Size_directive(32, szText); (g_is. Prefix_AddressSize)?sprintf_s(szText, "%s[si],", szText):sprintf_s(szText, "%s[esi], ", szText); Size_directive(32, szText); (g_is.Prefix_AddressSize)?sprintf_s(szText, "%s[di]", szText):sprintf_s(szText, "%s[edi]", szText); break;
	case 0xAA:sprintf_s(szText, "stosb "); Size_directive(8, szText); (g_is. Prefix_AddressSize)?sprintf_s(szText, "%s[di]", szText):sprintf_s(szText, "%s[edi]", szText); break;
	case 0xAB:sprintf_s(szText, "stosw "); Size_directive(32, szText); (g_is. Prefix_AddressSize)?sprintf_s(szText, "%s[di]", szText):sprintf_s(szText, "%s[edi]", szText); break;
	case 0xAC:sprintf_s(szText, "lobsb "); Size_directive(8, szText); (g_is. Prefix_AddressSize)?sprintf_s(szText, "%s[si]", szText):sprintf_s(szText, "%s[esi]", szText); break;
	case 0xAD:sprintf_s(szText, "lobsw "); Size_directive(32, szText); (g_is. Prefix_AddressSize)?sprintf_s(szText, "%s[si]", szText):sprintf_s(szText, "%s[esi]", szText); break;
	case 0xAE:sprintf_s(szText, "scasb "); Size_directive(8, szText); (g_is. Prefix_AddressSize)?sprintf_s(szText, "%s[di]", szText):sprintf_s(szText, "%s[edi]", szText); break;
	case 0xAF:sprintf_s(szText, "scasw "); Size_directive(32, szText); (g_is. Prefix_AddressSize)?sprintf_s(szText, "%s[di]", szText):sprintf_s(szText, "%s[edi]", szText); break;
	case 0xC3:sprintf_s(szText, "ret"); break;
	case 0xC9:sprintf_s(szText, "leave"); break;
	case 0xCB:sprintf_s(szText, "retf"); break;
	case 0xCC:sprintf_s(szText, "int 3"); break;
	case 0xCE:sprintf_s(szText, "info"); break;
	case 0xCF:sprintf_s(szText, "iret"); break;
	case 0xD6:sprintf_s(szText, "salc"); break;
	case 0xD7:sprintf_s(szText, "xlat"); break;
	case 0xEC:sprintf_s(szText, "in al, dx"); break;
	case 0xED:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "in ax, ex"):sprintf_s(szText, "in eax, ex"); break;
	case 0xEE:sprintf_s(szText, "out dx, al"); break;
	case 0xEF:(g_is.Prefix_OpcodeSize)?sprintf_s(szText, "out dx, ax"):sprintf_s(szText, "out dx, eax"); break;
	case 0xF1:sprintf_s(szText, "int 1"); break;
	case 0xF4:sprintf_s(szText, "htl"); break;
	case 0xF5:sprintf_s(szText, "cmc"); break;
	case 0xF8:sprintf_s(szText, "clc"); break;
	case 0xF9:sprintf_s(szText, "stc"); break;
	case 0xFA:sprintf_s(szText, "cli"); break;
	case 0xFB:sprintf_s(szText, "sti"); break;
	case 0xFC:sprintf_s(szText, "cld"); break;
	case 0xFD:sprintf_s(szText, "std"); break;
	/* Opcode + MOD(16bit 처리 고정) */
	case 0x63:sprintf_s(szText, "arpl "); Print_ModRM(IF_MOD(g_iif), 16, szText); break; //16bit 처리
	/* Opcode + 32bit DIS + 16bit IMM */
	case 0x9A:sprintf_s(szText, "call far "); Print_IMM(16, szText); sprintf_s(szText, ":"); Print_DIS(32, szText); break;//call Ap
	case 0xEA:sprintf_s(szText, "jmp far "); Print_IMM(16, szText); sprintf_s(szText, ":"); Print_DIS(32, szText); break;//jmp Ap
	/* float 형, 복잡한 처리... */
	case 0xD8:
	case 0xD9:
	case 0xDA:
	case 0xDB:
	case 0xDC:
	case 0xDD:
	case 0xDE:
	case 0xDF:Print_float(IF_OP(g_iif), IF_MOD(g_iif), szText); break;
	default: sprintf_s(szText, "???");
	}

	lItem->pszText=szText;
	m_list->SetItem(lItem);
}

int Set_IF_SIB(const BYTE modrm, unsigned char* psmBase)
{
	if(!g_is.Prefix_AddressSize)	{	// 16bit는 안 씀
		switch(ModRMTable[modrm]) {
		case 4: IF_SIB(g_iif)=*((PBYTE)psmBase++); if(BaseTable[IF_SIB(g_iif)]==5) { IF_DIS32(g_iif)=*((PDWORD)psmBase);  return 5;} return 1;
		case 12:
		case 20: IF_SIB(g_iif)=*((PBYTE)psmBase); return 1;
		default: IF_SIB(g_iif)=NULL; return 0;
		}
	}
	else {
		IF_SIB(g_iif)=NULL; return 0;
	}
}

int Set_IF_DIS(const BYTE modrm, unsigned char* psmBase, const BYTE bit)
{
	if(bit!=0x00) {
		switch(bit) {
		case 8: IF_DIS8(g_iif) = *((PBYTE)psmBase); return 1;
		case 16: IF_DIS16(g_iif) = *((PWORD)psmBase); return 2;
		case 32:
			if(g_is.Prefix_AddressSize) {
				IF_DIS16(g_iif) = *((PWORD)psmBase);
				return 2;
			}
			else {
				IF_DIS32(g_iif) = *((PDWORD)psmBase);
				return 4;
			}
		default: IF_DIS32(g_iif) = NULL; return 0;
		}
	}
	else {
		if(g_is.Prefix_AddressSize)	{
			switch(ModRMTable[modrm]) {
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15: IF_DIS8(g_iif)=*((PBYTE)psmBase); return 1;
			case 6:
			case 16:
			case 17:
			case 18:
			case 19:
			case 20:
			case 21:
			case 22:
			case 23: IF_DIS16(g_iif)=*((PWORD)psmBase); return 2;
			default: IF_DIS16(g_iif)=NULL; return 0;
			}
		}
		else {
			switch(ModRMTable[modrm]) {
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15: IF_DIS8(g_iif)=*((PBYTE)psmBase); return 1;
			case 5:
			case 16:
			case 17:
			case 18:
			case 19:
			case 20:
			case 21:
			case 22:
			case 23: IF_DIS32(g_iif)=*((PDWORD)psmBase); return 4;
			default: IF_DIS32(g_iif)=NULL; return 0;
			}
		}
	}
}

int Set_IF_IMM(const BYTE bit,unsigned char* psmBase)
{
	switch(bit) {
	case 8: IF_IMM8(g_iif) = *((PBYTE)psmBase); return 1;
	case 16: IF_IMM16(g_iif) = *((PWORD)psmBase); return 2;
	case 32:
		if(g_is.Prefix_AddressSize) {
			IF_IMM16(g_iif) = *((PWORD)psmBase);
			return 2;
		}
		else {
			IF_IMM32(g_iif) = *((PDWORD)psmBase);
			return 4;
		}
	default: IF_IMM32(g_iif) = NULL; return 0;
	}
}

int Set_ARPL_DIS(const BYTE modrm, unsigned char* psmBase)
{
	switch(ModRMTable[modrm]) {
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15: IF_DIS8(g_iif)=*((PBYTE)psmBase); return 1;
	case 6:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
	case 21:
	case 22:
	case 23: IF_DIS16(g_iif)=*((PWORD)psmBase); return 2;
	default: IF_DIS16(g_iif)=NULL; return 0;
	}
}

BOOL Check_Prefix(const BYTE Opcode)
{
	switch(Opcode) {
	//Prefix
	case 0x26://ES:
	case 0x2E://CS:
	case 0x36://SS:
	case 0x3E://DS:
	case 0x64://FS:
	case 0x65://GS:
	return TRUE;
	default: break;
	}
	switch(Opcode) {
	case 0x66://OPSIZE:
	g_is.Prefix_OpcodeSize = TRUE; return TRUE;
	case 0x67://ADSIZE:
	g_is.Prefix_AddressSize = TRUE; return TRUE;
	default: break;
	}
	switch(Opcode) {
	case 0xF0://LOCK:
	case 0xF2://REPNE:
	case 0xF3://REP:
	return TRUE;
	default: break;
	}

	return FALSE;
}

//
// One-byte Opcode Map
//
unsigned char* Disassemble(const BYTE Code, unsigned char* psmBase)
{
	if(Check_Prefix(Code)) {
		IF_PRE(g_iif) = Code;
		IF_OP(g_iif) = *((PBYTE)++psmBase);
	}
	else {
		IF_PRE(g_iif) = NULL;
		IF_OP(g_iif) = Code;
	}

	psmBase++;
	switch(IF_OP(g_iif))
	{
	case 0x0F://TWOBYTE
	IF_OP2(g_iif)=*((PWORD)--psmBase); psmBase+=2; break; //2바이트 처리 필요
	/* Opcode + 8bit MOD */
	case 0x00://add Eb, Gb
	case 0x01://add Ev, Gv
	case 0x02://add Gb, Eb
	case 0x03://add Gv, Ev
	case 0x08://or Eb, Gb
	case 0x09://or Ev, Gv
	case 0x0A://or Gb, Eb
	case 0x0B://or Gv, Ev
	case 0x10://adc Eb, Gb
	case 0x11://adc Ev, Gv
	case 0x12://adc Gb, Eb
	case 0x13://adc Gv, Ev
	case 0x18://sbb Eb, Gb
	case 0x19://sbb Ev, Gv
	case 0x1A://sbb Gb, Eb
	case 0x1B://sbb Gv, Ev
	case 0x20://and Eb, Gb
	case 0x21://and Ev, Gv
	case 0x22://and Gb, Eb
	case 0x23://and Gv, Ev
	case 0x28://sub Eb, Gb
	case 0x29://sub Ev, Gv
	case 0x2A://sub Gb, Eb
	case 0x2B://sub Gv, Ev
	case 0x30://xor Eb, Gb
	case 0x31://xor Ev, Gv
	case 0x32://xor Gb, Eb
	case 0x33://xor Gv, Ev
	case 0x38://cmp Eb, Gb
	case 0x39://cmp Ev, Gv
	case 0x3A://cmp Gb, Eb
	case 0x3B://cmp Gv, Ev
	case 0x62://BOUND
	case 0x84://test Eb, Gb
	case 0x85://test Ev, Gv
	case 0x86://xchg Eb, Gb
	case 0x87://xchg Ev, Gv
	case 0x88://mov Eb, Gb
	case 0x89://mov Ev, Gv
	case 0x8A://mov Gb, Eb
	case 0x8B://mov Gv, Ev
	case 0x8C://mov Ew, Sw
	case 0x8D://lea Gv, M
	case 0x8E://mov Sw, Ew
	case 0x8F://pop Ev Reg가 0으로 고정됨(2 ~ 6)
	case 0xC4://les Gv, Mp(lea처럼 좀 복잡)
	case 0xC5://lds Gv, Mp
	case 0xD0://rol Eb, 1
	case 0xD1://ro1 Ev, 1
	case 0xD2://rol Eb, CL
	case 0xD3://rol Ev, CL
	//////// float /////////
	case 0xD8://ESC 0, float
	case 0xD9://ESC 1, float
	case 0xDA://ESC 2, float
	case 0xDB://ESC 3, float
	case 0xDC://ESC 4, float
	case 0xDD://ESC 5, float
	case 0xDE://ESC 6, float
	case 0xDF://ESC 7, float
	case 0xFE://inc, dec 8bit
	case 0xFF://inc, dec 32bit
	IF_MOD(g_iif)=*(psmBase); psmBase+=Set_IF_SIB(IF_MOD(g_iif), ++psmBase); psmBase+=Set_IF_DIS(IF_MOD(g_iif), psmBase, 0); psmBase+=Set_IF_IMM(0, psmBase); break;
	/* Opcode + 8bit MOD + 8bit IMM */
	case 0x6B://IMUL Gv Ev Ib
	case 0x80://add Eb, Ib
	case 0x82://sub Eb, Ib
	case 0x83://sub Ev, Ib
	case 0xC0://ROR Eb, Ib
	case 0xC1://ROR Ev, Ib
	case 0xC6://mov Eb, Ib Reg가 0으로 고정됨(2 ~ 6)
	case 0xF6://test Eb
	IF_MOD(g_iif)=*(psmBase); psmBase+=Set_IF_SIB(IF_MOD(g_iif), ++psmBase); psmBase+=Set_IF_DIS(IF_MOD(g_iif), psmBase, 0); psmBase+=Set_IF_IMM(8, psmBase); break;
	/* Opcode + 8bit MOD + 32bit IMM */
	case 0x81://add Ev Iv
	case 0x69://IMUL Gv Ev Iv
	case 0xC7://mov Ev, Iv Reg가 0으로 고정됨(2 ~ 6)
	case 0xF7://test Ev
	IF_MOD(g_iif)=*(psmBase); psmBase+=Set_IF_SIB(IF_MOD(g_iif), ++psmBase); psmBase+=Set_IF_DIS(IF_MOD(g_iif), psmBase, 0); psmBase+=Set_IF_IMM(32, psmBase); break;
	/* Opcode + 8bit IMM */
	case 0x04://add AL, Ib
	case 0x0C://or AL, ib
	case 0x14://adc AL, Ib
	case 0x1C://sbb AL, Ib
	case 0x24://and AL, Ib
	case 0x2C://sub AL, Ib
	case 0x34://xor AL, Ib
	case 0x3C://cmp AL, Ib
	case 0x6A://push Ib
	case 0xA8://test AL, Ib
	case 0xB0://mov AL, Ib
	case 0xB1://mov CL, Ib
	case 0xB2://mov DL, Ib
	case 0xB3://mov BL, Ib
	case 0xB4://mov AH, Ib
	case 0xB5://mov CH, Ib
	case 0xB6://mov DH, Ib
	case 0xB7://mov BH, Ib
	case 0xCD://int Ib
	case 0xD4://aam Ib
	case 0xD5://aad Ib
	case 0xE3://jcxz
	case 0xE4://in AL, Ib
	case 0xE5://in eAX, Ib
	case 0xE6://out Ib, AL
	case 0xE7://out Ib, eAX
	IF_MOD(g_iif)=NULL; IF_SIB(g_iif)=NULL; psmBase+=Set_IF_DIS(0, psmBase, 0); psmBase+=Set_IF_IMM(8, psmBase); break;
	/* Opcode + 16bit IMM*/
	case 0xC2://retn lw
	case 0xCA://retf lw
	IF_MOD(g_iif)=NULL; IF_SIB(g_iif)=NULL; psmBase+=Set_IF_DIS(0, psmBase, 0); psmBase+=Set_IF_IMM(16, psmBase); break;
	/* Opcode + 24bit IMM*/
	case 0xC8://enter Iw Ib
	IF_MOD(g_iif)=NULL; IF_SIB(g_iif)=NULL; psmBase+=Set_IF_DIS(0, psmBase, 0); IF_IMM32(g_iif)=((*((PDWORD)psmBase))&0x00FFFFFF); psmBase+=3; break;
	/* Opcode + 32bit IMM */
	case 0x05://add eAX, Iv
	case 0x0D://or eAx, Iv
	case 0x15://adc eAX, Iv
	case 0x1D://adc eAX, Iv
	case 0x25://and eAX, Iv
	case 0x2D://sub eAX, Iv
	case 0x35://xor eAX, Iv
	case 0x3D://cmp eAX, Iv
	case 0x68://push Iv
	case 0xA9://test eAX, Iv
	case 0xB8://mov eAX, Iv
	case 0xB9://mov eCX, Iv
	case 0xBA://mov eDX, Iv
	case 0xBB://mov eBX, Iv
	case 0xBC://mov eSP, Iv
	case 0xBD://mov eBP, Iv
	case 0xBE://mov eSI, Iv
	case 0xBF://mov eDI, Iv
	IF_MOD(g_iif)=NULL; IF_SIB(g_iif)=NULL; psmBase+=Set_IF_DIS(0, psmBase, 0); psmBase+=Set_IF_IMM(32, psmBase); break;
	/* Opcode + 8bit DIS */
	case 0x70://jo Jb
	case 0x71://jno Jb
	case 0x72://jb Jb
	case 0x73://jnb Jb
	case 0x74://jz Jb
	case 0x75://jnz Jb
	case 0x76://jbe Jb
	case 0x77://ja Jb
	case 0x78://js Jb
	case 0x79://jns Jb
	case 0x7A://jp Jb
	case 0x7B://jnp Jb
	case 0x7C://jl Jb
	case 0x7D://jnl Jb
	case 0x7E://jle Jb
	case 0x7F://jnle Jb
	case 0xE0://loopnz Jb
	case 0xE1://loopz Jb
	case 0xE2://loop Jb
	case 0xEB://jmp Jb
	IF_MOD(g_iif)=NULL; IF_SIB(g_iif)=NULL; psmBase+=Set_IF_DIS(0, psmBase, 8); psmBase+=Set_IF_IMM(0, psmBase); break;
	/* Opcode + 32bit DIS */
	case 0xA0://mov AL, Ob
	case 0xA1://mov eAX, Ov
	case 0xA2://mov Ob, AL
	case 0xA3://mov Ov, eAX
	case 0xE8://call Jz
	case 0xE9://jmp Jz
	IF_MOD(g_iif)=NULL; IF_SIB(g_iif)=NULL; psmBase+=Set_IF_DIS(0, psmBase, 32); psmBase+=Set_IF_IMM(0, psmBase); break;
	/* Opcode*/
	case 0x06://push es
	case 0x07://pop es
	case 0x0E://push cs
	case 0x16://push ss
	case 0x17://pop ss
	case 0x1E://push ds
	case 0x1F://pop ds
	case 0x27://DAA
	case 0x2F://DAS
	case 0x37://AAA
	case 0x3F://AAS
	case 0x40://inc eAx
	case 0x41://inc eCx
	case 0x42://inc eDx
	case 0x43://inc eBx
	case 0x44://inc eSP
	case 0x45://inc eBP
	case 0x46://inc eSI
	case 0x47://inc eDI
	case 0x48://dec eAx
	case 0x49://dec eCx
	case 0x4A://dec eDx
	case 0x4B://dec eBx
	case 0x4C://dec eSP
	case 0x4D://dec eBP
	case 0x4E://dec eSI
	case 0x4F://dec eDI
	case 0x50://push eAx
	case 0x51://push eCx
	case 0x52://push eDx
	case 0x53://push eBx
	case 0x54://push eSP
	case 0x55://push eBP
	case 0x56://push eSI
	case 0x57://push eDI
	case 0x58://pop eAx
	case 0x59://pop eCx
	case 0x5A://pop eDx
	case 0x5B://pop eBx
	case 0x5C://pop eSP
	case 0x5D://pop eBP
	case 0x5E://pop eSI
	case 0x5F://pop eDI
	case 0x60://pusha
	case 0x61://popa
	case 0x6C://INSB Yb DX
	case 0x6D://INSW Yb DX
	case 0x6E://OUTSB DX Xb
	case 0x6F://OUTSW DX Xv
	case 0x90://nop
	case 0x91://xchg eAX, ECX
	case 0x92://xchg eAX, EDX
	case 0x93://xchg eAX, EBX
	case 0x94://xchg eAX, ESP
	case 0x95://xchg eAX, EBP
	case 0x96://xchg eAX, ESI
	case 0x97://xchg eAX, EDI
	case 0x98://CBW
	case 0x99://CWD
	case 0x9B://WAIT
	case 0x9C://pushfd
	case 0x9D://popfd
	case 0x9E://SAHF
	case 0x9F://LAHF
	case 0xA4://movsb Xb, Yb
	case 0xA5://movsw Xv, Yv
	case 0xA6://cmpsb Xb, Yb
	case 0xA7://cmpsw Xv, Yv
	case 0xAA://stosb Yb, AL
	case 0xAB://stosw Yv, eAX
	case 0xAC://lobsb AL, Xb
	case 0xAD://lobsw eAX, Xv
	case 0xAE://scasb AL, Yb
	case 0xAF://scasw eAX, Yv
	case 0xC3://ret
	case 0xC9://leave
	case 0xCB://retf
	case 0xCC://int3
	case 0xCE://info
	case 0xCF://iret
	case 0xD6://SALC
	case 0xD7://XLAT
	case 0xEC://in AL, DX
	case 0xED://in eAX, DX
	case 0xEE://out DX, AL
	case 0xEF://out DX, eAX
	case 0xF1://int1
	case 0xF4://HTL
	case 0xF5://CMC
	case 0xF8://CLC
	case 0xF9://STC
	case 0xFA://CLI
	case 0xFB://STI
	case 0xFC://CLD
	case 0xFD://STD
	IF_MOD(g_iif)=NULL; IF_SIB(g_iif)=NULL; psmBase+=Set_IF_DIS(0, psmBase, 0); psmBase+=Set_IF_IMM(0, psmBase); break;
	/* Opcode + MOD(16bit 처리 고정)*/
	case 0x63://ARPL	16bit 처리
	IF_MOD(g_iif)=*(psmBase); IF_SIB(g_iif)=NULL; psmBase+=Set_ARPL_DIS(IF_MOD(g_iif), psmBase); psmBase+=Set_IF_IMM(0, psmBase); break;
	/* Opcode + 32bit DIS + 16bit IMM*/
	case 0x9A://call Ap
	case 0xEA://jmp Ap
	IF_MOD(g_iif)=NULL; IF_SIB(g_iif)=NULL; psmBase+=Set_IF_DIS(0, psmBase, 32); psmBase+=Set_IF_IMM(16, psmBase); break;
	}

	return psmBase;
}

void Reset_iif(void)	// NULL로 초기화
{
	memset(&g_iif, 0, sizeof(INTEL_INSTRUCTION_FORMAT));
	memset(&g_is, 0, sizeof(INSTRUCTION_STATUS));
}

BOOL Init_Disassemble(const unsigned char* psmBase, const DWORD smSize, CListCtrl* m_list)
//sm(Section Memory)
{
	DWORD smOffset = NULL;
	BOOL count_switch = FALSE;
	char szText[MAX_PATH]="";
	LVITEM lItem;
	unsigned int index = 0;

	m_list->DeleteAllItems();

	lItem.mask=LVIF_TEXT;
	while(smOffset < smSize)	//Offset이 Size보다 무조건 작아야 함.
	{
		lItem.iItem=index;
		lItem.iSubItem=0;
		memset(szText, 0, MAX_PATH);
		sprintf_s(szText, "0x%05x", smOffset);
		lItem.pszText=szText;
		m_list->InsertItem(&lItem);

		Reset_iif();
		smOffset += Disassemble(*(psmBase+smOffset), (unsigned char*)(psmBase+smOffset)) - (psmBase+smOffset);

		lItem.iSubItem=1;
		memset(szText, 0, MAX_PATH);
		sprintf_s(szText, "%02x %02x %02x %02x %08x %08x", IF_PRE(g_iif), IF_OP(g_iif), IF_MOD(g_iif), IF_SIB(g_iif), IF_DIS32(g_iif), IF_IMM32(g_iif));
		lItem.pszText=szText;
		m_list->SetItem(&lItem);

		lItem.iSubItem=2;
		memset(szText, 0, MAX_PATH);
		PrintDisassem(m_list, &lItem);

		lItem.iSubItem=3;
		memset(szText, 0, MAX_PATH);
		sprintf_s(szText, "X");
		lItem.pszText=szText;
		m_list->SetItem(&lItem);

		index++;
	}

	return TRUE;
}

BOOL Init_Disassemble(const DWORD Base, const DWORD count, CListCtrl* m_list)
{
	DWORD smOffset = NULL;
	BOOL count_switch = FALSE;
	char szText[MAX_PATH]="";
	LVITEM lItem;
	unsigned int index = 0;
	unsigned char* base_addr = (unsigned char*)Base;

	m_list->DeleteAllItems();

	lItem.mask=LVIF_TEXT;
	while(index < count)	//Offset이 Size보다 무조건 작아야 함.
	{
		lItem.iItem=index;
		lItem.iSubItem=0;
		memset(szText, 0, MAX_PATH);
		sprintf_s(szText, "0x%05x", Base+smOffset);
		lItem.pszText=szText;
		m_list->InsertItem(&lItem);

		Reset_iif();
		smOffset += Disassemble(*(base_addr+smOffset), (unsigned char*)(base_addr+smOffset)) - (base_addr+smOffset);

		lItem.iSubItem=1;
		memset(szText, 0, MAX_PATH);
		sprintf_s(szText, "%02x %02x %02x %02x %08x %08x", IF_PRE(g_iif), IF_OP(g_iif), IF_MOD(g_iif), IF_SIB(g_iif), IF_DIS32(g_iif), IF_IMM32(g_iif));
		lItem.pszText=szText;
		m_list->SetItem(&lItem);

		lItem.iSubItem=2;
		memset(szText, 0, MAX_PATH);
		PrintDisassem(m_list, &lItem);

		lItem.iSubItem=3;
		memset(szText, 0, MAX_PATH);
		sprintf_s(szText, "X");
		lItem.pszText=szText;
		m_list->SetItem(&lItem);

		index++;
	}

	return TRUE;
}

DWORD Assem_Size(const DWORD Base) {
	DWORD Size = NULL;
	unsigned char* base_addr = (unsigned char*)Base;

	Reset_iif();
	Size = Disassemble(*base_addr, base_addr) - base_addr;

	return Size;
}

void Get_Disassem(PINTEL_INSTRUCTION_FORMAT piif, CListCtrl* m_list, DWORD row, DWORD column) {
	CString szText = NULL;
	CString remainder1 = NULL;
	CString remainder2 = NULL;
	CString remainder3 = NULL;
	CString remainder4 = NULL;
	CString remainder5 = NULL;
	CString remainder6 = NULL;
	
	szText = m_list->GetItemText(row, column);
	AfxExtractSubString(remainder1, szText, 0, ' ');
	AfxExtractSubString(remainder2, szText, 1, ' ');
	AfxExtractSubString(remainder3, szText, 2, ' ');
	AfxExtractSubString(remainder4, szText, 3, ' ');
	AfxExtractSubString(remainder5, szText, 4, ' ');
	AfxExtractSubString(remainder6, szText, 5, ' ');

	piif->Instruction_Prefixes = (unsigned char)strtoul(remainder1, NULL, 16);
	piif->Opcode.One_ByteOpcode = (unsigned char)strtoul(remainder2, NULL, 16);
	piif->ModRM = (unsigned char)strtoul(remainder3, NULL, 16);
	piif->SIB = (unsigned char)strtoul(remainder4, NULL, 16);
	piif->Displacement.DWordDisplacement = strtoul(remainder5, NULL, 16);
	piif->Immediate.DWordImmediate = strtoul(remainder6, NULL, 16);
}

BOOL Check_Disassem(BYTE Opcode, CONTEXT *context, PINTEL_INSTRUCTION_FORMAT piff, PDWORD Address) {
	switch(Opcode) {
	//case 0xC2: //retn lw
	//case 0xC3: //ret
	//case 0xCA: //*Address = *(PDWORD)context->Esp; break;//retf lw, 프로세스로부터 데이터를 읽어와야 함.
	case 0xE3: *Address = context->Eip + piff->Immediate.ByteImmediate; break;//jcxz, 조건 추가
	case 0x70://jo Jb
	case 0x71://jno Jb
	case 0x72://jb Jb
	case 0x73://jnb Jb
	case 0x74://jz Jb
	case 0x75://jnz Jb
	case 0x76://jbe Jb
	case 0x77://ja Jb
	case 0x78://js Jb
	case 0x79://jns Jb
	case 0x7A://jp Jb
	case 0x7B://jnp Jb
	case 0x7C://jl Jb
	case 0x7D://jnl Jb
	case 0x7E://jle Jb
	case 0x7F://jnle Jb
	case 0xE0://loopnz Jb
	case 0xE1://loopz Jb
	case 0xE2://loop Jb
	case 0xEB: *Address = context->Eip + piff->Immediate.WordImmediate; break;//jmp Jb
	case 0xE8://call Jz
	case 0xE9: *Address = context->Eip + piff->Displacement.DWordDisplacement; break;//jmp Jz
	case 0x9A://call Ap
	case 0xEA: *Address = context->Eip + piff->Displacement.DWordDisplacement + piff->Immediate.WordImmediate; break;//jmp Ap
	default: return FALSE;
	}

	return TRUE;
}