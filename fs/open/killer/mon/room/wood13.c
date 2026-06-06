//written by acelan...../u/a/acelan/room/wood13.c

inherit ROOM;

void create()
{
        set("short", "後山的森林");
        set("long", @LONG
來到這裡, 已經到了森林的邊緣, 無法在前進了, 你可以清楚的
看到地下有一個地道入口, 但卻無法開啟, 在一番努力之後, 你決定
放棄, 另尋出路。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "south" : "/open/killer/mon/room/wood7.c",
   ]));
   set("objects", ([ /* sizeof() == 1 */
       "/open/killer/mon/npc/grnnpc3.c":2,
   ]));
   set("no_clean_up", 0);

   setup();
}
