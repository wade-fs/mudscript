

inherit ROOM;
void create()
{
  set ("short", "格鬥場");
  set ("long","
    這邊擠滿了一些練武份子﹐這裡場地之大﹐可見這個
組織非常龐大而且嚴格﹐在這裡練武的人個個揮汗如雨﹐
都充滿了鬥氣﹐看來動不起的樣子。

 ");
   set("exits", ([
   "east"       : __DIR__"r15.c",
   "north"      : __DIR__"r12.c",
   
  ]));      
  set("objects", ([ /* sizeof() == 2 */
    "/open/soldier/npc/son":1,
]));
  set("light_up", 1);
  setup();
} 

