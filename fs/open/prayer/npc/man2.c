//man
#include <command.h>
#include <ansi.h>

inherit NPC;

string ask_metal()
{
	object who=this_player();
        if( who->query_temp("metal/where") >= 2 )
        {
	who->set_temp("metal/where",3);
        return(" 哦!!前幾天李嫂拿了塊鐵給我, 要我幫她打造鐵鍬.\n
        聽她說是他當家的無意間挖掘出來的!!\n");
        }
	else
	{
	return(" 西域的金屬是不准私下販售的!!\n");
	}
}   

void create()
{
    set_name("西域男子",({"man"}));
    set("gender", "男性");
    set("age",51);
    set("attitude","friendly");
    set("long",@LONG

	打鐵匠王六郎!!原本是西域官方的鑄匠, 因為年歲已高
	所以從官家退休了!!目前在家閒著, 有空會幫鄰居打點
	小東西!!

LONG);
 
    set("combat_exp",200);
    set("str",10);
    set("con",5);
    set("int",10);
    set("per",8);
    set("cps",3);
    set("kar",8);
    set("chat_chance",3);   
    set("chat_msg", ({
     HIC+"王六郎道: 昨兒個我那個小孫子拿著把鐵鎚在玩, 嘿!真是皮呀!!\n"+NOR,
    }) );
    set("inquiry",([
    "金屬":(: ask_metal :),
 ])); 
    set_skill("dodge", 5);
    setup();
    add_money("coin", 15);
}
