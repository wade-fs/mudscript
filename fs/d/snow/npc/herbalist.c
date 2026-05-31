// herbalist.c

inherit NPC;

string heal_me(object me);

void create()
{
	set_name("楊掌櫃", ({ "herbalist" }) );
	set("title", "桑鄰藥鋪");
	set("gender", "男性" );
	set("age", 54);
	set("long",
		"楊掌櫃是這附近相當有名的大善人﹐常常施捨草藥給付不起藥錢的窮人\n"
		"。此外他的醫術也不錯﹐年輕時曾經跟著山煙寺的玄智和尚學醫﹐一般\n"
		"的傷寒小病直接問他開藥吃比醫生還靈。\n" );
	set("combat_exp", 1300);
	set("attitude", "friendly");
	set("inquiry", ([
		"治傷": (: heal_me :),
		"療傷": (: heal_me :),
		"開藥": (: heal_me :),
	]) );

	set_skill("literate", 70);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	setup();
	add_money("coin", 80);
}

string heal_me(object me)
{
	int ratio;

	ratio = (int)me->query("eff_kee") * 100 / (int)me->query("max_kee");
	if( ratio >= 100 )
		return "這位" + RANK_D->query_respect(me) + "﹐您看起來氣色很好啊﹐不像有受傷的樣子。";
	if( ratio >= 95 )
		return "哦....我看看....只是些皮肉小傷﹐您買包金創藥回去敷敷就沒事了。";
	
}

