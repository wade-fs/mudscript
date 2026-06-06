
inherit ROOM;
void create()
{
  set ("short", "哨站");
  set ("long","
    這裡是一處攔檢處﹐未經過身分確認是沒辦法過去的
你從這邊望哨站後面望過去好像有很多人﹐在北邊可以通
到別的地方﹐你可以過去逛逛。

 ");
   set("exits", ([
   "east"       : __DIR__"r8.c",
   "northwest"  : __DIR__"r5.c",
   "west"       : __DIR__"r10.c",
  ]));      
  set("objects", ([ /* sizeof() == 2 */
    "/open/soldier/npc/sentry":2,
]));
  set("light_up", 1);
  setup();
} 
