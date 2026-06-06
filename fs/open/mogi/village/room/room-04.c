//room:/u/e/eva/village/room/room-04.c        made by eva
#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit ROOM;

void create()
{
    set("short","魔界村廣場");
    set("long","
    這裡是魔界村的市中心, 也就是魔界村最繁榮的地區, 魔界村並
無人管治, 一切的生活秩序全憑村民自發自理, 倒也十分平靜融洽,
四周是一片的吵雜聲, 有許\多千奇百怪不知名的物品, 擺\在你的面前
, 看的令你眼花撩亂!\n\n");
    set("exits",([
        "north" : __DIR__"room-03",
        "east" : __DIR__"room-47",
        "south" : __DIR__"room-05",
        "west" : __DIR__"room-46",
        ]));
    set("objects",([
        V_NPC"s_genie" : 1,
        V_NPC"s_woman_a" : 1,
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("outdoors",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);   
    setup();
call_other("/obj/board/mogi_b.c","???");
}
