#include <ansi.h>
#include <room.h>
inherit ROOM;
void create ()
{
  set ("short", "銀針門偏廳");
  set ("long", @LONG

    銀針門的偏廳，牆壁上面掛著一幅扁鵲的畫，上面記載著「銀針
門創立人--扁鵲，數十年前走遍大江南北，以義診為號召，精湛的醫
術，仁厚的心腸，致使中原一帶，頗傳佳譽。」

LONG);

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/doctor/npc/hwa" : 1,
]));
  set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"r1",
  "west" : __DIR__"2.c",
  "south" : __DIR__"4.c",
  "north" : __DIR__"rset_room.c",
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if (me->query("class")!="doctor" && dir=="out")
    return notify_fail("外面是銀針門私有的藥圃，因為你不是醫者，基於道德上，你的良心不允許\你進入。!\n");
  if((!me->query("quests/acupuncture") && me->query_temp("quests/acup") != 13) && dir == "north")
    return notify_fail("沒有經過銀針門掌門人的同意，你不敢隨意進去。\n");
  return ::valid_leave(me,dir);
}



