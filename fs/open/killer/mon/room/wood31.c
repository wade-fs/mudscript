//written by wataru...../open/killer/mon/room/wood31.c
inherit ROOM;

void create()
{
        set("short", "長繩");
        set("long", @LONG
	爬上了繩子之後，你發現這一棵樹實在太高了.......
	想不到你爬了數十尺，居然還是沒有看到綠雲組所在處。
	無奈，只好盡力的往上爬.........

LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "up" : "/open/killer/mon/room/g1.c",
        "down" : "/open/killer/mon/room/wood20.c",
   ]));
        set("no_clean_up", 0);

        setup();
        }
