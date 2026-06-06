#include "/open/open.h"
#include <ansi.h>
inherit F_VENDOR;

void create()
{
        set_name("陽明德",({"yang ming teck","yang","ming","teck"}));
        set("gender", "男性" );
        set("age", 35);
        set("long", @LONG
他是陽家藥店裏的老闆，他的買的各式各樣藥材，應有盡有。
LONG
        );
        set("combat_exp",20000);
        set("nickname",HIR + "藥到病除" + NOR);
set("title","專治狂犬病");
        set("attitude", "friendly");
        set_skill("dodge", 40);
set("no_lyssa",1);
        set_skill("unarmed", 20);
        set("vendor_goods", ({
        COMMON_OBJ"bandage",
"/open/marksman/obj/super_pill",
        COMMON_OBJ"pill",
        COMMON_OBJ"pill1",
        COMMON_OBJ"pill2",
"/open/doctor/pill/ff_pill",
        COMMON_OBJ"plaster",
        COMMON_OBJ"plaster1",
        COMMON_OBJ"plaster2",
        }) );
        setup();
        add_money("coin",35);
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                say("陽明德靠近你說: 這位"+RANK_D->query_respect(ob)
                    +"來買些特製補品吧!\n");
                break;
                case 1:
                say("陽明德客氣的道: 這兒什麼藥材都有 "+RANK_D->query_respect(ob)
                    +"要過來看看嗎!?\n");
                break;
                case 2:
                say("陽明德高聲喊道: 來來來, "+RANK_D->query_respect(ob)
                    +"要的話，我可以算便宜一點喔!\n");
                break;
        }
}
int accept_kill(object ob)
{
 command("say 哼!連醫生你也敢殺，真是無藥可救。");
 command("say 納命來!!");
 command("kill"+ob->query("id"));
return 1;
}
int accept_fight(object ob)
{
command("say 你沒有看見我在急救病人嗎?給我閃都別的地方去。");
return 0;
}
