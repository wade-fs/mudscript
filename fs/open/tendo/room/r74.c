// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","監牢地道");
        set("long", @LONG
走到這就是地道的盡頭了，這除了左右各有一間牢房外就沒有別
的東西。但盡頭的牆(wall)和別的地方的牆顏色有點不同，你在想--
可能是因為地道的關係吧!!且左右的火把閃爍不定使你更加確定你的
推測。
LONG);
set("exits", ([
	"north":__DIR__"r73",
	"west":__DIR__"r77",
	"east":__DIR__"r80",
]));
  setup();
}
void init()
{
        add_action("do_push","push");
}

int do_push(string str)
{
        object who;
        who = this_player();

        if(str!="wall"){return 0;}
        tell_object(who,"你輕輕的推了一下牆，但牆卻快速的轉了一圈，也連帶把你轉"+"了進去。\n");
        who->move("/open/tendo/room/r81");
        tell_room(this_object(),"你看到盡頭的牆被"+who->query("name")+"一推之下"
				+"轉動了一圈，而"+who->query("name")+"也被牆給"+
				"轉了進去。\n");
        return 1;
}
