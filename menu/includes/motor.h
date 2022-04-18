/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** run
*/

#ifndef MAP_H_
    #define MAP_H_

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/System/Export.h>
    #include <stdio.h>
    #include <time.h>
    #include <unistd.h>
    #include <math.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Vector3.h>
    #include <stddef.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Audio.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #define HEIGHT 1080
    #define WIDTH 1920
    #include "../includes/menu.h"

typedef struct player_s{
    sfSprite *sp;
    sfTexture *tx;
    int x;
    int y;
    int as_moved;
    int speed;
    int actual_sp;
    sfVector2f actual_speed;
    sfImage *collision_box;
}player;

typedef struct {
    sfSprite *sp;
    sfVector2f pos;
    int nb_stone;
}stone;

typedef struct {
    sfSprite *sp;
    int actual_room;
    int len_stone;
    stone *st;
    sfImage *room_col;
}room;

typedef struct {
    sfSprite *sp;
    sfVector2f pos;
    bool is_shooting;
    bool is_flying;
    int pv;
    int speed;
}adv_t;

typedef struct {
    unsigned long timer_total;
    unsigned long timer;
}timer;

typedef struct {
    timer ti;
    timer move_ti;
    sfClock *total_clock;
    adv_t *no_mouving_adv;
    adv_t *big_adv;
    adv_t *flying_adv;
    adv_t *little_adv;
    adv_t *wall_adv;
}enemies_t;

void move_enemies(enemies_t *enem_t, player *py, room *rm);
enemies_t *create_enemies(void);
void place_enemies(char *str, enemies_t *enem_t);
void draw_enemies(enemies_t *enem_t, sfRenderWindow *wndw, player *py, room *rm);
void anim_enemies(enemies_t *enem_t);
//int event_window(window *wndw, options *sprt, room *rm, player *py);
void player_room(player *py, sfRenderWindow *wd, room *rm);
player *creation_player(void);
room *create_room(char *str);
void move_event(player *py, sfEvent event, room *rm);
bool collision_stone(room *rm, player *py, int x, int y);
void draw_stone(room *rm, sfRenderWindow *wd);
void place_stone(room *rm, player *py, char *str);
stone *create_stone(char *str);
int move_sp_top(player *py, int top, room *rm);
#endif
