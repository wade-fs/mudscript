//written by acelan...../u/a/acelan/ghost/room/ghost1.c

inherit ROOM;

void create()
{
        set("short", "墓園入口");
        set("long", @LONG
這裡是殺手墓園的入口, 看起來怪恐怖的, 眼前聳立著一做石碑
, 大約有兩丈高, 上面刻著七個字－殺手第十三公墓。不知道裡面都
埋些什麼東西。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost4.c",
       "east" : "/open/killer/mon/room/wood22.c",
   ]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/ghost/npc/black5.c" : 2,
]));
   setup();
}
