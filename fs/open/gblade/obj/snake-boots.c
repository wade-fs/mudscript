inherit EQUIP;

void create()
{
        set_name("蛇靴",({"snake boots","boots"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "
由金麟莽蛇皮所縫製而成的，表面閃爍著或白或金的麟光，柔軟的裁質讓
你穿上之後，行動變得快捷靈動。
\n");
        set("unit","件");
        set("value",600);
        set("material","cloth");
        set("armor_type","boots");
	set("armor_prop/armor", 2);
        set("armor_prop/dodge", 2);
        }
        setup();
}

