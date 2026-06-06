// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "南廂房");
  set ("long", @LONG
這是計謀廳的南廂房，你可以看到計謀廳的長老正坐在那邊
，手上拿著筆正在地形圖上作記號，仔細看那張地形圖才發覺是
儒門四周的地形，可能是正在作儒門的防備工事圖。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"w3.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/old_scholar2.c" : 1,
]));

  setup();
}
