// /open/center/npc/vendor.c
#include "/open/open.h"
inherit NPC;
void create()
{
	set_name("楓林港守衛", ({ "guard" }) );
	set("gender", "男性" );
	set("age", 25);
	set("long", @LONG
由京城千挑萬選的精良守衛 , 負責維護港口的治安
他正站在瞭望台上注視著楓林的一舉一動 .
LONG);
	set("attitude","heroism");
	set("combat_exp",20000);
	set_skill("dodge",50);
	set_skill("blade",60);
	set_skill("parry",50);
	set_skill("unarmed",60);
	set("chat_chance",10);
	set("chat_msg",({
	}));
	set("greeting_msg", ({
	    	}) );
	setup();
	carry_object("/open/port/obj/guard_blade")->wield();
	carry_object("/open/port/obj/guard_armor")->wear();
	carry_object("/open/port/obj/guard_boots")->wear();
        add_money("silver",5);        
	
}
