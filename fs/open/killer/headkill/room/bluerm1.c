#include <room.h>
inherit ROOM;
void create ()
{
   set ("short","藍鳳組組長房間");
	set( "build", 12 );
   set ("long", @LONG
	利用五鬼搬運大法，你終於來到藍鳳組的組長所在地，
	四周被一種陣式所包圍，你並沒有看到任何通道。
        在你眼前的想必是藍鳳組的組長---喬小雨。

LONG);
  set("no_fight",1);
  set("no_magic", 1);
  set("no_transmit",1);
  set("objects",([
	"/open/killer/headkill/npc/hu_fa5.c":1,
        "/open/main/obj/torch" : 1,
        ]));
  setup();
}
