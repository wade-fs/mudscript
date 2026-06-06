inherit ROOM;
#include <ansi.h>
 
void create ()
{
  set ("short", "平地");
  set ("long", @LONG
你走在道路上, 感覺微風彿過, 非常舒暢, 天邊的流雲變化萬千
彷彿是一場精彩的舞台秀..
    你發現路旁有一隻怪怪的招財貓..

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"maiu-1.c",
]));
  set("outdoors", "/open/main/room");

  setup();
}

void init ()
{
  object me=this_player ();
  if ( me->query_temp("six_sp_quest") == 9)
      {
       message_vision(HIG + "\n突然間, 你發現不遠方有個小山嶺, 你感到可疑, 急忙奔去查看.\n\n" + NOR,me);
       me->move("/open/main/mi_room/mi01.c");
      }
}
