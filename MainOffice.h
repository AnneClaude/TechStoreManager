#pragma once

#include "Branch.h"
#include "HWExceptions.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

class MainOffice
{
	std::map<std::string, Branch*> branches; //the required map
	MainOffice(); //C'tor in private because its a Singleton.

public:

	//public destructor:
	~MainOffice();

	// getinstance func:
	static MainOffice& getInstance();

	// Add & Remove Branch:
	void addBranch(const std::string& locat, int cap);
	void removeBranch(const std::string& locat);

	// Get branch of location:
	Branch& getBranch(const std::string& locat);

	// sum help func:
	static int sumPrices(const std::vector<Item*>& catalog);

	// comprator by value:
	static bool compareByValue(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b);

	//prints(s):

	template <class func>
	inline void printBranchesByLocation(const func& print) const {
		std::cout << "There are " << branches.size() << " branches in Main Office: " << std::endl;

		std::map<std::string, Branch*>::const_iterator iter;

		for (iter = branches.begin(); iter != this->branches.end(); ++iter) {

			const std::vector<Item*>& brCatalog = iter->second->getCatalog();  // Get the catalog of the branch

			int totalValue = sumPrices(brCatalog);

			std::cout << iter->first << " : Item count: " << brCatalog.size() << ", Total Value: " << totalValue << std::endl;
			print(*(iter->second));  // Call the print function with the branch
		}
	}


	template <class func>
	void printBranchesByValue(const func& print) const {
		std::cout << "There are " << branches.size() << " branches in Main Office: " << "\n";

		std::vector< std::pair<std::string, int> > Values; /*a vector that has a pair of a locaton(string) and a value of the branch*/
		std::map<std::string, Branch*>::const_iterator iter = this->branches.begin();

		for (; iter != this->branches.end(); ++iter) {
			const Branch* br = iter->second;  // Get the Branch Section.
			const std::vector<Item*>& brCatalog = br->getCatalog();

			int totalValue = sumPrices(brCatalog);
			Values.push_back(std::make_pair(iter->first, totalValue));  // Add a pair with (branch name, branch value).
		}

		std::sort(Values.begin(), Values.end(), compareByValue);

		std::vector< std::pair<std::string, int> >::iterator iter2 = Values.begin();
		for (; iter2 != Values.end(); ++iter2) {

			const Branch* br = this->branches.find(iter2->first)->second;

			const std::vector<Item*>& brCatalog = br->getCatalog();

			std::cout << iter2->first << " : Item count: " << brCatalog.size() << ", Total Value: " << iter2->second << "\n";
			print(*br);
		}
	}
};
