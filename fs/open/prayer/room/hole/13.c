///open/prayer/room/hole/13.c

#include <room.h>
#include "/open/open.h"
inherit ROOM;

int have=1;
int time=0;

void create()
{
        set("short", "洞穴");
        set("long", @LONG

        你突然開始搖搖晃晃，站也站不穩倒在地上，咦??地震
        嗎??忽然遠方傳來魔獸的咆嘯聲"啊～～嗚～!!"，接著
        轟隆!!轟隆!!哇~~!!是什麼巨獸，走起路來天崩地裂似
        的??

LONG    );
    set("objects", ([ /* sizeof() == 2 */
   "/open/prayer/npc/crab-ox" : 1,              
   "/open/prayer/npc/evil-tiger" : 1,           
]));
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"15",
  "west":__DIR__"11",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
        setup();
}

void init()
{
    add_action("search_here", "search");
    add_action("dig_it","dig");
}

int search_here(string arg)
{
    object who=this_player();
    if( who->query_temp("metal/where",7) )
      write("你在這裡的四周敲敲打打的, 終於發現了一處挖掘過的痕跡..\n"+
      "挖挖看 (dig) 吧!! 說不定真能挖出什麼東東來耶!!\n");
      else
      write("你在幹嘛呀??\n");
    return 1;
}

int dig_it(string arg)
{
    object who,ob;
    who = this_player();
    if( who->query_temp("metal/where",7)  )
    {
    ob=new("/open/prayer/obj/silver");
    have = 0;
    ob->move(who);
    message_vision("一陣挖掘之後, 終於挖出來了一塊銀礦!!\n", who);
    who->delete_temp("metal/where");
    return 1;
    }
    return 0;
}   
void heart_beat()
{
 time++;
 if( time > 6000)
 {
   time=0;
   have=1;
  }
  return;
}   
