#pragma once

/// @brief Extra class to store and compare queue elements. 
/// Includes overloaded comparative operators.
/// Tree based queues must have comparative elements. 
/// @tparam T 
template<typename T>
struct Item
{
	T data;
	int priority;

	bool operator<(Item item)
	{
		return (this->priority < item.priority);
	}
	bool operator>(Item item)
	{
		return (this->priority > item.priority);
	}
	bool operator==(Item item)
	{
		return (this->priority == item.priority);
	}
	bool operator<=(Item item)
	{
		return (this->priority <= item.priority);
	}
	bool operator>=(Item item)
	{
		return (this->priority >= item.priority);
	}

	Item& operator=(const Item& item)
	{
		this->data = item.data;
		this->priority = item.priority;
		return *this;
	}

	Item() {}

	Item(T data, int priority)
		: data(data), priority(priority) {}
};