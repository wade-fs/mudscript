
inherit NPC;

void create()
{
        set_name("守護者", ({ "man" }) );
        set("long", "他是新手的守護者。\n");
	set("gender","男性");
        set("age", 50);
	set("max_gin", 100000);
        set("max_kee", 100000);
	set("max_sen", 100000);
	set("gin", 100000);
	set("kee", 100000);
	set("sen", 100000);       
	set("chat_chance", 30);
	set("chat_msg", ({
                "守護者說道：歡迎光臨新手練功\區。\n",
                "守護者說道：在這個區域練功\要用雞腿練功\法喔。\n",
                "守護者說道：什麼叫雞腿練功\法？就是裝備雞骨頭來戰鬥賺取經驗值與淺能。\n",
                "守護者說道：那裡有雞骨頭？去買隻雞腿把肉吃掉不就有雞骨頭了。\n",
	}) );
		
        set("combat_exp", 1000000);
	setup();        
}
