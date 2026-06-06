// Room: /open/start/room/eqroom
inherit ROOM;

void create()
{
  set ("short", "儒門儲藏室");
  set ("long", @LONG
這裡是專讓儒門子弟堆一些東西的房間。
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"small_house",
]));
  set("no_clean_up", 1);
  setup();
}
