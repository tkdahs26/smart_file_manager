#ifndef LOGFILE_MANAGER_PROJECT_H
#define LOGFILE_MANAGER_PROJECT_H

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
    std::map<std::string, std::unique_ptr<std::fstream>> logFiles;

};

#endif