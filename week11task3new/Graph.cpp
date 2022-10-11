#include "Graph.h"
#include <queue>
#include <set>

Graph::Graph() {
	mock();
}

int Graph::findDistance(int id1, int id2) {
	// Returns 0 if there are no connection between the nodes, or -1 if there are no elements with provided ids
	int distance = 0;
	User* userA, * userB;

	userA = getUserById(id1);
	userB = getUserById(id2);

	if (userA == nullptr || userB == nullptr) {
		distance = -1;
	}
	else {

		distance = calculateDistance(userA, userB);

	}


	return distance;
}

User* Graph::getUserById(int id) {
	// returns nullptr if there is no such node

	User* user = nullptr;
	int i = 0;
	while (user == nullptr && i < nodes.size()) {
		if (nodes[i]->getId() == id) {
			user = nodes[i];
		}
		i++;
	}

	return user;
}

int Graph::calculateDistance(User* start, User* destination) {
	// Returns 0 if there's no connection between those two nodes (or if it's the same user)

	int distance = 0;
	bool isFound = false;
	std::queue<User*> thisLevel; //stores nodes that are to be checked in current iteration (level)
	std::queue<User*> nextLevel; //=||= in next iteration (level)
	std::set<User*> alreadyCheckedNodes;

	// process first node
	thisLevel.push(start);
	if (start == destination) {
		isFound = true;
	}
	else {
		// find neighbours of the first node
		for (int i = 0; i < start->getFriends().size(); i++) {
			nextLevel.push(start->getFriends()[i]);
		}
	}
	alreadyCheckedNodes.insert(start);

	// process the rest of them
	while (nextLevel.size() != 0 && !isFound) {

		thisLevel = nextLevel; // TODO: does it work like I think that it does?
		nextLevel.empty();
		distance++;

		while (!thisLevel.empty()) {
			User* currentNode = thisLevel.front();

			thisLevel.pop();

			if (currentNode == destination) {
				isFound = true;
			}

			for (int i = 0; i < currentNode->getFriends().size(); i++) {
				if (alreadyCheckedNodes.find(currentNode) == alreadyCheckedNodes.end()) {// has it already been checked?
					nextLevel.push(currentNode->getFriends()[i]);
				}
			}
			alreadyCheckedNodes.insert(currentNode);
		}
	}

	if (!isFound) {
		distance = 0;
	}

	return distance;
}


void Graph::mock() {
	User* A, * B, * C, * D, * E, * F;
	A = new User("A", "A");
	B = new User("B", "B");
	C = new User("C", "C");
	D = new User("D", "D");
	E = new User("E", "E");
	F = new User("F", "F");
	A->setFriends(std::vector<User*>{B, C});
	B->setFriends(std::vector<User*>{A, E});
	C->setFriends(std::vector<User*>{A, E});
	D->setFriends(std::vector<User*>{E});
	F->setFriends(std::vector<User*>{E});
	E->setFriends(std::vector<User*>{B, C, D, F});
	nodes.push_back(A);
	nodes.push_back(B);
	nodes.push_back(C);
	nodes.push_back(D);
	nodes.push_back(E);
	nodes.push_back(F);
	//User A, B, C, D, E, F;
	//A = User("A", "A", std::vector<User*>{B, C});
	//B = User("B", "B", std::vector<User*>{&A, &E});
	//C = User("C", "C", std::vector<User*>{&A, &E});
	//D = User("D", "D", std::vector<User*>{&E});
	//E = User("E", "E", std::vector<User*>{&B, &C, &D, &F});
	//F = User("F", "F", std::vector<User*>{&E});
	/*nodes.push_back(A);
	nodes.push_back(B);
	nodes.push_back(C);
	nodes.push_back(D);
	nodes.push_back(E);
	nodes.push_back(F);*/
}

