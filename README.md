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




<img width="1910" height="749" alt="file1" src="https://github.com/user-attachments/assets/7f8ad478-da6a-4ed8-9f30-faa02ff408c6" /> 실행 화면
<img width="1910" height="749" alt="file2" src="https://github.com/user-attachments/assets/086f339a-6b12-4087-8b4e-c193c74310f1" /> 파일만들기선택 make_or_open_File 메소드 실행: 입력값 파일이있으면 메모리에 등록하고 없으면 파일 만드는 함수를 실행합니다.만들때 스마트포인터가 할당됩니다. testfile.txt가 생성된 것을 확인할 수 있습니다. 


<img width="1910" height="749" alt="file3" src="https://github.com/user-attachments/assets/41932ae4-b1ca-41e2-a511-bbd927a7c6fe" /> 텍스트 쓰기 선택 write_File 실행: 파일명과 내용을 입력해chrono 라이브러리를 활용한 현재시각과 함께 파일에 내용을 쓸 수 있습니다 



<img width="1910" height="749" alt="file4" src="https://github.com/user-attachments/assets/cb1259aa-b157-459e-90da-6027e460e69d" />전체 읽기 선택 readLogs() 실행: 파일명을 입력하면 글 쓴 시간과 전체 텍스트를 터미널에 출력합니다

<img width="1910" height="749" alt="file5" src="https://github.com/user-attachments/assets/3bcf9197-34b3-4f11-b09c-5bfff54418a7" /> 이름바꾸기 선택 rename_File()실행: 파일 선택 후 원하는 이름을 입력하면 이름을 바꿉니다.
















