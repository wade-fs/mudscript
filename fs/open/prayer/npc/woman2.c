//woman
#include <command.h>
#include <ansi.h>

inherit NPC;

string ask_metal()
{
    object who=this_player();
    if( who->query_temp("metal/where") >= 3 )
    { 
    who->set_temp("metal/where",4);
    return("還不是那天跟李嫂聊天的時候提到的!!她當家的呀, 就曾挖了塊鐵回來給她瞧瞧呢!!\n
    聽說是在某座山上挖到的!!\n");
    }
    else
    {
    return("來來來, 我們一起去找李嫂聊聊去!!\n");
    }
}

void create()
{
    set_name("西域婦女",({"westarea woman","woman"}));
    set("gender", "女性");
    set("age",42);
    set("attitude","friendly");
    set("long",@LONG

	西域婦女!!閒著沒事到朋友家去{開講}, 這種長舌的人
	知道的名堂應該很多才對.....

LONG);
 
    set("combat_exp",70);
    set("str",10);
    set("con",5);
    set("int",10);
    set("per",8);
    set("cps",3);
    set("kar",8);
    set("chat_chance",3);   
    set("chat_msg", ({
     HIC+"婦女說: 走囉!!今天呀沒有什麼事做, 去找人聊聊天兒!!\n"+NOR,
    }) );
    set("inquiry",([
    "金屬":(: ask_metal :),
 ])); 
    set_skill("dodge", 5);
    setup();
    add_money("coin", 15);
}
