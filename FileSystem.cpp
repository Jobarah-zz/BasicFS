//
// Created by jobar on 2/2/2017.
//

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

int FileSystem::getAvaliableBlocksCount() {
    return 0;
}

bool FileSystem::allocateBlocks(int blockCount) {
    Block readBlock = this->bfs->readBlock("oaDisk", 0, 512);
    cout<< readBlock.data << endl;
    return false;
}
