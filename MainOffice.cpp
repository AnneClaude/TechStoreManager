#include "MainOffice.h"


MainOffice::MainOffice() {}

MainOffice::~MainOffice() {
	for (std::map<std::string, Branch*>::iterator it = branches.begin(); it != branches.end(); ++it) {
		delete it->second; // delete Branch pointers
	}
}

// getinstance func:
MainOffice& MainOffice::getInstance() {
	static MainOffice instance;
	return instance;
}

// Add & Remove Branch:
void MainOffice::addBranch(const std::string& locat, int cap) {

	//if there is a branch with the same location:
	if (this->branches.find(locat) != this->branches.end())
		throw ExistingBranchInsertError();

	branches[locat] = new Branch(locat, cap);
}

void MainOffice::removeBranch(const std::string& locat) {

	std::map<std::string, Branch*>::iterator iter;
	iter = this->branches.find(locat);
	if (iter == branches.end())
		throw NonExistingBranchRemoveError();
	delete iter->second; // deleting the branch "section"
	branches.erase(iter);

}


//sum:
int MainOffice::sumPrices(const std::vector<Item*>& catalog) {
	int totalValue = 0; //sum of prices in the catalog.
	for (int i = 0; i < catalog.size(); ++i)
		if (catalog[i] != nullptr)
			totalValue += catalog[i]->getPrice();
	return totalValue;
}


// Get branch of location:
Branch& MainOffice::getBranch(const std::string& locat) {
	std::map<std::string, Branch*>::iterator iter;
	iter = this->branches.find(locat);
	if (iter == this->branches.end())
		throw NonExistingBranchRetrieveError();
	return *(iter->second);
}

// comparing branches by value:
bool MainOffice::compareByValue(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
	if (a.second != b.second)
		return a.second < b.second;
	return a.first < b.first;
}
