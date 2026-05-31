// shenliwan.c 美容丹

#include <ansi.h>
#include "check.h"

inherit ITEM;

void create()
{
	set_name(HIG "美容丸" NOR, ({ "meili wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一顆七彩的美容丸，據說吃了可以變美。\n");
                set("value", 10000);
		set("unit", "顆");
	}
}

void init()
{
    if(environment(this_object())==this_player())
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("你要吃什麼？\n");
        if( ! check_gift(this_player()))
          return 1;

        me = this_player();
        message_vision("$N一仰脖，吞下了一顆" + this_object()->name() +
                       "。\n", me);
        if (me->query("gift/perwan") >= 10)
        {
                message_vision("$N眨眨眼。\n", me);
                tell_object(me, "你覺得這藥沒啥味道，還不如花生好吃。\n");
        } else
        if (random(5) == 0)
        {
                tell_object(me, "不過你覺得好像沒什麼作用。\n");
        } else
        {
                tell_object(me, HIR "你覺得似乎自己變美了一些。\n" NOR);
                me->add("per", 1);
                me->add("setgift/per",1);
        }

        me->add("gift/perwan", 1);
        destruct(this_object());
	return 1;
}
