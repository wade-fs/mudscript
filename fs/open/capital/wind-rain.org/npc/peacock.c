// peacock.c by roger

inherit NPC;

void create()
{
	set_name("孔雀", ({ "peacock" }) );
	set("long",@LONG
       七彩羽的孔雀正鼓動著牠的
       雙翅, 四處遊蕩著.
LONG);
	set("race","野獸");
	set("age", 2);
	set("str", 6);
	set("con", 6);
	set("max_gin", 60);
	set("max_kee", 200);
	set("max_sen", 60);

	set("limbs", ({ "尖嘴", "羽毛", "左腳", "右腳", "爪子" }) );
        set("verbs", ({ "claw", "poke" }) );
	set("chat_chance", 4);
	set("chat_msg", ({
	"\n孔雀張開它那美麗的羽毛～～\n",
	}) );
		
	set("combat_exp",5000);
	setup();
	add_money("coin", 1);
}
