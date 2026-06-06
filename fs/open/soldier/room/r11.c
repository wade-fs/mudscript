
inherit ROOM;
void create()
{
  set ("short", "哨站");
  set ("long","
    這一個哨站幾乎是反亂軍中最重要的﹐因為這裡是所
有人必經之路﹐這裡的哨兵當然不是省油的燈﹐四個方向
都可以走﹐自己挑一條吧。

 ");
   set("exits", ([
   "southeast"   : __DIR__"r13.c",
   "southwest"   : __DIR__"r14.c",
   "northwest"   : __DIR__"r6.c",
   "northeast"   : __DIR__"r5.c",
  ]));      
  set("objects", ([ /* sizeof() == 2 */
    "/open/soldier/npc/sentry1":2,
]));
  set("light_up", 1);
  setup();
} 
