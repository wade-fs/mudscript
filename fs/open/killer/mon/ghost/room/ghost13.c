//written by acelan...../u/a/acelan/ghost/room/ghost13.c

inherit ROOM;

void create()
{
        set("short", "墓園小徑");
        set("long", @LONG
這是一條在墓園中的小徑, 四通八達, 可以通往各個墳墓, 小徑
向北不斷地延伸, 西邊是一座大墳墓, 看起來似乎是新冢, 而東邊則
是一堆小墳墓, 看起來雜亂無章的。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost20.c",
       "south" : __DIR__"ghost7.c",
       "east"  : __DIR__"ghost14.c",
       "west"  : __DIR__"ghost12.c",
   ]));
   set("no_clean_up", 0);

   setup();
}
