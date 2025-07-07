#include <iostream>

using namespace std;

// ? Task class
class Task
{
	// * Attributes
	string task;
	static int id = 0;

public:
	// * Constructors
	Task()
	{
		id++;
	}

	Task(int id = 0)
	{
		this->id = id;
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