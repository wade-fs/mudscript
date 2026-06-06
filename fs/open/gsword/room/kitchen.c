// Room: /open/gsword/room/kitchen.c
inherit ROOM;

void create ()
{
  set ("short", "伙房");
  set ("long", @LONG
這是平時廚子們做菜的地方，在右邊的一角放著小山一般高的蔬菜，
左前方用來炒菜的鐵鍋尤為嚇人，算了算半徑，直有五尺之多，想必
這廚子的也有幾分內功底子。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/gsword/room/eghouse1.c",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/disciple.c" : 1,
]));

  set("light_up", 1);

  setup();
}
