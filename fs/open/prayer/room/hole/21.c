//open/prayer/room/hole/21.c

#include <room.h>
#include "/open/open.h"
#include <ansi.h>

inherit ROOM;
int have = 1;
int time = 0;
 
void create()
{
       set ("short", "囹圄池");
       set ("long", @LONG
	血池之下有著可以站立的石崖，石壁上有著六個不同的鐵門!!血
	池中的野獸在那裡翻滾，一直想要將你撕裂，牠身上的鐵鏈因為
	牠的掙扎，鏗然作響，你的安全問題，越來越危險了.....
LONG);
  	set("exits", ([ /* sizeof() == 1 */
	"up" : __DIR__"20",
]));
	set("light_up", 1);
	set("objects", ([ /* sizeof() == 1 */
//    "/open/prayer/npc/kylin" : 1,
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}

void init()
{
	add_action("search_here", "search");
    	add_action("take_it","take");
}

int search_here(string arg)
{
   object me = this_player();
	if( (this_player()->query("combat_exp",1) > 100000) && have && me->query("class") == "prayer")
	{
   write("你向鐵門摸呀摸的, 找到了開關並打了開來, 裡面插著一隻\n"+
         "發光的白水晶....你決定要將它拿走(take it).\n");
        }
    else if(me->query_temp("know_book"))
        {
   message_vision("$N從血池中拿出一本殷紅的殘缺古冊，但隨即被古冊散發出的驚天魔氣給鎮攝住，因而當場昏厥。\n" + NOR,me);
   new("/open/badman/obj/evil_book.c")->move(me);
   me->unconcious();
        }
    else
   write("也許\是你的技術太差, 找不到鐵門的開關...\n");
    return 1;
}
int take_it(string arg)
{
    object user,ob;
    user = this_player();
    if( this_player()->query_temp("can_take") && have)
    {
    ob=new("/open/prayer/obj/crystal1");
    have = 0;
    ob->move(this_player());
    message_vision("當$N將白水晶從石壁中抽出來, 只見血麒麟一陣吼叫!!\n"+
                   "牠似乎很厭惡渾天水晶所發出的壓迫感",user);
    user->set("quests/white-crystal",1);
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
