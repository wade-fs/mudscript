#include "/open/open.h"
inherit NPC;
void create()
{
        set_name("山寨守衛", ({ "guard" }) );
	set("gender", "男性" );
	set("age", 25);
	set("long", @LONG
山寨守衛在這裡負責進出人員的檢查.
想進入山寨?先問問他吧!
LONG);
	set("attitude","heroism");
        set("combat_exp",100000);
         set_skill("dodge",60);
	set_skill("blade",60);
	set_skill("parry",50);
	set_skill("unarmed",60);
	set("chat_chance",10);
	set("chat_msg",({
	}));
	set("greeting_msg", ({
            "山寨守衛大喝 : 站住!! 你是什麼人? 在這裡鬼鬼祟祟的!!\n",
	    	}) );
	setup();
        carry_object("/open/ping/obj/guard_blade")->wield();
        add_money("gold",1);
	
}
