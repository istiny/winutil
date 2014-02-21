#pragma once
#include <windows.h>
#include <TlHelp32.h>
#include "../pub/cmn.h"

NAMESPACE_BEGIN
//
// ������ -> Toolhelp ϵͳ������
// Copyright (c) ph0ly 2013.05 - 2013.07 . All rights reserved.
//
class PH0LY Toolhelp
{
public:
	Toolhelp(void);
	Toolhelp(DWORD dwFlags, DWORD dwProcessId = NULL);
	~Toolhelp(void);
	// ��������
	bool CreateSnapshot(DWORD dwFlags, DWORD dwProcessId);

	// ö�ٿ��գ�ÿ��ö�ٽ��ᵼ��ö�ټ�������1
	// ����������¼���ö�٣���Ҫ����Reset���ÿ���
	// �ر�ע�⣺
	// ö�����ͺʹ������Ͳ�ͬ��������Next����false
	// ��ȷ�������������ͺ�ö������һ��
	BOOL Next(THREADENTRY32& te);
	BOOL Next(PROCESSENTRY32& pe);
	BOOL Next(MODULEENTRY32& me);
	BOOL Next(HEAPENTRY32& he, DWORD dwProcessID, UINT_PTR dwHeapID);

	// ���ҿ���
	BOOL Find(DWORD dwThreadId, THREADENTRY32& te) const;
	BOOL Find(DWORD dwProcessId, PROCESSENTRY32& pe) const;
	BOOL Find(LPCSTR pszExeName, PROCESSENTRY32& pe) const;
	BOOL Find(LPCSTR pszModulePath, MODULEENTRY32& me) const;

	// ���ÿ���
	BOOL Reset();

public:
	static BOOL EnablePrivilege(PCTSTR szPrivilege, BOOL fEnable = TRUE);

private:
	DWORD m_dwFlags;
	HANDLE m_hSnapshot;
	DWORD m_dwRefer;

};

NAMESPACE_END

