//written by acelan...../u/a/acelan/room/wood16.c

inherit ROOM;

void create()
{
        set("short", "地道的入口");
        set("long", @LONG
一走進地道, 一股寒風使你打了個寒顫, 兩旁的火把照的你的影
子搖晃不定, 看來這裡並不是毫無人跡, 說不定會有未知的危險, 你
需要小心的前進。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : "/open/killer/mon/room/wood23.c",
       "up" : "/open/killer/mon/room/wood12.c",
   ]));
   set("objects", ([ /* sizeof() == 1 */
       "/open/killer/mon/npc/grnnpc2.c":2,
   ]));
   set("no_clean_up", 0);

   setup();
}
