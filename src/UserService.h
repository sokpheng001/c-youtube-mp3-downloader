#pragma once
#include"User.h"
#include<vector>
using namespace std;

class UserService{
    public: 
        virtual User createNewUser(User user) = 0;
        virtual vector<User> getAllUsers() = 0;
        virtual int deleteUserById(int id) = 0;
};