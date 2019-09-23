#include "word_game.h"

int main() {
    char current_word[NUM_LETTERS] = {'b', 'e', 'l', 'l'};
    char target_word[NUM_LETTERS] = {'c', 'o', 'a', 't'};
    start_game(current_word, target_word);
    return 0;
}
