#pragma once

#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include "../pub/cmn.h"

NAMESPACE_PH0LY_BEGIN(tool)
//
// ������ -> PE PE�ļ�������
// Copyright(c) ph0ly 2013.07 . All rights reserved.
//
class PH0LY PE
{
public:

	enum PEType
	{
		DOS_HEADER,
		NT_HEADER,
		SECTIONS_HEADER,
		IMPORT_TABLE,
		EXPORT_TABLE
	};

	PE(void);
	PE(const char * pszFile);
	~PE(void);

	// ��������̼���PE�ļ������غ�ӳ��
	bool Load( const char * pszFile );
	// ���ڴ����PE�ļ�ӳ��
	bool Load( DWORD dwProcessId );
	// ���������������PE�ļ������غ�ӳ��
	void LazyLoad( const char * pszFile );

	// ӳ��PE�ļ����ڴ�
	bool Map();
		
	// �ж��Ƿ�ΪPE�ļ�
	bool IsPE();

	// ֻ��ȡ���뺯��
	bool GetImportFunctions( std::vector<std::string>& );

	// ��ȡ����������µĵ��뺯��
	// ��ͬʱ��ÿ����ƺͺ�������
	bool GetImportFunctions( std::map<std::string, std::vector<std::string>>& );
	// ��ȡ��������
	bool GetExportFunctions( std::vector<std::string>& );
	// ��ȡ������
	bool GetSections( std::vector<std::string>& );
	// ��ȡ������
	int  GetSections();
	// ��ȡPE�ļ���ڵ�
	PVOID GetEntryPoint();

	// RVA ת��Ϊ Raw Address
	PVOID RVAToRA( PVOID pvBase, PVOID pvRVA );

	// ��λPE�ļ�λ��
	PVOID Locate( PEType );
	// ��λPE�ļ�λ��, pvBaseΪ����ַ
	PVOID Locate( PVOID pvBase, PEType );

	// ���ڴ��е�PE�ļ���ȡ����
	bool Dump( const char * pszFilePath );

	// ȡ��PE�ļ����ڴ��ӳ��
	bool UnMap();

	operator PVOID();

private:
	virtual PVOID MapViewOfFile( std::string strFile, DWORD dwMapAccess = FILE_MAP_READ );
	virtual bool  UnMapViewOfFile( PVOID pv );
	// ��ȡ��ͬ���Ե������С
	virtual DWORD GetVMRgn( HANDLE hProcess, PVOID pvBase );
	// RVA ת��Ϊ Raw Address
	PVOID RVAToRA( PVOID pvRVA );
	DWORD RVAToRA( DWORD pvRVA );

private:
	//std::string m_strFile;
	char m_strFile[MAX_PATH];
	HANDLE m_hProcess;
	PVOID m_pvBase;

	DWORD m_dwVMRgn;

	HANDLE m_hFileMapping;
	HANDLE m_hFile;

	bool m_bAsImage;

};

NAMESPACE_PH0LY_END