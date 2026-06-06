// Room: /open/poison/room/road6
inherit ROOM;

void create ()
{
  set ("short", "園中小徑");
  set ("long", @LONG
你走在一個小徑上，兩旁盡是翠綠的竹林，竹葉隨風起
舞，發出沙沙的聲響，東南方有一小小的山洞。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"path11.c",
  0 : __DIR__"path2",
  "northwest" : __DIR__"road17",
]));
  set("outdoors", "/open/poison");

  setup();
}
