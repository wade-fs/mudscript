inherit EQUIP;

void create()
{
        set_name("五彩銀絲窄襖", ({ "glow cloth", "cloth" }) );
        set_weight(2800);
        set("long", "
一件用上好棉料作成的衣服，外頭用五彩絲線繡了一隻麒麟，在靠近腰的
部份，還用銀絲穿了兩個雕飾精美的翡翠，走起路來還會發出叮叮噹噹的
聲音。

\n");
        set("unit", "件");
	set("value", 10000);
        set("material", "cloth");
        set("armor_type", "cloth");
	set("armor_prop/armor", 18);
	set("dodge",3);
        setup();
}
