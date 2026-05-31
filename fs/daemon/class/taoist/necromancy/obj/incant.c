
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("爆裂符咒",({"incant"}));
       
        set("long",
                "一張符咒，上面畫了一些奇怪的文字。\n");
        set("unit", "張");
 
        set("value", 1);
        set("weight", 1);
      
        setup();     
}
