//room:/u/e/eva/village/room/room-52.c        made by eva
#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit BANK;

void create()
{
    set("short","魔界村錢莊");
    set("long","
    這裡是魔界村中的錢莊, 魔界村由於有魔力的保護下, 所以特別
的令人覺得安心, 錢莊老闆是一個和藹可親的人, 把錢存在這裡準沒
錯!!
    旁邊有一個布告(board)!\n\n");
    set("exits",([
        "out" : __DIR__"room-48",
        ]));
    set("objects",([
        V_NPC"b_boss" : 1 ,
        ]));
    set("item_desc",([
        "board" : "
        balance:   查看你現有的存款    convert:  換錢幣
        withdraw:  提款                deposit:  存款\n\n",
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("light_up",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);
    setup();
}
