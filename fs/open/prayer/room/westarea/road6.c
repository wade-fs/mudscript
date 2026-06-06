//open/prayer/room/westarea/road7.c

#include <room.h>
#include "/open/open.h"
inherit ROOM;
int have=1;
int time=0; 
 
void create()
{
        set("short","街道");
        set("long",@LONG
        西武林自成一格的街道, 四通八達, 處處繁華. 西邊是
        通往飄渺四宮之首的"青龍宮". 聖火教的門生常說聖火
        教內的高級幹部非常討厭舞者!!雖說這只是聽說的, 可
        是至今仍沒有舞者願意進去一試!!
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 1 */
        "south":__DIR__"road4",         //街道

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
    if( who->query_temp("metal/where") >=7 )
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
    ob=new("/open/prayer/obj/iron");
    have = 0;
    ob->move(who);
    message_vision("一陣挖掘之後, 終於挖出來了一塊[鐵礦]!!\n", who);
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
