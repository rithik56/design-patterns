#pragma once

#include "common.hpp"

class Review {
    private:
        int id;
        int userId;
        int bookId;
        string txt;
        double ratings;
        string reviewedAt;
    public:
        Review(int userId, int bookId, string txt, double ratings);
};