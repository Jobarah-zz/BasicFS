#include <fstream>
#include <cstring>
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

int BasicFileSystem::getNextAvailableBlock(string diskName, int blockSize, int diskSize) {
    ifstream input;
    input.open(diskName,ios::in|ios::binary);
    int currentBlock = 1;
    input.seekg(currentBlock*blockSize);
    Block * diskBlock = new Block();
    char * memBlock = (char*)calloc(1, blockSize);
    do{
        input.read(memBlock, blockSize);
        memcpy(diskBlock, memBlock, sizeof(Block));
        if(diskBlock->nextBlockId != -1) {
            input.close();
            delete[] memBlock;
            return diskBlock->blockId;
        }
        currentBlock++;
        input.seekg(currentBlock*blockSize);
    }while(currentBlock*blockSize<=diskSize);

    input.close();
    delete[] memBlock;
    return -1;
}