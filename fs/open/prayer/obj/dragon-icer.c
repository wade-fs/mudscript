#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
     set_name( "龍之冰燄菱",({"dragon-icer","icer"}) );
     set_weight(12000);
     if( clonep() ) 
            set_default_object(__FILE__);
     else {
            set("long","徒手型武器，係以埋在萬年不化雪石下的精鋼打造而成，套在手上除
	    了增強攻擊力之外，更可以使你在戰鬥中冷靜地判斷敵人的攻勢。\n");
            set("unit", "把");             
            set("value",20000);
            set("material","steel");
            }
            init_unarmed(75);
 
          setup();
}                   
