#include "profileService.hpp"
#include "user.hpp"
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

ProfileService::ProfileService()
{
}

Profile* ProfileService::createProfile(User* user) {
    // check if the phone number is already present. If present, don't create new profile and return existing profile
    for (auto it = this->userProfiles.begin(); it != this->userProfiles.end(); it++) {
        if (it->first->getPhoneNumber() == user->getPhoneNumber()) {
            return it->second;
        }
    }
    Profile* profile = new Profile(profileId++, user);
    this->userProfiles[user] = profile;
    return profile;
}

Profile* ProfileService::getUserProfile(User* user) {
    if (this->userProfiles.find(user) == this->userProfiles.end()) {
        cout << "profile not present for this user. Create a new profile" << endl;
    }
    return this->userProfiles[user];
}