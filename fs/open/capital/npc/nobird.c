
inherit NPC;

void create()
{
        set_name("太監", ({ "nobirdman", "man" }) );
        set("long",
                "這是在皇城裡的一位太監﹐平常就跟隨在皇帝或妃子旁服侍, \n
"
                "長得一副怪裡怪氣陰沈沈的一樣子, 一看就知道一定不是啥\n
"
                "好東西。\n");

        set("attitude", "heroism");
	set("class","officer");
        set("vendetta_mark", "authority");
        set("pursuer", 1);

        set("str", 20);
        set("cor", 21);
        set("cps", 21);

	set("combat_exp",4608);

	set("random_move",3);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "太監喝道﹕你是什麼人!?竟敢在皇城禁內鬧事! \n",
                "太監喝道: 我可是太監中功\夫最厲害的一位, 你簡直找死!!\n"
        }) );

        set_skill("unarmed", 30);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_skill("move", 35);

        set_temp("apply/attack", 35);
        set_temp("apply/defense", 35);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 35);
        set_temp("apply/move", 35);

        setup();

        carry_object("/obj/cloth")->wear();
}

