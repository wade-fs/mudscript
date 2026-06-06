// /u/j/judd/room/r23.c
inherit ROOM;

void create ()
{
set("short", "水之通道");
set("long", @LONG
映入眼中的，是一個大水池，而路在水池的另一頭，看起來似乎
沒有路可以過去，突然一個閃光吸引了你，仔細的檢查，發現在水池
的中間有一條由冰作出的小路，看起來好像還滿堅固的，只是不知道
會不會在水池的一半斷裂．
LONG
);
set("light_up", 1);
set("exits", ([ /* sizeof() == 2 */
 "southwest" : __DIR__"water.c",
 "northeast" : __DIR__"r19.c",
]));
setup();
}
