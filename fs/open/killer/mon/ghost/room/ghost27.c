//written by acelan...../u/a/acelan/ghost/room/ghost27.c

inherit ROOM;

void create()
{
        set("short", "墓園小徑");
        set("long", @LONG
這是一條在墓園中的小徑, 四通八達, 可以通往各個墳墓, 小徑
向北延伸只到這裡為止, 往西是屍骨散落滿地的亂葬崗, 東邊則是一
若有若無的小徑, 看起來挺詭異的。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "south" : __DIR__"ghost20.c",
       "east"  : __DIR__"ghost28.c",
       "west"  : __DIR__"ghost26.c",
   ]));
   set("no_clean_up", 0);

   setup();
}
