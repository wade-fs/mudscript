//room:/u/e/eva/village/room/room-54.c        made by eva
#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit ROOM;

void create()
{
    set("short","魔界村武器店");
	set( "build", 103 );
    set("long","
    這裡是魔界村中的武器店, 身處魔界的險境之中, 如果沒有武器
防身, 相信一踏出魔界村的大門, 就會死無全屍了, 如果你手上沒有
武器, 這裡的武器會是不錯的選擇!\n\n");
    set("exits",([
        "out" : __DIR__"room-13",
        ]));
    set("objects",([
        V_NPC"w_boss" : 1 ,
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("light_up",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);
    setup();
}
