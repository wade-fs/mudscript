// teacher.c

inherit NPC;

void create()
{
	set_name("魏無極", ({ "teacher", "wey" }) );
	set("title", "教書先生");
	set("gender", "男性" );
	set("age", 47);
	set("int", 26);
	set("long",
		"魏無極是個博學多聞的教書先生﹐他年輕時曾經中過舉人﹐但是\n"
		"因為生性喜愛自由而不願做官﹐魏無極以教書為業﹐如果你付他\n"
		"一筆學費﹐就可以成為他的弟子學習讀書識字。\n");
	set("inquiry", ([
		"學費": "嗯....知識是無價的﹐不過如果你有心的話──只要五兩銀子。\n",
		"讀書識字": "對﹐讀書識字。",
	]) );
	set("attitude", "peaceful");
	set_skill("literate", 40);
	setup();
}

int recognize_apprentice(object ob)
{
	if( !ob->query("marks/魏無極") ){
		say("魏無極說道﹕咦﹖我不記得收過你這個學生啊....\n");
		return 0;
	}

	return 1;
}

int accept_object(object who, object ob)
{
	if( !who->query("marks/魏無極") ) {
		if( ob->value() >= 500 ) {
			say("魏無極點了點頭﹐說道﹕很好﹐從今天起你隨時可以來問我有關讀書識字(literate)\n"
				"                      的任何問題。\n");
			who->set("marks/魏無極", 1);
			return 1;
		} else {
			say("魏無極說道﹕你的誠意不夠﹐這錢還是拿回去吧。\n");
			return 0;
		}
	} else
		say("魏無極點了點頭﹐說道﹕哦﹐向你這麼有心的學生還真是不多見﹐好好努力\n"
			"                      將來必定前途無量﹐謝了。\n");
	return 1;
}
