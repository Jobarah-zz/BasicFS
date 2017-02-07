//
// Created by jobar on 1/30/2017.
//

#include "DiskManager.h"
#include "FileSystem.h"
DiskManager::DiskManager() {
    this->fs = new FileSystem();
}

bool DiskManager::create(string diskName, int size, int blockSize) {
    return fs->formatDisk(diskName, size, blockSize);
}

bool DiskManager::mount(string diskName) {
    return this->fs->setUnit(diskName);
}

void DiskManager::unmount(string diskName) {
    delete this->fs;
}

bool DiskManager::allocateBlocks(int blockCount) {
//    if(this->getFreeBlocks() >= blockCount) {
        fs->allocateBlocks(blockCount);
//    }
    return false;
}

int DiskManager::getFreeBlocks(){
    return 0;
}

int DiskManager::getFreeSpace(){
    return 0;
}