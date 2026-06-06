//man--iron
#include <command.h>
#include <ansi.h>

inherit NPC;

string ask_metal()
{
	object who=this_player();
        if( who->query_temp("metal/where") >= 5 )
        {
	who->delete_temp("metal/where");
	who->set_temp("metal/where",6);
        return("哦!!你聽我家那女人說啦!! 我們礦工呀, 都是很會找金屬礦的啦!!\n
        我還有一些個朋友也都曾挖過其它的金屬哩!!\n");
        }
	else
	{
	return("來來來, 願意跟我們一起喝酒嗎??\n");
	}
}   

string ask_friend()
{
	object who=this_player();
	if( who->query_temp("metal/where") >= 6 )
        {
	who->set_temp("metal/where",7);
	return("[鐵礦]呀, 是我在東北角挖到的!!\n
         我告訴你喔!!我那些朋友啊, 都很喜歡在聖火教裡頭找人聊天!!\n
	 到各個支門去找找吧!!會找到他們的!!\n");
	}
        else
	{
	return 0;
	}
}

void create()
{
    set_name("西域男子",({"man"}));
    set("gender", "男性");
    set("age",43);
    set("attitude","friendly");
    set("long",@LONG

	李家官人, 現在是官家的礦工, 從事官方金屬的開採工作!!

LONG);
 
    set("combat_exp",600);
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
    "朋友":(: ask_friend :),
 ])); 
    set_skill("dodge", 5);
    setup();
    add_money("coin", 15);
}
