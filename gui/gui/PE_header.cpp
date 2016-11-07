#include "stdafx.h"
#include "PE_header.h"

PE_Format g_pf;

void Print_DOS_Header(CListCtrl *pelist)
{
	const char* Define_Table[] = 
	{"e_magic", "e_cblp", "e_cp", "e_crlc", "e_cparhdr", "e_minalloc", "e_maxalloc", "e_ss", "e_sp", "e_csum", 
	 "e_ip", "e_cs", "e_lfarlc", "e_ovno", "e_res[0]", "e_res[1]", "e_res[2]", "e_res[3]", "e_oemid", "e_oeminfo", 
	 "e_res2[0]", "e_res2[1]", "e_res2[2]", "e_res2[3]", "e_res2[4]", "e_res2[5]", "e_res2[6]", "e_res2[7]", "e_res2[8]", "e_res2[9]",
	 "e_lfanew"};
	const char* Explain_Table[] = 
	{"Magic Number", "Bytes on last page of file", "Pages in file", "Relocations", "Size of header in paragraphs", "Minimum extra paragraphs needed", "Maximum extra paragraphs needed", "Initial (relative) SS value", "Initial SP value", "Checksum",
	 "Initial IP value", "Initial (relative) CS value", "File address of relocation table", "Overlay number", "Reserved words[0]",  "Reserved words[1]", "Reserved words[2]",  "Reserved words[3]", "OEM identifier (for e_oeminfo)", "OEM information; e_oemid specific", 
	 "Reserved words[0]", "Reserved words[1]", "Reserved words[2]", "Reserved words[3]", "Reserved words[4]", "Reserved words[5]", "Reserved words[6]", "Reserved words[7]", "Reserved words[8]", "Reserved words[9]",
	 "File address of new exe header"};
	const DWORD Value_Table[] = 
	{IDH(e_magic), IDH(e_cblp), IDH(e_cp), IDH(e_crlc), IDH(e_cparhdr), IDH(e_minalloc), IDH(e_maxalloc), IDH(e_ss), IDH(e_sp), IDH(e_csum), 
	 IDH(e_ip), IDH(e_cs), IDH(e_lfarlc), IDH(e_ovno), RES(e_res, 0), RES(e_res, 1), RES(e_res, 2), RES(e_res, 3), IDH(e_oemid), IDH(e_oeminfo), 
	 RES(e_res2, 0), RES(e_res2, 1), RES(e_res2, 2), RES(e_res2, 3), RES(e_res2, 4), RES(e_res2, 5), RES(e_res2, 6), RES(e_res2, 7), RES(e_res2, 8), RES(e_res2, 9),
	 IDH(e_lfanew)};
	char szText[512] = {0};
	LVITEM lItem;
	unsigned int row = 0, column = 0;

	lItem.mask = LVIF_TEXT;
	for(; row<31; row++) {
		lItem.iItem = row;
		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		sprintf(szText, Define_Table[row]);
		lItem.pszText = szText;
		pelist->InsertItem(&lItem);

		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		if(row == 30) {
			sprintf(szText, "0x%08x", Value_Table[row]);
		} else {		
			sprintf(szText, "0x%04x", Value_Table[row]);
		}
		lItem.pszText = szText;
		pelist->SetItem(&lItem);

		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		sprintf(szText, "%s", Explain_Table[row]);
		lItem.pszText = szText;
		pelist->SetItem(&lItem);

		column = 0;
	}
}

DWORD Print_FILE_Header(CListCtrl *pelist, const DWORD row)
{
	const char* Define_Table[] = {" ", "IMAGE_FILE_HEADER", " ", "Machine", "NumberOfSections", "TimeDateStamp", "PointerToSymbolTable", "NumberOfSymbols", "SizeOfOptionalHeader", "Characteristics"};
	const char* Explain_Table[] = {" ", "PE Format Structure - IMAGE_NT_HEADER - IMAGE_FILE_HEADER", " ", "Machine", "NumberOfSections", "TimeDateStamp", "PointerToSymbolTable", "NumberOfSymbols", "SizeOfOptionalHeader", "Characteristics"};
	const DWORD Value_Table[] = {0, 7, 0, IFH(Machine), IFH(NumberOfSections), IFH(TimeDateStamp), IFH(PointerToSymbolTable), IFH(NumberOfSymbols), IFH(SizeOfOptionalHeader), IFH(Characteristics)};
	char szText[512] = {0};
	LVITEM lItem;
	unsigned int line = row, column = 0;

	lItem.mask = LVIF_TEXT;
	for(; line<row+10; line++) {
		lItem.iItem = line;
		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		sprintf(szText, Define_Table[line-row]);
		lItem.pszText = szText;
		pelist->InsertItem(&lItem);

		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		switch(line-row) {
		case 5:
		case 6:
		case 7:
			sprintf(szText, "0x%08x", Value_Table[line-row]);
			break;
		case 3:
		case 4:
		case 8:
		case 9:
			sprintf(szText, "0x%04x", Value_Table[line-row]);
			break;	
		case 1:
			sprintf(szText, "%x", Value_Table[line-row]);
			break;
		case 0:
		case 2:
			sprintf(szText, " ");
			break;
		default:
			return line;
		}
		lItem.pszText = szText;
		pelist->SetItem(&lItem);

		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		sprintf(szText, "%s", Explain_Table[line-row]);
		lItem.pszText = szText;
		pelist->SetItem(&lItem);

		column = 0;
	}

	return line;
}

DWORD Print_DATA_DIRECTORY(CListCtrl *pelist, const DWORD row)
{
	const char* Define_Table[] = 
	{"IMAGE_DATA_DIRECTORY", "VirtualAddress", "Size"};
	const char* Explain_Table[] = 
	{"IMAGE_OPTIONAL_HEADER - IMAGE_DATA_DIRECTORY", "VirtualAddress", "Size"};
	char szText[512] = {0};
	LVITEM lItem;
	unsigned int line = row, column = 0;
	DWORD Lotation = 0;

	lItem.mask = LVIF_TEXT;
	for(; line<SIZE3(row); line++) {
		lItem.iItem = line;
		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		sprintf(szText, "%s<%u>", Define_Table[(line-row)%3], (line-row)/3);
		lItem.pszText = szText;
		pelist->InsertItem(&lItem);

		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		if(Lotation == 1) {
			sprintf(szText, "0x%08x", IDD(line/2, VirtualAddress));
			Lotation++;
		} else if(Lotation == 2) {
			sprintf(szText, "0x%08x", IDD(line/2, Size));
			Lotation = 0;
		} else {
			sprintf(szText, " ");
			Lotation++;
		}
		lItem.pszText = szText;
		pelist->SetItem(&lItem);

		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		sprintf(szText, "%s<%u>", Explain_Table[(line-row)%3], (line-row)/3);
		lItem.pszText = szText;
		pelist->SetItem(&lItem);

		column = 0;
	}

	return line;
}

DWORD Print_OPTIONAL_Header(CListCtrl *pelist, const DWORD row)
{
	const char* Define_Table[] = 
	{" ", "IMAGE_OPTIONAL_HEADER", " ", "Magic", "MajorLinkerVersion", "MinorLinkerVersion", "SizeOfCode", "SizeOfInitializedData", "SizeOfUninitializedData", "AddressOfEntryPoint", "BaseOfCode", "BaseOfData", 
	"ImageBase", "SectionAlignment", "FileAlignment", "MajorOperatingSystemVersion", "MinorOperatingSystemVersion", "MajorImageVersion", "MinorImageVersion", "MajorSubsystemVersion", "MinorSubsystemVersion", "Win32VersionValue", 
	"SizeOfImage", "SizeOfHeaders", "CheckSum", "Subsystem", "DllCharacteristics", "SizeOfStackReserve", "SizeOfStackCommit", "SizeOfHeapReserve", "SizeOfHeapCommit", "LoaderFlags", 
	"NumberOfRvaAndSizes"};
	const char* Explain_Table[] = 
	{" ", "PE Format Structure - IMAGE_NT_HEADER - IMAGE_OPTIONAL_HEADER", " ", "Magic", "MajorLinkerVersion", "MinorLinkerVersion", "SizeOfCode", "SizeOfInitializedData", "SizeOfUninitializedData", "AddressOfEntryPoint", "BaseOfCode", "BaseOfData", 
	"ImageBase", "SectionAlignment", "FileAlignment", "MajorOperatingSystemVersion", "MinorOperatingSystemVersion", "MajorImageVersion", "MinorImageVersion", "MajorSubsystemVersion", "MinorSubsystemVersion", "Win32VersionValue", 
	"SizeOfImage", "SizeOfHeaders", "CheckSum", "Subsystem", "DllCharacteristics", "SizeOfStackReserve", "SizeOfStackCommit", "SizeOfHeapReserve", "SizeOfHeapCommit", "LoaderFlags", 
	"NumberOfRvaAndSizes"};
	const DWORD Value_Table[] = 
	{0, 30, 0, IOH(Magic), IOH(MajorLinkerVersion), IOH(MinorLinkerVersion), IOH(SizeOfCode), IOH(SizeOfInitializedData), IOH(SizeOfUninitializedData), IOH(AddressOfEntryPoint), IOH(BaseOfCode), IOH(BaseOfData), 
	IOH(ImageBase), IOH(SectionAlignment), IOH(FileAlignment), IOH(MajorOperatingSystemVersion), IOH(MinorOperatingSystemVersion), IOH(MajorImageVersion), IOH(MinorImageVersion), IOH(MajorSubsystemVersion), IOH(MinorSubsystemVersion), IOH(Win32VersionValue), 
	IOH(SizeOfImage), IOH(SizeOfHeaders), IOH(CheckSum), IOH(Subsystem), IOH(DllCharacteristics), IOH(SizeOfStackReserve), IOH(SizeOfStackCommit), IOH(SizeOfHeapReserve), IOH(SizeOfHeapCommit), IOH(LoaderFlags), 
	IOH(NumberOfRvaAndSizes)};
	char szText[512] = {0};
	LVITEM lItem;
	unsigned int line = row, column = 0;

	lItem.mask = LVIF_TEXT;
	for(; line<row+33; line++) {
		lItem.iItem = line;
		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		sprintf(szText, Define_Table[line-row]);
		lItem.pszText = szText;
		pelist->InsertItem(&lItem);

		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		switch(line-row) {
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 21:
		case 22:
		case 23:
		case 24:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
		case 32:
			sprintf(szText, "0x%08x", Value_Table[line-row]);
			break;
		case 3:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 25:
		case 26:
			sprintf(szText, "0x%04x", Value_Table[line-row]);
			break;	
		case 4:
		case 5:
			sprintf(szText, "0x%01x", Value_Table[line-row]);
			break;
		case 0:
		case 2:
			sprintf(szText, " ");
			break;
		case 1:
			sprintf(szText, "%u", Value_Table[line-row]);
			break;
		default:
			return line;
		}
		lItem.pszText = szText;
		pelist->SetItem(&lItem);

		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		sprintf(szText, "%s", Explain_Table[line-row]);
		lItem.pszText = szText;
		pelist->SetItem(&lItem);

		column = 0;
	}

	return Print_DATA_DIRECTORY(pelist, line);
}

void Print_NT_Header(CListCtrl *pelist)
{
	DWORD row = 0;
	char szText[512] = {0};
	LVITEM lItem;
	unsigned int column = 0;

	lItem.mask = LVIF_TEXT;
	lItem.iItem = row++;
	lItem.iSubItem = 0;
	sprintf(szText, "Signature");
	lItem.pszText = szText;
	pelist->InsertItem(&lItem);

	lItem.iSubItem = 1;
	memset(szText, 0, 512);
	sprintf(szText, "0x%08x", INH());
	lItem.pszText = szText;
	pelist->SetItem(&lItem);

	lItem.iSubItem = 2;
	memset(szText, 0, 512);
	sprintf(szText, "PE Format Structure - IMAGE_NT_HEADERS - Signature");
	lItem.pszText = szText;
	pelist->SetItem(&lItem);

	row = Print_OPTIONAL_Header(pelist, Print_FILE_Header(pelist, row));
}

void Print_SECTION_Header(CListCtrl *pelist)
{
	const char* Define_Table[] = 
	{"IMAGE_SECTION_HEADERS", " ", "Name", "Misc", "VirtualAddress", "SizeOfRawData", "PointerToRawData", "PointerToRelocations", "PointerToLinenumbers", "NumberOfRelocations", "NumberOfLinenumbers", "Characteristics", " "};
	const char* Explain_Table[] = 
	{"PE Format Structure - IMAGE_SECTION_HEADERS", " ", "Section's Name", "Misc", "VirtualAddress(Memory offset)", "SizeOfRawData", "PointerToRawData(File Offset)", "PointerToRelocations", "PointerToLinenumbers", "NumberOfRelocations", "NumberOfLinenumbers", "Characteristics", " "};
	char szText[512] = {0};
	LVITEM lItem;
	unsigned int row = 0, column = 0;

	lItem.mask = LVIF_TEXT;
	for(row = 0; row<(IFH(NumberOfSections)*13); row++) {
		lItem.iItem = row;
		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		switch(row%13) {
		case 0:	sprintf(szText, "%s<%u>", Define_Table[row%13]); break;
		default: sprintf(szText, "%s", Define_Table[row%13], (row/13)); break;
		}
		lItem.pszText = szText;
		pelist->InsertItem(&lItem);

		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		switch(row%13) {
		case 1: 
		case 12: sprintf(szText, " "); break;
		case 0:	sprintf(szText, "%u", 10); break;
		case 2: sprintf(szText, "%s", ISH1(row/13, Name)); break;
		case 3: sprintf(szText, "0x%08x", ISH1(row/13, Misc)); break;
		case 4: sprintf(szText, "0x%08x", ISH1(row/13, VirtualAddress)); break;
		case 5: sprintf(szText, "0x%08x", ISH1(row/13, SizeOfRawData)); break;
		case 6: sprintf(szText, "0x%08x", ISH1(row/13, PointerToRawData)); break;
		case 7: sprintf(szText, "0x%08x", ISH1(row/13, PointerToRelocations)); break;
		case 8: sprintf(szText, "0x%08x", ISH1(row/13, PointerToLinenumbers)); break;
		case 9: sprintf(szText, "0x%04x", ISH1(row/13, NumberOfRelocations)); break;
		case 10: sprintf(szText, "0x%04x", ISH1(row/13, NumberOfLinenumbers)); break;
		case 11: sprintf(szText, "0x%08x", ISH1(row/13, Characteristics)); break;
		default: break;
		}
		lItem.pszText = szText;
		pelist->SetItem(&lItem);

		lItem.iSubItem = column++;
		memset(szText, 0, 512);
		switch(row%13) {
		case 0:	sprintf(szText, "%s<%u>", Explain_Table[row%13]); break;
		default: sprintf(szText, "%s", Explain_Table[row%13], row/13); break;
		}
		
		lItem.pszText = szText;
		pelist->SetItem(&lItem);

		column = 0;
	}
}

// PE Format 정보를 획득
BOOL Get_PE_Format(const char* temp_mem)
{
    unsigned int mem_offset = 0;
    int i = 0;

    memcpy(&g_pf.idh, temp_mem, sizeof(DOS_HEADER));
    mem_offset = g_pf.idh.e_lfanew;
    memcpy(&g_pf.inh, &temp_mem[mem_offset], sizeof(NT_HEADERS));
    mem_offset += sizeof(NT_HEADERS);

    g_pf.psa = (PIMAGE_SECTION_ALL) calloc(TotalSection(sizeof(IMAGE_SECTION_ALL), g_pf.inh.FileHeader.NumberOfSections), 1);      //PE의 모든 Section을 저장하기 위한 구조체 배열 생성
    for(i=0; i<g_pf.inh.FileHeader.NumberOfSections; i++)
    {
		memcpy(&(g_pf.psa[i].psh), &temp_mem[mem_offset], sizeof(SECTION_HEADER));
		mem_offset += sizeof(SECTION_HEADER);

        if(g_pf.psa[i].psh.SizeOfRawData != 0)              //섹션 데이터 읽어와서 저장
        {
            g_pf.psa[i].shdata = (char*) calloc(g_pf.psa[i].psh.SizeOfRawData, sizeof(char));     //new heap memory
            memcpy(g_pf.psa[i].shdata, &temp_mem[g_pf.psa[i].psh.PointerToRawData], g_pf.psa[i].psh.SizeOfRawData);
        }
    }

    return TRUE;
}

// 프로그램 시작시 호출
BOOL Init_PE_Format(const char* pe_file)
{
    FILE* pefp = NULL;
    char* temp_mem = NULL;
    unsigned int fsize = 0;
    pefp = fopen(pe_file, "rb");
    if(!pefp) return FALSE;
    fseek(pefp, 0, SEEK_END);
    fsize = ftell(pefp);
    rewind(pefp);

    temp_mem = (char*) calloc(fsize, sizeof(char));
    if(temp_mem == 0) return FALSE;
    if(fread(temp_mem, fsize, 1, pefp) == fsize) return FALSE;
    fclose(pefp);
    if(!Get_PE_Format(temp_mem)) return FALSE;

    SAFE_FREE(temp_mem);

    return TRUE;
}

// Exit시 호출
BOOL Destroy_PE_Format(void)
{
    for(int i=0; i<g_pf.inh.FileHeader.NumberOfSections; i++)       //섹션 데이터 해제
    {
        if(g_pf.psa[i].psh.SizeOfRawData != 0)
        {
            SAFE_FREE(g_pf.psa[i].shdata);
        }
    }
    SAFE_FREE(g_pf.psa);

	memset(&g_pf, 0, sizeof(PE_Format));

    return TRUE;
}