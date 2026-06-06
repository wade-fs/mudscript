inherit ITEM;
#include <ansi.h>
void create()
{
    set_name("黑翼石"NOR,({"blackstone"}));

    set("long","表面油黑不透光的一顆寶石，似近無止盡的黑洞要將你的靈魂吸入一般。\n");
    set("unit","顆");
     set("value",10000);
     set("no_sell",1);
     setup();
}
