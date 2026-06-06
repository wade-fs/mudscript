

inherit ROOM;
void create()
{
  set ("short", "報到處");
  set ("long","
    這裡是反亂軍們報到的地方﹐這裡集結了一些外國
豪傑﹐個個都示威武雄壯﹐在前方有一方桌站著一排人
好像都來報到練武的。

 ");
   set("exits", ([
   "west"       : __DIR__"r8.c",
      
  ]));      
  set("objects", ([ /* sizeof() == 1 */
    "/open/soldier/npc/alo":1,
]));
  set("light_up", 1);
  setup();
} 

