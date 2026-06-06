// guard.c by oda

#include "/open/open.h"

inherit NPC;

void create()
{
	set_name("守衛嘍嘍", ({ "guard" }) );
	set("title", "惡人谷第二代小嘍嘍");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "badman");
	set("long", "你看到一個凶神惡煞的男子，正在小心翼翼的擔任警戒的工作。\n");
	setup();
	carry_object(BAD_OBJ"blade")->wield();
}
