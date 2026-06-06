
inherit ROOM;
void create()
{
  set ("short", "走道");
  set ("long","
    這裡有一些守衛像流浪漢般的在這巡邏神怕被別人侵
佔的樣子北邊似乎可以通道別的地方﹐這裡四面充滿了泥
土的味道聞起來有點讓人反胃﹐在南方好像很熱鬧的樣子

 ");
   set("exits", ([
   "south"   : __DIR__"r26.c",
   "north"   : __DIR__"r19.c",
   
  ]));      
  set("objects", ([ /* sizeof() == 1 */
    "/open/soldier/npc/ma1":1,
]));
  set("light_up", 1);
  setup();
} 
