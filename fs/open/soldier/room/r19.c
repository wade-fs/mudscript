
inherit ROOM;
void create()
{
  set ("short", "交叉口");
  set ("long","
    在這裡往難看過去燈火通明似乎很熱鬧﹐在你右邊有
間大廳﹐這一路走來總覺的神神祕密的﹐機關一大堆眼看
大廳就在旁邊而已﹐不過又看到另一邊燈火通明想過去湊
熱鬧﹐趕快決定吧～

 ");
   set("exits", ([
   "jump"       : __DIR__"r14.c",
   "east"       : __DIR__"r18.c",
   "south"      : __DIR__"r21.c",
  ]));      
  set("light_up", 1);
  setup();
} 

