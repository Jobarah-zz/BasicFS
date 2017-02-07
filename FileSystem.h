#ifndef BASICFS_FILESYSTEM_H
#define BASICFS_FILESYSTEM_H

#include <string>
#include "BasicFileSystem.h"
#include "Block.h"

using namespace std;

class FileSystem {
    BasicFileSystem *bfs;

public:

    FileSystem();

    bool setUnit(string diskName);

    bool formatDisk(string diskName, int diskSize, int blockSize);

    Block* getDiskData(string diskName, int diskSize, int blockSize);

    int getAvaliableBlocksCount(string diskName, int blockCount, int blockSize);

    int getNextAvailableBlock();

    bool allocateBlocks(int blockCount);
};


#endif //BASICFS_FILESYSTEM_H
