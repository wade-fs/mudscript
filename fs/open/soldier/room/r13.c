
inherit ROOM;
void create()
{
  set ("short", "工地");
  set ("long","
    這裡插著一塊板子:

                 ┌───┐
                 │施工中│  請繞路....
                 └───┘

 ");
   set("exits", ([
   "northwest"   : __DIR__"r11.c",     
  ]));      
  set("light_up", 1);
  setup();
} 

