#include "chatManager.hpp"
#include "chat.hpp"

ChatManager* ChatManager::instance = NULL;
mutex ChatManager::mtx;

ChatManager::ChatManager() {

}

ChatManager* ChatManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new ChatManager();
        }
        mtx.unlock();
    }
    return instance;
}

Chat* ChatManager::createChat(Booking* booking) {
    int chatId = newChatId++;
    Chat* chat = new Chat(chatId, booking);
    this->mp[chatId] = chat;
    return chat;
}