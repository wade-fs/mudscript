inherit ROOM;

void create()
{
  set ("short", "南町臨港路");
  set ("long", @LONG
路面逐漸縮小而不平，喧嘩之聲也逐漸遠去。兩旁住家的房屋也
逐漸矮小起來。路上的人群奚奚落落，與大街上似有天壤之別。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"j23.c",
    "east" : __DIR__"j19.c",
  ]));
  setup();
}
