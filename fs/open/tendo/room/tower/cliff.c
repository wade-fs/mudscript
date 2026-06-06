#include <room.h>
inherit ROOM;
void create()
{
        set("short", "峭壁");
	set("long", @LONG
這是一片峭壁的正下方，由於這個地方只是一片峭壁，所以根本很
少人在此逗留，而這裡也是一片荒蕪的景象，峭壁上垂滿了蔓生的藤，
而峭壁下也都長滿了高過人頭的雜草(brush)。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south"  : "/open/tendo/room/tower/cave2",
]));
	set("outdoors", 1);
	setup();
}
void init()
{
        add_action("enter_brush", "enter" );
}
int enter_brush(string str)
{
    if(str!="brush")
      {
       write("你要進去那裡啊﹖\n");
        return 0;
      }
      else
      {
       write("你撥開了草叢，走了進去。\n");
        say(""+this_player()->query("name")+"穿過了草叢，發出沙沙聲。\n");
       this_player()->move("/open/tendo/room/tower/room5a");
       say("草叢發出沙沙聲，"+this_player()->query("name")+"撥開了草叢，走了進來。\n");
       return 1;
}
}


