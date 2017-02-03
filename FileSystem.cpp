//
// Created by jobar on 2/2/2017.
//

#include <c++/bits/ios_base.h>
#include <c++/ios>
#include <c++/fstream>
#include "FileSystem.h"
#include "SuperBlock.h"
#include "Block.h"

FileSystem::FileSystem () {
}

bool FileSystem::setUnit(string diskName) {
    return false;
}

bool FileSystem::formatDisk(string diskName, int diskSize, int blockSize) {
    ofstream out;
    int blockCount = diskSize/ blockSize;
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
