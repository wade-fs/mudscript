#include "/open/open.h"
inherit NPC;
void create()
{
    set_name("一等哨兵", ({ "sentry" }) );
    set("title", "反亂軍");
	set("gender", "男性");
    set("long", "這是站在裡面專門堪察敵人動態的士兵。\n");
  set("age",22);
	set("attitude", "heroism");
	set("kee",450);
	set("max_kee",450);
    set("combat_exp",7000);
    set_skill("dodge",15);
	setup();
}
