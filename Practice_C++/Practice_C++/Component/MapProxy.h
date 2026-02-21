#ifndef _HEADER_MAP_PROXY_H_
#define _HEADER_MAP_PROXY_H_

#include "Map.h"

class CLoadMapProxy
{
public:
    CLoadMapProxy() = default;
    ~CLoadMapProxy() = default;

    void AddMapComponent(std::unique_ptr<CMapComponent> _pMapComponent)
    {
        // lazy 초기화, 그런데 함수마다 초기화 넣기는 귀찮긴한데
        EnsureInitialize();
        m_pMapComposite->add(std::move(_pMapComponent));
    }
    void DisplayMap()
    {
        EnsureInitialize();
        m_pMapComposite->display();
    }

private:
    void EnsureInitialize()
    {
        if(nullptr == m_pMapComposite)
        {
            m_pMapComposite = std::make_unique<CMapComposite>();
            std:: cout << "Load Map Proxy" << std::endl;
        }
    }

    std::unique_ptr<CMapComposite> m_pMapComposite;

};

#endif