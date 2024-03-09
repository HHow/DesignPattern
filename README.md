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
