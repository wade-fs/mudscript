// trainer.c

inherit NPC;

void create()
{
	set_name("李火獅", ({ "trainer", "lee" }) );
	set("title", "拳法教練");
	set("gender", "男性" );
	set("age", 28);
	set("str", 26);
	set("int", 14);
	set("long",
		"李火獅是個孔武有力的大塊頭﹐他正在訓練他的弟子們習練「柳家拳\n"
		"法」(liuh-ken)。\n" );
	set("combat_exp", 3000);
	set("attitude", "heroism");

	set("force", 120);
	set("max_force", 120);
	set("force_factor", 1);

	set("inquiry", ([
		"here": "這裡當然是淳風武館﹐不然還是哪裡﹖\n",
		"name": "在下姓李﹐名字就叫火獅﹐人稱李教頭的便是我。\n",
		"柳家拳法": "哦....說來慚愧\﹐小弟這套拳法還沒學得到家, 柳館主就教我在這裡傳藝。\n"
	]) );

	set_skill("unarmed", 30);
	set_skill("liuh-ken", 20);
	set_skill("dodge", 30);
	map_skill("unarmed", "liuh-ken");

	setup();
}

int recognize_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="封山劍派" ) return 1;
	command("say 對不起﹐這位" + RANK_D->query_respect(ob) + "﹐您不是我們武館的弟子。");
	return notify_fail( "李火獅不願意教你拳法。\n");
}

int accept_fight(object me)
{
	if( (string)me->query("family/family_name")=="封山劍派" ) {
		command("nod");
		command("say 進招吧。");
		return 1;
	}
	command("say 館主吩咐過﹐不許\和來這裡的客人過招。");
	return 0;
}
