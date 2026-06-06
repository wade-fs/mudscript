//written by wataru...../open/killer/mon/room/g11.c
inherit ROOM;

void create()
{
        set("short", "綠雲組組長室");
        set("long", @LONG
	此處並沒有任何特別奢華之處，甚至讓你感到是否來到道觀之中？
	
	相傳周八伯精通靈異知識，甚至具有通靈之力。

	這項特異功能，讓葉秀沙放心的將後山這廣大的區域交給他管理。

	因為，就算是在細微之處，他也可以算命數得知。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "out" : __DIR__"g10.c",
   ]));
   set("objects", ([ /* sizeof() == 1 */
       "/open/killer/mon/npc/hu_fa5.c":1,
   ]));
        setup();
}
