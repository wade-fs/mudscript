// Room: /u/s/sueplan/newplan/area/f1.c
inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG
春雨霏霏連日不絕，潮潤得四處泥濘難行，農家們把舊年的稻草，
就著破瓦碎石，平整紮實地鋪出一條路來；路旁不知名的小花兀自綻著
蓓蕾，更有初植下的秧苗，吃足了雨水瑩著綠油油的粉翠，襯著遠處農
舍的炊煙裊裊，正是春天好風光。
LONG);

  set("outdoors", "/u/s");
  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/marksman/room/room2-5.c",
  "south" : __DIR__"f2.c",
]));

  setup();
}
