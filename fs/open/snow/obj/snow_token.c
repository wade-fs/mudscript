inherit ITEM;
#include <ansi.h>
void create()
{
     set_name(HIC + "雪泉聖物" + NOR,({"snow token"}));
            set("long","這是要雪泉的聖物﹐相傳要有雪泉聖物才能進入雪泉。\n");
      set("unit","件");
     set("value",10000);
        setup();
}
