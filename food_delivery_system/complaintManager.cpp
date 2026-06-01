#include "complaintManager.hpp"

ComplaintManager* ComplaintManager::instance = NULL;
mutex ComplaintManager::mtx;

ComplaintManager::ComplaintManager() {

}

ComplaintManager* ComplaintManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new ComplaintManager();
        }
        mtx.unlock();
    }
    return instance;
}

Complaint* ComplaintManager::addComplaint(Order* order, string query, COMPLAINT_TYPE type) {
    int complaintId = newComplaintId++;
    Complaint* complaint = new Complaint(complaintId, order, query, type);
    this->mp[newComplaintId] = complaint; 
    return complaint;
}