inherit NPC;
void create()
{
        set_name("守塔者", ({ "pagoda guard", "guard"}) );
        set("gender"  , "男性" );
        set("age", 27);
        set("str", 30);
        set("int", 29);
        set("long","瀧山武館的拳法教頭,被任正晴分派來守護這座塔。\n");
        set("attitude"      , "heroism");
        set("combat_exp",400000);
        set("force"         , 2500);
        set("max_force"     , 2000);
        set("force_factor"  , 10);
        set("super_fire",1);
         set("env/狂擊","YES");
        set_skill("lungshan", 80);
        set_skill("dodge"   , 50);
        set_skill("haoforce", 50);
        set_skill("force"   , 70);
        set_skill("unarmed", 90);
        set_skill("parry", 60);
        set_skill("dodge",40);
        set_skill("henma-steps",40);
        set_skill("fire-kee",60);
        map_skill("force", "haoforce");
        map_skill("unarmed", "lungshan");
        map_skill("dodge", "henma-steps");
        map_skill("parry", "fire-kee");
        setup();
       carry_object("/open/wu/obj/ring1.c")->wield();
        add_money("gold", 8);
}

void die()
{
object room,me;
	room = environment(this_object());
	me = this_object() ->query_temp("last_damage_from");

	if( me->query("id") == "wild man" || me->query("id") == "iv bu" )
	{
		tell_object(users(),"乾坤八卦塔 第"+room->query("mark")+"層 被 "+me->query("name")+" 攻破了。\n");
	}
::die();
}
