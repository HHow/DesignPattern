#include "../Map.h"

// ���� ����� �ʱ�ȭ �ʿ�, �ȱ׷��� �ٸ����� ȣ��� link error �߻�
// c++ static ������ ��ü����� �ƴ϶� Ŭ���� ����̶�, Ŭ������ ������� ȣ��� �ʱ�ȭ ���ϸ� �����Ϸ��� ������
CRestMap* CRestMap::MapStateInstance = NULL; 
CBurningMap* CBurningMap::MapStateInstance = NULL;
CFinalMap* CFinalMap::MapStateInstance = NULL;