inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name(HIY"漩氣丹"NOR,({"whirlpool pill","pill"}));
        set("long",
"邪靈界的產物之一，\n");
	set("unit","堆");
        set("base_unit", "隻");
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
        message_vision("$N吞食了一顆$n，體內不斷的散發出惡臭味。\n",me,ob);
	me->delete_temp("evil/water/killed");
        add_amount(-1);
        return 1;

}
