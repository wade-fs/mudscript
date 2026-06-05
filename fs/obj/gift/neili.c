// lingzhi.c 千年雪蓮
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        if(environment(this_object()) == this_player())
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR + "萬年雪蓮" + NOR, ({"xu lian", "lian"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("long", "這是一棵武林人士夢寐以求的萬年雪蓮，據說吃一棵可得100內力上限。\n");
                set("value", 0);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("你要吃什麼？\n");

        if(this_player()->query("max_force")+500 > 5000)
          this_player()->set("max_force",5000);
        else
        this_player()->add("max_force", 100);
        this_player()->add("force",100);
        message_vision("$N吃下一棵萬年雪蓮，只覺得自己的內力變厲害了一些 !\n", this_player());
        destruct(this_object());
        return 1;
}

