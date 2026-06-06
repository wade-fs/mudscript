//written by acelan...../u/a/acelan/room/wood27.c

inherit ROOM;

void create()
{
        set("short", "樹林上的密道");
        set("long", @LONG
有一股巨大的風, 突然刮起又倏然消失, 天色瞬間暗了下來又立
即回復光亮, 似乎在短短的幾秒鐘內過了一天一夜, 你抬起頭來往上
看, 看到遠方有一隻大鵬正以駭人的速度, 朝南方飛去。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "east" : "/open/killer/mon/room/wood28.c",
       "south" : "/open/killer/mon/room/wood21.c",
   ]));
   set("objects", ([ /* sizeof() == 1 */
       "/open/killer/mon/npc/grnnpc2.c":1,
   ]));

   set("no_clean_up", 0);

   setup();
}
