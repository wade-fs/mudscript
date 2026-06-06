#include <ansi.h>

inherit NPC;

void create()
{
        set_name("山賊頭頭", ({ "bandit king", "bandit", "king"}) );
        set("long",
             "山賊的頭頭,在下山搶劫行動中失敗了,回山寨的時候,無意間走到此處卻迷路了,雖然派人去找出路,可是內心的緊張還是完全的表露在臉上。\n");
        set("attitude", "heroism");

	set("combat_exp", 12975);
        set("chat_chance",6);
	set_skill("sword",60);
	set_skill("dodge",60);
	set_skill("parry",60);
	set("random_move",4);
       set("chat_msg",({
          (:this_object(),"random_move":),
}));
        setup();
	carry_object("/obj/longsword")->wield();
}
