//open/prayer/room/westarea/road37.c

#include <room.h>
#include "/open/open.h"
inherit ROOM;
int have=1;
int time=0; 
 
void create()
{
        set("short","街道");
	set( "build", 15 );
        set("long",@LONG

        聖火教南北向的快速道路. 往北邊走可以到達聖火教的總壇. 
        四方則到處可見聖火教的各個支門. 南邊是與中原武林相通的
        甬道. 渾天心法共有十層, 只有教主本人練到第九層的[ 血穹
        蒼 ], 其餘的門主中, 只有一位司徒知華練到第八層!!

LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"road33",        //街道
        "south":"/open/main/room/maiu-1",               //街道
        "east":__DIR__"road36",         //街道
        "west":__DIR__"road38",         //街道

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
