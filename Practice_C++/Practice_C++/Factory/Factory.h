#ifndef _HEADER_FACTORY_H_
#define _HEADER_FACTORY_H_

#include <vector>
#include "../Type/type.h"

template<class T>
class Factory
{
public:
	Factory() {};
	virtual ~Factory() {};

	void Set(T* _T)
	{
		if (nullptr != _T)
		{
			m_vtData.push_back(_T);
		}
	}

	std::vector<T*> m_vtData;
};

#endif