# Smart File Manager (C++)

프로젝트 개요

본 프로젝트는 면접 과제 이후 리팩토링을 통해 개선한  
C++ 기반 파일 생성 및 관리 프로그램입니다.

파일 생성, 삭제, 이름 변경, 내용 쓰기 기능을 제공하며,  
스마트 포인터를 사용해 파일 자원을 안전하게 관리하도록 구현했습니다.



 
주요 기능
 switch-case 사용자 입력을 받아 다음의 기능을 선택해 실행
 파일 생성과 열기
 파일 내용 쓰기 / 읽기
 파일 삭제 및 이름 변경 


특징
std::unique_ptr 스마트포인터를 사용해 파일 스트림의 단일 소유권 관리
C++ 표준 라이브러리: filesystem, fstream 파일 관리로 활용, chrono 를 활용해 시간 정보 처리
헤더 / 구현 파일 분리를 통한 구조 정리 

배운 점
 참조(&)를 활용해 객체를 효율적으로 수정
 스마트 포인터를 사용한 자원 관리 방식
 filesystem API를 통한 파일 관리
 
개발 환경

- Language: C++
- IDE: Visual Studio 2022




구현 파일 Logfile_manager_project.cpp<br>
실행 파일 Logfile_manager_project_input.cpp<br>

 
<br><br><br><br><br>



<img width="1910" height="749" alt="file1" src="https://github.com/user-attachments/assets/7f8ad478-da6a-4ed8-9f30-faa02ff408c6" /> 실행 화면
<br><br><br>
<img width="1910" height="749" alt="file2" src="https://github.com/user-attachments/assets/086f339a-6b12-4087-8b4e-c193c74310f1" />
파일 만들기 메뉴를 선택하면 make_or_open_File 메소드 실행,
입력한 파일 이름이 이미 존재하는 경우에는 파일을 열고 존재하지 않는 경우에는 새 파일을 생성합니다.

 결과에서 testfile.txt 파일이 생성된 것을 폴더에서 확인할 수 있습니다.

 <br><br><br>

<img width="1910" height="749" alt="file3" src="https://github.com/user-attachments/assets/41932ae4-b1ca-41e2-a511-bbd927a7c6fe" /> 
텍스트 쓰기 메뉴를 선택하면 지정한 파일에 입력한 내용을 저장할 수 있습니다.

아래 예시에서는 testfile.txt 파일에 입력한 텍스트와 함께 현재 시간이 기록된 것을 확인할 수 있습니다.
텍스트 쓰기 선택 write_File 실행:find()를 사용해 메모리에 파일이 있다면 파일명과 내용을 입력해chrono 라이브러리를 활용한 현재시각과 함께 파일에 내용을 쓸 수 있습니다 
<br><br><br>


<img width="1910" height="749" alt="file4" src="https://github.com/user-attachments/assets/cb1259aa-b157-459e-90da-6027e460e69d" />전체 읽기 선택 readLogs() 실행: 파일명을 입력하면 vector.pushback을 활용해 전체 텍스트를 터미널에 출력합니다 
<br><br><br>
<img width="1910" height="749" alt="file5" src="https://github.com/user-attachments/assets/3bcf9197-34b3-4f11-b09c-5bfff54418a7" /> 이름바꾸기 선택 rename_File()실행:
이름바꾸기전 erase를 실행해서 메모리에 있는 파일을 일단 지웁니다. rename함수를 사용해서 error_code가 없다면 이름바꾸기에 성공한 파일을 메모리에 등록하고 error_code가 있으면 바꾸기 전 파일을 메모리에 등록합니다

















