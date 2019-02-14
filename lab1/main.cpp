#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printOptions()
{
    cout << "Menu: Please select one of the following options:\n\n"
            "\tquit - Quit the program\n"
            "\tdisplay - Display all restaurants\n"
            "\tadd - Add a restaurant\n"
            "\tremove - Remove a restaurant\n"
            "\tcut - \"Cut\" the list of restaurants\n"
            "\tshuffle - \"Shuffle\" the list of restaurants\n"
            "\tbattle - Begin the tournament\n"
            "\toptions - Print the options menu\n\n";
}

int find(const vector<string> &restaurants, const string &restaurant)
{
    for(int i = 0; i < restaurants.size(); i++)
    {
        if( restaurants[i] == restaurant )
        {
            return i;
        }
    }

    return -1;
}

bool isPowerOfTwo(int n)
{
    int twoPower = 1;

    while( twoPower <= n )
    {
        if( n == twoPower )
        {
            return true;
        }

        twoPower *= 2;
    }

    return false;
}

void printRestaurants(const vector<string> &restaurants)
{
    cout << "Here are the current restaurants:\n\n";

    for(int i = 0; i < restaurants.size(); i++)
    {
        cout << "\t\"" << restaurants[i] << "\"\n";
    }

    cout << "\n";
}

void addRestaurant(vector<string> &restaurants)
{
    string restaurant = "";

    cout << "What is the name of the restaurant you want to add?\n";
    getline(cin, restaurant);

    int index = find(restaurants, restaurant);

    if( index != -1 )
    {
        cout << "That restaurant is already on the list, you can not add it again.\n";
    }
    else
    {
        restaurants.push_back(restaurant);
        cout << restaurant << " has been added.\n";
    }

    cout << "\n";
}

void removeRestaurant(vector<string> &restaurants)
{
    string restaurant = "";

    cout << "What is the name of the restaurant you want to remove?\n";
    getline(cin, restaurant);

    int index = find(restaurants, restaurant);

    if(index == -1)
    {
        cout << "That restaurant is not on the list, you can not remove it.\n";
    }
    else
    {
        restaurants.erase(restaurants.begin() + index);
        cout << restaurant << " has been removed.\n";
    }

    cout << "\n";
}

void cutResaurants(vector<string> &restaurants)
{
    int number = 0;
    bool isNumberValid = false;

    while( !isNumberValid )
    {
        cout << "How many restaurants should be taken from the top and put on the bottom? ";
        cin >> number;
        isNumberValid = true;

        if(number < 0 || number > restaurants.size())
        {
            cout << "The cut number must be between 0 and " << restaurants.size() << "\n";
            isNumberValid = false;
        }
        else
        {
            int n = restaurants.size();
            vector<string> previousRestaurants = restaurants;

            for(int i = 0; i < n; i++)
            {
                restaurants[i] = previousRestaurants[(i + number) % n];
            }
        }
    }

    cin.ignore();
    cout << "\n";
}

void shuffleRestaurants(vector<string> &restaurants)
{
    if( !isPowerOfTwo(restaurants.size()) )
    {
        cout << "The current tournament size (" << restaurants.size() << ") is not a power of two (2, 4, 8...).\n"
                "A shuffle is not possible. Please add or remove restaurants.\n";

        return;
    }

    int n = restaurants.size();
    vector<string> previousRestaurants = restaurants;

    for(int i = 0; i < n / 2; i++)
    {
        restaurants[2 * i] = previousRestaurants[n / 2 + i];
        restaurants[2 * i + 1] = previousRestaurants[i];
    }
}

void battleRestaurants(vector<string> restaurants)
{
    int round = 1;

    if( !isPowerOfTwo(restaurants.size()) )
    {
        cout << "The current tournament size (" << restaurants.size() << ") is not a power of two (2, 4, 8...).\n"
                "A battle is not possible. Please add or remove restaurants.\n";

        return;
    }

    while(restaurants.size() != 1)
    {
        cout << "Round: " << round << "\n\n";

        int n = restaurants.size();
        vector<string> afterRoundRestaurants;

        for(int i = 0; i < n / 2; i++)
        {
            int number = 0;
            bool isNumberValid = false;

            while( !isNumberValid )
            {
                cout << "Type \"1\" if you prefer " << restaurants[2 * i] << " or\n";
                cout << "type \"2\" if you prefer " << restaurants[2 * i + 1] << "\n";
                cout << "Choice: ";
                cin >> number;
                cout << "\n";

                isNumberValid = true;

                if(number != 1 && number != 2)
                {
                    cout << "Invalid choice\n";
                    isNumberValid = false;
                }
                else
                {
                    afterRoundRestaurants.push_back(restaurants[2 * i + number - 1]);
                }
            }
        }

        restaurants = afterRoundRestaurants;
        round++;
    }

    cin.ignore();
    cout << "The winning restaurant is " << restaurants[0] << ".\n\n";
}

int main(int argc, char **argv)
{
    bool isWorking = true;
    vector<string> restaurants;

    cout << "Welcome to the restaurant battle! options.Enter \"options\" to see options.\n\n";

    while( isWorking )
    {
        string option = "";
        bool isOptionCorrect = false;

        while( !isOptionCorrect )
        {
            cout << "Enter your selection: ";
            getline(cin, option);
            cout << "\n";

            isOptionCorrect = true;

            if( option == "quit" )
            {
                cout << "Goodbuy!\n";
                isWorking = false;
            }
            else if( option == "display" )
            {
                printRestaurants(restaurants);
            }
            else if( option == "add" )
            {
                addRestaurant(restaurants);
            }
            else if( option == "remove" )
            {
                removeRestaurant(restaurants);
            }
            else if( option == "cut" )
            {
                cutResaurants(restaurants);
            }
            else if(option == "shuffle" )
            {
                shuffleRestaurants(restaurants);
            }
            else if(option == "battle")
            {
                battleRestaurants(restaurants);
            }
            else if(option == "options")
            {
                printOptions();
            }
            else
            {
                isOptionCorrect = false;
            }

            if( !isOptionCorrect )
            {
                cout << "Invalid Selection\n";
                printOptions();
            }
        }
    }

    return 0;
}