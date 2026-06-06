// 藏經閣通行證b-mark.c的no_save版 by blazakira 2011/1/20
#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIY + "入閣令" + NOR, ({"book_mark","mark"}));
  set_weight(50);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit","面");
    set("long","一張入藏經閣的令牌!\n");
    set("no_get",1);
    set("no_auc",1);
    set("no_give",1);
    set("no_put",1);
    set("no_sell",1);
    set("no_sac",1);
    set("no_drop",1);
    set("no_save",1);
    set("no_steal",1);
  }
  setup();
}

int query_autoload()
{
    return 0;
}
