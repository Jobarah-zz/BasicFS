#include "FileSystem.h"
#include "SuperBlock.h"
#include <iostream>
#include <fstream>

using namespace std;

FileSystem::FileSystem () {
    this->bfs = new BasicFileSystem();
}

bool FileSystem::setUnit(string diskName) {
    return false;
}

bool FileSystem::formatDisk(string diskName, int diskSize, int blockSize) {
    ofstream out;
    int blockCount = diskSize / blockSize;
    out.open(diskName, ios::out|ios::binary|ios::app);
    char * disk = (char*)calloc(blockCount, blockSize);
    out.write(disk, diskSize);
    delete [] disk;
    out.close();
    Block* diskData = getDiskData(diskName, diskSize, blockSize);
    return this->bfs->writeBlock(diskName, 0, diskData, blockSize);
}

Block* FileSystem::getDiskData(string diskName, int diskSize, int blockSize) {
    return new SuperBlock(diskName, diskSize, blockSize);
}

int FileSystem::getAvaliableBlocksCount(string diskName, int blockCount,int blockSize) {
    int usedBlocks = 0;
    int nextBlockIndex = 0;
    Block * block = new Block();

    do {

        this->bfs->readBlock(diskName, nextBlockIndex, blockSize, block);
        nextBlockIndex = block->nextBlockId;
        usedBlocks++;
    } while (block->data != NULL);

    int availableBlocks = blockCount -  usedBlocks;

    return availableBlocks;
}

bool FileSystem::allocateBlocks(int blockCount) {
    Block * superBlock = new Block();
    Block * readBlock = this->bfs->readBlock("oaDisk", 0, 512,superBlock);
    return false;
}

 int FileSystem::getNextAvailableBlock(){
     return 0;
 }
