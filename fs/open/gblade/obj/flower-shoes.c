inherit EQUIP;

void create()
{
        set_name("繡花鞋",({"flower shoes","shoes"}) );
	set_weight(300);
        set("gender_only", "女性");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "
手工細膩小巧的一雙繡花鞋，鞋面上繡著殷紅的花朵，旁邊綴著翠綠的葉
瓣，隱約間散發著一股幽香。
\n");
        set("unit","件");
        set("value",300);
        set("material","cloth");
        set("armor_type","boots");
	set("armor_prop/armor", 1);
        set("armor_prop/dodge", 1);
        }
        setup();
}
