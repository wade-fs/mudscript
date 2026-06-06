// Room: /u/r/rence/room/room5.c

#include <room.h>
#include "/open/open.h"

inherit ROOM;

void create()
{
        set("short","瀧山迷宮");
        set("long",@LONG
這裡充滿著神秘的感覺﹐在四周各有一扇門﹐不知是通往何處﹐
七殺塔內的密秘到底是什麼呢? 這些門的背後到底通到那? 然
而在石壁上有刻著﹕

          
          「東西南北﹐陰陽無極﹐破乾坤」

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 4 */
        "杜門":__DIR__"room1",
        "傷門":__DIR__"room2",
        "景門":__DIR__"room3",
        "開門":__DIR__"room4",

        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 3 */
  "/u/k/kael/npc/kaio-mob.c" : 1,
  "/u/k/kael/npc/kmob1.c" : 2,
  "/u/k/kael/npc/kmob2.c" : 2,
]));
  setup();
}
