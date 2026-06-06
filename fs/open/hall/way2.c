// Room: /open/hall/way2.c

inherit ROOM;

void create()
{
        set("short", "廳旁走道");
        set("long", @LONG
這兒是一條鋪了石子的走道，走道兩旁各有一個花圃，裡頭雜草叢
生，似乎很久沒人整理囉......
LONG);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"way3",
  "east" : __DIR__"hall.c",
]));

        setup();
}
