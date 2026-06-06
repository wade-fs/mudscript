//woman
#include "/open/open.h"
#include <ansi.h>
inherit NPC;

string ask_metal()
{
     object who=this_player();
     who->set_temp("metal/where",1);
     return("我也是聽我當家說的!!好像是～～有四種金屬吧!!\n");
}

void create()
{
    set_name("西域少婦",({"young woman","woman"}));
    set("gender", "女性");
    set("age",22);
    set("attitude","friendly");
    set("long",@LONG

	西域少婦!!正在街上行走著, 應該是要到市集採辦食品吧.....

LONG);
 
    set("combat_exp",20);
    set("str",10);
    set("con",5);
    set("int",10);
    set("per",8);
    set("cps",3);
    set("kar",8);
    set("chat_chance",3);   
    set("chat_msg", ({
     HIC+"少婦說: 最近聽說有人發現一個地方可以挖到金屬耶!!\n"+NOR,
    }) );
    set("inquiry",([
    "金屬":(: ask_metal :),
 ])); 
    set_skill("dodge", 5);
    setup();
    add_money("coin", 15);
}
