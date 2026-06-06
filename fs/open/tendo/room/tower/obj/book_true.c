//失落天書....不能study
inherit ITEM;
void create()
{
	set_name("天書", ({ "book" }));
	set_weight(100);
	if( clonep() )
	  set_default_object(__FILE__);
	else 
	{
	  set("unit", "本");
	  set("long","這就是失落的天書, 可惜你完全看不懂。\n");
          set("value", 0);
	  set("material", "paper");
	  set("true",1);
	}
}
int valid_learn(object me)
{
	return -1;
}                          


