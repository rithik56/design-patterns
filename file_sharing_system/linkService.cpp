#include "linkService.hpp"
#include "link.hpp"
#include "component.hpp"
#include "accessList.hpp"
#include "userPermission.hpp"

LinkService *LinkService::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new LinkService();
        }
        mtx.unlock();
    }
    return instance;
}

LinkService *LinkService::instance = nullptr;
mutex LinkService::mtx;

LinkService::LinkService()
{
}

Link *LinkService::generateLink(Component *component, AccessList *accessList, string expires_at) {
    string token = "token?component=" + component->getName();
    Link* link = new Link(linkId, token, component, accessList, expires_at);
    unordered_map<User*, UserPermission*>& componentPermisssions = component->getAccessList()->getUserAccess();
    unordered_map<User*, UserPermission*>& updatedUserPermission = accessList->getUserAccess();
    for (auto it = updatedUserPermission.begin(); it != updatedUserPermission.end(); it++) {
        if (componentPermisssions.find(it->first) == componentPermisssions.end()) {
            componentPermisssions[it->first] = it->second;
        } else {
            for (auto it2 = it->second->getModes().begin(); it2 != it->second->getModes().end(); it2++) {
                componentPermisssions[it->first]->addMode(*it2);
            }
        }
    }
    this->links[linkId] = link;
    linkId++; 
    return link;
}