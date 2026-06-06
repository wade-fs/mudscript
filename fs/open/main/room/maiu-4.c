// Room: /open/main/room/maiu-4.c
inherit ROOM;

void create ()
{
  set ("short", "小村廣場");
  set ("long", @LONG
走進了村內,一個中形的廣場就在眼前,幾隊苗族士兵正在
操練著,預備對抗漢族的入侵,你的東方,南方,北方各有一棟小
屋.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"maiu-7",
  "north" : __DIR__"maiu-6",
  "west" : __DIR__"maiu-5.c",
  "east" : __DIR__"maiu-3",
]));
  set("outdoors", "/open/main");

  setup();
}
