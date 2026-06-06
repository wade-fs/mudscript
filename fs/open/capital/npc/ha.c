inherit NPC;

void create()
{
	set_name("副總管 哈常", ({ "master ha","master","ha" }) );
	set("race", "人類");
	set("age", 40);
	set("gender", "男性");
	set("long",
"哈常是乾通天在年少結交的夥伴, 這麼多年來, 在乾通天的身旁不知做了多少大大"+
"小小的事, 因此當乾通天發達後, 便派給他這麼一個涼差, 以感謝其辛勞。\n"
            );
        set( "inquiry", ([
             "name" : "在下哈常, 不知閣下有何指教。",
             "乾通天" : "他是我一生中最佩服的人了。",
             		]));
	set("str",22);             

	set("attitude", "friendly");
        set_temp("apply/attack", 50);
        set("combat_exp",10484);
	setup();
        add_money("silver",10);
        
}

