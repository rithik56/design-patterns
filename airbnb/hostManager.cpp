#include "hostManager.hpp"
#include "host.hpp"

HostManager* HostManager::instance = NULL;
mutex HostManager::mtx;

HostManager::HostManager() {

}

HostManager* HostManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new HostManager();
        }
        mtx.unlock();
    }
    return instance;
}

Host* HostManager::createHost(User* user) {
    int hostId = newHostId++;
    Host* host = new Host(hostId, user);
    this->mp[hostId] = host;
    return host;
}