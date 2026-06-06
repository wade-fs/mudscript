// keeper.c

inherit NPC;

void create()
{
        set_name("商店老闆", ({ "keeper" }) );
        set("long",
                "本店的老闆，原本哈哈大笑與另一位客人聊天的，但在你進來之後
臉色就變得相當難看。\n");

        set("race", "人類");
        set("gender", "男性");
        set("age", 41);
        set("limbs", ({ "頭部", "身體", "左手", "右手", "左腳", "右腳" }) );

        set("str", 17);
        set("cor", 15);
        set("cps", 22);

		set("combat_exp", 60000);
        setup();
        set("inquiry", ([
            "桃花源"   : "...哼！\n",
			"規矩"     : "哼哼......\n",
			"寶物"     : "哼...\n",
			"玲玲"     : "......哼。\n",
			"傳說"     : "哼！！\n",
			"村長"     : "......\n",
			"水井"     : "？？\n",
		]) );

}

void init()
{
	add_action("do_no","list");
	add_action("do_no","buy");
	add_action("do_no","sell");
	add_action("do_no","value");
	add_action("do_no","view");
	::init();

	return;
}

int do_no( string arg )
{
	command("say 滾！我從不賣給外地人。");
    return 1;
}

