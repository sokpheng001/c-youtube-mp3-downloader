#pragma once
#include<string>
#include<iostream>
using namespace std;

class User{
    private:
        int id;
        string username;
        string password;
        string bio;
        string createdDate;
    public:
        User(int id, string username, string password, string bio, string createdDate)
        : id(id), username(username), password(password), bio(bio), createdDate(createdDate){}
        User(){}
        void setId(int id){this->id = id;}
        int getId(){return id;}
        void setUsername(string username){this->username = username;}
        string getUsername(){return username;}
        void setPassword(string password){this->password = password;}
        string getPassword(){return password;}
        void setBio(string bio){this->bio = bio;}
        string getBio(){return bio;}
        void setCreatedDate(string createdDate){this->createdDate = createdDate;}
        string getCreatedDate(){return createdDate;}
        // Add more member functions as needed for user management
        // For example, add functions to update bio, change password, etc.
        void getUserDetail(){
            cout << "User ID: " << id << endl;
            cout << "Username: " << username << endl;
            cout << "Bio: " << bio << endl;
            cout << "Created Date: " << createdDate << endl;
        }
};