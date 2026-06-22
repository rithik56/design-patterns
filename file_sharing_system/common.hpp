#pragma once

#include<iostream>
using namespace std;

enum PLAN_ENUM {
    FREE,
    PROFESSIONAL
};

enum ACCESS_MODE {
    VIEW,
    EDIT
};

extern int userId;
extern int planId;
extern int linkId;