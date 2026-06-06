//written by wataru...../open/killer/mon/room/g4.c
inherit ROOM;

void create()
{
        set("short", "綠雲組內部");
        set("long", @LONG

	北方是一條鬼斧神工般的天然通道，

	西方，似乎有一條通道在那，但又看不真切

	西南方看起來還蠻寬敞的，似乎蠻特別的

	不知道，綠雲組的組長周八伯是不是在哪裡呀....

	看來似乎，值得往那裡一探.............
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"g3.c",
       "west" : __DIR__"g6.c",
       "westsouth" : __DIR__"g10.c",
   ]));
   set("objects", ([ /* sizeof() == 1 */
       "/open/killer/mon/npc/grnnpc4.c":1,
       "/open/killer/mon/npc/spy5.c":1,
   ]));

        setup();
}
