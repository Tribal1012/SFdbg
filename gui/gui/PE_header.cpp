#include "stdafx.h"
#include "PE_header.h"

PE_Format g_pf;

void Print_DOS_Header(const PDOS_HEADER pidh)
{
    printf("\n PE Format Structure - IMAGE_DOS_HEADER\n");
    printf("┌───────────────────────\n");
    printf("│Magic Number : 0x%02x\n", pidh->e_magic);
    printf("│Bytes on last page of file : 0x%02x\n", pidh->e_cblp);
    printf("│Pages in file : 0x%02x\n", pidh->e_cp);
    printf("│Relocations : 0x%02x\n", pidh->e_crlc);
    printf("│Size of header in paragraphs : 0x%02x\n", pidh->e_crlc);
    printf("│Minimum extra paragraphs needed : 0x%02x\n", pidh->e_minalloc);
    printf("│Maximum extra paragraphs needed : 0x%02x\n", pidh->e_maxalloc);
    printf("│Initial (relative) SS value : 0x%02x\n", pidh->e_ss);
    printf("│Initial SP value : 0x%02x\n", pidh->e_sp);
    printf("│Checksum : 0x%02x\n", pidh->e_csum);
    printf("│Initial IP value : 0x%02x\n", pidh->e_ip);
    printf("│Initial (relative) CS value : 0x%02x\n", pidh->e_cs);
    printf("│File address of relocation table : 0x%02x\n", pidh->e_lfarlc);
    printf("│Overlay number : 0x%02x\n", pidh->e_ovno);
    printf("│Reserved words : 0x%02x %02x %02x %02x\n", pidh->e_res[0], pidh->e_res[1], pidh->e_res[2], pidh->e_res[3]);
    printf("│OEM identifier (for e_oeminfo) : 0x%02x\n", pidh->e_oemid);
    printf("│OEM information; e_oemid specific : 0x%02x\n", pidh->e_oeminfo);
    printf("│Reserved words : 0x");
    for(int i=0; i<10; i++)
        printf("%02x ", pidh->e_res2[i]);
    printf("\n│File address of new exe header : 0x%04x\n", pidh->e_lfanew);
    printf("└───────────────────────\n");
}

void Print_FILE_Header(const PFILE_HEADER pfh)
{
    printf("\n PE Format Structure - IMAGE_FILE_HEADER\n");
    printf("┌───────────────────────\n");
    printf("│Machine : 0x%02x\n", pfh->Machine);
    printf("│NumberOfSections : 0x%02x\n", pfh->NumberOfSections);
    printf("│TimeDateStamp : 0x%04x\n", pfh->TimeDateStamp);
    printf("│PointerToSymbolTable : 0x%04x\n", pfh->PointerToSymbolTable);
    printf("│NumberOfSymbols : 0x%04x\n", pfh->NumberOfSymbols);
    printf("│SizeOfOptionalHeader : 0x%02x\n", pfh->SizeOfOptionalHeader);
    printf("│Characteristics : 0x%02x\n", pfh->Characteristics);
    printf("└───────────────────────\n");
}

void Print_OPTIONAL_Header(const POPTIONAL_HEADER poh)
{
    printf("\n PE Format Structure - IMAGE_OPTIONAL_HEADER\n");
    printf("┌───────────────────────\n");
    printf("│Magic : 0x%02x\n", poh->Magic);
    printf("│MagorLinkerVersion : 0x%01x\n", poh->MajorLinkerVersion);
    printf("│MinorLinkerVersion : 0x%01x\n", poh->MinorLinkerVersion);
    printf("│SizeOfCode : 0x%04x\n", poh->SizeOfCode);
    printf("│SizeOfInitializedData : 0x%04x\n", poh->SizeOfInitializedData);
    printf("│SizeOfUninitializedData : 0x%04x\n", poh->SizeOfUninitializedData);
    printf("│AddressOfEntryPoint : 0x%04x\n", poh->AddressOfEntryPoint);
    printf("│BaseOfCode : 0x%04x\n", poh->BaseOfCode);
    printf("│BaseOfData : 0x%04x\n", poh->BaseOfData);
    printf("│\n");
    printf("│ImageBase : 0x%04x\n", poh->ImageBase);
    printf("│SectionAlignment : 0x%04x\n", poh->SectionAlignment);
    printf("│FileAlignment : 0x%04x\n", poh->FileAlignment);
    printf("│MajorOperatingSystemVersion : 0x%02x\n", poh->MajorOperatingSystemVersion);
    printf("│MinorOperatingSystemVersion : 0x%02x\n", poh->MinorOperatingSystemVersion);
    printf("│MajorImageVersion : 0x%02x\n", poh->MajorImageVersion);
    printf("│MinorImageVersion : 0x%02x\n", poh->MinorImageVersion);
    printf("│MajorSubsystemVersion : 0x%02x\n", poh->MajorSubsystemVersion);
    printf("│MinorSubsystemVersion : 0x%02x\n", poh->MinorSubsystemVersion);
    printf("│Win32VersionValue : 0x%04x\n", poh->Win32VersionValue);
    printf("│SizeOfImage : 0x%04x\n", poh->SizeOfImage);
    printf("│SizeOfHeaders : 0x%04x\n", poh->SizeOfHeaders);
    printf("│CheckSum : 0x%04x\n", poh->CheckSum);
    printf("│Subsystem : 0x%02x\n", poh->Subsystem);
    printf("│DllCharacteristics : 0x%02x\n", poh->DllCharacteristics);
    printf("│SizeOfStackReserve : 0x%04x\n", poh->SizeOfStackReserve);
    printf("│SizeOfStackCommit : 0x%04x\n", poh->SizeOfStackCommit);
    printf("│SizeOfHeapReserve : 0x%04x\n", poh->SizeOfHeapReserve);
    printf("│SizeOfHeapCommit : 0x%04x\n", poh->SizeOfHeapCommit);
    printf("│LoaderFlags : 0x%04x\n", poh->LoaderFlags);
    printf("│NumberOfRvaAndSizes : 0x%04x\n", poh->NumberOfRvaAndSizes);
    printf("│\n│PE Format Structure - IMAGE_NT_HEADER - IMAGE_OPTIONAL_HEADER - IMAGE_DATA_DIRECTORY\n");
    for(int i=0; i<IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++)
    {
        printf("│<%u>│VirtualAddress : 0x%04x\n", i, poh->DataDirectory[i].VirtualAddress);
        printf("│<%u>│Size : 0x%04x\n", i, poh->DataDirectory[i].Size);
    }
    printf("└───────────────────────\n");
}

void Print_NT_Header(const PNT_HEADERS pnh)
{
    printf("\n PE Format Structure - IMAGE_NT_HEADER\n");
    printf("┌───────────────────────\n");
    printf("│Signature : 0x%04x\n", pnh->Signature);
    printf("└───────────────────────\n");
    Print_FILE_Header(&pnh->FileHeader);
    Print_OPTIONAL_Header(&pnh->OptionalHeader);
}

void Print_SECTION_Header(const PSECTION_HEADER psh)
{
    printf("\n PE Format Structure - IMAGE_SECTION_HEADERS\n");
    printf("┌───────────────────────\n");
    printf("│Name : %-8s\n", psh->Name);
    printf("│Misc : 0x%04x\n", psh->Misc);
    printf("│VirtualAddress : 0x%04x\n", psh->VirtualAddress);
    printf("│SizeOfRawData : 0x%04x\n", psh->SizeOfRawData);
    printf("│PointerToRawData : 0x%04x\n", psh->PointerToRawData);
    printf("│PointerToRelocations : 0x%04x\n", psh->PointerToRelocations);
    printf("│PointerToLinenumbers : 0x%04x\n", psh->PointerToLinenumbers);
    printf("│NumberOfRelocations : 0x%02x\n", psh->NumberOfRelocations);
    printf("│NumberOfLinenumbers : 0x%02x\n", psh->NumberOfLinenumbers);
    printf("│Characteristics : 0x%04x\n", psh->Characteristics);
    printf("└───────────────────────\n");
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

    return TRUE;
}