#pragma once
#include <vector>
#include <string>
#include <map>
#include "../pub/cmn.h"

NAMESPACE_PH0LY_BEGIN(conf)
// 
// ������ -> IniHelper INI�ļ�������
// Copyright (c) ph0ly 2013.07. All rights reserved.
//
class PH0LY IniHelper
{
public:
	IniHelper(void);
	~IniHelper(void);

	static std::vector<std::string> GetChildren(std::string strPath, std::string strNode);
	// ��ȡini�ļ��ڵ��µ��ӽڵ�
	// ע�⣺�ú�������ȱ�ݣ��������������ƣ���������Сʱ����ѡ��
	static std::vector<std::string> GetProfileSectionNodes(std::string strPath, std::string strNode);

};
NAMESPACE_PH0LY_END

