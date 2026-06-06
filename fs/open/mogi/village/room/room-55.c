//room:/u/e/eva/village/room/room-55.c        made by eva
#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit ROOM;

void create()
{
    set("short","魔界村防具店");
	set( "build", 6894 );
    set("long","
    這裡是魔界村中的防具店, 在魔界之中有好的防具是很重要的,
身穿一套好的防具, 可以保住小命一條, 沒有防具就走出魔界村, 無
疑是自殺的行為, 所以沒有防具的旅客多喜歡在此添購!\n\n");
    set("exits",([
        "out" : __DIR__"room-14",
        ]));
    set("objects",([
        V_NPC"a_boss" : 1 ,
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("light_up",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);
    setup();
}
