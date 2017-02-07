//
// Created by jobar on 2/2/2017.
//

#ifndef BASICFS_BLOCK_H
#define BASICFS_BLOCK_H

#include <string>
using namespace std;
class Block {
public:
    Block();
    int blockId;
    int nextBlockId;
    char * data;
    int blockSize;
    virtual void writeBlock(string diskName, int blockNumber, Block* block, int blockSize);
    virtual Block * readBlock(string diskName, int blockNumber, int blockSize);
};


#endif //BASICFS_BLOCK_H
