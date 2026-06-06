// bento.c

inherit ITEM;

void create()
{
	set_name("便當",({"bento"}));
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	  set("long","一盒香噴噴的便當，令你不禁食指大動。\n");
	  set("unit","盒");
	  set("食物", ([
                        "剩" : 1,       // 可以吃幾口
                        "供應": 50,     // 每一口填飽肚子的量
          ]) );
	}
	setup();
}

int finish_eat()
{
	set_name("便當盒",({"bento box","box"}));
	set_weight(150);
	set("unit","個");
	set("long","一個空空的便當盒。\n");
	return 1;
}

int do_eat(string arg)
{
	object who;
	who = this_player();

	// 一定要是自己去拿的便當才可以吃，以免有人幫別人拿
	if( !who->query_temp("bento") )
		return notify_fail("人家的便當你吃什麼吃？\n");
	if( who->query_temp("eating") )
		return notify_fail("嘿嘿....吃一個就夠了吧！\n");
	who->set_temp("eating", 1);

	return 1;
}
