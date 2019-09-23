#include "word_game.h"
#include "string.h"

char get_char() {
    char res = getchar();
    boolean finish = False;
    char dummy_char = ' ';
    while (finish == False) {
        dummy_char = getchar();
        if (dummy_char == '\n')
            finish = True;
    }
    return res;
}

char input() {
    char res = ' ';
    int num1 = 0;
    while (num1 == num1) {
        printf("\nEnter a command: ");
        res = get_char();
        if (res == '>' || res == '<' || (res >= 'a' && res <= 'z')) { break; }
    }
    return res;
}

void move_cursor_left(char current_word[NUM_LETTERS], char** position_of_cursor_ptr, int* num_of_changes_ptr, char command, int* num_moves_ptr){
    if (*position_of_cursor_ptr > &current_word[0]) {
            *position_of_cursor_ptr = *position_of_cursor_ptr - 1;
            *num_moves_ptr = *num_moves_ptr + 1;
    }
}

void move_cursor_right(char current_word[NUM_LETTERS], char** position_of_cursor_ptr, int* num_of_changes_ptr, char command, int* num_moves_ptr){
    if (*position_of_cursor_ptr < &current_word[NUM_LETTERS - 1]) {
            *position_of_cursor_ptr = *position_of_cursor_ptr + 1;
            *num_moves_ptr = *num_moves_ptr + 1;
    }
}

void change_letter(char current_word[NUM_LETTERS], char** position_of_cursor_ptr, int* num_of_changes_ptr, char command, int* num_moves_ptr){
    **position_of_cursor_ptr = command;
    *num_of_changes_ptr = *num_of_changes_ptr + 1;
    *num_moves_ptr = *num_moves_ptr + 1;
}

void display_state(char current_word[NUM_LETTERS], char target_word[NUM_LETTERS], char *position_of_cursor, int num_of_changes,int num_of_moves) {
    printf("-----THE GAME STATUS-----\n");
    printf("Target: ");
    for (int i = 0; i < sizeof(4); i++) {
        printf("%c", target_word[i]);
    }
    printf("\n\n");
    for (int i = 0; i < sizeof(current_word); i++) {
        printf("%c", current_word[i]);
    }
    int numOfSpaces = position_of_cursor - &current_word[0];
    printf("\n");
    for (int i = 0; i < numOfSpaces; i++) {
        printf(" ");
    }
    printf("_");
    printf("\n\nChanges: %d\n", num_of_changes);
    printf("Moves: %d\n\n", num_of_moves);
    printf("\n\n\n\n\n\n");
}

int compare_letters(char current_word[NUM_LETTERS], char target_word[NUM_LETTERS], int num_of_changes, int max_changes, int num_of_moves, int max_moves) {
    int res = 0;
    if (num_of_changes == max_changes) { res = 1; }
    else if (num_of_moves == max_moves) { res = 2; }
    else {
        res = 3;
        for (int i = 0; i < sizeof(target_word); i++) {
            if (current_word[i] != target_word[i]) {
                res = 0;
                break;
            }
        }
    }
    return res;
}

void start_game(char current_word[NUM_LETTERS], char target_word[NUM_LETTERS]) {

    char* position_of_cursor = &current_word[0];
    char** position_of_cursor_ptr = &position_of_cursor;
    int num_of_changes = 0;
    int* num_of_changes_ptr = &num_of_changes;
    int max_changes = NUM_LETTERS * 2;
    int num_of_moves = 0;
    int* num_moves_ptr = &num_of_moves;
    int max_moves = 10;
    int gameOver = compare_letters(current_word, target_word, num_of_changes, max_changes, num_of_moves, max_moves);

    display_state(current_word, target_word, position_of_cursor, num_of_changes,num_of_moves);
    while (gameOver == 0) {
        printf("Enter The Commands:\n");
        printf("Right '>'\t Left '<'\t  Changing a Letter 'a'---'z'\n");
        char command = input();
        if (command == '<'){ move_cursor_left(current_word, position_of_cursor_ptr, num_of_changes_ptr, command, num_moves_ptr); }
        else if (command == '>'){ move_cursor_right(current_word, position_of_cursor_ptr, num_of_changes_ptr, command, num_moves_ptr); }
        else{ change_letter(current_word, position_of_cursor_ptr, num_of_changes_ptr, command, num_moves_ptr); }

        display_state(current_word, target_word, position_of_cursor, num_of_changes,num_of_moves);
        gameOver = compare_letters(current_word, target_word, num_of_changes, max_changes, num_of_moves, max_moves);
    }
    if (gameOver == 1) { printf("\nGAME OVER: You have hit the change limit before getthing the word.\n\n"); }
    else if (gameOver == 2) { printf("\nGAME OVER: You have hit the guess limit before getthing the word.\n\n"); }
    else { printf("\nCongratulations you have won!! \nIt took you %d changes and %d moves\n\n", num_of_changes, num_of_moves); }
}
