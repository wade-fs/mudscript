// /u/j/judd/room/r10.c
inherit ROOM;

void create ()
{
set("short", "風之通道");
set("long", @LONG
這裡的風，不知道為何，強得不得了，可說是寸步難行，經過你
不停的嘗試，終於發現只有正中間的部分是沒有風的，也就是說，有
一條無風的小路可以繼續前進，真不知道到底是怎麼設計出這麼巧妙
的機關的，走過小路，風室圖書館就到了．
LONG
);
set("light_up", 1);
set("exits", ([ /* sizeof() == 2 */
 "southwest" : __DIR__"r15.c",
 "northeast" : __DIR__"wind.c",
]));
setup();
}
