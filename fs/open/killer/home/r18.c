inherit ROOM;
void create()
{
  set ("short", "走廊");
  set ("long", @LONG
由於殺手們長年追殺他人，導致仇家不少，總壇自然成了最佳的避風港。
為了方便長期躲藏，屬於殺手的休息處與吃飯的地方可少不了。
東方是殺手們吃飯的大餐廳與宿舍。沒事不要大聲喧嘩哦。
LONG);
   set("exits", ([
   "east"   : __DIR__"foodrm.c",
   "west"   : __DIR__"floorm.c",
   "north"  : __DIR__"shoprm.c",
  ]));
   set("no_fight", 1);
  set("no_magic", 1);
  set("no_transmit", 2);
  set("light_up", 1);
  setup();
} 
