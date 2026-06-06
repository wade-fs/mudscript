#include <room.h>

inherit ROOM;

void create()
{
           set("short","通吃小築二樓前庭");
         set("long",@LONG
	在你面前的是一面巨大的石門，一旁有各看似機關的東西。
	在機關上面寫的是，莊靜柔因為天魔解體大法練不成，改練成招式是？
	在另外一邊有四個(空格)，看來你要刻在上面了
 
LONG);
        set("exits", ([
          "down":__DIR__"hr7.c",
        ]) );
        set("objects",([
          "/open/killer/npc/magnpc2.c":2,]));
        setup();
}

void init()
{
      add_action("do_look","look");
	add_action("do_write","cut");
}

int do_look(string str)
{
      if(str!="空格") 
	return 0;
      tell_object(this_player(),"碑石上還有一行空行(table)。\n");
      tell_object(this_player(),"（請使用指令格式 cut XXXX on table) \n");
       return 1;
}

int do_write(string str)
{
  object me;

  me=this_player();
if (str !="陰性氣指 on table")
	return 0;
  tell_object(me,"你用匕首在空格刻下『陰性氣指』\n");
  tell_object(this_player(),"在你眼前的石門打開了.........\n");
  me->move(__DIR__"hru1.c");
  return 1;
}
