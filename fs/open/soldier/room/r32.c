
inherit ROOM;
void create()
{
  set ("short", "偏聽");
  set ("long","
    這理事接待客人的地方﹐提供長期跋涉而來的武俠豪
傑﹐這裡通風良好﹐在旁邊種滿了盆栽﹐不時有花草之味
遍佈整個房間﹐讓房間不會有異味。

 ");
   set("exits", ([
   "east"   : __DIR__"r20.c",     
  ]));      
  set("light_up", 1);
  setup();
} 

