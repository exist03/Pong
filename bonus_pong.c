#include <ncurses.h>
#include <stdio.h>

void print_won_first();
void print_won_second();
void print_court(int* rocket1_y_position, int* rocket2_y_position, int* ball_x, int* ball_y, int* score_first,
                 int* score_second);
void move_ball(int* ball_x, int* ball_y, int* vector_x, int* vector_y, int* rocket1_y_position,
               int* rocket2_y_position);
int define_winner(int* ball_x, int* ball_y, int* score_first, int* score_second, int* rocket1_y_position,
                  int* rocket2_y_position);
void move_rocket(int* rocket1_y_possition, int* rocket2_y_possition, char temp);

int main() {
    int rocket_1_Y = 13;
    int rocket_2_Y = 13;
    int ball_X = 41;
    int ball_Y = 13;
    int vector_x = 1;
    int vector_y = 1;
    int score_first = 0;
    int score_second = 0;
    initscr();
    keypad(stdscr, true);  //Включаем режим чтения функциональных клавиш
    noecho();  //Выключаем отображение вводимых символов, нужно для getch()
    halfdelay(1);  //Устанавливаем ограничение по времени ожидания getch()

    bool ex = false;
    while (!ex) {
        int ch = getch();

        switch (ch) {
            case ERR:
                clear();
                refresh();
                move_ball(&ball_X, &ball_Y, &vector_x, &vector_y, &rocket_1_Y, &rocket_2_Y);
                print_court(&rocket_1_Y, &rocket_2_Y, &ball_X, &ball_Y, &score_first, &score_second);
                refresh();
                if (define_winner(&ball_X, &ball_Y, &score_first, &score_second, &rocket_1_Y, &rocket_2_Y)) {
                    break;
                }
                break;
            case 'a':
                move_rocket(&rocket_1_Y, &rocket_2_Y, ch);
                clear();
                refresh();
                move_ball(&ball_X, &ball_Y, &vector_x, &vector_y, &rocket_1_Y, &rocket_2_Y);
                print_court(&rocket_1_Y, &rocket_2_Y, &ball_X, &ball_Y, &score_first, &score_second);
                refresh();
                if (define_winner(&ball_X, &ball_Y, &score_first, &score_second, &rocket_1_Y, &rocket_2_Y)) {
                    getch();
                    endwin();
                    return 0;
                }
                break;
            case 'z':
                move_rocket(&rocket_1_Y, &rocket_2_Y, ch);
                clear();
                refresh();
                move_ball(&ball_X, &ball_Y, &vector_x, &vector_y, &rocket_1_Y, &rocket_2_Y);
                print_court(&rocket_1_Y, &rocket_2_Y, &ball_X, &ball_Y, &score_first, &score_second);
                refresh();
                if (define_winner(&ball_X, &ball_Y, &score_first, &score_second, &rocket_1_Y, &rocket_2_Y)) {
                    getch();
                    endwin();
                    return 0;
                }
                break;
            case 'k':
                move_rocket(&rocket_1_Y, &rocket_2_Y, ch);
                clear();
                refresh();
                move_ball(&ball_X, &ball_Y, &vector_x, &vector_y, &rocket_1_Y, &rocket_2_Y);
                print_court(&rocket_1_Y, &rocket_2_Y, &ball_X, &ball_Y, &score_first, &score_second);
                refresh();
                if (define_winner(&ball_X, &ball_Y, &score_first, &score_second, &rocket_1_Y, &rocket_2_Y)) {
                    getch();
                    endwin();
                    return 0;
                }
                break;
            case 'm':
                move_rocket(&rocket_1_Y, &rocket_2_Y, ch);
                clear();
                refresh();
                move_ball(&ball_X, &ball_Y, &vector_x, &vector_y, &rocket_1_Y, &rocket_2_Y);
                print_court(&rocket_1_Y, &rocket_2_Y, &ball_X, &ball_Y, &score_first, &score_second);
                refresh();
                if (define_winner(&ball_X, &ball_Y, &score_first, &score_second, &rocket_1_Y, &rocket_2_Y)) {
                    getch();
                    endwin();
                    return 0;
                }
                break;
            case 'c':  //Выходим из программы
                ex = true;
                break;
        }

        refresh();  //Выводим на настоящий экран
    }
    getch();
    endwin();
    return 0;
}

void print_won_first() {
    printw("--------------------------------------------------------------------------------\n");
    printw("|                                                                              |\n");
    printw("|                                   /|                                         |\n");
    printw("|                                  / |                                         |\n");
    printw("|                                 /  |                                         |\n");
    printw("|                                /   |                                         |\n");
    printw("|                                    |                                         |\n");
    printw("|                                    |                                         |\n");
    printw("|                                                                              |\n");
    printw("|                            CONGRATULATIONS!                                  |\n");
    printw("|                            ----------------                                  |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("--------------------------------------------------------------------------------");
}
void print_won_second() {
    printw("--------------------------------------------------------------------------------\n");
    printw("|                                                                              |\n");
    printw("|                                ______                                        |\n");
    printw("|                                      |                                       |\n");
    printw("|                                      |                                       |\n");
    printw("|                                ______|                                       |\n");
    printw("|                                |                                             |\n");
    printw("|                                |                                             |\n");
    printw("|                                |______                                       |\n");
    printw("|                                                                              |\n");
    printw("|                            CONGRATULATIONS!                                  |\n");
    printw("|                            _________________                                 |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("|                                                                              |\n");
    printw("--------------------------------------------------------------------------------");
}
void print_court(int* rocket1_y_position, int* rocket2_y_position, int* ball_x, int* ball_y, int* score_first,
                 int* score_second) {
    printw("--------------------%d----------------------------------------%d--------------------\n",
           *score_first, *score_second);
    // only court
    for (int y = 0; y < 27; y++) {
        for (int x = 0; x < 82; x++) {
            // printig rackets
            if ((x == 2 && (y == *rocket1_y_position - 1 || y == *rocket1_y_position ||
                            y == *rocket1_y_position + 1)) ||
                (x == 79 && (y == *rocket2_y_position - 1 || y == *rocket2_y_position ||
                             y == *rocket2_y_position + 1))) {
                printw("|");
                // printing ball
            } else if (x == *ball_x && y == *ball_y) {
                printw("*");
            } else if (((y == 0 || y == 27 - 1) && (x != 0 || x != 82 - 1))) {
                printw("-");
            } else if ((x == 0 || x == 82 - 1 || x == 82 / 2) && (y != 0 || y != 27 - 1)) {
                printw("|");
            } else {
                printw(" ");
            }
        }
        printw("\n");
    }
}
void move_ball(int* ball_x, int* ball_y, int* vector_x, int* vector_y, int* rocket1_y_position,
               int* rocket2_y_position) {
    if (*ball_x - 1 == 2 && (*ball_y == *rocket1_y_position || *ball_y == *rocket1_y_position - 1 ||
                             *ball_y == *rocket1_y_position + 1)) {
        *vector_x *= -1;
    }
    if (*ball_x + 1 == 79 && (*ball_y == *rocket2_y_position || *ball_y == *rocket2_y_position - 1 ||
                              *ball_y == *rocket2_y_position + 1)) {
        *vector_x *= -1;
    }
    if (*ball_y == 1 || *ball_y + 1 == 27 - 1) {
        *vector_y *= -1;
    }
    *ball_x += *vector_x;
    *ball_y += *vector_y;
}
int define_winner(int* ball_x, int* ball_y, int* score_first, int* score_second, int* rocket1_y_position,
                  int* rocket2_y_position) {
    if (*ball_x < 2) {
        (*score_second) += 1;
        *ball_x = 41;
        *ball_y = 13;
        *rocket1_y_position = 13;
        *rocket2_y_position = 13;
    }
    if (*ball_x > 79) {
        (*score_first) += 1;
        *ball_x = 41;
        *ball_y = 13;
        *rocket1_y_position = 13;
        *rocket2_y_position = 13;
    }
    if (*score_first == 21) {
        clear();
        print_won_first();
        refresh();
        return 1;
    }
    if (*score_second == 21) {
        clear();
        print_won_second();
        refresh();
        return 1;
    }
    return 0;
}
void move_rocket(int* rocket1_y_possition, int* rocket2_y_possition, char temp) {
    if (temp == 'a') {
        if (*rocket1_y_possition - 2 != 0) {
            *rocket1_y_possition -= 1;
        }
    } else if (temp == 'z') {
        if (*rocket1_y_possition + 2 != 27 - 1) {
            *rocket1_y_possition += 1;
        }
    } else if (temp == 'k') {
        if (*rocket2_y_possition - 2 != 0) {
            *rocket2_y_possition -= 1;
        }
    } else if (temp == 'm') {
        if (*rocket2_y_possition + 2 != 27 - 1) {
            *rocket2_y_possition += 1;
        }
    }
}