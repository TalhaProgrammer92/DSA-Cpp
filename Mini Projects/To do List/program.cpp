#include <iostream>

using namespace std;

// ? Task class
class Task
{
	// * Attributes
	string task;
	static int id = 0;
	
public:
	Task *next;

	// * Constructors
	Task()
	{
		id++;
		next = NULL;
	}

	Task(int id = 0)
	{
		this->id = id;
		next = NULL;
	}

	// * Getters
	string get_task()
	{
		return task;
	}
	int get_id()
	{
		return id;
	}

	// * Setters
	void set_task(string task)
	{
		if (task.length() > 0)
			this->task = task;
	}
};

int main()
{
}