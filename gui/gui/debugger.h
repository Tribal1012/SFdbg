/* define class */
#pragma once
#ifndef __DEBUGGER_H
#define __DEBUGGER_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include <TlHelp32.h>
#include "tchar.h"
#include <conio.h>		//getch()
#include "stdio.h"

#define BREAK_POINT 0xCC
#define Visual2013

using namespace std;

namespace SFdbg {
	//Windows & Process Structure Information
	class WINDOWS_INFO
	{
	protected:
		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		HANDLE hProcess;
		HANDLE hThread;
	public:
		WINDOWS_INFO()
		{
			memset(&si, NULL, sizeof(STARTUPINFO));
			si.cb=sizeof(si);
			memset(&pi, NULL, sizeof(STARTUPINFO));
		}
	};

	class EXECUTE
	{
	public:
		//attach
		int pid;
		BOOL attached;
		char pid_name[MAX_PATH];
		
		//open
		BOOL isopened;
		BOOL isrun;
		BOOL isstep;
	};

	//Windows Debugger Class
	class DEBUGGER: public WINDOWS_INFO
	{
	private:
		//¸â¹ö º¯¼ö
		char g_filepath[MAX_PATH];
		char g_cmdline[MAX_PATH];
		EXECUTE g_exec;				//attahed process check
		DEBUG_EVENT g_de;			//store debug event
		CONTEXT g_context;		//store register
		char g_KeyBUF[128];
		char g_count;

	public:
		DEBUGGER();
		~DEBUGGER();
		//¸â¹ö ÇÔ¼ö
		BOOL Open_Process(CString filename, CString filepath);
		BOOL Attach_Process(int pi);
		void View_Processlist(CListCtrl* LBset);
		void View_Register(CListCtrl* m_list, BOOL Modify);
		void Timeless(CListCtrl* m_list);
		void Print_Stack(CListCtrl* m_list);
		void Modify_Stack(CListCtrl* m_list, DWORD memsize);
		void View_Memory(DWORD address, CListCtrl* m_list);
		BOOL Set_SoftBreakPoint(DWORD address, PDWORD opcode);
		BOOL Delete_SoftBreakPoint(DWORD address, PDWORD opcode);
		BOOL Set_SingleStep(void);
		BOOL Delete_SingleStep(void);
		BOOL Start_Debug(CListCtrl* m_list1, CListCtrl* m_list2, CListBox* m_list3, CListCtrl* m_list4, CListCtrl* m_list5);
		void Set_ExecConfig(int flag);
		BOOL Get_ExecConfig(int flag);
		void ResetAll(void);
	};

	extern DEBUGGER g_mydebugger;
}
#endif