
inherit ROOM;
void create()
{
  set ("short", "戰備池");
  set ("long","
    這裡的水好像特別乾淨﹐不像之前的水那麼髒﹐在天
花板上還開有一個通氣孔來排出水氣﹐而這裡的水好像都
自山上﹐水的味道有一種特別的味道﹐該不會是珍的偷接
山上的水來用。

 ");
   set("exits", ([
   "east"   : __DIR__"r30.c",
      
  ]));      
  set("light_up", 1);
  setup();
} 

