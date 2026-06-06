inherit EQUIP;

void create()
{
        set_name("混銀戰袍",({"silver robe","robe"}) );
	set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
奪目閃耀的銀色光澤，緊緊地裹住戰袍表面，這是以精鋼絲編織為底，再
以水銀浸溶製造而成的，細韌的鋼絲與漾然的水銀，使得戰袍在堅實之中
仍賦輕靈。
\n");
        set("unit", "套");
        set("value",3000);
        set("material","steel");
        set("armor_type", "cloth");
	set("armor_prop/armor",12);
        set("armor_prop/dodge", 2);
        }
        setup();
}
