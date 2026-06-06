//written by acelan...../u/a/acelan/ghost/room/ghost6.c

inherit ROOM;

void create()
{
        set("short", "土地公廟");
        set("long", @LONG
在殺手墓園裡, 竟然還有這種東西, 可見殺手人殺多了, 心裡還
是會不安的, 有土地公在這裡鎮鎮鬼氣, 大家膽子也大些, 只是不知
土地公真的能鎮的住這些冤魂厲鬼嗎。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost12.c",
       "south" : __DIR__"ghost3.c",
       "east"  : __DIR__"ghost7.c",
       "west"  : __DIR__"ghost5.c",
   ]));
set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/ghost/npc/god.c" : 1,
  "/open/killer/mon/ghost/npc/black5.c" : 2,
]));


   setup();
}
