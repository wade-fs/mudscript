inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name(HIB + "惡蠱卵" + NOR,({"evil-gu ovum","ovum"}));
        set("long",
"邪靈界的產物, 以萬蠱相鬥的道理, 找出所有蠱種最強的蠱蟲, 然後使用密法
將其退化成可食用的蠱卵, 每種蠱蟲都有不同的用法, 此種蠱卵服食後, 服食
者體內會產生一股令邪靈界蟲類厭惡的味道，使得蟲子退避三舍。\n");
	set("unit","堆");
        set("base_unit", "條");
	set("value",500000);
        set("base_weight", 50);
        set_amount(1);
        setup();
}

void init()
{
add_action("eat_pill", "eat");
}

int eat_pill(string arg)
{
        object ob,me;
	int i;

		me = this_player();
		i = (int)me->query_condition("evil_pill02");

        if( !arg )
		return 0;

        arg=lower_case(arg);
        if( !ob = present(arg,me) )
		return 0;
        if( ob != this_object() )
		return 0;
        message_vision("$N服食了一條蠱卵。\n",me);
	me->apply_condition("evil_pill02", i+5 );
        add_amount(-1);
        return 1;

}
