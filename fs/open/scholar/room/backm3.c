// Room: /open/scholar/room/backm1.c
inherit ROOM;

void create ()
{
  set ("short", "後山");
  set ("long", @LONG
從這裡再往前走，就會到達後山了，不過我想沒有經過同意，
應該也沒有人敢隨便進去吧。
LONG);

  set("outdoors", "/open/scholar");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"backm2",
  "north" : __DIR__"backm4",
]));

  setup();
}
