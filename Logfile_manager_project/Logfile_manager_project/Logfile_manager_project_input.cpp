#include "Logfile_manager_project.cpp"    


int main() {

    //1,2,3,4 입력 1파일만들기,2파일쓰기,3읽기 4닫기 행동후 원위치 2번은 매개변수첫번째에 파일이름 두번째 파일쓰는내용 


    LogFileManager manager;
    int choice = 0;
    std::string filename, message;

    while (true) {
        std::cout << "\n[메뉴] 1:파일만들기or열기, 2:텍스트쓰기, 3:전체읽기, 4:파일삭제,5:파일이름변경 6:종료\n";
        std::cout << "선택: ";
        std::cin >> choice;
        if (choice == 6) break;
        switch (choice)
        {
        case 1:
            std::cout << "파일만들기 or 열기 파일명(확장자필수): ";
            std::cin >> filename;
            manager.make_or_open_File(filename);
            break;
        case 2:
            std::cout << "텍스트쓰기 파일명: ";
            std::cin >> filename;
            std::cout << "텍스트 내용: ";
            std::cin.ignore(); // 입력 버퍼 비우기
            std::getline(std::cin, message); // 공백 포함 한 줄 읽기
            manager.write_File(filename, message);
            break; 
        case 3:
            std::cout << "읽을 파일명: ";
            std::cin >> filename;
            {
                std::vector<std::string> logs = manager.readLogs(filename);
                std::cout << "파일내용: [" << filename << "]\n";
                for (const auto& line : logs) {
                    std::cout << line << std::endl;
                }
            }
            break;
        case 4:
            std::cout << "닫을 파일명: ";
            std::cin >> filename;
            manager.delete_File(filename);
            break;
        case 5:
        {
            std::string oldName, newName;
            std::cout << "변경할 현재 파일명: ";
            std::cin >> oldName;
            std::cout << "변경할 새로운 파일명: ";
            std::cin >> newName;

            manager.rename_File(oldName, newName);
        }
        break;








        default:
            std::cout << "잘못된 입력입니다.\n";
            break;
        }
    }

    std::cout << "프로그램을 종료합니다.\n";
    return 0;







        }





 

   


