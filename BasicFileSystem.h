#ifndef BASICFS_BASIFILESYSTEM_H
#define BASICFS_BASIFILESYSTEM_H


#include "Block.h"
#include <string>

using namespace std;

class BasicFileSystem {
public: 
    BasicFileSystem();

    bool writeBlock(string diskName, int blockNumber, Block* block, int blockSize);

    Block * readBlock(string diskName, int blockNumber, int blockSize,Block * block);

    int getNextAvailableBlock(string diskName, int blockSize, int diskSize);
};


#endif //BASICFS_BASIFILESYSTEM_H
