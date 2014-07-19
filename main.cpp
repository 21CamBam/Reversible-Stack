// The following code is the base code given to me by my professor to run my program
// Please note that it is not mine

// Cammi Smith
// 11366085
// CptS 223 - Advanced Data Structures
// Homework assignment #1

#include <string>
#include <iostream>
#include <fstream>
#include "ReversibleStack.h" // You need to create ReversibleStack.h

using namespace std;

void Display(ReversibleStack& rs)
{
	// Implement this function (use only Push, Pop and IsEmpty member functions of stack)
	// After the function completes, the stack should be unmodified (see assignment instructions)
	ReversibleStack buffer;
	int num;
	if (rs.isEmpty())
	{
		cout << "Stack is empty.\n" << endl;
		return;
	}
	while (!rs.isEmpty())
	{
		num = rs.Pop();
		cout << num << " ";
		buffer.Push(num);
	}
	cout << "\n" << endl;
	while (!buffer.isEmpty()) // Puts stack rs back to original state
	{
		num = buffer.Pop();
		rs.Push(num);
	}
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Missing required argument for input file" << endl;
		return 0;
	}

	ReversibleStack rs;
	ifstream inFile;
	int num;
	inFile.open(argv[1], ifstream::in);
	if (!inFile.is_open())
	{
		cout << "Could not open: " << argv[1] << endl;
		return 0;
	}

	while (!inFile.eof())
	{
		string line;
		getline(inFile, line);

		// Process the command here
		if (0 == line.compare(0, 6, "header"))
		{
			rs.Header();
		}
		else if (0 == line.compare(0, 4, "push"))
		{
			char *str = &line[5];
			num = atoi(str);
			rs.Push(num);
			cout << num << " has been pushed.\n" << endl;
		}
		else if (0 == line.compare(0, 3, "pop"))
		{
			num = rs.Pop();
			cout << num << " has been popped.\n" << endl;
		}
		else if (0 == line.compare(0, 7, "reverse"))
		{
			rs.Reverse();
		}
		else if (0 == line.compare(0, 7, "isempty"))
		{
			bool ans = rs.isEmpty();
			if (ans)
			{
				cout << "Stack is empty.\n" << endl;
			}
			else
			{
				cout << "Stack is not empty.\n" << endl;
			}
		}
		else if (0 == line.compare(0, 7, "display"))
		{
			Display(rs);
		}
		// You'll need to implement several other commands in here
		else
		{
			cout << "Unknown command: " << line;
		}
	}

	// Complete
	inFile.close();
	cout << endl << "Done" << endl;
	cin >> num;
	return 1;
}
