//written by acelan...../u/a/acelan/ghost/room/ghost25.c

inherit ROOM;

void create()
{
        set("short", "亂葬崗");
        set("long", @LONG
這裡是殺手墓園最混亂的一角, 四周墓塚一堆一堆的雜亂無章,
甚至還有任隨骨骸暴露在外的, 陣陣陰風再加上不時出現在身旁的鬼
火, 沒有人會認為這裡是可以久留之地。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "south" : __DIR__"ghost18.c",
       "east"  : __DIR__"ghost26.c",
   ]));
set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/ghost/npc/black4.c" : 1,
  "/open/killer/mon/ghost/npc/black5.c" : 1,
]));
   setup();
}
