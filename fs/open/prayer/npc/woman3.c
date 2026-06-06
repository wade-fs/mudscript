//woman
#include "/open/open.h"
#include <ansi.h>

inherit NPC;

string ask_metal()
{
    object who=this_player();
    if( who->query_temp("metal/where") >= 4 )
    { 
     who->set_temp("metal/where",5);
     return("對呀!!我家那個男人呀, 竟然帶了塊鐵回來, 還要我拿去打了把鐵鍬呢!!\n");
    }
    else
    {
     return("咦!!請問您是官府的人嗎??\n");
    }
}
void create()
{
    set_name("李嫂",({"lee woman","lee","woman"}));
    set("gender", "女性");
    set("age",41);
    set("attitude","friendly");
    set("long",@LONG

	李嫂是西街的長舌婦之一, 她的先生是一位礦工, 在官
	家做事!!

LONG);
 
    set("combat_exp",25);
    set("str",10);
    set("con",5);
    set("int",10);
    set("per",8);
    set("cps",3);
    set("kar",8);
    set("chat_chance",3);   
    set("chat_msg", ({
     HIC+"李嫂說: 呵呵!!我呀, 昨天聽到陳家媳婦兒跟她當家的在撒嬌哩!!\n"+NOR,
    }) );
    set("inquiry",([
    "金屬":(: ask_metal :),
    "當家的":"我當家的呀, 他現在在聖火教的總壇裡面找朋友喝酒哪!!\n",
 ])); 
    set_skill("dodge", 5);
    setup();
    add_money("coin", 15);
}
