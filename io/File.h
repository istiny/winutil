#pragma once
#include <vector>
#include <string>
#include <memory>
#include "../pub/cmn.h"

NAMESPACE_PH0LY_BEGIN(io)
//
// ������ -> File �ļ��� 
// Copyright (c) ph0ly 2013.03.13 . All rights reserved.
// 
class PH0LY File
{
public:
	// FM -> File Mode
	enum Mode
	{
		FM_TEXT = 1,
		FM_BINARY = 2,
		FM_CREATE = 4
	};

	File(void);
	~File(void);
	/**
	 * �ļ��Ƿ����
	 * @param lpszFileName �ļ�·��
	 */
	static bool Exists( const char* lpszFileName );

	/// ɾ���ļ�
	static bool Delete( const char* lpszFileName );

	/// �����ļ�
	static bool Create( const char* lpszPath );

	/// ��ȡ�ļ�ǰ׺����������׺���֣�
	static bool GetFilePrefix( const char* lpszName, char* lpszOut, int nMaxBuffer );

	/// ��ȡ�ļ���
	static bool GetFileName( const char* lpszName, char* lpszOut, int nMaxBuffer );
	/// ��ȡ�ļ���
	static bool GetFileNameWithExtension( const char* lpszName, char* lpszOut, int nMaxBuffer );

	/// �Ƿ����ļ�
	static bool IsFile( const char* lpszPath );
	/// �Ƿ���Ŀ¼
	static bool IsDirectory( const char* lpszPath );

	/// ��ȡ�ļ���׺
	static bool GetFileExtension( const char* lpszName, char* lpszOut, int nMaxBuffer );

	/// ��ȡ�ļ���Ŀ¼
	static bool GetDirectory( const char* lpszPath, char * lpszOut, int nMaxBuffer );

	/// ����Ŀ¼lpszDir�еģ���lpszEndsΪ��׺���ļ���������vOutFiles��
	static bool FindFiles( const char* lpszDir, const char* lpszEnds, std::vector<std::string>& vOutFiles );

	/// ��ȡ�����ı��ļ����� 
	static bool ReadAllText( const char* lpszPath, std::string& strOutput );

	/// �����ı��ļ�
	static bool SaveAllText( const char* lpszPath, const std::string& strInput );
};
NAMESPACE_PH0LY_END

