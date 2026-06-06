#include <room.h>

inherit ROOM;

string do_look();

void create()
{
           set("short","洞穴");
          set("long",@LONG
穴洞第二層, 由於景象都差不多, 所以在沒有完整的地圖概念之前,
最好不要誤闖此處,在西面的石壁似乎有點古怪。
LONG);

        set("exits", ([
          "west":__DIR__"hole19",
          "east":__DIR__"hole20",
          "north":__DIR__"hole15",
        ]) );
	set("search_desc", ([
	    "wall" :	(: do_look :),
	    "石壁" :	(: do_look :),
	]) );
        setup();
}
void init()
{
	add_action("do_key","push");
}

string do_look()
{
         return "你發現牆上有一個暗門，門旁有個鑰匙(key)孔，\n"+
	        "也許\可以壓壓看(push)。\n";
}
int do_key(string str)
{
         if(str!="key") return 0;
        tell_object(this_player(),"結果「喀」的一聲﹐你推動了石壁。\n");
          tell_object(this_player(),"你進入了密室。\n");
        this_player()->move(__DIR__"hole26");
         return 1;
}
