#include "stdafx.h"
#include "easyhook.h"
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "EasyHook64.lib")

#define FORCE(expr) {if(!SUCCEEDED(NtStatus = (expr))) goto ERROR_ABORT;}

typedef DWORD (CALLBACK *FUNC)(HWND, UINT_PTR, UINT, TIMERPROC);

static bool isFirstTime = TRUE;

FUNC hProcSetTimer;

BOOL WINAPI SetTimerHook(_In_opt_ HWND hWnd, _In_ UINT_PTR nIDEvent,
						 _In_ UINT uElapse, _In_opt_ TIMERPROC lpTimerFunc)
{
	if(nIDEvent == 6)
	{
		// TODO: do some magic to uElapse :)
	}

	return (*hProcSetTimer)(hWnd,nIDEvent,uElapse,lpTimerFunc);
}


bool FKRuijie()
{
	NTSTATUS NtStatus;
	ULONG ACLEntries[1] = {0};
	TRACED_HOOK_HANDLE hHook = new HOOK_TRACE_INFO();

	hProcSetTimer = (FUNC)GetProcAddress(LoadLibraryA("user32.dll"), "SetTimer");


	FORCE(LhInstallHook(
		hProcSetTimer,
		SetTimerHook,
		(PVOID)0x12345678,
		hHook));

	FORCE(LhSetInclusiveACL(ACLEntries, 1, hHook));

	return TRUE;

ERROR_ABORT:

	if(hHook != NULL)
		delete hHook;

	if(RtlGetLastError() != 0)
		MessageBoxA(NULL, "ERROR", "FKAdvapi", 0);

	return NtStatus;
}

BOOL APIENTRY DllMain( HMODULE hModule,
					  DWORD  ul_reason_for_call,
					  LPVOID lpReserved
					  )
{
	if(isFirstTime)
	{
		isFirstTime = FALSE;

		FKRuijie();
	}

	return TRUE;
}
