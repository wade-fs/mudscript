//雙麒麟火琉璃------by dhk 2000.4.9
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("" + HIC + "雙麒麟" + HIR + "火琉璃" + NOR + "", ({ "fire colored glaze","glaze" }) );
    set_weight(100);
 if( clonep() )
    set_default_object(__FILE__);
 else {
       set("long", "這是一件記載在〝" + HIB + "況古奇物大全" + NOR + "〞中" + WHT + "鬼斧神工篇" + HIC + "─" + NOR + "四大奇珍之一。\n");
       set("unit", "件");
       set("value", 1500000000);
       set("no_auc",1);
       set("no_get",1);
       set("no_drop",1);
       set("no_sell",1);
      }
    setup();
}
