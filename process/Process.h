#pragma once
#include <string>
#include <windows.h>
#include <memory>
#include "../pub/cmn.h"
NAMESPACE_BEGIN
#define MAXWAITFORPROCESSTIME 1000 * 5  // ���ʱ
#define MAXOUTPUTSIZE		  1024 * 5  // 
#define MAX_PIPE_INPUT_COUNT  1024 * 20 // ���20K�ܵ���������������ֹ�������ܵ����������£�WriteFile�����޷�����

//
// ������ -> Process ������
// Copyright(c) ph0ly 2013.03 - 2013.07. All rights reserved.
//

class PH0LY Process
{
public:

	enum ProcessReturns
	{
		EP_SUCCESS = 0,
		EP_WAITTIMEOUT,
		EP_CREATEFAILED,
		EP_CREATEPIPEFAILED,
		EP_SETINPUTERROR
	};

	Process(void);
	~Process(void);

	// -> ����������ز���

	/// ��������ģʽ���̣���������
	ProcessReturns Create( const char* lpszCmdlines, bool bShowWnd = false );
	/// �������Խ��̣���WaitDbg����ʹ��
	ProcessReturns CreateDbg( const char* lpszCmdlines );
	/// �����������
	ProcessReturns CreateSuspend( const char* lpszCmdlines, bool bDebug = true );
	/// ���������н���
	ProcessReturns CreateCommand( bool bShowWnd = false );
	/// ����������ģʽ���̣�����������
	/// ����pOnFinishedΪ�ص�������ָʾ���̴�����Ϻ�Ӧ����ʲô
	/// ��ע�⣺������δʵ��
	ProcessReturns CreateAsync( const char* lpszCmdlines, void (*pOnFinished)(void * pParm) );

	// -> ����д�����ز���

	/// д������, ����д����������
	int  Write( const char* lpszInput );
	/// д��һ������, ����д����������
	int  WriteLine( const char* lpszInput );

	/// ��ȡ����, ���ض�����������
	int  Read( char* lpszOutput, unsigned int nCapacity = 0 );
	/// ��ȡ�������ݣ����ض�ȡ������
	/// ������������������������ܴ�����
	int  ReadAll( std::string& strOutput );
	/// ��һ��, ���ض�����������
	int  ReadLine( char* lpszOutput, unsigned int nCapacity = 0 );

	// -> ���氲ȫ��ǰ�ȫ��ȡ����Ϊ������exe����ʱ������ȷ���������δ֪��С������
	// -> ���ǲ�������ν�İ�ȫ�ͷǰ�ȫ

	/// ��ȫ��ȡ���ݣ������ֶ��ͷ�
	/// shared_ptr������ָ�룬�ڴ�ᱻ�Զ����գ����ó���Ա�ֶ��ͷ�
	std::tr1::shared_ptr<char> SafeReadAll( int* lpBytesRead );
	/// ����ȫ��ȡ���ݣ�Ҳ�����ڲ�ʹ�öѽ����ڴ���䣬��Ҫ�ֶ��ͷ�
	/// ��UnSafeFreeMemory����ʹ��
	int  UnSafeReadAll( char** ptr );
	/// �ͷŲ���ȫ�ڴ�
	bool UnSafeFreeMemory( char** ptr );

	/// ֻ��ѯ������������ȡ������������
	int  Peek();

	/// �ȴ�����
	DWORD Wait( DWORD dwMillisenconds = INFINITE );
	/// �ȴ����Խ����˳�
	/// dwMillisenconds : ���ȴ�ʱ��
	/// nErrCount : �쳣����������������������˳�����
	DWORD WaitDbg( DWORD dwMillisenconds, DWORD nErrCount );

	/// ���ٽ���
	bool  Destroy();
	/// ��ȡ���̾��
	HANDLE GetProcessHandle() const;
	/// ��ȡ�߳̾�� 
	HANDLE GetThreadHandle() const;
	/// ��ȡ�˳���
	DWORD  GetExitCode() const;
	/// ��ȡ���̺�
	DWORD GetProcessId() const;
	/// ��ȡ���̺߳�
	DWORD GetThreadId() const;

private:
	HANDLE m_hProcess;
	HANDLE m_hThread;
	HANDLE m_hInputReadPipe;
	HANDLE m_hInputWritePipe;
	HANDLE m_hOutputReadPipe;
	HANDLE m_hOutputWritePipe;

	DWORD m_dwProcessId;
	DWORD m_dwThreadId;

	bool m_bDbg;

	DWORD m_dwExitCode;
};
NAMESPACE_END