// room7.c by konn
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","古堡一樓");
        set ("long","陰陰沈沈的古堡一樓裡，到處是魍聲魅影，寒氣極是煞人。在這種地方
你覺得自身的\功\力\似乎一點一滴慢慢地流失掉，心神也不自禁地恐慌
起來。你趕忙定下心來凝聚內力已應付不可未知的妖魔鬼怪。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "south" :  __DIR__"room4",
            "north"  : __DIR__"room6",
            
      ]));

        set("objects",([ /* sizeof() == 1 */
   __DIR__"npc/mob3" : 4,
      ]));

        setup();
}
