//open/prayer/room/youkoun/26.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","刑房");
        set("long",@LONG

        走到密道的盡頭之後, 光線突然整個亮了起來, 你的眼睛
        一時無法適應, 等你漸漸可以看見東西後, 你懷疑自己究
        竟在那裡??這裡的屍首遍地, 還有好多是剛死去沒多久的
        男性屍體. 個個臉上都是那恐怖的表情!!嘔~~~~你忍不住
        吐了一地!!

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "south":__DIR__"27",    
        "west":__DIR__"25",     
 
        ]) );
        set("no_fight", 0);
                
  setup();
}

void init()
{
 add_action("search_here", "search");
}

int search_here(string str)
{
    write("你仔細一看, 發現牆腳下有個活動的小鐵門!!\n");
    set("exits/down",__DIR__"29");
    call_out("do_close",10);
    return 1;
}

void do_close()
{
        if(!query("exits/down"))
                return;
        delete("exits/down");
        tell_room(this_object(),"匡~~~~牆壁又自動合起來了。\n");
}
