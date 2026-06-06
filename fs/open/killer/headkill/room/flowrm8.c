#include <room.h>
inherit ROOM;
void create ()
{
   set ("short","迷陣花居");
   set ("long", @LONG
	度過一次又一次的相同景色後，終於來到有點不一樣的地方了。
	這裡是一個簡陋但蠻漂亮的一間小木屋中，
	裡面坐著一位老人，正面無表情的看著你。
	難道這一位就是藍鳳組的聯絡人嗎？

LONG);
  set("no_fight",1);
  set("no_magic", 1);
  set("no_transmit",1);
  set("objects",([
	"/open/killer/headkill/npc/comit.c":1,
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
	tell_object(who,"你走向他所說的方向，以便脫離迷陣。\n");
	who->move("/open/killer/room/outr3.c");
	 return 1;
  }
  return 0;
}
