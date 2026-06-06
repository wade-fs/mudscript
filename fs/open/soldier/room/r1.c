
inherit ROOM;
void create()
{
  set ("short", "倉庫");
  set ("long","
    這裡是反亂軍中最最最重要的地方﹐這是反亂軍所有
囤積糧食的地方﹐你看到旁邊的米堆裡發現有一些米蟲在
裡面爬呀爬的﹐上面還躺著一個壯漢。

 ");
   set("exits", ([
   "south"   : __DIR__"r2.c",     
  ]));      
  set("objects", ([ /* sizeof() == 1 */
    "/open/soldier/npc/rice":1,
]));
  set("light_up", 1);
  setup();
} 
