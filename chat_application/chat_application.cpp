#include "profileService.hpp"
#include "chatService.hpp"
#include "profile.hpp"
#include "user.hpp"
#include "chatSection.hpp"
#include "media.hpp"
#include "chat.hpp"
#include "groupChat.hpp"

int main() {
    ProfileService* profileService = ProfileService::getInstance();
    ChatService* chatService = ChatService::getInstance();
    Profile* profile1 = profileService->createProfile(new User("rithik", "9643093319", GENDER::MALE, ""));
    Profile* profile2 = profileService->createProfile(new User("riya", "9011528769", GENDER::FEMALE, ""));
    chatService->sendProfileMessage(profile1, profile2, "hi riya", {});
    chatService->sendProfileMessage(profile2, profile1, "hey rithik", {});
    Profile* profile3 = profileService->createProfile(new User("rohit", "9876543210", GENDER::MALE, ""));
    chatService->sendProfileMessage(profile3, profile2, "Hello Riya, what you are doing on weekend ?", {});
    // 1
    cout << profile1->getChatSection()->getAllChats().size() << endl;
    // 2
    cout << profile2->getChatSection()->getAllChats().size() << endl;
    // 1
    cout << profile3->getChatSection()->getAllChats().size() << endl;
    unordered_set<Profile*> group1Profiles;
    group1Profiles.insert(profile1);
    group1Profiles.insert(profile2);
    group1Profiles.insert(profile3);
    GroupChat* group1 = chatService->createGroup("rohit,riya,rithik", group1Profiles, profile1);
    // 2
    cout << profile1->getChatSection()->getAllChats().size() << endl;
    // 3
    cout << profile2->getChatSection()->getAllChats().size() << endl;
    // 2
    cout << profile3->getChatSection()->getAllChats().size() << endl;
    chatService->sendGroupMessage(group1, "hi riya, rohit", profile1, {});
    chatService->sendGroupMessage(group1, "hi rohit, rithik", profile2, {});
    chatService->sendGroupMessage(group1, "hi riya, rithik", profile3, {});
    // rohit,riya,rithik
    cout << group1->getGroupName() << endl;
    // 3
    cout << profile1->getChatSection()->getChatHistory(group1).size() << endl;
    profile1->getChatSection()->clearChatHistory(group1);
    // 0
    cout << profile1->getChatSection()->getChatHistory(group1).size() << endl;
    // 3
    cout << profile2->getChatSection()->getChatHistory(group1).size() << endl;
    // 3
    cout << group1->getMembers().size() << endl;
    group1->exitGroup(profile1);
    // 2
    cout << group1->getMembers().size() << endl;
    return 0;
}