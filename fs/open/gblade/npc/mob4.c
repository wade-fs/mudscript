inherit NPC;

void create()
{
        set_name("金翅鷗鵬", ({ "gold-brachium roc","roc" }) );
        set("race", "野獸");
        set("age", 550);
        set("long", "
金閃閃的羽毛，銳利的雙眼，是一隻少見的珍禽異獸，牠那強而有力的翅
膀，尖銳的雙爪，就是最佳的攻擊武器，也告訴所有的人最好不要惹牠。
");
        set("str", 40);
        set("con", 55);
        set("kee",4000);
        set("max_kee",4000);
        set("verbs", ({ "bite","claw"}));
        set("limbs", ({ "頭部", "爪子","翅膀","雙眼"  }) );
        set("attitude","peacful");
        set("combat_exp",100000);
	set_temp("apply/attack",100);
	 set_temp("apply/dodge",100);
        set("chat_chance",10);
        set("chat_msg", ({
        "金翅鷗鵬展開雙翼鼓動颳起陣陣強風吹的你的臉隱隱作痛。\n",
         }) );
       setup();
}
void init()
{
        object ob;
        ::init();
        if(interactive(ob=this_player()) && !is_fighting())
        {
        remove_call_out("greeting");
        call_out("greeting",2,ob);
        }
}
void greeting(object ob)
{
if(ob->query("pass_gblade")<4)
        this_object()->kill_ob(ob);
}
void die()
{
        object ob;
        ob= this_object()->query_temp("last_damage_from");
	if(ob&&userp(ob)&&ob->query("pass_gblade")<4)
	ob->set("pass_gblade",4);
::die();
}

