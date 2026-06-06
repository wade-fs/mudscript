// Room: /open/poison/room/road19
inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG
這裡四處片荒蕪，到處長滿了野草，看來是一個罕有人
跡的地方。西邊有一大片的密林，樹林林立，看不出有任何
方法可以進入這片森林。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road7",
]));
  set("outdoors", "/open/poison");

  setup();
}
