#include <iostream>
#include <unistd.h>
#include <random>
#include <fstream>
#include <time.h>

int TOTAL_SCORE = 0;

void regsiter_score() {
    std::ofstream fichier(".scorefile");

    if (fichier.is_open()) {
        fichier << TOTAL_SCORE;
        fichier.close();
    }
}

std::string display_menu(void) {
    std::string input;

    std::cout << "Menu:" << std::endl;
    std::cout << "---" << std::endl;
    std::cout << "1. Play" << std::endl;
    std::cout << "2. Exit" << std::endl;

    std::getline(std::cin, input);
    return input;
}

std::string print_commands(void) {
    std::string input;

    std::cout << "Comand:" << std::endl;
    std::cout << "---" << std::endl;
    std::cout << "1. Rock" << std::endl;
    std::cout << "2. Paper" << std::endl;
    std::cout << "3. Scissors" << std::endl;
    std::cout << "9. Exit" << std::endl;

    std::getline(std::cin, input);
    return input;
}

void display_conteur(void) {
    std::string tab[] = {
        "Rock",
        "Paper",
        "Scissors",
    };

    for (int i = 0; i < 3; i++) {
        std::cout << tab[i] << std::endl;
        sleep(1);
    }
}

int computer_playing(void) {
    srand(time(NULL));
    return rand() % 3 + 1;
}

int max(int value1, int value2) {
    if (value1 > value2)
        return 1;
    return -1;
}

int compare_result(int player_choise, int computer_choise) {  
    if (player_choise == 1 && computer_choise == 3 ||
        player_choise == 2 && computer_choise == 1 ||
        player_choise == 3 && computer_choise == 2)
        return 1;
    
    if (player_choise == player_choise)
        return 0;

    return -1;
}

void print_result(int score, int player_choise, int computer_choise) {
    std::string tab[] = {
        "Rock",
        "Paper",
        "Scissors",
    };

    std::cout << "-----" << std::endl;
    if (score == -1)
        std::cout << "You're lose" << std::endl;
    else if (score == 0)
        std::cout << "It's a tie" << std::endl;
    else
        std::cout << "You're winner" << std::endl;
    TOTAL_SCORE += score;

    std::cout << "Your choosed " << tab[player_choise - 1] << std::endl;
    std::cout << "Computer choosed " << tab[computer_choise - 1] << std::endl;
    std::cout << "Score: " << TOTAL_SCORE << std::endl;
    std::cout << "-----" << std::endl;
}

int loop_game() {
    int ret = 0;
    bool playing = true;
    std::string input;

    while (playing) {
        input = print_commands();
        if (std::stoi(input) == 9)
            playing = false;
        else {
            display_conteur();
            int computer_choise = computer_playing();
            int score = compare_result(std::stoi(input), computer_choise);
            print_result(score, std::stoi(input), computer_choise);
        } 
    }

    regsiter_score();
    return ret;
}

void extract_score_file() {
    std::ifstream fichier(".scorefile");
    
    if (fichier.is_open()) {
        fichier >> TOTAL_SCORE;
        fichier.close();
    } else {
        std::cout << "Erreur sur le fichier: Impossible d'ouvrir le fichier";
    }
}

int main(void) {
    std::string input;

    input = display_menu();

    if (input == "2")
        return 0;
    if (input == "1") {
        extract_score_file();
        return loop_game();
    }

    return 42;
}
