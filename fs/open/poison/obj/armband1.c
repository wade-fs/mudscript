inherit EQUIP;
#include <ansi.h>

void create()
{
        set_name(HIY + "神龍金環 " + NOR,({"dragon gold armband","armband"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","相傳此環乃由神龍的鱗片燒鑄而成 ,擁有很好的防禦率 .");
        set("unit","個");
        set("value",2750);
        set("material","steel");
        set("armor_type","armbands");
        set("wear_msg","$N戴上$n，身上頓時被一片龍氣籠罩！\n");
        set("unequip_msg","$N脫下$n之後，$N的龍氣逐漸消失。\n");
        set("armor_prop/armor", 9);
        set("armor_prop/force", 10);
        set("armor_prop/parry", 10);
        }
        setup();
}
