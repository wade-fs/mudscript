//written by acelan...../u/a/acelan/ghost/room/ghost7.c

inherit ROOM;

void create()
{
        set("short", "墓園小徑");
        set("long", @LONG
這是一條在墓園中的小徑, 四通八達, 可以通往各個墳墓, 小徑
向北不斷地延伸, 西邊有一間土地公廟, 而東邊有一座好大的墳墓,
不知道是什麼人埋在裡面。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost13.c",
       "south" : __DIR__"ghost4.c",
       "east"  : __DIR__"ghost8.c",
       "west"  : __DIR__"ghost6.c",
   ]));
   set("no_clean_up", 0);

   setup();
}
