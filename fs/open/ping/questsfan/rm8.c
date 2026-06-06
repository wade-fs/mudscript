// Room: /u/d/dhk/questsfan/rm8
inherit ROOM;

void create ()
{
  set ("short", "六分棧道");
  set ("long", @LONG
好不容易爬到半山處。這兒是一處有六條分枝林道的分路
口。此地稱做六分棧道，棧道中央有一處小水泉、一株長的很
像一座大涼亭的巨榕，而榕樹下有數塊平滑的大石。一切的一
切就好像一處大自然( 嵩山 )造的休息棧一般，故名為〝棧道〞
也。

LONG);

  set("exits", ([ /* sizeof() == 6 */
  "northup" : __DIR__"rm9",
  "southwest" : __DIR__"rm21",
  "westdown" : __DIR__"rm7",
  "northwest" : __DIR__"rm22",
  "northeast" : __DIR__"rm23",
  "southeast" : __DIR__"rm24",
]));
  set("outdoors", "/u/d");

  setup();
}
