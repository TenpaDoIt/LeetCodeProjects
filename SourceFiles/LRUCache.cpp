//		LeetCode Problem 146 :
/*
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key 
exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently 
used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?
xample:

LRUCache cache = new LRUCache( 2 / * capacity * / );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

#include "../HeaderFiles/LRUCache.hpp"

LRUCache::LRUCache(int capacity) 
{
	// initialize variables
	LRUlist = new list<LRU>;
	firstKey = 0; 
	lastKey = 0;
	size = 0;
	LRUcapacity = capacity;
}

int LRUCache::get2(int key)
{
	if (LRUmap[key] > 0)
	{
		if (firstKey == key)
		{ 
			return LRUmap[key];
		}
		else if (lastKey == key)
		{
			lastKey = LRUHead[lastKey];
			LRUHead[LRUTail[lastKey]] = 0;
			LRUTail[lastKey] = 0;
			// insert to First one
			LRUHead[firstKey] = key;
			// record key tail to whom
			LRUTail[key] = firstKey;
			firstKey = key;
			LRUHead[key] = 0;	// key Head to 0
		}
		else
		{
			LRUTail[LRUHead[key]] = LRUTail[key];
			LRUHead[LRUTail[key]] = LRUHead[key];
			// insert to First one
			LRUHead[firstKey] = key;
			// record key tail to whom
			LRUTail[key] = firstKey;
			firstKey = key;
			LRUHead[key] = 0;
		}
		
		return LRUmap[key];
	}
	return -1;
}

void LRUCache::put2(int key, int value)
{
	if (LRUmap[key] == 0)	// New Key
	{
		LRUmap[key] = value;
		if (size < LRUcapacity) // Has Position can put
		{
			// first Key head
			if (firstKey == 0)	// The first Key
			{
				firstKey = key;
				lastKey = key;
				LRUHead[key] = 0;
				LRUTail[key] = 0;
			}
			else				// Not the first
			{
				LRUHead[firstKey] = key;
				// record key tail to whom
				LRUTail[key] = firstKey;
				firstKey = key;
				LRUHead[key] = 0;	// key Head to 0
			}
			size++;
		}
		else					// Full Position has to remove the last one
		{
			if (LRUcapacity == 1)
			{
				LRUmap[lastKey] = 0;
				firstKey = key;
				lastKey = key;
				LRUHead[key] = 0;
				LRUTail[key] = 0;
			}
			else
			{
				// remove Last one 
				LRUmap[lastKey] = 0;
				lastKey = LRUHead[lastKey];
				LRUHead[LRUTail[lastKey]] = 0;
				LRUTail[lastKey] = 0;
				// insert to First one
				LRUHead[firstKey] = key;
				// record key tail to whom
				LRUTail[key] = firstKey;
				firstKey = key;
				LRUHead[key] = 0;	// key Head to 0
			}
		}
	}
	else					// Exist Key
	{
		LRUmap[key] = value;
		if (firstKey == key)
		{
			return;
		}
		else if (lastKey == key)
		{
			lastKey = LRUHead[lastKey];
			LRUHead[LRUTail[lastKey]] = 0;
			LRUTail[lastKey] = 0;
			// insert to First one
			LRUHead[firstKey] = key;
			// record key tail to whom
			LRUTail[key] = firstKey;
			firstKey = key;
			LRUHead[key] = 0;	// key Head to 0
		}
		else
		{
			LRUTail[LRUHead[key]] = LRUTail[key];
			LRUHead[LRUTail[key]] = LRUHead[key];
			// insert to First one
			LRUHead[firstKey] = key;
			// record key tail to whom
			LRUTail[key] = firstKey;
			firstKey = key;
			LRUHead[key] = 0;
		}
	}
}

int LRUCache::get(int key) 
{
	for (list<LRU>::iterator it = LRUlist->begin(); it != LRUlist->end(); it++)
	{
		if (it->key == key)
		{
			int result = it->value;
			LRU temp = LRU(it->key, it->value);
			LRUlist->erase(it);
			LRUlist->push_front(temp);
			return result;
		}
	}
	return -1;
}

void LRUCache::put(int key, int value) {

	if (LRUlist->size() < LRUcapacity)
	{
		for (list<LRU>::iterator it = LRUlist->begin(); it != LRUlist->end(); it++)
		{
			if (it->key == key)
			{
				it->value = value;
				LRU temp = LRU(it->key, it->value);
				LRUlist->erase(it);
				LRUlist->push_front(temp);
				return;
			}
		}
		LRUlist->push_front(LRU(key, value));
	}
	else
	{
		for (list<LRU>::iterator it = LRUlist->begin(); it != LRUlist->end(); it++)
		{
			if (it->key == key)
			{
				it->value = value;
				LRU temp = LRU(it->key, it->value);
				LRUlist->erase(it);
				LRUlist->push_front(temp);
				return;
			}
		}
		LRUlist->pop_back();
		LRUlist->push_front(LRU(key, value));
	}
}

void LRUCache::Test()
{
	put2(1, 1);
	put2(2, 2);
	get2(1);       // returns 1
	put2(3, 3);    // evicts key 2
	get2(2);       // returns -1 (not found)
	put2(4, 4);    // evicts key 1
	get2(1);       // returns -1 (not found)
	get2(3);       // returns 3
	get2(4);       // returns 4
}