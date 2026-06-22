#pragma once

#include "common.hpp"

class Link;
class Component;
class AccessList;

class LinkService {
    private:
        unordered_map<int, Link*> links;
        LinkService();
        static LinkService* instance;
        static mutex mtx;
    public:
        static LinkService* getInstance();
        Link* generateLink(Component* component, AccessList* accessList, string expires_at);
};