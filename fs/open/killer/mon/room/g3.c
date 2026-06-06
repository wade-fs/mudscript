//written by wataru...../open/killer/mon/room/g3.c
inherit ROOM;

void create()
{
        set("short", "綠雲組內部");
        set("long", @LONG

	前方是一條由許多枝葉所構成的天然通道，

	要不是你仔細看，你還無法發現這一條通道的存在。

	令你不禁讚嘆，此處真的有如鬼斧神工一般.......
	
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"g2.c",
       "south" : __DIR__"g4.c",
   ]));
        setup();
}
