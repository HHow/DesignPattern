#ifndef _HEADER_FACADE_H_
#define _HEADER_FACADE_H_

#include <iostream>
#include <vector>

class CActUser;
class CAbstractExpression;
class CActuser;
class Tribe;
class CComponent;
class MapComposite;

// 실 사용자가 사용하는 class
class CFacade
{
public:
	CFacade(std::string _strUserName, std::string _strType);
	~CFacade();
	void AddComponent(CComponent* _component);
	void Draw();

	std::string DoingChat(std::string _strInputWord);

	CActUser* GetActUser();
	Tribe* GetTribe();
private:
	Tribe* MyTribe = NULL;
	MapConposite* m_pMapComposite;
	CActUser* ActingUser = NULL;
	std::vector<CAbstractExpression*> vtActList;
};

#endif

/*
#pragma once
#include <memory>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>

class CMapComponent;
class CMapComposite;
enum class eMapState;

class MapFacade {
public:
    using ComponentID = std::uint64_t;

    MapFacade();
    ~MapFacade();

    // 초기화 / 종료
    void Initialize();            // 내부 Proxy/Factory 초기화
    void Shutdown();

    // 컴포넌트 추가: 소유권 이전, 성공 시 ID 반환
    std::optional<ComponentID> AddComponent(std::unique_ptr<CMapComponent> comp);

    // ID로 제거: 성공 여부 반환
    bool RemoveComponent(ComponentID id);

    // 특정 컴포넌트에 데코레이터 적용 (데코레이터는 unique_ptr로 전달)
    bool DecorateComponent(ComponentID id, std::unique_ptr<CMapComponent> decoratedVersion);

    // 바로 데코레이터를 생성/적용하는 편의 API (옵션 기반)
    bool DecorateAndAdd(std::unique_ptr<CMapComponent> base, const std::string& decoratorType);

    // 렌더/표시
    void DisplayMap();

    // 맵 상태 제어
    void SetMapState(eMapState state);
    eMapState GetMapState() const;

    // 탐색/조회
    std::vector<ComponentID> FindComponentsByType(const std::string& type) const;

    // 비동기/프리페치(선택)
    void Prefetch(); // 내부적으로 Proxy가 필요 시 로드

private:
    // 내부 구현은 opaque 포인터(또는 unique_ptr)로 감춤
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

 */