// Room: /open/gsword/room/su-
inherit ROOM;

void create()
{
  set ("short", "雜草路");
  set ("long", @LONG
由此往北就是蜀中密林了,往南則通往蜀中城,東西兩側皆是
峭壁夾道,高聳而不可攀爬,北方森林極密,聽說盛產藥材,然而猛
獸邪怪,亦非少數,你可要小心才是.
LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 1 */
  "north" : "open/main/room/F5",
  "south" : __DIR__"froad0",
]));
  setup();
}
