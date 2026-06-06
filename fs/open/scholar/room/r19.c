// /u/j/judd/room/r19.c
inherit ROOM;

void create ()
{
  set ("short", "中堂西側");
  set ("long", @LONG
有一條藍色的道路延伸往西南方，想必就是通往儒門的四大圖書
館之一，水室圖書館，光從名稱，是不會知道水室圖書館是放些什麼
書的，只有親自去看過，才能知道儒門四大圖書館到底是放些什麼，
東邊則通往出口方向。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r16.c",
  "southwest" : __DIR__"r23.c",
]));
  set("light_up", 1);

  setup();
}
