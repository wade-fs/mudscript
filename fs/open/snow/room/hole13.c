#include <room.h>

inherit ROOM;

void create()
{
           set("short","洞穴");
          set("long","洞穴第二層,由於景象都差不多,所以在沒有完整的地圖概念之前,最好不要誤闖此處,在西面的石壁(wall)似乎有點古怪。\n");

        set("exits", ([
          "west":__DIR__"hole17",
          "east":__DIR__"hole18",
          "south":__DIR__"hole16",
        ]) );
        setup();
}
void init()
{
        add_action("do_look","l");
            add_action("do_look","look");
            add_action("do_key","push");
}
int do_look(string str)
{
         if(str!="wall") return 0;
         tell_object(this_player(),"你發現牆上有一個暗門(key)。\n");
          return 1;
}
int do_key(string str)
{
         if(str!="key") return 0;
        tell_object(this_player(),"結果「喀」的一聲﹐你推動了石壁。\n");
          tell_object(this_player(),"你進入了密室。\n");
this_player()->move("/open/gblade/room/room26.c");
         return 1;
}
