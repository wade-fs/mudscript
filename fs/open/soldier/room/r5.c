
inherit ROOM;
void create()
{
  set ("short", "走道");
  set ("long","
    這裡往西南好像有些人在那裡巡邏往東南也是一樣﹐
北邊似乎可以通道別的地方﹐這裡四面充滿了泥土的味道
聞起來有點讓人反胃。

 ");
   set("exits", ([
   "southeast"   : __DIR__"r9.c",
   "southwest"   : __DIR__"r11.c",
   "north"       : __DIR__"r3.c",
   
  ]));      
  set("light_up", 1);
  setup();
} 
