// trainee.c

inherit NPC;

void create()
{
	set_name("武館弟子", ({ "trainee" }) );
	set("gender", "男性" );
	set("age", 19);
	set("long", "你看到一位身材高大的漢子﹐正在辛苦地操練著。\n");
	set("combat_exp", 100);
	setup();
	carry_object("/d/snow/obj/linen")->wear();
}
