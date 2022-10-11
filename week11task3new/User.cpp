#include "User.h"

int User::numberOfAllUsersEver = 0;

User::User() {}

User::User(std::string firstName, std::string lastName, std::vector<User*> friends) {
	numberOfAllUsersEver++;

	id = numberOfAllUsersEver;
	this->firstName = firstName;
	this->lastName = lastName;
	this->friends = friends;
}

void User::setFriends(std::vector<User*> friends) {
	this->friends = friends;
}

std::vector<User*> User::getFriends() {
	return friends;
}

int User::getId() {
	return id;
}
