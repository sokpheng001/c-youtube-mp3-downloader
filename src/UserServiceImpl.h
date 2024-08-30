#pragma one
#include"UserService.h"
#include"UserRepository.h"
#include"User.h"
#include<vector>

class UserServiceImpl : public UserService{
    public:
        User createNewUser(User user) override{
            users.push_back(user);
            return user;
        }
        vector<User> getAllUsers() override{
            return users;
        }
        int deleteUserById(int id) override{
            for(auto user = users.begin(); user != users.end();){
                if(user->getId() == id){
                    users.erase(user);
                    return 1;
                }
            }
        }
};