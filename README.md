# TechStoreManager
A C++ terminal application designed to simulate the backend inventory and device management system for a tech retail chain. This project models a `MainOffice` managing multiple `Branch` locations, handling polymorphic catalogs of computers and peripheral devices.

## Core Features
*   **Object-Oriented Design:** Extensive use of inheritance, polymorphism, and encapsulation to model real-world retail items (Computers, Laptops, Keyboards, Mice).
*   **Design Patterns:** Implements the **Singleton** pattern for the `MainOffice` to ensure centralized control of all store branches.
*   **Exception Handling:** Custom exception classes (`HWExceptions`) to safely manage edge cases like connecting peripherals to full ports, adding duplicate items, or querying non-existent branches.
*   **Dynamic Device Linking:** Simulates hardware connections, ensuring peripherals cannot connect to multiple computers simultaneously and respecting USB port limitations.

## Technical Highlights
*   **Language:** C++
*   **Standard Template Library (STL):** Utilizes `std::vector` and `std::map` for dynamic inventory storage and O(log n) branch retrieval by location.
*   **Runtime Type Identification (RTTI):** Uses `typeid` to dynamically verify hardware compatibility during peripheral connections.

## How to Compile and Run

This project can be compiled using any standard C++ compiler (like GCC or Clang).

**1. Compile the project:**
```bash
g++ *.cpp -o TechStoreManager.exe
```
**2. Run the executable:**
```bash
# On Windows
.\TechStoreManager.exe

# On Mac/Linux
./TechStoreManager
```
