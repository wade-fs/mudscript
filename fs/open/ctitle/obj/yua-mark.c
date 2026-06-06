inherit ITEM;
#include <ansi.h>

void create()
{
    set_name("" + HIB + "『" + HIR + "拳" + HIB + "』" + NOR + "",({"yua-mark"}));

    set("long","三面拳的信物，為三面拳的傳人所有。對三面拳的傳人來說，見此信物如見到三面拳本人。
此信物共有三樣，分別為『三』『面』『拳』各為雷電、飛燕、月光三人所有。若你身上有此信物，或許\可以展示(reveal)給三面拳的傳人看。\n");
     set("unit","顆");
     set("no_sell",1);
     set("no_save",1);
     set("no_put",1);
     set("no_auc",1);
     set("no_get",1);
     set("no_give",1);
     set("no_drop",1);
     setup();
}
