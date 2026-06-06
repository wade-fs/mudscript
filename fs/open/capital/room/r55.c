// Room: /open/capital/room/r55.c

inherit ROOM;

void create ()
{
  set ("short", "雲洋大街");
  set ("long", @LONG
你來到了鎮遠侯府門口，一扇由天山雪木製成的大門及兩旁栩栩如
生石獅，顯示了鎮遠侯不凡的氣勢與剛正的性格。
    北邊門上的匾額有皇帝親題的四個字：$HIY$鎮遠侯府$NOR$

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/capital/room/general",
  "west" : "/open/capital/room/r54",
  "east" : "/open/capital/room/r56",
]));

  set("outdoors", "/open/capital");

  setup();
}
