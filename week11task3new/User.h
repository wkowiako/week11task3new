#pragma once
#include <string>
#include <vector>
class User {
public:
	User();
	User(std::string firstName, std::string lastName, std::vector<User*> friends);
	User(std::string firstName, std::string lastName) :
		User(firstName, lastName, std::vector<User*>{}) {}; //TODO: Is that a correct way to pass an empty vector?

	void setFriends(std::vector<User*> friends);
	std::vector<User*> getFriends();
	int getId();

private:
	int id;
	std::string firstName;
	std::string lastName;
	std::vector<User*> friends;

	static int numberOfAllUsersEver;
};

