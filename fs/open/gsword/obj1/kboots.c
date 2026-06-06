#include <armor.h>
#include <ansi.h>
inherit BOOTS;
object me=this_player();
void create()
{
        set_name(HIY + "劍聖戰靴" + NOR,({"kensai boots","boots"}) );
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
                set("unit","雙");
                set("value",0);
                set("armor_prop/armor",12);
                set("armor_prop/dodge",10);
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);

        set("no_drop",1);
        set("no_get",1);
                set("armor_prop/move",10);
                set("material","steel");
                set("long","此鞋為一種不知名的材料所製成。\n");
                set("wear_msg","$N穿上$n頓時感到身上重量減輕許\多。\n");
                setup();
        }
}
