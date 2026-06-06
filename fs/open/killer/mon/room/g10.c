//written by wataru...../open/killer/mon/room/g10.c
inherit ROOM;

void create()
{
        set("short", "綠雲組組長室門口");
        set("long", @LONG
	在你眼前的是一道看似門，但又不是門的一道屏障，

	此屏障雕功精細，精細到讓你會懷疑這是人刻的嗎？

	看來，周八伯應該就在這一道屏障的後面，

	不知道，他現在是否在組上，而沒有出任務去呢？
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "eastnorth" : __DIR__"g4.c",
       "westnorth" : __DIR__"g9.c",
       "enter" : __DIR__"g11.c",
   ]));
   set("objects", ([ /* sizeof() == 1 */
       "/open/killer/mon/npc/grnnpc4.c":2,
       "/open/killer/mon/npc/spy5.c":1,
   ]));

        set("no_clean_up", 0);

        setup();
        }
