// lingzhi.c 冰糖葫蘆
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIM"冰糖葫蘆"NOR, ({"ling zhi", "zhi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("long", "這是一棵武林人士夢寐以求的冰糖葫蘆，據說吃一棵可得2000經驗，1000潛能。\n");
                set("value", 0);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("你要吃什麼？\n");

        this_player()->add("combat_exp", 2000);
        this_player()->add("potential",1000);
        message_vision("$N吃下一串冰糖葫蘆，只覺得自己又變厲害了一些 !\n", this_player());
        destruct(this_object());
        return 1;
}

