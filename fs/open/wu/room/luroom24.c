// Room: /open/wu/room/luroom24.c
// 瀧山武館內道
inherit ROOM;
void create ()
{
  set ("short", "走道");
  set ("long", @LONG
這裡是瀧山武館內的走道,走道上的燈將走道照得十分明亮
往北的話是通往瀧山派的內院而南邊是瀧山派的禁地及瀧山
派的大廳。
LONG);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"luroom25",
  "south" : __DIR__"luroom20",
]));
  set("light_up", 1);
  setup();
}
