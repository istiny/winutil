#pragma once
#include <windows.h>
#include <string>
#include "../pub/cmn.h"

NAMESPACE_BEGIN
//
// ������ -> APIHook API������
// Copyright (c) ph0ly 2013.06-2013.07 . All rights reserved.
//
class PH0LY APIHook
{
public:

	// @param lpszModule ģ������
	// @param lpszCurrentModule ��ǰģ�������
	// @param lpszFuncName Ҫ�滻�ĺ�������
	// @param pfnHook �º���
	// ʾ����
	// APIHook g_HookMessageBoxA("user32.dll", "currentdll.dll", "MessageBoxA", (PROC)Hook_MessageBoxA);
	APIHook(LPCSTR lpszModule, LPCSTR lpszCurrentModule, LPCSTR lpszFuncName, PROC pfnHook);

	// �ù��캯�����Զ�Ѱ�� @param lpszFuncName ���ڵ�ģ�飬����user32.dll
	APIHook(LPCSTR lpszCurrentModule, LPCSTR lpszFuncName, PROC pfnHook);
	~APIHook(void);

	// �滻�����
	void ReplaceIAT();
	// �ָ������
	void RestoreIAT();

private:

	void ReplaceIATInOneMod(PROC pfnOrig, PROC pfnNew);

	PROC m_pfnOrig;
	PROC m_pfnCurrent;

	std::string m_strCurrentModule;

	std::string m_strModule;

};
NAMESPACE_END

