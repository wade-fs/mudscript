//written by wataru...../open/killer/mon/room/g1.c
inherit ROOM;

void create()
{
        set("short", "綠雲組入口");
        set("long", @LONG
	爬上了繩子之後，你終於來到傳說中，鎮守後山的綠雲組所在地。
	難怪綠雲組不易為一般人所發現，因為這裡幾乎沒有突兀建築物。
	有的只是利用天然的植物，所建設出來的居住地與日常器材。
	四周傳來陣陣的清香，這是來自自然的味道，令人神清氣爽。

LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "east" : __DIR__"g2.c",
       "west" : __DIR__"g7.c",
       "down" : __DIR__"wood31.c",
   ]));
   set("objects", ([ /* sizeof() == 1 */
       "/open/killer/mon/npc/grnnpc4.c":2,
       "/open/killer/mon/npc/spy5.c":1,
   ]));

        set("no_clean_up", 0);

        setup();
        }
