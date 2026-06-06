//open/prayer/room/westarea/road12.c

#include <room.h>
#include "/open/open.h"
inherit ROOM;
int have=1;
int time=0; 
 
void create()
{
        set("short","街道");
        set("long",@LONG
        西武林自成一格的街道, 四通八達, 處處繁華. 往東可以到達
        天樞門與天權門. 至於破邪洞窟的存在, 是因為當時未開發的
        西域到處都是奇怪的怪物, 教主為了要開闢聖火教, 便以一己
        之力將它們全部制服後, 再建造出來一個洞窟當做放置怪物的
        場所!! 
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"road11",                 //街道
        "west":__DIR__"road13",         //街道
 
        ]) );
        
        set("no_fight", 0);
        
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
    ob=new("/open/prayer/obj/copper");
    have = 0;
    ob->move(who);
    message_vision("一陣挖掘之後, 終於挖出來了一塊[銅礦]!!\n", who);
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
