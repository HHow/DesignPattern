# DesignPattern
디자인패턴/cmake 공부


main 내부 build 폴더를 만들어 실행 산출물 나옴. "main"

main 경로로 가서 아래 코드 실행

mkdir build
- build 폴더를 만들어 소스코드랑 make 산출물 파일 분리

cd build


cmake ..
- build 상위 경로에 main cmakefile이 있어 .. 붙여서 cmake
- 프로젝트 구성

cmake --build . or make
- 프로젝트 빌드

실행파일 main 생성

-----------------------------
pattern remind
refactory guru 좀 친다

1.adaptor pattern


<img width="300" alt="스크린샷 2024-03-09 오후 5 24 13" src="https://github.com/HHow/DesignPattern/assets/31755455/d8632c06-b653-4051-8b7f-696803427c61">
https://refactoring.guru/ko/design-patterns/adapter


https://refactoring.guru/ko/design-patterns/adapter/cpp/example


https://cinrueom.tistory.com/49

새로운 기능이 추가되지만 사용자는 기존에 쓰는 api를 계속 쓰고싶어 한다.

이 기능은 기존의 api로 제공하기 좀 껄끄럽지만

제공하는 api를 상속받아 해당 api에 신규 기능을 끼워넣는다 보면 된다.

1.adaptee란 클래스를 만들어서 adaptee를 통해 api를 불리게 할수도 있고

2.다중 상속을 통해 기존 api호출되면 신규 class 에서 동작하는 기능을 추가로 호출


