///open/prayer/room/hole/5.c

#include <room.h>
#include "/open/open.h"
inherit ROOM;
int have=1;
int time=0;

void create()
{
        set("short", "洞穴");
        set("long", @LONG

        洞窟內的石壁上都是野獸的爪痕，還沾滿了許多的血跡!!
        遠處不時有野獸的叫聲，在這洞窟內迴響不已.......啊~
        !!遠處傳來一陣慘叫聲，喔喔!!看來前面有人被宰了，四
        處濃霧迷漫，伸手難見五指，只要稍一疏忽，隨時都會變
        成野獸的點心......

LONG    );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"7",
  "north":__DIR__"3",
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
    ob=new("/open/prayer/obj/gold");
    have = 0;
    ob->move(who);
    message_vision("一陣挖掘之後, 終於挖出來了一塊金礦!!\n", who);
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
