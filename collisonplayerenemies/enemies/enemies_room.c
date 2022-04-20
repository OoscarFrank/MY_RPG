/*
** EPITECH PROJECT, 2022
** prg
** File description:
** enemies room
*/

#include "../includes/motor.h"

int search_len_en(adv_t *adv)
{
    for (int i = 0; i < 10; ++i)
        if (adv[i].pos.x == - 1)
            return i;
    return 0;
}

void place_enemies(char *str, enemies_t *enem_t)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == 'L')
            enem_t->little_adv[search_len_en(enem_t->little_adv)]
            .pos = (sfVector2f){i % 22 * 78 + 140, (i / 22 * 90) + 82};
        if (str[i] == 'F')
            enem_t->flying_adv[search_len_en(enem_t->flying_adv)]
            .pos = (sfVector2f){i % 22 * 78 + 140, (i / 22 * 90) + 82};
        if (str[i] == 'I')
            enem_t->big_adv[search_len_en(enem_t->big_adv)]
            .pos = (sfVector2f){i % 22 * 78 + 140, (i / 22 * 90) + 82};
        if (str[i] == 'N')
            enem_t->no_mouving_adv[search_len_en(enem_t->no_mouving_adv)]
            .pos = (sfVector2f){i % 22 * 78 + 140, (i / 22 * 90) + 82};
        if (str[i] == 'W')
            enem_t->wall_adv[search_len_en(enem_t->wall_adv)]
            .pos = (sfVector2f){i % 22 * 78 + 140, (i / 22 * 90) + 82};
    }
}

void draw_adv(adv_t *adv, sfRenderWindow *wndw)
{
    for (int i = 0; i < 10; ++i)
        if (adv[i].pos.x != - 1 && adv[i].pos.y != - 1) {
            sfSprite_setPosition(adv[i].sp, adv[i].pos);
            sfRenderWindow_drawSprite(wndw, adv[i].sp, NULL);
        }
}

void draw_enemies(enemies_t *enem_t, sfRenderWindow *wndw, player *py, room *rm)
{
    anim_enemies(enem_t);
    move_enemies(enem_t, py, rm);
    draw_adv(enem_t->no_mouving_adv, wndw);
    //draw_adv(enem_t->wall_adv, wndw);
    draw_adv(enem_t->flying_adv, wndw);
    draw_adv(enem_t->little_adv, wndw);
    draw_adv(enem_t->big_adv, wndw);
}