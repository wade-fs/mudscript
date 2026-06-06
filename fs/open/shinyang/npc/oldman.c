
inherit NPC;

#include "base_victim.h"
void create()
{
        set_name("老人",({"old man"}));
        set("long","一個非常老的老人，襄陽城裡的年輕人都去當兵扺抗蒙古軍了。\n
");
        set("str",1);
        set("con",1);
        set("cor",1);
        set("int",1);
        set("max_kee",5);
        set("max_gin",5);
        set("max_sen",5);
        set("age",64);
        set("combat_exp",0);
        setup();
}
