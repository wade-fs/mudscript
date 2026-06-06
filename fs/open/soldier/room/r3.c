
inherit ROOM;
void create()
{
  set ("short", "走道");
  set ("long","
    你站在這裡依稀還可以見到一點點陽光﹐此地往左好
像有間奇怪的房間﹐往右燈火通明好像很熱鬧的樣子﹐在
你面前有刻著一些字。

             <----XXX    飯廳---->

 ");
   set("exits", ([
   "east"   : __DIR__"r2.c",
   "west"    : __DIR__"r4.c",
  "south"    : __DIR__"r5.c",
  ]));      
  set("light_up", 1);
  setup();
} 
