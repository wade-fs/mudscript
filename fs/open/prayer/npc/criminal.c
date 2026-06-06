#include <command.h>
#include <ansi.h>
 
inherit NPC;
 
void create()
{
    set_name("人犯",({"criminal"}));
    set("title", "地牢的");
    set("gender", "女性");
    set("age",36);
    set("attitude","friendly");
    set("long",@LONG

	天機門地牢內的人犯, 不知道為何會被關在此地!!身上傷痕
	累累, 應該是用刑後的痕跡吧.

LONG);
 
    set("combat_exp",50);
    set("str",1);
    set("con",1);
    set("int",1);
    set("max_kee",5);
    set("kee",5);
    set("limbs",({"頭","手","腳","背","腹","腰"}));

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
    return notify_fail("人犯無力地說道:$N看我這樣子還能打嗎?? 不要開玩笑了!!");
}

void greeting(object who)
{
    if( (who->query("family/family_name") == "聖火教") )
    {
       command("cower "+who->query("name"));
       command("say "+who->query("name")+"不要虐待我了........拜託!!");
    }
    else
    {
    command("say 快走吧!!聖火教的人都是變態呀!!!被抓到你就知道了.......");
    }
return;
}
