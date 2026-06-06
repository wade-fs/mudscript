// /u/j/judd/room/r25.c
inherit ROOM;

void create ()
{
set("short", "土之通道");
set("long", @LONG
看到前面的路，你不禁倒吸一口氣，只見兩旁都是看不到底的空
洞，想要通過這裡，只有小心翼翼的沿著那彎彎曲曲的小路前進，往
底下看，黑壓壓的一片，讓你覺得有點頭暈，最好趕快通過，掉下去
大概就完蛋了．
LONG
);
set("light_up", 1);
set("exits", ([ /* sizeof() == 2 */
 "southeast" : __DIR__"land.c",
 "northwest" : __DIR__"r21.c",
]));
setup();
}
