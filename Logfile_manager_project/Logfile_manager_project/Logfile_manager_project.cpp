#include <iomanip>
#include <chrono>
#include <ctime>
#include <filesystem>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <fstream>
#include <filesystem>
class LogFileManager {
public:
    LogFileManager() = default;
    ~LogFileManager() = default;

    LogFileManager(const LogFileManager&) = delete;
    LogFileManager& operator=(const LogFileManager&) = delete;


    void make_or_open_File(const std::string& filename);
    void write_File(const std::string& filename, const std::string& message);
    std::vector<std::string> readLogs(const std::string& filename);
    void close_File(const std::string& filename);
    void delete_File(const std::string& filename);
    void rename_File(const std::string& oldName, const std::string& newName);
private:
    std::map<std::string, std::unique_ptr<std::fstream>> logFiles;// 스마트포인터활용 fstream생성

};


void LogFileManager::make_or_open_File(const std::string& filename) {
    if (logFiles.find(filename) == logFiles.end()) {
        logFiles[filename] = std::make_unique<std::fstream>(filename, std::ios::in | std::ios::out | std::ios::app);
        std::cout << "파일을 만들거나 열었습니다: " << filename << std::endl;
    }
}

void LogFileManager::write_File(const std::string& filename, const std::string& message) {
    auto it = logFiles.find(filename);

    if (it != logFiles.end()) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        struct tm timeinfo;
        localtime_s(&timeinfo, &now_c);// localtime_s 함수 내부의 역참조를 위해 주소 연산자로 호출

        *(it->second) << "[" << std::put_time(&timeinfo, "%Y-%m-%d %H:%M:%S") << "] " << message << std::endl;
    }  // *( (*it).second)   사용자정의 operator*()호출
}

std::vector<std::string> LogFileManager::readLogs(const std::string& filename) {
    std::vector<std::string> logs;  //vector[] = 자바의 arraylist와 비슷
    std::ifstream file(filename); // ifstream생성자호출 filename열기

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            logs.push_back(line);
        }
        file.close();
    }
    return logs;
}

void LogFileManager::close_File(const std::string& filename) {
    if (logFiles.erase(filename)) {
        std::cout << " 파일을 닫았습니다: " << filename << std::endl;
    }
}

void LogFileManager::delete_File(const std::string& filename) {

    logFiles.erase(filename);  //먼저 메모리에서 제거해 파일을 닫음


    if (std::filesystem::remove(filename)) {
        std::cout << "파일이 삭제되었습니다: " << filename << std::endl;
    }
    else {
        std::cout << "삭제할 파일이 없거나 실패했습니다." << std::endl;
    }
}


void LogFileManager::rename_File(const std::string& oldName, const std::string& newName) {

    auto it = logFiles.find(oldName);   // 메모리에 해당 파일이 있는지 확인
    if (it == logFiles.end()) {
        std::cout << "변경할 파일이 목록에 없습니다." << std::endl;
        return;
    }

    logFiles.erase(it);//현재 열려있는 파일을 메모리에서 제거해야 변경가능

    //파일 이름 변경
    std::error_code error_code;
    std::filesystem::rename(oldName, newName, error_code);//오류시 error code 저장

    if (!error_code) {
        std::cout << "이름 변경 성공: " << oldName << " > " << newName << std::endl;
        //  새 이름으로 다시 파일을 열어 등록
        make_or_open_File(newName);
    }
    else {
        std::cout << " 변경 실패: " << error_code.message() << std::endl;
        // 실패 시 기존 이름으로 복구 시도
        make_or_open_File(oldName);

    }


}
