///open/prayer/room/hole/8.c

#include <room.h>
#include "/open/open.h"
inherit ROOM;
int have=1;
int time=0;

void create()
{
        set("short", "洞穴");
        set("long", @LONG

        這裡就是破邪洞窟的內部了!!血紅色的濃霧飄來，聞起來
        有股腥味!!令人的意識漸漸模糊....... 去死吧!!看我的
        "無敵風火輪"!!咦??前面好像很精彩的樣子，不趕快過去
        瞧瞧就看不到好戲囉!!你心神一振，加緊腳步繼續往前搜
        巡.....

LONG    );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"10",
  "south":__DIR__"6",
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
    ob=new("/open/prayer/obj/copper");
    have = 0;
    ob->move(who);
    message_vision("一陣挖掘之後, 終於挖出來了一塊銅礦!!\n", who);
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
