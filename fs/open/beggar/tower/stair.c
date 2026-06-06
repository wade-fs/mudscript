inherit ROOM;
#include <ansi.h>
object me = this_player();
void create()
{
        set("short",HIR + "不死鳥ソ塔" + NOR);
        set("long", @LONG 
這裡是通往不死鳥之塔上層的樓梯間。


LONG);
        set("exits", ([
        "up" : __DIR__"room1.c",
        ]));
        set("light", 1);
        set("no_auc", 1);
        set("no_quit", 1);
        set("no_scale",1);
        set("no_chome", 1);
        set("no_transmit",1);
        setup();

}

void init()
{
 this_player()->set_temp("stair",this_object());	
}
