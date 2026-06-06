// Room: /u/g/guetenr/beggar/room/beg1/room17.c
inherit ROOM;

void create ()
{
  set ("short", "小泥徑");
  set ("long", @LONG
春雨霏霏連日不絕，潮潤得四處泥濘難行，農家們把舊年的稻草，就著
破瓦碎石，平整紮實地鋪出一條路來；路旁不知名的小花兀自綻著蓓蕾，更
有初植下的秧苗，吃足了雨水瑩著綠油油的粉翠，襯著遠處農舍的炊煙裊裊
，正是好春光。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room16.c",
  "south" : __DIR__"room18.c",
]));
  set("outdoors", "/open/");

  setup();
}
