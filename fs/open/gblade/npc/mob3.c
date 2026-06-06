inherit NPC;

void create()
{
        set_name("六足雙頭蛇", ({ "two-heads snake","snake" }) );
        set("race", "野獸");
        set("age", 500);
        set("long", "
一條十多丈長的巨蛇，兩顆碩大的舌頭再擬面前晃來晃去，還不時耀武
揚威的對你吐著蛇信，從口中散發出的臭味，聞了欲噁。
");
        set("str", 40);
        set("con", 55);
        set("kee",4000);
        set("max_kee",4000);
        set("verbs", ({ "bite","claw"}));
        set("limbs", ({ "頭部", "足部","尾部"  }) );
        set("attitude","peacful");
        set("combat_exp",98000);
	set_temp("apply/dodge",70);
	 set_temp("apply/attack",80);
	set("chat_chance",10);
        set("chat_msg", ({
        "六足雙頭蛇張開雪盆大口一口就把一隻不知名的怪獸吞了下去。\n",
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
  if(ob->query("pass_gblade")<3)
        this_object()->kill_ob(ob);
}
void die()
{
        object ob;
        ob= this_object()->query_temp("last_damage_from");
	if(ob&&userp(ob)&&ob->query("pass_gblade")<3)
	ob->set("pass_gblade",3);
::die();
}
