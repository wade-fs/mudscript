inherit NPC;

void create()
{
        set_name("三首九尾龜", ({ "nine-switch tortoise","tortoise" }) );
        set("race", "野獸");
        set("age", 1000);
        set("long", "
三個好像牛頭一般大的頭部，真不知道牠要怎麼協調彼此的動作？而那滿
是花紋的龜殼，倒是相當的漂亮，聽說烏龜殼的花紋越多，表示年齡越大
，看樣子牠大概活了上千年了。
");
        set("str", 68);
        set("con", 40);
	  set("kee",10000);
	 set("max_kee",10000);
        set("verbs", ({ "bite","claw"}));
        set("limbs", ({ "頭部", "龜殼","尾巴"  }) );
        set("attitude","peacful");
	set("combat_exp",1000000);
	set_temp("apply/attack",100);
	set_temp("apply/dodge",100);
        set("chat_chance",10);
        set("chat_msg", ({
        "九尾龜慢慢的爬著。\n",
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
if(ob->query("pass_gblade")<6)
        this_object()->kill_ob(ob);
}
void die()
{
        object ob;
        ob= this_object()->query_temp("last_damage_from");
	if(ob&&userp(ob)&&ob->query("pass_gblade")<6)
	ob->set("pass_gblade",6);
::die();
}

