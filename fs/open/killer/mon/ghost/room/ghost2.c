//written by acelan...../u/a/acelan/ghost/room/ghost2.c

inherit ROOM;

void create()
{
        set("short", "墓園");
        set("long", @LONG
這裡是十三公墓的一角, 由於地處偏遠, 再加上風水並不是很理
想, 所以這裡並沒有埋有墳墓。四周野草及腰, 且兼光線昏暗, 連落
腳處都看不清, 所以還是不要久留的好。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost5.c",
       "east"  : __DIR__"ghost3.c",
   ]));
set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/ghost/npc/black4.c" : 1,
  "/open/killer/mon/ghost/npc/black5.c" : 1,
]));
   setup();
}
