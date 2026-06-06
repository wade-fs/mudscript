// guard.c

#include <ansi.h>

inherit NPC;
void create()
{
        set_name("左侍衛",({ "left guard","guard" }) );
	set("gender", "男性" );
        set("age", 45);
        set("str", 40);
        set("cor", 60);
	set("cps", 25);
	set("int", 15);
	set("long","將軍府的左侍衛,他正在值勤中.\n");
	set("inquiry",([
	    "搜索令" : "一張五百\n",
	    "薪水" : "將軍給的太少了,跟本不夠花.\n",
	    "靠官" : "就是有要用到官府的地方...\n",
	    ]));
	set("chat_chance", 10);
	set("chat_msg", ({
	    "左侍衛 說: 麵粉漲了,房租漲了,只有(薪水)老不漲.\n",
	    "左侍衛 說: 你在蜀中有要(靠官),找我就對了.\n",
	    }));   
        set("combat_exp", 6000);
	set("attitude", "peaceful");
        set("max_force", 350);
        set("force_factor", 10);
        set("force", 350);
        set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("dodge", 40);
        set_skill("snow-martial", 24);
        map_skill("dodge","snow-martial");
        map_skill("unarmed","snow-martial");
	setup();
	add_money("silver",20);
        carry_object("/open/gsword/obj/ring")->wear();
        carry_object("/open/gsword/obj/robe_3")->wear();
        carry_object("/open/gsword/obj/legging")->wear();
         	
}
int accept_object(object me,object ob)
{
    if( ob->value() < 500 )
    {
      say("左侍衛 說:搜索令一張 500...不二價,童叟無欺...\n");
      return 1;
    }
    new("/open/gsword/obj/su_note")->move(me);
    say("左侍衛給你一張搜索令.\n");
    return 1;
}
      
