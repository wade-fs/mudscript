// Room: /open/wu/room/luroom6.c
// 瀧山武館的練武場
inherit ROOM;
void create ()
{
  set ("short", "練武場");
  set ("long", @LONG
這裡是瀧山派練武場地的中庭,一條由花崗石所鋪成的道路向瀧山派的
大廳而去,西邊直行的話是通往瀧山派的大門,花崗道路的二旁放滿了椅
子,想必是瀧山派用來考較弟子的武學程度的地方。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"luroom5",
  "west" : __DIR__"luroom3",
  "south" : __DIR__"luroom7",
  "east" : __DIR__"luroom9",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/b_trainee" : 2,
]));

  setup();
}
