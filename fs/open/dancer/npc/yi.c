//yi.c
#include "/open/open.h"
inherit F_VENDOR;

void create()
{
        set_name("小怡",({"yi"}));
        set("gender", "女性" );
        set("age", 18);
        set("long", @LONG
她是夜夢小築上負責藥房的弟子，夜夢小築的藥材都由她負責。
LONG
        );
        set("combat_exp",10000);
        set("attitude", "friendly");
        set_skill("dodge", 35);
        set_skill("dremagic", 35);
        set_skill("dreamdance", 45);
        set_skill("paull-steps", 45);
        set_skill("magic", 45);
        set_skill("unarmed", 35);
        set_skill("move", 35);
        set_skill("parry", 35);
        map_skill("unarmed","dreamdance");
        map_skill("parry","dreamdance");
        map_skill("dodge","paull-steps");
        map_skill("move","paull-steps");
        map_skill("magic","dremagic");
        set("vendor_goods", ({
        COMMON_OBJ"bandage",
        COMMON_OBJ"pill",
        COMMON_OBJ"pill1",
        COMMON_OBJ"pill2",
        COMMON_OBJ"plaster",
        COMMON_OBJ"plaster1",
        COMMON_OBJ"plaster2",
        }) );
        setup();
        add_money("silver",5);
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                say("小怡靠近你說: 這位"+RANK_D->query_respect(ob)
                    +"來買些特製補品吧!\n");
                break;
                case 1:
                say("小怡客氣的道: 這兒什麼藥材都有 "+RANK_D->query_respect(ob)
                    +"要過來看看嗎!?\n");
                break;
                case 2:
                say("小怡高聲喊道: 來來來, "+RANK_D->query_respect(ob)
                    +"要的話，我可以算便宜一點喔!\n");
                break;
        }
}
