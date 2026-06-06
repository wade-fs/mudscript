inherit NPC;
#include <ansi.h>
#include "wind-rain.h"
void create()
{
	set_name("庭園侍女",({"girl"}));
	set("long","
負責整理庭園中花花草草的
婢女, 她正在認真的維持金
風細雨樓的整潔體面.
");
	set("gender","女性");
	set("combat_exp",13000);
	set("attitude","peaceful");
	set("age",25);
	set("class","soldier");
	set("str", 30);
        set("cor", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
        set("max_kee",800);
	set_skill("dagger",5);
	set_skill("dodge",5);
        set_skill("move",5);
        
        set("chat_chance", 5);
	set("chat_msg", ({
	"\n庭園侍女說 : 請不要亂丟垃圾好嗎？人家昨天晚上玩太晚現在很累耶:(\n",
        "\n庭園侍女說 : 告訴你，愛可以多做，花不可亂折。\n",
	}));
        //carry_object(C_OBJ"/dagger-1")->wield();
        
	setup();
	add_money("silver",10);
}

