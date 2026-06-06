inherit EQUIP;

void create()
{
        set_name("龍睛寶戒",({"dragon_eye ring","ring"}) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","在戒指的中央鑲上西域破邪洞窟內黃甲金龍的眼珠。\n");
        set("unit","件");
        set("value", 40000);
        set("material","gem");
        set("no_auc",1);
        set("no_give",1);
        set("armor_type","finger");
        set("wear_msg","戴上$n之後，$N的身上開始產生金龍的鬥氣。\n");
        set("armor_prop/move", -3);
        set("armor_prop/dodge", -3);
        set("armor_prop/armor", 10);
        }
        setup();
}        
