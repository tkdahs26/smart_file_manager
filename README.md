# smart_file_manager

C++ 표준 라이브러리를 활용한 파일생성 및 관리하는 시스템


Tool: Visual Studio 2022


주요기능
스마트 포인터 를 활용해 알아서 관리하도록 설정 


make_or_open_File메소드 입력값 파일이 없으면 만들고 
writeLog메소드 파일에 타임스탬프와 함께 로그 기록
readLogs메소드 파일의 모든 내용을 읽어 반환
closeLogFile메소드 맵에서 해당 파일을 제거하고 리소스 해제



헤더 파일을 만들고 이 클래스가 어떤 기능을 제공하는지 한눈에 파악할 수 있도록 설계
헤더 파일 Logfile_manager_project.h
구현 파일 Logfile_manager_project.cpp
실행 파일 Logfile_manager_project_input.cpp



while (true) {}로 실행 상태를 유지하고 
switch-case로 메소드를 구분했습니다



















