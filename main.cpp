/*	Project:    Text Analyzer
	Name:       Michael Fliess
    Partner:    PARTNER'S NAME IF ANY
    Class:      CSC 1810 - 2
*/

#include <iostream>
#include <vector>

using namespace std;

string menuNum = "2";
int i = 1;

void inputPost(string &name)
{
	if (::i < 2)
	{
		cout << "Input Post" << endl;
		getline(cin, name);
		char c;
		cin.get(c);
		cout << endl;
	}
	else
	{
		cout << "Input Post" << endl;
		getline(cin, name);
		cout << endl;
	}

	return;
}

void outputPost(const string &name)
{
	cout << "Output Post" << endl;
	cout << name << endl
		 << endl;
	//cin.ignore(1);
	return;
}

void getTotalWordCount(const string &name, unsigned int i = 0, int words = 1)
{
	cout << "Word Count" << endl;

	while (i < name.size())
	{
		if (name.at(i) == ' ')
		{
			words++;
		}
		i++;
	}
	cout << "The total word count for your post is: " << words << endl
		 << endl;
	return;
}

void replaceAcronyms(const string &finder, const string &replacer, string &name)
{
	while (name.find(finder) < 10000)
	{

		int start = name.find(finder);
		int length = finder.length();

		name.replace(start, length, replacer);

		cout << "Acronym found. Searching again." << endl;
	}

	cout << "Acronym not found. Returning to menu." << endl;
	cin.ignore(1);
	return;
}

//This function is an overloaded function that only passes in the post by reference in order to implement a cleaner design.
void replaceAcronyms(string &name)
{

	string finder;
	string replacer;
	cout << "Enter acronym to find. ";
	cin >> finder;
	cout << "Enter phrase to replace it with. ";
	cin >> replacer;

	while (name.find(finder) < 10000)
	{

		int start = name.find(finder);
		int length = finder.length();

		name.replace(start, length, replacer);

		cout << "Acronym found. Searching again." << endl;
	}

	cout << "Acronym not found. Returning to menu." << endl;
	cin.ignore(1);
	return;
}

int main(int argc, char *argv[])
{

	string post = "No text yet. Choose an option to get started. Enter 1 to input a post, 2 to output your post, 3 to get the total word count, 4 to replace an acronym you choose, or 5 to quit.";

	while (::i < 10000)
	{

		if (::menuNum == "1")
		{
			inputPost(post);
		}

		if (::menuNum == "2")
		{
			outputPost(post);
		}

		if (::menuNum == "3")
		{
			getTotalWordCount(post);
		}

		if (::menuNum == "4")
		{
			cout << "Acronym Replacer" << endl;

			//replaceAcronyms(post); This function call would be used in order to access the cleaner implementation of this function.

			string finder;
			string replacer;
			cout << "Enter acronym to find. ";
			cin >> finder;
			cout << "Enter phrase to replace it with. ";
			cin >> replacer;

			replaceAcronyms(finder, replacer, post);
		}

		if (::menuNum == "5")
		{
			cout << "Thank you for using my software." << endl;

			{
				char c;
				cout << "Hit enter to exit:";
				cin.get(c);

				return 0;
			}
		}

		cout << "Please enter menu choice: " << endl;

		getline(cin, ::menuNum);

		cout << endl;

		::i++;
	}

	// This causes the program to pause at its completion, only if it does not follow the intended sequence.
	{
		char c;
		cout << "Hit enter to exit:";
		cin.get(c);
	}
	return 0;
}