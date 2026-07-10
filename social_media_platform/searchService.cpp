#include "searchService.hpp"
#include "profile.hpp"

SearchService *SearchService::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new SearchService();
        }
        mtx.unlock();
    }
    return instance;
}

SearchService *SearchService::instance = nullptr;
mutex SearchService::mtx;

SearchService::SearchService()
{
}

vector<Profile *> SearchService::searchProfiles(string keyword)
{
    vector<Profile *> ans;
    for (auto it = this->profiles.begin(); it != this->profiles.end(); it++)
    {
        if (it->second->getName().substr(0, keyword.size()) == keyword)
        {
            ans.push_back(it->second);
        }
    }
    return ans;
}

unordered_map<int, Profile*> &SearchService::getProfiles()
{
    return this->profiles;
}
void SearchService::setProfiles(unordered_map<int, Profile*>& profiles)
{
    this->profiles = profiles;
}