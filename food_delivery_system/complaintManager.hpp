#pragma once

#include "common.hpp"
#include "complaint.hpp"
#include "mutex"

class ComplaintManager {
    private:
        ComplaintManager();
        static ComplaintManager* instance;
        static mutex mtx;
        unordered_map<int, Complaint*> mp;
    public:
        static ComplaintManager* getInstance();
        Complaint* addComplaint(Order* order, string query, COMPLAINT_TYPE type);
};