#include <iostream>
#include <random>
#include <limits>

void fixLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter a vaild input!";
}

std::mt19937 seed(){

    std::random_device rd{};

    std::seed_seq ss{
        rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};

    return std::mt19937(ss);
}

int TotalMirennse(int min, int max){

    std::uniform_int_distribution<> die(min, max);

    std::mt19937 mt{seed()};

    return die(mt);
}

void askUser(){
    std::cout << "Lets play a game. im thiking a number from 1 to 100. and you have to guess it, you only got 7 guesses!\n";

    int correctNum{TotalMirennse(1, 100)};

    int num;
    std::cout << "Enter number: ";
    std::cin >> num;

    if (!std::cin)
    {
        std::cin.clear();

        fixLine();

        return;
    }

    if (num == correctNum)
    {
        std::cout << "YOU WON! \n";
        return;
    }

    if (num < correctNum)
    {
        std::cout << "Number is too Low! \n";
    }
    else
    {
        std::cout << "Number is too High! \n";
    }


    for (int i{1}; i <= 7; i++){
        std::cout << "Enter another number: ";
        std::cin >> num;

        if (!std::cin)
        {
            std::cin.clear();

            fixLine();

            return;
        }

        if (num < correctNum){
            std::cout << "Number is too Low! \n";
        }else{
            std::cout << "Number is too High! \n";
        }

        if (num == correctNum)
        {
            std::cout << "YOU WON! \n";
            return;
        }

    }

    std::cout << "Out of guesses!";
}

int main(){

    askUser();

    return 0;
}