#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
     set_name( "金剛紅燄扣",({"emery-firer","firer"}) );
     set_weight(11500);
     if( clonep() ) 
            set_default_object(__FILE__);
     else {
            set("long","徒手型武器，係以紅炎礦石與鐵混製而成，套在手上可以
	    增強攻擊力，也可以使你在戰鬥中爆發出較多的潛能。\n");
            set("unit", "把");             
            set("value",10000);
            set("material","iron");
            }
            init_unarmed(45);
 
          setup();
}                   
