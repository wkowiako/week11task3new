#pragma once
#include <vector>
#include "User.h"

class Graph {
public:
	Graph();
	int findDistance(int id1, int id2);

private:
	void mock();
	User* getUserById(int id);
	int calculateDistance(User* start, User* destination);

	std::vector<User*> nodes; //TODO: Is that correct way to store nodes? Should I store them in a container in the first place?
	//std::vector<User> nodes; 

};
