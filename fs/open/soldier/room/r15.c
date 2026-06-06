
inherit ROOM;
void create()
{
  set ("short", "體檢處");
  set ("long","
    來這邊報到的人一定都要通過體能測驗﹐才能入伍
當然了..這裡的體能教練一定是很能幹的﹐在地上有一
個啞鈴(dumbbell)你可以拿起來看看。

 ");
   set("exits", ([
   "west"       : __DIR__"r16.c",
      
  ]));      
  set("objects", ([ /* sizeof() == 1 */
    "/open/soldier/npc/john":1,
]));
  set("light_up", 1);
  setup();
} 

