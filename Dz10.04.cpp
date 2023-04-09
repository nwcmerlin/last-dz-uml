#include <iostream>

#include <fstream>

#include <string>

class FileWorker {

public:

    static FileWorker* getInstance() {

        if (instance == nullptr) {

            instance = new FileWorker();

        }

        return instance;

    }

    void createFile(const std::string& path) {

        std::ofstream file(path);

        if (!file) {

            std::cerr << "Error: unable to create file at path " << path << std::endl;

        }

        file.close();

    }

    void renameFile(const std::string& oldPath, const std::string& newPath) {

        if (std::rename(oldPath.c_str(), newPath.c_str()) != 0) {

            std::cerr << "Error: unable to rename file from " << oldPath << " to " << newPath << std::endl;

        }

    }

    void deleteFile(const std::string& path) {

        if (std::remove(path.c_str()) != 0) {

            std::cerr << "Error: unable to delete file at path " << path << std::endl;

        }

    }

    bool fileExists(const std::string& path) {

        std::ifstream file(path);

        bool exists = file.good();

        file.close();

        return exists;

    }

private:

    FileWorker() {} // private constructor

    static FileWorker* instance; // pointer to single instance of FileWorker

};

FileWorker* FileWorker::instance = nullptr; // initialize static instance pointer to nullptr

int main() {

    // get the singleton instance of FileWorker

    FileWorker* worker = FileWorker::getInstance();

    // test file creation

    worker->createFile("test.txt");

    // test file renaming

    worker->renameFile("test.txt", "newTest.txt");

    // test file deletion

    worker->deleteFile("newTest.txt");

    // test file existence

    if (worker->fileExists("newTest.txt")) {

        std::cout << "File exists" << std::endl;

    } else {

        std::cout << "File does not exist" << std::endl;

    }

    return 0;

}
