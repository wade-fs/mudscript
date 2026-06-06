// Room: /open/wu/room/luroom20.c
// 瀧山武館的內道
inherit ROOM;
void create ()
{
  set ("short", "內道");
  set ("long", @LONG
這裡是瀧山武館內的走道,往西直行的話是通往瀧山派的大廳,
南邊則通往瀧山派的禁地,而向北則是通往瀧山派的內院。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"luroom19.c",
  "south" : __DIR__"luroom23",
  "north" : __DIR__"luroom24.c",
]));
  set("light_up", 1);

  setup();
}
