
inherit NPC;

#include "base_victim.h"
void create()
{
        set_name("婦女",({"woman"}));
        set("long","一個年輕的婦女。\n
");
        set("str",1);
        set("con",1);
        set("cor",1);
        set("int",1);
        set("max_kee",5);
        set("max_gin",5);
        set("max_sen",5);
        set("age",25);
        set("combat_exp",0);
        setup();
}
