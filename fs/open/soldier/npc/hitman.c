#include "/open/open.h"
inherit NPC;
void create()
{
    set_name("打飯兵", ({ "hitman" }) );
    set("title", "反亂軍");
	set("gender", "男性");
    set("long", "這是反亂軍中蠻重要的職位,沒有他們大家都沒飯吃。\n");
    set("age",21);
	set("attitude", "heroism");
	set("kee",400);
	set("max_kee",400);
    set("combat_exp",800);
	setup();
}
