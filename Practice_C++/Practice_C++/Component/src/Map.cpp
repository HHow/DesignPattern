#include "../Map.h"

// 정적 멤버는 초기화 필요, 안그러면 다른데서 호출시 link error 발생
// c++ static 변수는 객체기반이 아니라 클래스 기반이라, 클래스로 정적멤버 호출시 초기화 안하면 컴파일러는 뭔지모름
CRestMap* CRestMap::MapStateInstance = NULL; 
CBurningMap* CBurningMap::MapStateInstance = NULL;
CFinalMap* CFinalMap::MapStateInstance = NULL;