//written by acelan...../u/a/acelan/ghost/room/ghost8.c

inherit ROOM;

void create()
{
        set("short", "墓園小徑");
        set("long", @LONG
這是一條在墓園中的小徑, 四通八達, 可以通往各個墳墓, 在小
徑東方的盡頭, 有一座好大的墳墓, 看來這條小徑就是專為那個墳墓
所闢的, 而北邊則是一堆小墳墓。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost14.c",
       "east"  : __DIR__"ghost9.c",
       "west"  : __DIR__"ghost7.c",
   ]));
   set("no_clean_up", 0);

   setup();
}
