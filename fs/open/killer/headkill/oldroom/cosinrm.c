#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
   set ("short","神秘房間");
   set ("long", @LONG
	這裡到底是哪裡？想不到透過你認為熟的不能在熟的水底密道？
	你居然來到了一個前所未見的地方？四處並無明顯的出口！
	這下該如何是好？不過在你眼前的居然有一位神秘人在靜坐著，
	此人會是誰呢？看來你大概該問看看該名神秘人（你是誰）了？

LONG);
  set("no_fight",1);
  set("no_magic", 1);
  set("no_transmit",1);
  set("objects",([
	"/daemon/class/killer/yaco.c":1,
        "/open/main/obj/torch" : 1,
        ]));
  setup();
}

void init()
{
   add_action("do_pass",({"pass"}) );
}


int do_pass(string arg)
{
  object who;
  who=this_player();
  if(arg == "way")
  {
	tell_object(who,HIY + "你吃力的往光線處游去,爬過小洞,來到了不知名的地方。\n" + NOR);
	who->move("/open/killer/room/firstrm.c");
	 return 1;
  }
   return 0;
}
