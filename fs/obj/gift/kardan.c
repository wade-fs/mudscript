// hobowdan.c 荷包蛋
#include <ansi.h>
#include "check.h"
inherit ITEM;

void setup()
{}

void init()
{
        if(environment()==this_player())
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIY + "貢品" + NOR, ({"gon pon", "pon"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "片");
                set("long", "這是信徒給土地公的貢品，傳言中，吃了貢品會增加好運呢。\n");
                set("value", 0);
        }
        setup();
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
        if (me->query("gift/gonpondan") >= 5)
        {
                message_vision("$N搖搖晃晃的，突然「啪嗒」一下子摔了個跟頭。\n", me);
                tell_object(me, "你覺得吃完以後頭重腳輕的。\n");
        } else
        if (random(5) == 0)
        {
                tell_object(me, "不過你覺得好像沒什麼作用。\n");
        } else
        {
                tell_object(me, HIM + "霎時間你覺得運氣增加百分百，一個開心就暈了過去。\n" + NOR);
                me->add("kar", 1);
                me->add("setgift/kar",1);
                me->unconcious();
        }

        me->add("gift/gonpondan", 1);
        destruct(this_object());
        return 1;
}

