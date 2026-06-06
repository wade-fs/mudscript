// beggar.c
// first written by grand 9/30/1995
// fixed by wade

inherit NPC;

void create()
{
	set_name("乞丐", ({ "beggar" }) );
	set("race", "人類");
	set("age", 23);
	set("long", "一個渾身髒兮兮的乞丐，用乞求的眼光看著你.\n
	              你想起你是如此的殺孽罪重,不禁想幫他...\n ");
	set("str", 24);
	set("cor", 26);
	set("chat_chance", 15);
	set("chat_msg", ({
		"乞丐用手拉了拉你袖子。\n",
		"乞丐抱住你的腳﹐想討東西吃。\n",
		"乞丐對著你喃喃自語。\n" }) );
	set("inquiry", ([
	"thief" : "給我一些錢, 我就偷偷說與你聽。",
	]));
	set("combat_exp",256);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);

        setup();
carry_object("/obj/cloth")->wear();
}

void reset()
{
  delete("accept_object");
}

// 用總次數故定對某些玩家不公, 會無法學到, 改成一人只給一次機會
// reset 的時候或者死掉重生的時候清掉重來, fixed by wade 12/13/1995
int accept_object(object who, object ob)
{
	int b, value;
	if (!query("accept_object/"+who->query("id"))) {
	  b = who->query("bellicosity"); 
          if( (value=ob->value())  && b>0 ) {
		value = value/10;
		if (value < 1) value = 1;
		b = b - value;
		if (b < 0) b = 0;
	        who->set("bellicosity", b); 
		add("accept_object/"+who->query("id"), 1);
		write("你覺得罪孽洗清了一些.\n");
	  }
	}
	else
	  say ("謝謝! 謝謝!\n");
	destruct(ob);
        return 1;
}
