// /u/j/judd/room/r10.c
inherit ROOM;

void create ()
{
set("short", "火之通道");
set("long", @LONG
這條往火室圖書館的道路，相當的嚇人，兩旁竟然都是火燄，只
有中間有一條紅色的小徑通往圖書館，膽子不大的人很可能在此就打
退堂鼓了，其實，只要小心的走，是不會受傷的，火室圖書館，就在
前方．
LONG
);
set("light_up", 1);
set("exits", ([ /* sizeof() == 2 */
 "southeast" : __DIR__"r13.c",
 "northwest" : __DIR__"fire.c",
]));
setup();
}
