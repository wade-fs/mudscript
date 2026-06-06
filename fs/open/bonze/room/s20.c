// Room: /open/bonze/npc//room/s20.c
inherit ROOM;

void create ()
{
  set ("short", "$HIW$寶殿之頂$NOR$");
  set ("long", @LONG

這裡是位於大雄寶殿的樓上,遠離了陣陣的誦經聲及練武聲
在這邊你可以好好的休息,不用怕會被人打擾.

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"bonze_room.c",
    "down" : __DIR__"big.c",
  ]));
  setup();
}

int valid_leave(object me, string dir)
{
  if( dir=="north" && !wizardp(me) )
    return notify_fail("前方密室為少林發展討論的紀錄，有建議可在下方版面上提議，謝謝。\n");
  return ::valid_leave(me,dir);
}
