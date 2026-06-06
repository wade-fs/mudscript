
inherit NPC;
void create()
{
set_name("鐵人",({"man"}) );
	set("gender", "男性" );
        set("age",45);
        set("str",35);
        set("cor",45);
	set("cps",25);
	set("int",15);
set("long","一個給你練習用的鐵人.\n"
                "他正忙著他的工作.\n");
set("combat_exp",10000);
	set("attitude", "peaceful");
set("max_kee",2000);
        set("chat_chance", 25);
set_skill("parry",30);
set_skill("unarmed",30);
set_skill("dodge",30);
	setup();
         	
}

