//
// Created by thh on 2020/9/17.
//
#include <iostream>
#include <cstring>
#include <zconf.h>
#include <sys/stat.h>

using namespace std;
bool CreateDir(const char* path_name) {
    int   i,len;
    char  DirName[256];
    strcpy(DirName, path_name);

    len = strlen(DirName);
    if (DirName[len-1] != '/') {
        strcat(DirName, "/");
    }

    for(i = 1; i < len; i++) {
        if (DirName[i] == '/') {
            DirName[i] = 0;
            if (access(DirName, 0) != 0) {
                if (mkdir(DirName, 0755) == -1) {
                    cout << "[DownloadFiles] mkdir error"<<endl;
                    return false;
                }
            }
            DirName[i] = '/';
        }
    }
    return true;
}
int main(){
    string path = "/tmp/USB/PORT2/PART1/1600943071_oem_Androidlog1/";
    auto t = CreateDir(path.c_str());
   std::cout << (bool)t << std::endl;
}
