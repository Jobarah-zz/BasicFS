#ifndef BASICFS_DISKMANAGER_H
#define BASICFS_DISKMANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include "FileSystem.h"

using namespace std;

class DiskManager {
    FileSystem *fs;
public:
    DiskManager();
    bool create(string diskName, int size, int blockSize);
    int getFreeBlocks();
    int getFreeSpace();
    bool mount(string diskName);
    void unmount(string diskName);

    bool allocateBlocks(int blockCount);
};


#endif //BASICFS_DISKMANAGER_H
