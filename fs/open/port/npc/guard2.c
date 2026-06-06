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
他現在正值勤完畢 , 坐在椅子上泡茶 .
LONG);
	set("sttitude","heriosm");
	set("combat_exp",20000);
	set_skill("dodge",50);
	set_skill("blade",60);
	set_skill("parry",50);
	set_skill("unarmed",60);
	set("chat_chance",5);
	set("chat_msg",({
	}));
	set("greeting_msg", ({
	    	}) );
	setup();
        add_money("silver",5);        
	
}
