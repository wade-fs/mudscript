// Room: /open/wu/room/luroom3.c
// 瀧山武館的練武場
inherit ROOM;
void create ()
{
  set ("short", "練武場");
  set ("long", @LONG
這裡是瀧山派練武場地的中庭,一條由花崗石所鋪成的道路向瀧山派的
大廳而去,西邊通往瀧山派的大門,花崗道路的二旁放滿了各式各樣的武
器,想必瀧山派雖是拳術門派,但是其他的武器也是精通的。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"luroom1",
  "south" : __DIR__"luroom4",
  "north" : __DIR__"luroom2",
  "east" : __DIR__"luroom6",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/b_trainee" : 2,
]));

  setup();
}
