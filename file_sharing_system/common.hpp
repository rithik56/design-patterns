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

enum COMPONENT_INPUT {
    FILE_INPUT,
    FOLDER_INPUT
};

extern int userId;
extern int planId;
extern int linkId;