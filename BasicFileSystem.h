//
// Created by jobar on 2/2/2017.
//

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

    int getNextAvailableBlock();
};


#endif //BASICFS_BASIFILESYSTEM_H
