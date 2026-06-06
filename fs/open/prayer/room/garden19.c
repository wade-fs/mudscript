//open/prayer/room/garden19.c
#include <room.h>
#include "/open/open.h"
inherit ROOM;

int have = 1;
 
void create()
{
        set("short","花園");
        set("long",@LONG

            這裡有座高約四尺的麒麟石像，剛才在濃
        霧中所見的雕像一定是它了!!這作雕像遠遠望
        去給人一股非常柔和的感覺!!威嚴中帶點不可
        被侵犯的尊貴!!

LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "south":"/open/prayer/room/garden15",             
        "east":"/open/prayer/room/garden18",              
        "west":"/open/prayer/room/garden20",              
        ]) );
         set("item_desc", ([
         "statue": "麒麟石像，你可以嘗試著推推看。\n"
        ]));
   setup();
}

void init()
{
            add_action("search_here", "search");
        add_action("do_push","push");
}

int search_here(string str)
{
    if( (this_player()->query("quests/white-crystal",1) ) || (this_player()->query_temp("know_book") ))
      write("你嘗試著推一推石像,覺得這石像似乎有點問題.\n"+
            "你可以試著推動它(push statue).\n");
    else
      write("也許\是你經驗不足,你什麼也沒發現...\n");
    return 1;
}
int do_push(string str)
{
        object ob;
        ob = this_player();

        if(!str || str != "statue")
                return notify_fail("你在推什麼啦?\n");
        else {
        set("exits/down","/open/prayer/room/hole/2");
message_vision("$N緩緩的把石像推開，這才發現原來有底下有一道階梯。可是它通往何處呢??\n", ob);
        call_out("do_close",10);
        }
        return 1;
}

void do_close()
{
        if(!query("exits/down"))
                return;
        delete("exits/down");
        tell_room(this_object(),"被人推開的石像又緩緩的自動回到了原位。\n");
}
