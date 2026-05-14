/*
Author: Jason Miller
Date: 7 May 2026
Description: Creates a specified number of entries in Sequence A001155
    as defined by the OEIS. https://oeis.org/A001155
*/
#include <iostream>
#include <limits>
#include <string>

/*
This function takes the input and finds the next entry in the sequence.
Finds the frequency of each number until it changes and combines it 
with the number until it reaches the end of the entry.

For example: 888
Outputs 38 (because there are 3 8s)

Another example: 7722229
Outputs 274219 (because there are 2 7s, 4 2s, and 1 9)
*/
std::string makeLine(const std::string inputLine) {
    std::string sameCharacterList; //holds the current sequence of same-character sequence
    std::string nibble; //a 2-character chunk that makes up each entry in the sequence.
    int sequenceIndex = 0; //stores the number of the character we're analyzing in the sequence length 
    std::string workingLine; //after finding each nibble, it appends it to this. returns this


    //repeats for while the sequence index is less than the length.
    while (sequenceIndex < inputLine.length()) {
        do {
            sameCharacterList.append(std::to_string(inputLine.at(sequenceIndex) - '0')); //by subtracting '0' it reads it as a number, not ascii
            sequenceIndex += 1;

            //checks for if the current character equals the last, and if the index is still less than the length.
            //Check for if it's less than the length first to prevent a crash from reading from what's at an out of bounds index.
        } while ((sequenceIndex < inputLine.length()) && ((inputLine.at(sequenceIndex) - '0') == (sameCharacterList.at(0) - '0')));
            //sets the nibble to the length of the list
            nibble = std::to_string(sameCharacterList.length());
            //appends the first value to that list. subtracts '0' to have it read as a number
            nibble.append(std::to_string(sameCharacterList.at(0) - '0')); 

            sameCharacterList = "";

            workingLine.append(nibble);
    }
    return workingLine;
}


//Asks the user how many parts of the sequence to return, then calculates them via a loop.
int main() {
    int userInput; //dummy variable.
    std::cout << "How many entries in the sequence to return?: ";

    //validate input
    while (!(std::cin >> userInput)) {
        std::cout << "enter a number, stoopid. INTEGER. " << std::endl;
        std::cin.clear(); //clears some bullshit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignores some bullshit so it works
    }

    const int linesToPrint = userInput;
    std::cout << std::endl;

    if (linesToPrint > 60) {
        std::cout << "Woah there pardner, that's a big number.\n"
        "Entries grow exponentially and, past 60, will take a while to compute.\n"
        "You sure?\n"
        "[1]: Yea\n"
        "[2]: waitttt actually nvm lol\n" << std::endl;
        std::cin >> userInput;
        if (userInput == 2) {
            std::cout << "ok twin" << std::endl;
            abort();
        }
    }

    std::string lastLine = "0";
    std::cout << "0" << std::endl;
    for (int i = 0; i < (linesToPrint - 1); i++) {
        lastLine = makeLine(lastLine);
        std::cout << lastLine << std::endl;
    }
    return 0;
}
