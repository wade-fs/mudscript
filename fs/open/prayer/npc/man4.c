//man--silver
#include <command.h>
#include <ansi.h>

inherit NPC;

string ask_metal()
{
	object who=this_player();
        if( who->query_temp("metal/where") >= 6 )
        {
	who->delete_temp("metal/where");
	who->set_temp("metal/where",7);
        return("哦!!你聽老李說過啦!!我們礦工呀, 都是很會找金屬礦的啦!!\n
	在西邊兩個支門之間, 那裡可以找到[銀礦]喔!!洞窟裡也可以找到[銀礦]喔!!\n");
        }
	else
	{
	return("來來來, 願意跟我們一起喝酒嗎??\n");
	}
}   

void create()
{
    set_name("西域男子",({"man"}));
    set("gender", "男性");
    set("age",43);
    set("attitude","friendly");
    set("long",@LONG

	這位老兄現在是官家的礦工, 從事官方金屬的開採工作!!

LONG);
 
    set("combat_exp",500);
    set("str",10);
    set("con",5);
    set("int",10);
    set("per",8);
    set("cps",3);
    set("kar",8);
    set("chat_chance",3);   
    set("chat_msg", ({
     HIC+"男子道: 來來來, 今天喝個不醉不歸呀!!\n"+NOR,
    }) );
    set("inquiry",([
    "金屬":(: ask_metal :),
 ])); 
    set_skill("dodge", 5);
    setup();
    add_money("coin", 15);
}
