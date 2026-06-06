#include <command.h>
#include <ansi.h> 
 
inherit NPC;
string ask_help()
{
   object who=this_player();

   if( !who->query_temp("殺害人犯") && who->query("marks/聖火八天門",1))
   {
   command("say 請你幫我向門主求情, 好嗎(nod)??");
   who->set_temp("can_nod",1);
   }
   else
   {
   return 0;
   }
}
 
void create()
{
    set_name("人犯",({"criminal"}));
    set("title", "地牢的");
    set("gender", "男性");
    set("age",46);
    set("attitude","friendly");
    set("long",@LONG
	這位萎靡不振的人犯曾經是天機門的弟子之一, 被關在此地是因為
	虐待人犯太過殘暴!!連續害死數名重要的人犯, 所以被門主禁錮在
	此, 嘗嘗被虐待的滋味!!

LONG);
 
    set("combat_exp",4000);
    set("str",1);
    set("con",1);
    set("int",1);
    set("max_kee",5);
    set("kee",5);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set("chat_chance",5);
    set("chat_msg",({
    HIC+"人犯說 : 幫我去跟門主求情好嗎??\n"+NOR,
    HIC+"人犯說: 拜託了!!\n"+NOR, 

 }));
    set("inquiry",([
    "求情":(: ask_help :),
    ]));

    setup();
}

int accept_kill(object who)
{
        who->set_temp("殺害人犯",1);
        command("say 嗚.."+RANK_D->query_rude(who)+who->name()+"殺害人犯會有報應的。");
        return 1;
}

int accept_fight(object who)
{
    return notify_fail("人犯無力地說道:$N行行好吧!! 直接解決我吧!!用kill比較快啦");
}

void init()
{
     add_action("do_nod","nod"); 
}

int do_nod()
{
	object who=this_player();
    if( who->query_temp("can_nod",0))
	return 0;
	if( who->query_temp("殺害人犯"))
	return 0;
	who->delete_temp("can_nod");
	who->set_temp("can_tell",1);
}
