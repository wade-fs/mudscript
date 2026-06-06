inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIY + "鳳凰羽毛" + NOR,({"phoenix feather","feather"}));
    set("long","一根亮麗的羽毛。\n");
    set("unit","根");
    set("value",10000);
        set("no_auc",1);
        set("no_put",1);
        set("no_drop",1);
    setup();
}

