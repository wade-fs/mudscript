// Room: /open/wu/room/luroom11.c
// 瀧山武館的花園
inherit ROOM;
void create ()
{
  set ("short", "花園");
  set ("long", @LONG
這裏是瀧山武館的花園,由於瀧山武館的地理位置位在南方所以四季如
春,花繁景緻,看到修剪有序的花園,看起來十分清爽,更可以看出平時除
了練武外,更可以培養一些樂趣。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"luroom8",
  "south" : __DIR__"luroom13",
  "east" : __DIR__"luroom12",
]));

  setup();
}
