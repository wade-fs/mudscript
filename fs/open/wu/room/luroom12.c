// Room: /open/wu/room/luroom12.c
// 瀧山武館的花園
inherit ROOM;
void create ()
{
  set ("short", "花園");
  set ("long", @LONG
這裏是瀧山武館的花園,由於瀧山武館的地理位置位在南方所以四季如
春,花繁景緻,一陣陣和煦的風吹來,讓人精神氣爽,消除了在平時練武
的辛苦,四週蝴蝶飛舞,更是談請說愛的好地方。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"luroom11",
  "south" : __DIR__"luroom14",
  "east" : __DIR__"luroom15",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/bufferfly" : 2,
]));

  setup();
}
