inherit NPC;

void create()
{
	set_name("平西大將軍  左正", ({ "General Zuozhen","general"}));
	set("race", "人類");
	set("age", 68);
	set("long",
"一個身長八尺孔武有力的大漢，當年曾率一支八千人的部隊孤軍
遠征西域，平定西方四十餘國，威震八方，並建立了現在的蜀中
城．雖然已逐漸年邁，但你可不要小看他，他那一手獨一無二的
左氏迴風劍可也不是好惹的喔！！
\n");
        set("str", 45);
	set("cor", 30);
        set("max_kee",670);
        set("kee",670);
	set("chat_chance", 30);
 	set("chat_msg", ({
		"平西大將軍 左正伸了一個懶腰。\n",
		"平西大將軍 左正拔出劍來仔細端詳。\n",
		"平西大將軍 左正打了個噴涕。\n" }) );
	set("inquiry",([
             "搜索令" : "你是甚麼東西啊...敢向本府索取?",
	     "左氏迴風劍" : "只是從仙劍劍法化出來的劍法。",
	     "柳毅風" : "柳大俠目前在哪我並不清楚, 這事師爺才知道。",
	     "liu"    : "柳大俠目前在哪我並不清楚, 這事師爺才知道。",
	     ]));
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 5);     	
        set_skill("parry", 5);
        set_skill("sword", 5);
        set_skill("unarmed", 60);
        set_skill("dodge", 5);
        set_skill("shasword", 45);
        set_skill("linpo-steps", 5);
        map_skill("dodge","linpo-steps");
        map_skill("sword","shasword");
	set("combat_exp",50000);
        setup();		
        carry_object("/open/gsword/obj/no_tax");
        carry_object("/open/gsword/obj/windsword.c")->wield();
        carry_object("/open/gsword/obj/ring-1")->wear();
        carry_object("/open/gsword/obj/boots")->wear();
        carry_object("/open/gsword/obj/officer_suit.c")->wear();
        add_money("silver",50);

}
int accept_kill(object who)
{
    command("wear all");
    command("fight");
    return 1;
}
int accept_fight(object who)
{
    command("wear all");
    command("kill");
    return 1;
}                
