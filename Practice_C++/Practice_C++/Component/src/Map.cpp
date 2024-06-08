#include "../Map.h"

/*
// ���� ����� �ʱ�ȭ �ʿ�, �ȱ׷��� �ٸ����� ȣ��� link error �߻�
// c++ static ������ ��ü����� �ƴ϶� Ŭ���� ����̶�, Ŭ������ ������� ȣ��� �ʱ�ȭ ���ϸ� �����Ϸ��� ������
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
 
        // remove, remove_if�� c++ 20 ���� ����
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