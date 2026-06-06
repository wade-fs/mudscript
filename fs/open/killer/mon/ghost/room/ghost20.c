//written by acelan...../u/a/acelan/ghost/room/ghost20.c

inherit ROOM;

void create()
{
        set("short", "墓園小徑");
        set("long", @LONG
這是一條在墓園中的小徑, 四通八達, 可以通往各個墳墓, 小徑
向北不斷地延伸, 西邊屍骨散落滿地, 看起來應該是亂葬崗, 東邊則
是一堆小墳墓, 看起來雜亂無章的。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost27.c",
       "south" : __DIR__"ghost13.c",
       "east"  : __DIR__"ghost21.c",
       "west"  : __DIR__"ghost19.c",
   ]));
set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/ghost/npc/black4.c" : 1,
  "/open/killer/mon/ghost/npc/black4.c" : 1,
]));
   setup();
}
