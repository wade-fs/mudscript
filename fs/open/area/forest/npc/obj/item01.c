inherit ITEM;

void create()
{
	set_name("野人盒子",({"wild's box", "box"}));
	set("long","一個長方形的木製盒子，裡面放著野人的服飾跟一張野人面膜。
(wear box)你可以穿上它變成野人的模樣。\n");
	set("unit","個");
	set("weight",100);
	set("value",100);
	if ( clonep() )
		set_default_object(__FILE__);
	setup();
}

void init()
{
add_action("do_wear","wear");
}

int do_wear(string arg)
{
object me,box;
	me = this_player();
	box = this_object();
	if(!arg)
		return 0;
	if(arg!="box")
		return 0;
	message_vision("$N打開$n，將裡面的服飾跟面膜帶上。\n",me,box);
	me->set_temp("wild/mask",1);
	destruct(box);
return 1;
}
	
