//
// Created by jobar on 2/2/2017.
//

#include "SuperBlock.h"

SuperBlock::SuperBlock(string diskName, int diskSize, int blockSize) {
    this->diskName = diskName;
    this->diskSize = diskSize;
    this->blockSize = blockSize;
    this->blockCount = diskSize / blockSize;
}
