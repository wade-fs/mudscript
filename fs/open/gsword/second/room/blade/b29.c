#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW + "虛空世界－九空刀神界" + NOR);
        set("long", @LONG
你眼前漸漸出現一個身影，手中的靈刀夜千鳥似乎感應道什麼似的，發出炫麗的光芒
照耀四周身邊亦出現許多過往的影像，定睛一看似乎是百多年前仙魔大戰的景象！！
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south":"/open/common/room/inn.c",
  "north":"/open/gsword/room1/blood/room1/r1.c",
]));
 set("objects", ([ /* sizeof() == 1 */
   "/open/gsword/second/room/blade/npc/blademan" :1,
]));
        set("no_transmit", 1);
        set("no_drop",1);
        set("no_auc",1);
        setup();
}

int valid_leave(object me, string dir)
{
if(dir=="north" && present("blademan",environment(me)))
   if(!me->query_temp("allow_pass",1))
   return notify_fail("你以為你能活得過去嗎??"+RANK_D->query_respect(me)+"想太多了\n");
return ::valid_leave(me,dir);
}
