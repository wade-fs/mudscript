#include <ansi.h>

inherit NPC;

void create()
{
        set_name("衙門守衛", ({ "hall garrison", "hall", "garrison" }) );
        set("long",
                "這是個正在執行公務的縣城官兵﹐雖然和許\多武林人物比起來﹐官兵\n"
                "們的武功\實在稀鬆平常﹐但是他們是有組織、有紀律的戰士﹐誰也不\n"
                "輕易地招惹他們。\n");

        set("attitude", "peaceful");
//      set("vendetta_mark", "authority");
        set("pursuer", 1);

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

	set("combat_exp",11955);

        set("chat_chance", 10);
        set("chat_msg", ({
                "衙門守衛說: 唉～真無聊...\n",
                "衙門守衛說: 整天呆在這裡, 真悶死人了! 好想去吃刷羊肉喔!\n",
                "衙門守衛說: 真羨慕那些可以出去抓兇手的弟兄們...\n",
		"衙門守衛說: 真無聊，上次有個人拿份地圖來問我一個叫哭什麼坡的。\n"+
		"衙門守衛說: 雖然我跟他標了個記號, 可惜他依然找不到是在哪兒。\n",
        }) );

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "衙門守衛喝道: 還不快放下武器束手就縛﹖\n",
                "衙門守衛喝道: 大膽刁民竟敢拒捕﹖反了﹗反了﹗\n"
        }) );
	
	set("inquiry", ([
	  "thief" : "想抓賊嗎? 跟咱們無塵大人詢問吧。",
	]));
	  
        set_skill("unarmed", 70);
        set_skill("sword", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("move", 100);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/longsword")->wield();
}
