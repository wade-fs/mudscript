inherit NPC;

#include "base_victim.h"
void create()
{
        set_name("孩童",({"child"}));
        set("long","一個五、六歲的孩童，還在城裡跑來跑去，彷彿不知道發生了什事。\n
");
        set("str",1);
        set("con",1);
        set("cor",1);
        set("int",1);
        set("max_kee",5);
        set("max_gin",5);
        set("max_sen",5);
        set("age",5);
        set("combat_exp",0);
        setup();
}
