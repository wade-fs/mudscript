//open/prayer/room/2elder1

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "執法長老房");
	set( "build", 238 );
  set ("long", @LONG

            聖火教總舵三位護教長老之一的執法長老
	所專屬的辦公處。長老正在為處罰犯了教規的
	門徒傷腦筋。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/lawyer-elder" : 1,		//執法長老
]));
  set("exits", ([ /* sizeof() ==  1*/
	"east" : "/open/prayer/room/2elder3",		//`長老房
]));
 set("light_up", 1);
  set("valid_startroom", 2);

  setup();
}
 
void init()
{
 add_action("search_here", "search");
}

int search_here(string str)
{
    if( (this_player()->query("combat_exp",1) > 100000)  )
    {
    write("房間背後有一道暗門!!\n");
      set("exits/west",__DIR__"bottle-room");
      call_out("do_close",10);
    }
    else
    {
    write("也許\是你經驗不足,你什麼也沒發現...\n");
    }    
return 1;
}

void do_close()
{
	if(!query("exits/west"))
		return;
	delete("exits/west");
	tell_room(this_object(),"暗門自動地關上了。\n");
}

