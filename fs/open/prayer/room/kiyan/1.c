//open/prayer/room/kiyan/1.c

#include <room.h>
#include "/open/open.h"

inherit ROOM;
int have=1;
int time=0;
 
void create()
{
        set("short","門主的房間");
        set("long",@LONG

        門主的房間一眼看去非常的整齊，原因是房間內的擺\設實在是太少
        了，只有一座小小的木板床!!．壁上掛著一口紅色外殼的短劍!!旁
        邊有一行小小的蠅頭小字．不知道是自己文學程度太差還是怎麼的
        ，就是看不懂他寫些什麼??

LONG);
        set("exits", ([ /* sizeof() == 1 */
        "south":__DIR__"4",             //門主
]) );
        set("no_fight", 0);
        set("light_up", 1);
  setup();
}

void init()
{
    add_action("search_here", "search");
    add_action("take_it","take");
}

int search_here(string arg)
{
    if( (this_player()->query("combat_exp",1) > 100000)  && have)
      write("你朝牆上望呀望的,發現這口寶劍實在是非常的漂亮與高貴.真想偷偷拿走..\n"+
               "你膽子一大,決定要將它拿走(take it).\n");
    else
       write("也許\是你的膽子不夠大,你不敢對這口寶劍有所遐思...\n");
    return 1;
}
int take_it(string arg)
{
    object user,ob;
    user = this_player();
    if( this_player()->query("quests/girlsword",1) && !present("Red-sword",user) )
    {
    ob=new("/open/prayer/obj/sword");
    have = 0;
    ob->move(this_player());
    message_vision("當$N將寶劍抽出來,只見寶劍豪光四射.........哇!!一口上好的劍耶!!\n", user);
    return 1;
    }
    return 0;
}   
void heart_beat()
{
 time++;
 if( time > 3000)
 {
   time=0;
   have=1;
  }
  return;
}   
