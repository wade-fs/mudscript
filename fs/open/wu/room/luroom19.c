// Room: /open/wu/room/luroom19.c
// 瀧山武館內道
inherit ROOM;
void create ()
{
  set ("short", "走道");
  set ("long", @LONG
這裡是瀧山武館內的走道,往東的話是通往瀧山派的禁地及內院,
而南邊是瀧山派的祠堂,往西走的話則是回到瀧山派的大廳。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"luroom22",
  "west" : __DIR__"luroom18",
  "east" : __DIR__"luroom20",
]));
  set("light_up", 1);

  setup();
}
