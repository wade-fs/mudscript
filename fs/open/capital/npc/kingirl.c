
inherit NPC;

void create()
{
        set_name("宮女", ({ "Castle lady", "lady" }));
        set("long",
                "這是在皇城裡的一位宮女,平常跟隨在皇帝或妃子身旁服侍, \n
"
                "她正面帶微笑的看著你,眼神中露出懷疑的眼神,懷疑你為什\n
"
                "麼會在這裡出現 \n");


	set("gender","女性");
         set("age", 22);
	set("str",18);
	set("cor", 18);
	set("cps", 18);

	set("combat_exp",3200);


        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "宮女喊道 : 救命啊!!有刺客啊!! \n",
                "宮女喊道 : 快來人啊~~~~這邊有來路不明的人!! \n",
        }) );

        set_skill("unarmed", 30);
        set_skill("parry", 40);
        set_skill("dodge", 40);
	set_skill("move", 40);


        setup();

	carry_object("/open/capital/obj/silk_cloth2")->wear();
}

