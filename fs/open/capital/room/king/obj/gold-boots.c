inherit EQUIP;

void create()
{
        set_name("金瑣戰靴",({"gold boots","boots"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "
由一片片呈六角形的黃金鎖片鑲接成的戰靴，相傳必須由沈埋地底六甲子
的礦質元素，才能提煉出這種人間罕見的裁質。
\n");
        set("unit","件");
	set("value",3000);
        set("material","crimsonsteel");
        set("armor_type","boots");
	set("armor_prop/armor", 2);
	set("armor_prop/dodge", 5);
        }
        setup();
}
