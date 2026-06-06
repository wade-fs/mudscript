inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name(HIY + "骨蠱蛹" + NOR,({"bon-gu pupa","pupa"}));
        set("long",
"邪靈界的產物, 以萬蠱相鬥的道理, 找出所有蠱種最強的蠱蟲, 然後使用密法
將其退化成可食用的蠱蛹, 每種蠱蟲都有不同的用法, 此種蠱蛹服食後, 生長
於服食者體內, 其成長成蠱蟲時, 會散發出一種惡臭, 可以避免受到一些潛藏
的蟲類攻擊。\n");
	set("unit","堆");
        set("base_unit", "顆");
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
		i = (int)me->query_condition("evil_pill01");

        if( !arg )
		return 0;

        arg=lower_case(arg);
        if( !ob = present(arg,me) )
		return 0;
        if( ob != this_object() )
		return 0;
        message_vision("$N服食了一顆蟲蛹。\n",me);
	me->apply_condition("evil_pill01", i+5);
        add_amount(-1);
        return 1;

}
