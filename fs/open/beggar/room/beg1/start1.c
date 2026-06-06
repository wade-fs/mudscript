// Room: /u/g/guetenr/beggar/room/beg1/start1.c
inherit ROOM;

void create ()
{
  set ("short", "平原");
  set ("long", @LONG
你在一片平野上走著, 青青的綠草在散亂的碎石間叢生, 開著五色花朵
的小草堆中, 不時一些小生物爬來爬去。這裡的草地有一大片奇怪的痕跡，
有些散亂難辨，有些卻是完整的圓形和環狀，好像有什麼奇特的東西在這裡
出現過似的。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/scholar/room/newplan/area/f9.c",
  "north" : __DIR__"room1.c",
]));
  set("outdoors", "/u/open/");

  setup();
}
