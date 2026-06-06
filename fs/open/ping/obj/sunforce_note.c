// 一陽心法秘笈...學一陽心法中的 exert 招式才有用...不能 study..:P 

inherit ITEM;

void create()
{
	set_name("一陽心法秘笈", ({ "sunforce note","note" }));
	set_weight(100);
	if( clonep() )
	  set_default_object(__FILE__);
	else 
	{
	  set("unit", "本");
	  set("long","這是由柳毅風所尋回的, 裡頭記載了一陽心法的秘密, 可惜你完全看不懂。\n");
          set("value", 0);
	  set("material", "paper");
	  set("skill", ([
	  "name" : "sunforce",
	  "sen_cost" : 100,
          "max_skill": 1
	  ]) );
	}
}

int valid_learn(object me)
{
	return -1;
}                          
