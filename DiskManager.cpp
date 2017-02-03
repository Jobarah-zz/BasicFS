//
// Created by jobar on 1/30/2017.
//

#include "DiskManager.h"
#include "FileSystem.h"
DiskManager::DiskManager() {

}

bool DiskManager::create(string diskName, int size, int blockSize) {
    FileSystem *fs = new FileSystem();
    return fs->formatDisk(diskName, size, blockSize);
}

bool DiskManager::mount(string diskName) {
    this->fs = new FileSystem();
    return this->fs->setUnit(diskName);
}

void DiskManager::unmount(string diskName) {
    delete this->fs;
}

bool DiskManager::allocateBlocks(int blockCount) {
    if(this->getFreeBlocks() >= blockCount) {
        fs->allocateBlocks(blockCount);
    }
    return false;
}
