// post_officer.c

inherit NPC;

string send_mail();
string receive_mail();

void create()
{
	set_name("杜寬", ({ "post officer", "officer" }) );
	set("title", "雪亭驛長");
	set("gender", "男性" );
	set("age", 43);
	set("long",
		"杜寬擔任雪亭驛的驛長已經有十幾年了﹐雖然期間有幾次升遷的\n"
		"機會﹐但是他都因為捨不得離開這個小山村而放棄了﹐雪亭鎮的\n"
		"居民對杜寬的風評相當不錯﹐常常會來到驛站跟他聊天。\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	set("inquiry", ([
		"驛站" : "是啊... 這裡就是雪亭驛﹐你要寄信嗎﹖",
		"寄信" : (: send_mail :),
		"收信" : (: receive_mail :),
	]) );
	set_skill("literate", 70);
	set_skill("dodge", 50);
	set_skill("unarmed", 40);
	setup();
	add_money("coin", 70);
}

string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱還在吧﹖用信箱就可以寄信了。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "真是抱歉﹐請您等一下到驛站來找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "哦... 要寄信是嗎﹖這是你的信箱﹐寄信的方法信箱上有說明。\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱還在吧﹖你所有的信都在裡面。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "真是抱歉﹐請您等一下到驛站來找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "好﹐待我找找....有了﹐你的信箱在這﹐慢慢看吧﹐不打攪你了。\n";
}
