inherit NPC;

void create()
{
        set_name("肥遺", ({ "curious snake","snake" }) );
        set("race", "野獸");
        set("age", 630);
   set("long", "
相傳：首生盤古，垂死化身，氣為風，聲為雷，目瞳為電，身成萬物，
而肥遺即為其所化之蛇，六足四翼，見則天下大旱。
");
	 set("str", 40);
        set("con", 45);
        set("kee",4500);
        set("max_kee",4500);
        set("verbs", ({ "bite","claw"}));
        set("limbs", ({ "頭部", "翅膀","六足"  }) );
	 set("attitude","peaceful");
        set("combat_exp",30000);
	set_temp("apply/attack",60);
	set_temp("apply/dodge",60);
        set("chat_chance",10);
        set("chat_msg", ({
        "肥遺對著你張牙舞爪。\n",
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
	if(ob->query("pass_gblade")<2)
        this_object()->kill_ob(ob);
}
void die()
{
        object ob;
        ob= this_object()->query_temp("last_damage_from");
	if(ob&&userp(ob)&&ob->query("pass_gblade")<2)
	ob->set("pass_gblade",2);
::die();
}
