// kame_suit.c

inherit EQUIP;

void create()
{
        set_name("一品官服",({"officer suit","suit"}) );
        set_weight(5000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","這是朝廷正一品官服,你看上面繡著金絲祥鳳,及精美的錦繡花繪.\n");
        set("unit","件");
        set("value",25000);
	set("material","cloth");
        set("armor_type","cloth");
         set("armor_prop/armor", 20);
        set("armor_prop/dodge", 5);
        set("armor_prop/attack",3);
	}
        setup();
}
