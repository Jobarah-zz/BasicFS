//
// Created by jobar on 2/2/2017.
//

#include <fstream>
#include "BasicFileSystem.h"

using namespace std;

BasicFileSystem::BasicFileSystem() { };
bool BasicFileSystem::writeBlock(string diskName, int blockNumber, Block* block, int blockSize) {
    block->writeBlock(diskName,blockNumber,block,blockSize);
    return true;
}

Block * BasicFileSystem::readBlock(string diskName, int blockNumber, int blockSize, Block * block) {
    return block->readBlock(diskName,blockNumber,blockSize);
}

int BasicFileSystem::getNextAvailableBlock() {
    return 0;
}