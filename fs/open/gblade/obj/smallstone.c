inherit ITEM;
#include <ansi.h>
void create()
{
    set_name("小石頭",({"stone"}));
    set("long","一顆奇怪的石頭。\n");
    set("unit","顆");
    set("value",100);
    set("no_get",1);
    set("no_sac",1);
    set("no_auc",1);
    set_weight(500000);
        setup();
}
