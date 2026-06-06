inherit EQUIP;

void create()
{
	set_name("青銅戰袍",({"bronze robe","robe"}) );
	set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
以極細的鋼絲編織而成的長袍，再熔以沸騰的液態青銅漿，將鋼絲間所遺
留的縫隙彌足。蒼鬱的古銅色外觀，反射著黯黯的黃色光澤。
\n");
        set("unit", "套");
	set("value",1000);
        set("material","steel");
        set("armor_type", "cloth");
        set("armor_prop/armor",7);
        set("armor_prop/dodge", 1);
        }
        setup();
}
