#include <ansi.h>
#include "/open/open.h"
inherit F_VENDOR;
void create()
{
        set_name("陳總",({"cheng chong","cheng","chong"}));        set("gender", "男性" );
        set("age",40);
        set("long", "天龍客棧的掌櫃 , 整天在那裏數著不完的銀票 .\n");
        set("attitude", "friendly");
        set("combat_exp",20000);
        set("nickname",HIG + "財迷心竅" + NOR);
        set("dodge",50);
        set("parry",50);
        set("unarmed",50);
        set("chat_chance",20);
        set("chat_msg",({
        "陳總驚慌的說：我可是沒有什麼錢喔，你去找別人吧。\n",
        }));

        setup();
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
say("陳總說道: 這位"+RANK_D->query_respect(ob)+"你好 , 來吃點東西吧 !\n");
return;
}
int accept_kill(object ob)
{
 command("say 天呀!救命呀!有人要搶劫呀!");
 command("kill"+ob->query("id"));
return 1;
}
int accept_fight(object ob)
{
command("say 你好煩喔!!我忙著數錢都來不急了，走開走開別煩我數錢。");
return 0;
}
