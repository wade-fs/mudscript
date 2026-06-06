#include <room.h>
inherit ROOM;
void create ()
{
   set ("short","水底");
   set ("long", @LONG
這是地下水道的底部,三方都是黑暗無光
只有上面有微弱的光線(light)照射下來
 

你手上抱著一顆大石頭(stone)。
LONG);
set("item_desc",([
  "light" : "你盡力地想看清楚光線是從那兒照射下來,但是太暗了,看不清楚,要過去的話,請(pass) 。\n",
  "stone" : "就是這一顆石頭救了你的命,要放開請(swim)。\n",]));
  set("no_fight",1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_transmit", 2);
  setup();
}
void init()
{
   add_action("do_swim",({"swim"}) );
   add_action("do_pass",({"pass"}) );
}
int do_swim(string arg)
{
   object me;
   if (!arg || arg=="" )  {
   me = this_player();
  tell_object(me,"只聽你ㄚ～～ㄚ～～的叫聲聲響起,你的手放開了大石,再一次地被
水流帶走 。\n");
  tell_object(me,"最後你終於被水流給拋出地面 。\n");
  me->move("/open/ping/room/road8");
 return 1;
 }
return 1;
}
int do_pass(string arg)
{
  object who;
  who=this_player();
  if((arg="light") || (arg=="light")) {
  tell_object(who,"你吃力的往光線處游去,爬過小洞,來到了不知名的地方。\n");
  who->move(__DIR__"rb.c");
  return 1;
  }
   return 0;
}
