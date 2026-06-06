//written by acelan...../u/a/acelan/ghost/room/ghost28.c

inherit ROOM;

void create()
{
        set("short", "墓園小徑");
        set("long", @LONG
這是一條在墓園中的小徑, 不過這條卻出奇的隱密, 正當你以為
小徑到此為止時, 你忽然覺得東方隱約有著些什麼東西, 這一望才發
現, 小徑若有若無的正朝著東方延伸。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "south" : __DIR__"ghost21.c",
       "east"  : __DIR__"ghost29.c",
       "west"  : __DIR__"ghost27.c",
   ]));
set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/ghost/npc/black3.c" : 1,
  "/open/killer/mon/ghost/npc/black4.c" : 1,
]));
   setup();
}
