//虹晶礦石------by dhk 2000.4.22
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("" + HIR + "虹" + HIC + "晶" + HIY + "礦" + HIG + "石" + NOR + "", ({ "hon diamond stone","stone" }) );
    set_weight(100);
 if( clonep() )
    set_default_object(__FILE__);
 else {
       set("long", "這種礦石名曰『虹晶』是當年由一代武器大師─北勝天，歷經千辛萬苦\n"
                  +"走片大江南北所找到的奇石。它若製成武器能百分百的傳遞使用者的內\n"
                  +"力，做最有效的攻擊。它產於晶谷。\n");
       set("unit", "塊");
       set("value", 1500000000);
       set("no_give",1);
       set("no_auc",1);
       set("no_sell",1);
       set("no_drop",1);
       
      }
    setup();
}
