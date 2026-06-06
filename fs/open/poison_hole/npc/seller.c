//vendor.c
#include "/open/open.h"
inherit F_VENDOR;

void create()
{
	set_name("小販",({"vendor"}));
	set("gender", "男性" );
	set("age", 27);
set("long", @LONG
四處設攤賣些小東西的人,你可以列出(list)他賣些什麼...
LONG
	);
	set("combat_exp",800);
        set("attitude", "friendly");
        set_skill("dodge", 25);
        set_skill("hammer", 17);
        set_skill("parry", 27);
	set("vendor_goods", ({
                COMMON_OBJ"bandage",
               CAPITAL_OBJ"tea",
                resolve_path(__DIR__,"../obj/rope")
	}) );
	setup();
	add_money("coin",35);
}

void greeting(object ob)
{
  int rand ;
string *msg = ({
    "你們想上山啊，我會賣你們有可能用到的東西哦！\n",
    "我這裡有賣各種東西哦！\n",
    "再上去就沒有任何地方賣茶水哦，你可以從我這裡買一點。\n"
    });
rand = random(sizeof(msg));
say(this_object()->query("name")+"說道："+msg[rand]);

}
