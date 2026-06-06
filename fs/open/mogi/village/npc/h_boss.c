#include "village.h"
#include <ansi.h>

inherit F_VENDOR;

void create()
{
        set_name("妖子",({"hotel boss","boss"}));
        set("gender", "女性" );
        set("title","魔界村旅店老闆");
        set("age", 23);
        set("long","魔界村旅店的老闆, 看起來很年輕, 事實上則是千歲以上的魔族\n");
        set("combat_exp",5000);
        set("attitude", "friendly");
        set("no_kill", 1);
        set_skill("dodge", 30);
        set_skill("unarmed",30 ); 
        set_skill("parry", 30);
        set("vendor_goods", ({
             V_OBJ"d_leg",
             V_OBJ"bone_pot",
             V_OBJ"h_dumpling",
        }) );
        setup();
        add_money("coin",35);
}

void init()
{
        object ob;

        ::init();
        add_action("do_vendor_list", "list");
}  
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        command("say 請問"+RANK_D->query_respect(ob)+"需要休息嗎?");
} 
