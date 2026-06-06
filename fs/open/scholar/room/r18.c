// /u/j/judd/room/r18.c
inherit ROOM;

void create ()
{
  set ("short", "中堂東側");
  set ("long", @LONG
你現在在風與土的圖書館的中間，往北就是風室圖書館，往南就
是土室圖書館，而地板的顏色也從中間對分，北邊是代表風的白色，
南邊是代表土的黃色，也不知道是用什麼東西染的色，看起來相當的
怪異。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"e3.c",
  "south" : __DIR__"r21.c",
  "north" : __DIR__"r15.c",
]));
  set("light_up", 1);

  setup();
}
