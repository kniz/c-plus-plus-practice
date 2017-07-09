#include <dirent.h>
#include <sys/stat.h>
#include <iostream>
#include <errno.h>
#include <string.h>
using namespace std;

int main() {
    DIR* iterator = opendir("C:\\MingW");
    struct dirent* file = 0;
    while(file = readdir(iterator)) {
        cout << file->d_name << " --> ";
        struct stat info;
        string path = string("C:\\MingW\\") + file->d_name;
        if(stat(path.c_str(), &info)) {
            cout << "failed: " << strerror(errno) << "\n";
            continue;
        }

        cout << "size=" << info.st_size << ", is folder=" << (info.st_mode & S_IFDIR) << "\n";
    }

    seekdir(iterator, 10);
    file = readdir(iterator);
    cout << "\n\n\n and ! " << file->d_name << "\n";

    return 0;
}