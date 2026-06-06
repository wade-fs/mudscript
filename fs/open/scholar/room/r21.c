// /u/j/judd/room/r21.c
inherit ROOM;

void create ()
{
  set ("short", "中堂東側");
  set ("long", @LONG
東南邊就是通往土室圖書館的唯一道路，只見地上有一條黃土構
成的道路，只要沿著黃土走，就能到達儒門的四大圖書館之一，土室
圖書館，西邊則可通往出口。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"r25.c",
  "north" : __DIR__"r18.c",
]));
  set("light_up", 1);

  setup();
}
