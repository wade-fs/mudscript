inherit ROOM;
void create()
{
  set ("short", "走廊");
  set ("long", @LONG
由於殺手們長年追殺他人，導致仇家不少，總壇自然成了最佳的避風港。
為了方便長期躲藏，特地派專人運補糧草，北方就是殺手的專賣室。
西邊是殺手專用的煉丹房，據說殺手密藥就是在哪裡調製的。
LONG);
   set("exits", ([
   "east"   : __DIR__"floorm.c",
   "west"   : __DIR__"pillrm.c",
   "north"  : __DIR__"sellrm.c",
  ]));
   set("no_fight", 1);
  set("no_magic", 1);
  set("no_transmit", 2);
  set("light_up", 1);
  setup();
} 
