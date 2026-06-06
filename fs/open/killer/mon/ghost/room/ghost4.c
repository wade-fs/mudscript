//written by acelan...../u/a/acelan/ghost/room/ghost4.c

inherit ROOM;

void create()
{
        set("short", "墓園小徑");
        set("long", @LONG
這是一條在墓園中的小徑, 四通八達, 可以通往各個墳墓, 小徑
向北不斷地延伸, 西邊則是一大片的土饅頭, 而東邊看起來則像是尚
未整好的墓地, 想來應該是沒有人埋在裡面吧。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost7.c",
       "south" : __DIR__"ghost1.c",
       "west"  : __DIR__"ghost3.c",
   ]));
   set("no_clean_up", 0);

   setup();
}
