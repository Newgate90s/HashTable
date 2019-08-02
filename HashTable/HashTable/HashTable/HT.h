#ifndef HT_H
#define HT_H
#include <unordered_map>

// Templated hash table class using two typename values
template<typename K, typename V>
class HashTable
{
private:

	// Using struct elements for our key and value
	struct element 
	{
		K key;
		V value;
	};

	// Using element pointer pointer for the hash array, size and current size are set to int data type
	element** hash_array;
	int size;
	int current_size;
	
	// Resize function gets called when the table is full and increases the size + 5 each time.
	void resize(K key, V value)
	{
		int old_size = size;
		size += 5;
		current_size = 0;
		element** new_table = new element*[size];
		element** old_array = hash_array;

		for (int i = 0; i < size; i++)
		{
			new_table[i] = nullptr;
		}

		for(int i=0; i<old_size; i++)
		{
			if(hash_array[i] != nullptr)
			{
				insert_private(new_table, hash_array[i]->key, hash_array[i]->value);
				delete hash_array[i];
			}
		}
		insert_private(new_table, key, value);

		hash_array = new_table;
		delete[] old_array;
	}
	
	// Insert private function used for inserting the old table values into new table
	void insert_private(element** new_table, K key, V new_value)
	{
		int start_index = -1;
		int index = hash(key);

		while (index != start_index && new_table[index] != nullptr && new_table[index]->key != key)
		{
			if (start_index == -1)
			{
				start_index = index;
			}

			index = (index + 1) % size;
		}

		if (new_table[index] == nullptr)
		{
			new_table[index] = new element;
			new_table[index]->key = key;
			new_table[index]->value = new_value;
			current_size++;
		}

		else if (new_table[index]->key == key)
		{
			new_table[index]->value = new_value;
		}

		else
		{
			return;
		}
	}

public:
	
	// Hash table constructor, set to a size of 10 at the start
	HashTable() 
	{
		size = 10;
		current_size = 0;
		hash_array = new element*[size];
		
		for (int i = 0; i < 10; i++)
		{
			hash_array[i] = nullptr;
		}
	}

	// Hash table deconstructor set to default
	~HashTable() {}

	// Hash is set to int, uses the key value
	// If the hash value is less than 0 it is multiplied by -1 to make it a positive
	int hash(K key)
	{
		int hash_value = std::hash<K>()(key);

		if (hash_value < 0)
		{
			hash_value *= -1;
		}
		return hash_value % size;
	}

	// Insert function
	void insert(K key, V new_value)
	{
		int start_index = -1;
		int index = hash(key);
		
		while (index != start_index && hash_array[index] != nullptr && hash_array[index]->key != key)
		{
			if (start_index == -1)
			{
				start_index = index;
			}
			
			index = (index + 1) % size;
		}
		if(index == start_index && current_size == size)
		{
			resize(key, new_value);
		}
		else if (hash_array[index] == nullptr)
		{
			hash_array[index] = new element;
			hash_array[index]->key = key;
			hash_array[index]->value = new_value;
			current_size++;
		}

		else if (hash_array[index]->key == key)
		{
			hash_array[index]->value = new_value;
		}

		else
		{
			return;
		}
	}

	// Retrieve function
	V retrieve(K key)
	{
		int start_index = -1;
		int index = hash(key);

		while (index != start_index && hash_array[index] != nullptr && hash_array[index]->key != key)
		{
			if (start_index == -1)
			{
				start_index = index;
			}

			index = (index + 1) % size;
		}

		if (hash_array[index] == nullptr||hash_array[index]->key != key)
		{
			return NULL;
		}

		return hash_array[index]->value;
	}

	// Overall table size function, returns size
	int table_size()
	{
		return size;
	}

	// Used table size function, returns current size
	int get_current_size()
	{
		return current_size;
	}

};

#endif