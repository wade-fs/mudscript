#include <room.h>

inherit ROOM;

void create()
{
           set("short","密室");
         set("long",@LONG
這裡到底是哪裡呢？黑暗的讓人難以看清四周，不禁起了一陣雞皮疙瘩。
不過，隱隱約約之中似乎看到有人在那裡。不知道是不是自己眼花了？
來時的密道已經封閉，四周似乎沒有出路，但往上似乎還有通道耶。。。。。
一旁的碑石刻著：
      「再回首,已是百年身」
 
LONG);
        set("exits", ([
          "up":__DIR__"rbd",
        ]) );
        set("objects",([
          "/open/killer/npc/doctor.c":1,]));
        setup();
}

void init()
{
      add_action("do_look","look");
      add_action("do_write","write");
}
int do_look(string str)
{
      if(str!="碑石") return 0;
      tell_object(this_player(),"碑石上還有一行空行(table)。\n");
       return 1;
}
int do_write(string str)
{
  object me;

  me=this_player();
  if( str != "一失足,成千古恨 on table" )   return 0;
  tell_object(me,"你用匕首在空行刻下『一失足,成千古恨。』\n");
  tell_object(this_player(),"突然出現了陷阱，你掉入陷阱中。。\n");
  me->move(__DIR__"boxrm.c");
  return 1;
}
