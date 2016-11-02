/* define class function*/
#pragma once
#include "StdAfx.h"
#include "Disassem.h"
#include "debugger.h"
#include "PE_header.h"
#include "Timeless.h"

time_t time_old, time_now;	//실행시간 측정을 위해 사용
unsigned g_tcount=0;

namespace SFdbg {
	DEBUGGER g_mydebugger;

	DEBUGGER::DEBUGGER()
	{
		memset(g_bp_table, NULL, sizeof(BREAKPOINT_TABLE)*1024);
		g_bp_table_count = 0;
		g_count = 0;
		g_exec.isopened = FALSE;
		g_exec.isrun = FALSE;
	}
	DEBUGGER::~DEBUGGER()
	{
		if(g_exec.isopened)
		{
			g_exec.isopened = FALSE;
		}
		else if(g_exec.attached)
		{
			DebugActiveProcessStop(g_exec.pid);
			g_exec.attached = FALSE;
		}
		//Delete_SingleStep();				//I don't know
	}
	//oepn process
	BOOL DEBUGGER::Open_Process(CString filename, CString filepath)
	{
		strcpy(g_filepath, filepath.GetBuffer(0));	//convert from CString to LPSTR
		strcpy(g_cmdline, filename.GetBuffer(0));
		memset(g_cmdline, 0, MAX_PATH);
		if(CreateProcess(g_filepath, (LPSTR)g_cmdline, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | DEBUG_ONLY_THIS_PROCESS, NULL, NULL, &si, &pi))
		{
			AfxMessageBox(g_filepath);
		}
		else
		{
			AfxMessageBox("File Open Error\nPlease Check File Path");
			return FALSE;
		}
		g_exec.isopened = TRUE;
		g_exec.attached = FALSE;
		Init_PE_Format(g_filepath);
		time(&time_old);		// 실행 시부터 카운트
		return TRUE;
	}
	//attach process
	BOOL DEBUGGER::Attach_Process(int pi)
	{
		HANDLE hSnapShot = INVALID_HANDLE_VALUE;
		PROCESSENTRY32 pe32;
		DWORD dwSize;
		int i = 0;

		pe32.dwSize = sizeof(PROCESSENTRY32);
		hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);		//Get Process Entry
		Process32First(hSnapShot, &pe32);
		do
		{
			i++;
			if(i == pi)
			//if(!_stricmp(g_filepath, pe32.szExeFile))
			{
				AfxMessageBox(pe32.szExeFile);
				g_exec.pid = pe32.th32ProcessID;
				break;
			}
		}
		while(Process32Next(hSnapShot, &pe32));		//Find a Process in Process Entry
		CloseHandle(hSnapShot);
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, g_exec.pid);		//Attach
		if(hProcess == NULL)
			return FALSE;
		ZeroMemory(g_exec.pid_name, sizeof(MAX_PATH));
		dwSize = sizeof(g_exec.pid_name)/sizeof(char);
		QueryFullProcessImageName(hProcess, 0, g_exec.pid_name, &dwSize);		//Get Filename
		//printf("Name : %s\n", g_exec.pid_name);
		Init_PE_Format(g_exec.pid_name);

		return TRUE;
	}
	//View_Processlist
	void DEBUGGER::View_Processlist(CListCtrl* LBset)
	{
		HANDLE hSnapShot = INVALID_HANDLE_VALUE;
		PROCESSENTRY32 pe32;
		char szText[MAX_PATH]="";
		LVITEM lItem;
		unsigned int i = 0;

		pe32.dwSize = sizeof(PROCESSENTRY32);
		hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);		//Get Process Entry
		Process32First(hSnapShot, &pe32);
		do
		{
			lItem.mask=LVIF_TEXT;
			lItem.iItem=i;
			lItem.iSubItem=0;

			sprintf(szText, "%u", i+1);
			lItem.pszText=(LPSTR)szText;
			LBset->InsertItem(&lItem);

			lItem.iSubItem=1;
			sprintf(szText, "%s", pe32.szExeFile);
			lItem.pszText=(LPSTR)szText;
			LBset->SetItem(&lItem);

			i++;
		}
		while(Process32Next(hSnapShot, &pe32));		//Find a Process in Process Entry
		CloseHandle(hSnapShot);
	}
	void DEBUGGER::View_Register(CListCtrl* m_list, BOOL Modify)
	{
		const char* regbuffer[] = {"EAX", "EBX", "ECX", "EDX", "ESP", "EBP", "ESI", "EDI", "EIP", "ELFAGS", "CS", "DS", "SS", "ES", "FS", "GS"};
		DWORD conbuffer[16] = {0};
		char szText[MAX_PATH]="";
		LVITEM lItem;
		unsigned int index = 0;

		GetThreadContext(hThread, &g_context);	//Setting Register
		conbuffer[0]=g_context.Eax;
		conbuffer[1]=g_context.Ebx;
		conbuffer[2]=g_context.Ecx;
		conbuffer[3]=g_context.Edx;
		conbuffer[4]=g_context.Esp;
		conbuffer[5]=g_context.Ebp;
		conbuffer[6]=g_context.Esi;
		conbuffer[7]=g_context.Edi;
		conbuffer[8]=g_context.Eip;
		conbuffer[9]=g_context.EFlags;
		conbuffer[10]=g_context.SegCs;
		conbuffer[11]=g_context.SegDs;
		conbuffer[12]=g_context.SegSs;
		conbuffer[13]=g_context.SegEs;
		conbuffer[14]=g_context.SegFs;
		conbuffer[15]=g_context.SegGs;
		if(Modify) {
			for(index=0; index<16; index++) 
				m_list->DeleteItem(0);		// 0번을 지우면 하나씩 올라오기 때문
		}

		index=0;
		lItem.mask=LVIF_TEXT;
		while(index<16) {
			lItem.iItem=index;
			lItem.iSubItem=0;

			memset(szText, 0, MAX_PATH);
			sprintf(szText, "%-10s", regbuffer[index]);
			lItem.pszText=(LPSTR)szText;
			m_list->InsertItem(&lItem);

			lItem.iSubItem=1;
			sprintf(szText, "0x%08x", conbuffer[index]);
			lItem.pszText=(LPSTR)szText;
			m_list->SetItem(&lItem);

			index++;
		}
	}
	void DEBUGGER::Timeless(CListCtrl* m_list4)
	{
		const DWORD conbuffer[] = {g_context.Eax, g_context.Ebx, g_context.Ecx, g_context.Edx, g_context.Esp, g_context.Ebp, g_context.Esi, g_context.Edi, g_context.Eip, g_context.EFlags};
		char szText[MAX_PATH]="";
		LVITEM lItem;

		time(&time_now);
		lItem.mask=LVIF_TEXT;
		lItem.iItem=g_tcount;
		lItem.iSubItem=0;

		memset(szText, 0, MAX_PATH);
		sprintf(szText, "%x", time_now-time_old);
		lItem.pszText=(LPSTR)szText;
		m_list4->InsertItem(&lItem);

		for(int i=1;i<12; i++) {
			lItem.iSubItem=i;
			sprintf(szText, "0x%08x", conbuffer[i]);
			lItem.pszText=(LPSTR)szText;
			m_list4->SetItem(&lItem);
		}

		g_tcount++;
	}

#define Stack_Offset1(x, y) (x-(DWORD)y)/16
#define Stack_Offset2(x, y) (x-(DWORD)y)%16
	void DEBUGGER::Print_Stack(CListCtrl* m_list)
	{
		char szText[MAX_PATH] = {0};
		void* base_address = (void*)(g_context.Esp&0xFFFFF000);
		void* Align_Esp = (void*)((DWORD)g_context.Esp-Stack_Offset2(g_context.Esp, base_address));
		unsigned int i=0;
		LVITEM lItem;

		for(i=0; i<0x100; i++) {
			lItem.mask=LVIF_TEXT;
			lItem.iItem=i;
			lItem.iSubItem=0;

			memset(szText, 0, MAX_PATH);
			sprintf(szText, "%p", (void*)((DWORD)base_address+(i*0x10)));
			lItem.pszText=(LPSTR)szText;
			m_list->InsertItem(&lItem);

			sprintf(szText, "0x%08x", 0x0);
			lItem.pszText=(LPSTR)szText;		//값 초기화
			for(int j=1; j<5; j++) {
				lItem.iSubItem=j;
				m_list->SetItem(&lItem);
			}
		}
	}

	void DEBUGGER::Modify_Stack(CListCtrl* m_list, DWORD memsize)
	{
		char szText[MAX_PATH] = {0};
		char buffer[16] = {0};
		void* base_address = (void*)(g_context.Esp&0xFFFFF000);
		void* Align_Esp = (void*)((DWORD)g_context.Esp-Stack_Offset2(g_context.Esp, base_address));
		DWORD checksize = 0;
		BOOL ReadWrite_result = FALSE;
		unsigned int i=0;
		LVITEM lItem;
		LVFINDINFO lfi;

		ReadWrite_result = ReadProcessMemory(hProcess, (LPCVOID)Align_Esp, buffer, memsize, &checksize);
		if((checksize == memsize)&&(ReadWrite_result == TRUE))
		{
			lfi.flags = LVFI_STRING;
			sprintf(szText, "%p", Align_Esp);
			lfi.psz = szText;
			i = m_list->FindItem(&lfi, 1);//Stack_Offset1(g_context.Esp, base_address);

			lItem.mask=LVIF_TEXT;
			lItem.iItem=i;
			lItem.iSubItem=0;
			m_list->DeleteItem(lItem.iItem);

			memset(szText, 0, MAX_PATH);
			sprintf(szText, "%p", (void*)Align_Esp);
			lItem.pszText=(LPSTR)szText;
			m_list->InsertItem(&lItem);

			for(int j=0; j<4; j++) {
				lItem.iSubItem=j+1;
				sprintf(szText, "0x%08x", (DWORD)*(buffer+(j*4)));
				lItem.pszText=(LPSTR)szText;
				m_list->SetItem(&lItem);
			}

			i+=4;
		}
	}
	
	//Configure Software BreakPonint	중요
	BOOL DEBUGGER::Set_SoftBreakPoint(DWORD address)
	{
		MEMORY_BASIC_INFORMATION mbi;
		MEMORY_BASIC_INFORMATION temp_mbi;
		DWORD checksize = 0;
		BOOL ReadWrite_result;
		BYTE break_opcode = BREAK_POINT;

		ReadWrite_result = ReadProcessMemory(hProcess, (LPCVOID)address, &g_bp_table[g_bp_table_count].opcode, 1, &checksize);
		if((checksize != 1)||(ReadWrite_result != 1))
		{
			g_bp_table[g_bp_table_count].opcode = NULL;
			return FALSE;
		}
		VirtualQueryEx(hProcess, (LPCVOID)g_context.Eip, &mbi, sizeof(MEMORY_BASIC_INFORMATION));
	    if (!VirtualProtectEx(hProcess, mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &mbi.Protect))
	    {
	    	g_bp_table[g_bp_table_count].opcode = NULL;
	        return FALSE ;
	    }
		g_bp_table[g_bp_table_count].Eip = g_context.Eip;
		break_opcode = BREAK_POINT;
		ReadWrite_result = WriteProcessMemory(hProcess, (LPVOID)address, (LPCVOID)&break_opcode, 1, &checksize);
		if((checksize != 1)||(ReadWrite_result != 1))
		{
			g_bp_table[g_bp_table_count].opcode = NULL;
			return FALSE;
		}
		if (!VirtualProtectEx(hProcess, mbi.BaseAddress, mbi.RegionSize, mbi.Protect, &temp_mbi.Protect))
	    {
	    	g_bp_table[g_bp_table_count].opcode = NULL;
	        return FALSE ;
	    }
	    FlushInstructionCache(hProcess, mbi.BaseAddress, 1);
		g_bp_table_count++;
		return TRUE;
	}
	//Delete Software BreakPonint
	BOOL DEBUGGER::Delete_SoftBreakPoint(DWORD address)
	{
		MEMORY_BASIC_INFORMATION mbi;
		MEMORY_BASIC_INFORMATION temp_mbi;
		DWORD checksize = 0;
		BOOL ReadWrite_result = FALSE;
		VirtualQueryEx(hProcess, (LPCVOID)address, &mbi, sizeof(MEMORY_BASIC_INFORMATION));
	    if (!VirtualProtectEx(hProcess, mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &mbi.Protect))
	    {
	    	g_bp_table[g_bp_table_count].opcode = NULL;
	        return FALSE ;
	    }
		WriteProcessMemory(hProcess, (LPVOID)address, &g_bp_table[g_bp_table_count].opcode, 1, &checksize);
		if((checksize != 1)||(ReadWrite_result != 1))
		{
			g_bp_table[g_bp_table_count].opcode = NULL;
			return FALSE;
		}
		g_bp_table[g_bp_table_count].Eip = 0;
		if (!VirtualProtectEx(hProcess, mbi.BaseAddress, mbi.RegionSize, mbi.Protect, &temp_mbi.Protect))
	    {
	    	g_bp_table[g_bp_table_count].opcode = NULL;
	        return FALSE ;
	    }
		//BreakPoint로 EIP 설정
		FlushInstructionCache(hProcess, mbi.BaseAddress, 1);
		g_context.Eip-- ;
        if (!SetThreadContext(hThread,&g_context))
            return FALSE;
        g_bp_table_count--;
		return TRUE;
	}
	BOOL DEBUGGER::Set_SingleStep()
	{
	    g_context.EFlags |= 0x100 ;	//Trap bit
	    if(!SetThreadContext(hThread,&g_context))
		{
			g_context.EFlags ^= 0x100;
			return FALSE;
		}
	    return TRUE;
	}
	// SingleStep Exception Clear
	BOOL DEBUGGER::Delete_SingleStep()
	{
	    g_context.EFlags ^= 0x100 ;	//Trap bit
	    if(!SetThreadContext(hThread,&g_context))
		{
			g_context.EFlags |= 0x100;
			return FALSE;
		}
	    return TRUE;
	}

	//Start Debug
	BOOL DEBUGGER::Start_Debug(CListCtrl* m_list1, CListCtrl* m_list2, CListBox* m_list3, CListCtrl* m_list4, CListCtrl* m_list5)
	{
		//continue
		if(g_exec.isrun || g_exec.isstep)
			ContinueDebugEvent(g_de.dwProcessId, g_de.dwThreadId, DBG_CONTINUE);

		g_exec.isstep = FALSE;

		if(WaitForDebugEvent(&g_de, 100) == NULL)
		{
			//puts("Don't Start Debug Event");
			return TRUE;
		}
		switch(g_de.dwDebugEventCode)
		{
		//Create Process
		case CREATE_PROCESS_DEBUG_EVENT:		//3
			//Store Process Status
			hProcess = g_de.u.CreateProcessInfo.hProcess;
			hThread = g_de.u.CreateProcessInfo.hThread;
			g_context.ContextFlags = CONTEXT_FULL;
			g_mydebugger.View_Register(m_list2, FALSE);
			g_mydebugger.Print_Stack(m_list5);
			g_mydebugger.Timeless(m_list4);
			Init_Disassemble((const unsigned char*)g_pf.psa[1].shdata, (const DWORD)g_pf.psa[1].psh.SizeOfRawData, m_list1);
			Set_SoftBreakPoint(g_context.Eip);
			break;
		//Exit Process
		case EXIT_PROCESS_DEBUG_EVENT:		//5
			/*if(g_exec.attached)
				DebugActiveProcessStop(g_exec.pid);*/
			return FALSE;
		//Occur Debug Exception
		case EXCEPTION_DEBUG_EVENT:			//1
			switch(g_de.u.Exception.ExceptionRecord.ExceptionCode)
			{
			//Single Step Execute
			case EXCEPTION_SINGLE_STEP:
				/* "Single Step!! */
				GetThreadContext(hThread, &g_context);	//Setting Register
				time(&time_now);	//현재 시간 카운트
				g_mydebugger.View_Register(m_list2, TRUE);					//추가에서 수정으로 변경
				g_mydebugger.Modify_Stack(m_list5, 0x10);
				//input_table(g_context, (time_now-time_old));

				Set_SingleStep();
				break;
			//BreakPonint
			case EXCEPTION_BREAKPOINT:
				/* BreakPoint */
				GetThreadContext(hThread, &g_context);
				time(&time_now);	//현재 시간 카운트
				g_mydebugger.View_Register(m_list2, TRUE);					//추가에서 수정으로 변경
				g_mydebugger.Modify_Stack(m_list5, 0x10);
				//input_table(g_context, (time_now-time_old));

				Set_SingleStep();
				g_exec.isrun = FALSE;
				break;
			default:
				break;
			}
		default:
			break;
    	}
		return TRUE;
	}

	void DEBUGGER::Set_ExecConfig(int flag)
	{
		if(flag == 0x0) {
			g_exec.isrun = FALSE;
			g_exec.isstep = FALSE;
		} else if(flag == 0x1) {
			g_exec.isopened = TRUE;
		} else if(flag == 0x2) {
			g_exec.isrun = TRUE;
		} else if(flag == 0x3) {
			g_exec.isstep = TRUE;
		}
	}

	BOOL DEBUGGER::Get_ExecConfig(int flag)
	{
		if(flag == 0x0) {
			return (g_exec.isopened)||(g_exec.attached);
		} else if(flag == 0x2) {
			return g_exec.isstep;
		} else if(flag == 0x3) {
			return g_exec.isrun;
		}

		return FALSE;
	}
}