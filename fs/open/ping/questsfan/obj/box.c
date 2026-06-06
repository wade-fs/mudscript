//雲霞寶盒------by dhk 2000.4.22
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(""HIC"雲"HIM"霞"HIY"寶盒"NOR"", ({ "cloud rosyclon box","box" }) );
    set_weight(1200);
 if( clonep() )
    set_default_object(__FILE__);
 else {
       set("long", "這是一只泛出白光紅紫色又帶點透明的寶盒，這就是傳說裡\n"
                  +"面裝有名曰"HIC"『"WHT"黑暗的禁忌"HIC"』"NOR"的神劍。相傳它被置於寶盒已越\n"
                  +"千年。跟據古書記載寶盒總共只有被打開過三次，非常神秘\n"
                  +"。\n");
       set("unit", "只");
       set("value", 150000);
       set("no_auc",1);
      }
    setup();
}
