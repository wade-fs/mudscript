inherit EQUIP;

void create()
{
        set_name("金絲戰袍",({"gold robe","robe"}) );
	set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
由纖細的金絲與柔軟的天蠶絲交織而成，是一件兼具防護與輕柔的絕佳戰
袍，金碧輝煌的外觀，更令人為之炫然三尺。
\n");
        set("unit", "套");
        set("value",10000);
        set("material","crimsonsteel");
        set("armor_type", "cloth");
	set("armor_prop/armor",15);
	set("armor_prop/dodge", 5);
        }
        setup();
}
