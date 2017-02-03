//
// Created by jobar on 2/2/2017.
//

#ifndef BASICFS_SUPERBLOCK_H
#define BASICFS_SUPERBLOCK_H

#include "Block.h"
#include <string>

using namespace std;

class SuperBlock: public Block {
public:
    SuperBlock(string diskName, int diskSize, int blockSize);
    string diskName;
    int diskSize;
    int blockSize;
    int blockCount;
};


#endif //BASICFS_SUPERBLOCK_H
