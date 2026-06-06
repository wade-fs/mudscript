
inherit NPC;
void create()
{
        set_name("九天應龍", ({ "dragon" }) );
        set("race", "野獸");
        set("age", 650);
        set("long", "
九天應龍的兩顆巨眼直盯著你瞧，巨大的爪子，似乎隨時要揮下來打你
打碎，口中不時噴出一道火焰，照的漆黑的地道一片光亮。
");
        set("str", 65);
        set("con", 55);
	set("kee",8000);
	set("max_kee",8000);
        set("verbs", ({ "bite","claw"}));
        set("limbs", ({ "頭部", "利爪","尾巴"  }) );
        set("attitude","peacful");
	set("combat_exp",1000000);
	set_temp("apply/attack",100);
	set_temp("apply/dodge",100);
        set("chat_chance",10);
        set("chat_msg", ({
        "九天應龍從口中噴出一道火焰，差點把你的眉毛都燒掉了。\n",
	"九天應龍的爪子一拍，地動山搖，頭上的岩石應聲落下好幾塊來。\n",
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
if(ob->query("pass_gblade")<7)
        this_object()->kill_ob(ob);
}
void die()
{
        object ob;
        ob= this_object()->query_temp("last_damage_from");
	if(ob&&userp(ob)&&ob->query("pass_gblade")<7)
	ob->set("pass_gblade",7);
::die();
}

