//written by acelan...../u/a/acelan/ghost/room/ghost19.c

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
       "north" : __DIR__"ghost26.c",
       "south" : __DIR__"ghost12.c",
       "east"  : __DIR__"ghost20.c",
       "west"  : __DIR__"ghost18.c",
   ]));
   set("no_clean_up", 0);

   setup();
}
