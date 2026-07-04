#include "storageService.hpp"
#include "linkService.hpp"
#include "plan.hpp"
#include "editFolder.hpp"
#include "editFile.hpp"
#include "folder.hpp"
#include "file.hpp"
#include "fileInput.hpp"
#include "folderInput.hpp"
#include "accessList.hpp"
#include "component.hpp"
#include "userPermission.hpp"
#include "link.hpp"

int main()
{
    StorageService *storageService = StorageService::getInstance();
    User *user1 = storageService->createDirectory("rithik", "rithik19901998@gmail.com", new Plan(planId++, PLAN_ENUM::FREE, 1500, 0));
    Folder *user1Directory = storageService->getDirectory(user1);
    EditFolder *user1DirectoryEdit = user1Directory->edit(user1);
    Component* userFile1;
    Component* userFolder1;
    if (user1DirectoryEdit)
    {
        userFile1 = user1DirectoryEdit->createComponent(new FileInput("userFile1", "abcdefghijkl"), user1);
        userFolder1 = user1DirectoryEdit->createComponent(new FolderInput("userFolder1", {}), user1);
    }
    // 12
    cout << storageService->getDirectorySize(user1) << endl;
    User *user2 = storageService->createDirectory("rahul", "rahul19901998@gmail.com", new Plan(planId++, PLAN_ENUM::FREE, 1500, 0));
    EditFolder *user1DirectoryEdit2;
    // you don't seem to have access. Please request the access from owner
    user1DirectoryEdit2 = user1Directory->edit(user2);
    AccessList *user1DirectoryAccessList = user1Directory->getAccessList();
    unordered_set<ACCESS_MODE> permissions;
    permissions.insert(ACCESS_MODE::EDIT);
    permissions.insert(ACCESS_MODE::VIEW);
    user1DirectoryAccessList->updateUserAccess(user2, new UserPermission(permissions));
    user1DirectoryEdit2 = user1Directory->edit(user2);
    Component* userFile2;
    Component* userFolder2;
    if (user1DirectoryEdit2)
    {
        // a file or folder already exists with this name. choose another name
        user1DirectoryEdit2->createComponent(new FileInput("userFile1", "abcdefghijkl"), user2);

        userFile2 = user1DirectoryEdit2->createComponent(new FileInput("userFile2", "abcdefghijklasfsasafsafasfsafdsfhdsgfghfsdjymmgreykfuyegfyeryfewtrfewfrekfrewfhr"), user2);

        // 92
        cout << storageService->getDirectorySize(user1) << endl;

        userFolder2 = user1DirectoryEdit2->createComponent(new FolderInput("userFolder2", {new FileInput("userFile3", "ewqewqeqweqw"), new FolderInput("userFolder2", {new FileInput("userFile3", "ewqewqeqweqw")})}), user2);

        // 104
        cout << storageService->getDirectorySize(user1) << endl;

        // 0
        cout << storageService->getDirectorySize(user2) << endl;
    }

    // userFile1
    // userFolder1
    // userFile2
    // userFolder2
    user1Directory->view(user1);

    Folder *user2Directory = storageService->getDirectory(user2);

    // empty
    user2Directory->view(user2);

    LinkService* linkService = LinkService::getInstance();

    User *user3 = storageService->createDirectory("rohit", "rohit19901998@gmail.com", new Plan(planId++, PLAN_ENUM::FREE, 1500, 0));

    AccessList* userFile1AccessList = userFile1->getAccessList();
    unordered_set<ACCESS_MODE> permissions2;
    permissions.insert(ACCESS_MODE::EDIT);
    permissions.insert(ACCESS_MODE::VIEW);
    userFile1AccessList->updateUserAccess(user3, new UserPermission(permissions));

    Folder *user3Directory = storageService->getDirectory(user3);

    // 0
    cout << user3Directory->getSharedComponents().size() << endl;

    Link* userFile1Link = linkService->generateLink(userFile1, userFile1AccessList, "5/7/2026");

    // 1
    cout << user3Directory->getSharedComponents().size() << endl;

    Component* user3File1;

    user3File1 = userFile1Link->accessComponent(user3, ACCESS_MODE::VIEW);

    userFile1AccessList->removeUser(user3);

    // You don't have the required access for the component. Please request the acces from the owner.
    user3File1 = userFile1Link->accessComponent(user3, ACCESS_MODE::VIEW);

    return 0;
}