#include "../Map.h"

/*
// 정적 멤버는 초기화 필요, 안그러면 다른데서 호출시 link error 발생
// c++ static 변수는 객체기반이 아니라 클래스 기반이라, 클래스로 정적멤버 호출시 초기화 안하면 컴파일러는 뭔지모름
CRestMap* CRestMap::MapStateInstance = NULL; 
CBurningMap* CBurningMap::MapStateInstance = NULL;
CFinalMap* CFinalMap::MapStateInstance = NULL;
*/
void Map::Component::SetParent(Component * _pComponent)
{
    if(nullptr != _pComponent)
        this->m_pParentComponent = _pComponent;
    else
        std::cout<<"Set map component is null"<<std::endl;
}

Map::Component * Map::Component::GetComponent() const
{
    return this->m_pParentComponent;
}

void Map::Mountain::Realize()
{
    std::cout<<"Mountain Realize"<<std::endl;
}

void Map::Rock::Realize()
{
    std::cout<<"Rock Realize"<<std::endl;
}

void Map::MapComposite::AddComponent(Component * _pComponent)
{
    if(nullptr != _pComponent)
    {
        _pComponent->SetParent(this);
        this->ltChildComponent.push_back(_pComponent);
    }
    else
        std::cout<<"add map component is null"<<std::endl;
}

void Map::MapComposite::RemoveComponent(Component * _pComponent)
{
    if(nullptr != _pComponent)
    {
        for(auto it = this->ltChildComponent.begin(); it != this->ltChildComponent.end(); it++)
        {
            if(*it == _pComponent)
            {
                _pComponent->SetParent(nullptr);
                this->ltChildComponent.erase(it);
            }
        }
 
        // remove, remove_if는 c++ 20 부터 지원
        //this->ltChildComponent.remove(_pComponent);
        _pComponent->SetParent(nullptr);
    }
    else
        std::cout<<"remove map component is null"<<std::endl;
}

void Map::MapComposite::Realize()
{
    for(const auto component : this->ltChildComponent)
    {
        component->Realize();
    }
}