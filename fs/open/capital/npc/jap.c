
inherit NPC;

void create()
{
	set_name("扶桑浪人", ({ "jap" }) );
	set("race", "人類");
	set("age", 22);
	set("long",@LONG
	一眼撇見這位老兄的衣著服飾，令你覺得些許好笑，卻帶著些許
	不安，從他身上配戴的武器看來，此人大概是遠從東瀛渡海而來
	，不知他此行目的為何。
LONG);
						
	set("attitude", "peaceful");
	set("str", 33);
	set("cor", 30);
	set("combat_exp", 1500);
	set("chat_chance", 6);
	set("chat_msg", ({
 	   (: this_object(), "random_move" :),
 	    "私ゾ日本人ザゾやベネオモ。\n"}) );
	set_skill("dodge",10);
	set_temp("apply/armor", 3);
	setup();
	carry_object("/open/capital/obj/katana.c")->wield();			
}
