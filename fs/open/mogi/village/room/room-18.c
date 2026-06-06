//room:/u/e/eva/village/room/room-18.c        made by eva
#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit ROOM;

void create()
{
    set("short","魔界村火祭壇");
    set("long","
    這裡是魔界村的左上角, 也是魔界村五陣之一, 相傳是自古以來
先人設下的, 正因為五陣的魔力, 才使得魔界村得以安保於魔界中,
祭壇四周佈滿了符咒, 符咒間散發出強大的魔力, 也許\是因為有符咒
壓制, 才使得祭壇中散發的魔力, 不至於傷害到人.\n\n");
    set("exits",([
        "east" : __DIR__"room-19",
        "south" : __DIR__"room-24",
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("outdoors",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);
    setup();
}
