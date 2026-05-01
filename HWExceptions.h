#pragma once
#include <iostream>

// FullCatalogError Class:
class FullCatalogError : public std::exception {
public:
	virtual const char* what() const noexcept override {
		return "Trying to add an item to a full catalog";
	}
};

// ExistingItemError Class:
class ExistingItemError : public std::exception {
public:
	virtual const char* what() const noexcept override {
		return "Trying to add an item with an id already in the catalog";
	}
};

// NonExistingBranchRetrieveError Class:
class NonExistingBranchRetrieveError : public std::exception {
public:
	virtual const char* what() const noexcept override {
		return "Trying to retrieve a branch with a non existing location";
	}
};

// NonExistingBranchRemoveError Class:
class NonExistingBranchRemoveError : public std::exception {
public:
	virtual const char* what() const noexcept override {
		return "Trying to remove a branch with a non existing location";
	}
};

// ExistingBranchInsertError Class:
class ExistingBranchInsertError : public std::exception {
public:
	virtual const char* what() const noexcept override {
		return "Trying to add a branch with an already existing location";
	}
};

// NonExistingItemError Class:
class NonExistingItemError : public std::exception {
public:
	virtual const char* what() const noexcept override {
		return "Trying to remove an item with a non existing id";
	}
};

// NoneExistingItemTypeError Class:
class NoneExistingItemTypeError : public std::exception {
public:
	virtual const char* what() const noexcept override {
		return "Trying to get an item with a non existing type";
	}
};

// ConnectError Class:
class ConnectError : public std::exception {
public:
	virtual const char* what() const noexcept override {
		return "Failed connection attempt";
	}
};
