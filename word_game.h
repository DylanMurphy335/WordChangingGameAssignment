#define A01_WORD_GAME_H
#define A01_WORD_GAME_H
#include <stdio.h>
#define NUM_LETTERS 4

enum Bool { False, True };
typedef enum Bool boolean;
char get_char();
char input();
void move_cursor_left(char current_word[NUM_LETTERS], char** position_of_cursor_ptr, int* num_of_changes_ptr, char command, int* num_moves_ptr);
void move_cursor_right(char current_word[NUM_LETTERS], char** position_of_cursor_ptr, int* num_of_changes_ptr, char command, int* num_moves_ptr);
void change_letter(char current_word[NUM_LETTERS], char** position_of_cursor_ptr, int* num_of_changes_ptr, char command, int* num_moves_ptr);
void display_state(char current_word[NUM_LETTERS], char target_word[NUM_LETTERS], char* position_of_cursor, int num_of_changes,int num_of_moves);
int compare_letters(char current_word[NUM_LETTERS], char target_word[NUM_LETTERS], int num_of_changes, int max_changes,int num_of_moves, int max_moves);
void start_game(char current_word[NUM_LETTERS], char target_word[NUM_LETTERS]);
