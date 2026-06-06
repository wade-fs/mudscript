//written by acelan...../u/a/acelan/ghost/room/ghost21.c

inherit ROOM;

void create()
{
        set("short", "墓園");
        set("long", @LONG
這裡的墓碑東倒西歪, 想必在這裡已經有相當的歲月了, 以至連
個能來整理雜草的親人都沒有。雖說是雜草叢生, 可是四周卻盛開著
一些不知名的小花, 青白紅相間, 蔚為奇觀。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost28.c",
       "south" : __DIR__"ghost14.c",
       "west"  : __DIR__"ghost20.c",
   ]));
   set("no_clean_up", 0);

   setup();
}
