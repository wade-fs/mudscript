//room:/u/e/eva/village/room/room-42.c        made by eva
//加入ctitle npc. -CHAD-20090421
#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit ROOM;

void create()
{
    set("short","魔界村民房");
    set("long","
    此處位於魔界之中，卻有著不凡的氣息，與魔界截然不同的裝設擺\飾，屋內十分的簡單，
只見有一位老者坐在椅子上，看起來就像是歷經過許\多滄桑，但仍然正氣凜然使你心生敬佩！\n\n");
    set("exits",([
        "south" : __DIR__"room-15",
        ]));
    set("objects",([
        "/open/ctitle/npc/lay" : 1,
    ]));
    set("no_fight",1);
    set("no_magic",1);
    set("light_up",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);
    setup();
}
