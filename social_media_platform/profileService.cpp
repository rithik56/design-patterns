#include "profileService.hpp"
#include "searchService.hpp"
#include "profile.hpp"

ProfileService *ProfileService::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new ProfileService();
        }
        mtx.unlock();
    }
    return instance;
}

ProfileService *ProfileService::instance = nullptr;
mutex ProfileService::mtx;

ProfileService::ProfileService() {

}

Profile* ProfileService::createProfile(string email, string password, string name) {
    // check if email is already registered
    if (this->checkProfile(email)) {
        cout << "this email already exists in DB. Use another email." << endl;
        return NULL;
    }
    Profile* profile = new Profile(profileId++, name, email, password);
    unordered_map<int, Profile*> profiles = SearchService::getInstance()->getProfiles();
    profiles[profile->getId()] = profile;
    SearchService::getInstance()->setProfiles(profiles);
    return profile;
}

bool ProfileService::checkProfile(string email) {
    unordered_map<int, Profile*> profiles = SearchService::getInstance()->getProfiles();
    for (auto it = profiles.begin(); it != profiles.end(); it++) {
        if (it->second->getEmail() == email) {
            return true;
        }
    }
    return false;
}