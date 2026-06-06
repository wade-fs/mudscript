// juju5.c by konn
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW + "九字真言之「皆」字訣" + NOR,({"juju 5","juju"}));
        set_weight(50);
        if(clonep())
                set_default_object(__FILE__);
        else {
           set("long",
"這是一張極稀有的符紙, 符上畫了一些奇怪的符號及文字, 頂端寫著一個\n"+
"大大的紅字 -- 「皆」, 相傳這是避邪納福所用的符紙, 只有茅山道士才\n"+
"會有這種東西, 不知為何流傳了出來。\n");

           set("unit", "張");
           set("light_up", -1);
           set("no_drop", 1);
           set("no_sell", 1);
           set("no_give", 1);
        }
        setup();
}

int query_autoload() { return 1; }
