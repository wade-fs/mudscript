#include <room.h>

 inherit ROOM;

 void create()
{

        set("short", "小徑");
        set("long", @LONG
這是一條滿佈青苔的小路，由地上的痕跡看來，這似乎鮮少有人經過
，兩旁的巨石足足有十尺高，看的你不禁連連咋舌，到了小徑盡頭，發現
一道石門在你面前，不知要如何開啟它。
 
LONG
        );

        set("exits", ([
        "southeast":__DIR__"h-2.c",
        ]) );
	set("outdoors" ,"/open/gsword/room");
        
setup();

}

void init()
{
    add_action("do_enter","enter");
}

int do_enter(string str)
{
   object me = this_player();
   if( me->query_skill("shasword",1)==100 && me->query_skill("sha-steps",1)==100 && me->query("get_sha_sp",1))
   me->move("/open/gsword/room/h-1.c");
   return 1;
}   
