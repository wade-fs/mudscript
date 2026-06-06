
#include <armor.h>
#include <ansi.h>
inherit WAIST;
object me=this_player();
void create()
{
    set_name(HIY"劍聖腰帶"NOR, ({"kensai belt","belt"}) );
    set_weight(1000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("unit", "付");
            set("material", "leather");
            set("value", 0);
            set("long","不知名布料所織~此乃劍神所傳..無法知道如何織成..。\n");
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
       set("no_drop",1);
        set("no_get",1);
            set("wear_msg", MAG"$N把$n繫在腰上，陣陣神力逐漸往$N聚集。\n");
     }
            setup();
this_object()->set("armor_prop/sword",5);
            this_object()->set("armor_prop/dodge",7);
            this_object()->set("armor_prop/attack",6);
            this_object()->set("armor_prop/armor",10);
            this_object()->set("armor_prop/parry",5);

}
