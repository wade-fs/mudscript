#include "/open/open.h"
#include "ansi.h"
inherit NPC;
inherit F_MASTER;
 
void create()
{
    set_name("行刑者",({"chamber"}));
    set("title", "刑房的");
    set("gender", "女性");
    set("age",46);
    set("attitude","aggressive");
    set("long",@LONG

	刑房內負責行使酷刑的人, 直接受命於瑤光門主周琇虔的
	指使, 用刑殘暴!!已經不知殺死多少門主所厭惡的男性了
	!!

LONG);
 
    set("combat_exp",1000);
    set("str",15);
    set("con",15);
    set("int",15);
    set("max_kee",500);
    set("kee",500);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set("chat_chance",30);   
     set("chat_msg", ({
     HIR+"行刑者說: 你竟敢擅闖刑房!!我要去向門主稟告!!\n"+NOR,
     HIR+"行刑者說: 去死吧!!看我的皮鞭神功\~~~\n"+NOR,
        }) );
    setup();
}

int accept_kill(object who)
{
        who->set_temp("擅闖刑房",1);
        command("say 可惡"+RANK_D->query_rude(who)+who->name()+"擅闖刑房,該死!!");
        return 1;
}


