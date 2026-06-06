//open/prayer/room/youkoun/3.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","瑤光門大廳");
        set("long",@LONG

        在大廳的西方站著一位左護法, 和右護法一起保護門主.
        不過你總覺得這裡怪怪的, 可是又說不上來那種感覺..
        不曉得到底是哪兒不對勁..

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "southeast":__DIR__"4",         //大廳
        "east":__DIR__"2",                      //門主
 
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/left7" : 1,           //左護法
]));
  setup();
}

void init()
{
 add_action("search_here", "search");
}

int search_here(string str)
{
    write("你仔細一看, 發現牆壁是可以活動的!!\n");
    set("exits/west",__DIR__"22");
    call_out("do_close",10);
    return 1;
}

void do_close()
{
        if(!query("exits/west"))
                return;
        delete("exits/west");
        tell_room(this_object(),"匡~~~~牆壁又自動合起來了。\n");
}
