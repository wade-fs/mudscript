// Room: /u/u/unfinished/room/is1.c
inherit ROOM;

void create ()
{
  set ("short", "石丘");
  set ("long", @LONG
位於小島的西南角, 小島上突起的小石丘, 石丘上草不不生, 只有遍地白沙
及碎岩石. 佇立此處可以看到這座小島的大概地形. 北邊是茂密的樹林, 東邊是
沿岸. 此地地高風勁, 站在此處不禁令人有"天地獨我任逍遙"的感覺.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"is6.c",
  0 : __DIR__"quest",
  "east" : __DIR__"is2.c",
]));
  set("outdoors", "y");

  setup();
}
