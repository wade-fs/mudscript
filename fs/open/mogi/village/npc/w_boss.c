#include "village.h"
#include <ansi.h>

inherit F_VENDOR;

void create()
{
        set_name("歐陽牛",({"weapon boss","boss"}));
        set("gender", "男性" );
        set("title","魔界村武器店老闆");
        set("age", 25);
        set("long","魔界村武器店的老闆, 人如其名力大如牛, 是個樸實的人.\n");
        set("combat_exp",5000);
        set("attitude", "friendly");
        set("no_kill", 1);
        set_skill("dodge", 30);
        set_skill("unarmed",30 ); 
        set_skill("parry", 30);
        set("vendor_goods", ({
             V_OBJ"msword",
             V_OBJ"mblade",
             V_OBJ"mpen",
             V_OBJ"mdagger",
             V_OBJ"mwhip",
             V_OBJ"mclaw",

       }) );
        setup();
   add_money("coin",500);
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
        command("say "+RANK_D->query_respect(ob)+"想要什麼的話可以儘管挑!");
} 

