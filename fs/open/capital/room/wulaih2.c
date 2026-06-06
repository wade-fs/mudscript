// Room: /open/capital/room/wulaih2
inherit ROOM;

void create ()
{
  set ("short", "無賴窩");
  set ("long", @LONG
四週一片漆黑。有股噁心的臭味，還是別待太久得好。地板下傳來
些許細微的響聲，看了看地板，似乎有暗門。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wulaih",
  "down" : __DIR__"j1",
]));
  create_door("down","暗門","up");

  setup();
}
