/*
THE PROJECT MADE BY HERTZ
last edit: 17-Jun-2026
*/

#include <iostream> // main
#include <cstdlib>// for guessing
#include <ctime>
#include <string>
#include <vector>   // to use unknown arrays (letters in words tbh)

int main()
{
    std::cout << "Welcome to hangman game !\n";

    std::vector<std::string> words = {
        "apple", "car", "programming",
        "elephant", "computer", "engineering"
    };

    std::srand(std::time(nullptr));

    const int random_value = std::rand() % words.size();
    std::string selected_By_AI = words.at(random_value);

    std::cout << "the selected number is "
        << selected_By_AI.size()
        << std::endl;

    std::string blank(selected_By_AI.size(), '-');

    std::cout << blank;
    int tries = selected_By_AI.size() + 2; //to make it easy
    std::cout << std::endl
        << "now start putting your gussing words, you have " << tries <<" tries\n";

    char user;

    while (tries > 0)
    {
        std::cin >> user;

        bool found_in_word = false;

        for (int i = 0; i < selected_By_AI.size(); i++)
        {
            if (selected_By_AI.at(i) == user && blank.at(i) == '-')
            {
                blank.at(i) = user;
                found_in_word = true;
            }
        }

        if (found_in_word)
        {
            std::cout << "Found!\n-> ";
            std::cout << blank << std::endl;

            if (blank.find('-') == std::string::npos)
            {
                std::cout << "\nCONGRATS!!!! YOU DID IT !!!! The word was: "
                    << selected_By_AI << "\n";
                break;
            }
        }
        else
        {
            tries--;

            std::cout << "Not found, you have "
                << tries
                << " tries ";

            if (tries == 0)
            {
                std::cout << "\nGame Over! The word was: "
                    << selected_By_AI << "\n";
            }
        }
    }

    return 0;
}
