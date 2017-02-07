#ifndef BASICFS_SUPERBLOCK_H
#define BASICFS_SUPERBLOCK_H

#include "Block.h"
#include <string>

using namespace std;

class SuperBlock: public Block {
public:
    SuperBlock();
    SuperBlock(string diskName, int diskSize, int blockSize);
    char diskName [30];
    int diskSize;
    int blockCount;
    virtual void writeBlock(string diskName, int blockNumber, Block* block, int blockSize);
    virtual Block * readBlock(string diskName, int blockNumber, int blockSize);
};


#endif //BASICFS_SUPERBLOCK_H
