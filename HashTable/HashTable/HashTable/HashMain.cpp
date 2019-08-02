#include <iostream>
#include <string>
#include "HT.h"

bool HT_Test();

int main()
{
	// Creates our hash table
	HashTable<std::string, int> H_Table;
	
	std::cout << "Welcome to the virtual phone book hashing program." << std::endl;
	
	// We instert 10 phone numbers into the hash table, this is the max size of the table set at the start
	H_Table.insert("Bob", 6021234567);
	H_Table.insert("Reed", 6022345678);
	H_Table.insert("Gordon", 6023456789);
	H_Table.insert("William", 6023456789);
	H_Table.insert("Sonia", 6024567891);
	H_Table.insert("David", 6025678912);
	H_Table.insert("Wilson", 6026789123);
	H_Table.insert("Adam", 6027891234);
	H_Table.insert("Jerry", 6028912345);
	H_Table.insert("Christine", 6029123456);
	
	// Prints out the current size of the used table size
	std::cout << "\nYou have imported a total of " << H_Table.get_current_size() << " contacts." << std::endl;
	
	std::cout << "\nThis are their hashing results:" << std::endl;

	// Prints out the hasing results of those 10 phone numbers
	std::cout << "========================================================" << std::endl;
	std::cout << "Bob: " << H_Table.retrieve("Bob") << std::endl;
	std::cout << "Reed: " << H_Table.retrieve("Reed") << std::endl;
	std::cout << "Gordon:" << H_Table.retrieve("Gordon") << std::endl;
	std::cout << "William:" << H_Table.retrieve("William") << std::endl;
	std::cout << "Sonia:" << H_Table.retrieve("Sonia") << std::endl;
	std::cout << "David:" << H_Table.retrieve("David") << std::endl;
	std::cout << "Wilson:" << H_Table.retrieve("Wilson") << std::endl;
	std::cout << "Adam:" << H_Table.retrieve("Adam") << std::endl;
	std::cout << "Jerry:" << H_Table.retrieve("Jerry") << std::endl;
	std::cout << "Christine:" << H_Table.retrieve("Christine") << std::endl;
	std::cout << "========================================================" << std::endl;

	// Inserts 3 more numbers, this will call our resize function and increase the table size by 5
	H_Table.insert("Melissa", 6020123456);
	H_Table.insert("Amanda", 6020234567);
	H_Table.insert("Hector", 6020345678);

	// Prints out the current size of the used table size
	std::cout << "\nYou have imported a total of " << H_Table.get_current_size() << " contacts." << std::endl;
	std::cout << "\nThis is the new contact hasing results:" << std::endl;

	std::cout << "========================================================" << std::endl;
	std::cout << "Melissa:" << H_Table.retrieve("Melissa") << std::endl;
	std::cout << "Amanda:" << H_Table.retrieve("Amanda") << std::endl;
	std::cout << "Hector:" << H_Table.retrieve("Hector") << std::endl;
	std::cout << "========================================================" << std::endl;

	// Calls our hash table test function
	HT_Test();

	system("pause");
	return 0;
}

// Bool test function
bool HT_Test()
{
	// Bool pass set to true
	bool pass = true;

	std::cout << "\n\n**TESTING**" << std::endl;

	// Initialize test
	HashTable<std::string, int> Test_Hash;
	std::cout << "========================================================" << std::endl;
	std::cout << "Does the table start at the pre set 10 size?" << std::endl;
	if(Test_Hash.table_size() == 10)
	{
		std::cout << "Result: Test passed." << std::endl;
	}
	else
	{
		std::cout << "Test failed." << std::endl;
		pass = false;
	}
	std::cout << "========================================================" << std::endl;
	std::cout << "Is the current size 0 because the table is empty?" << std::endl;
	if(Test_Hash.get_current_size() == 0)
	{
		std::cout << "Result: Test passed." << std::endl;
	}
	else
	{
		std::cout << "Test failed." << std::endl;
		pass = false;
	}

	// Insert function test
	// Retrieve function test
	std::cout << "========================================================" << std::endl;
	Test_Hash.insert("Matt", 1);
	std::cout << "Does the insert and retrieve function work properly?" << std::endl;

	if(Test_Hash.retrieve("Matt") == 1)
	{
		std::cout << "Result: Test passed." << std::endl;
	}
	else
	{
		std::cout << "Test failed." << std::endl;
		pass = false;
	}
	std::cout << "========================================================" << std::endl;

	// Current used table size test
	std::cout << "Is the current table size calculated correctly?" << std::endl;

	if (Test_Hash.get_current_size() == 1)
	{
		std::cout << "Result: Test passed." << std::endl;
	}
	else
	{
		std::cout << "Test failed." << std::endl;
		pass = false;
	}
	std::cout << "========================================================" << std::endl;
	// Hash function test
	std::cout << "Does the hash function work properly?" << std::endl;

	if (Test_Hash.hash("Tony") == (-1* std::hash<std::string>()("Tony"))%Test_Hash.table_size())
	{
		std::cout << "Result: Test passed." << std::endl;
	}
	else
	{
		std::cout << "Test failed." << std::endl;
		pass = false;
	}


	// Insert until table is full to test resize function
	Test_Hash.insert("Carla", 2);
	Test_Hash.insert("Alex", 3);
	Test_Hash.insert("Scott", 4);
	Test_Hash.insert("Jordan", 5);
	Test_Hash.insert("Sam", 6);
	Test_Hash.insert("Keira", 7);
	Test_Hash.insert("Erik", 8);
	Test_Hash.insert("Marlon", 9);
	Test_Hash.insert("Kent", 10);
	Test_Hash.insert("Sara", 11);
	Test_Hash.insert("Jane", 12);

	// Overall table size test
	std::cout << "========================================================" << std::endl;
	std::cout << "Does the table resize if the table is filled up?" << std::endl;

	if (Test_Hash.table_size() == 15)
	{
		std::cout << "Result: Test passed." << std::endl;
	}
	else
	{
		std::cout << "Result: Test passed." << std::endl;
		pass = false;
	}
	std::cout << "========================================================" << std::endl;

	return pass;
}
