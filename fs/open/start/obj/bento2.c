// bento2.c

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
	}
	setup();
}

int do_eat(string arg)
{
	tell_object(this_player(), "你還吃啊？貪吃鬼！快送去給農夫吧。\n");
	return 1;
}
