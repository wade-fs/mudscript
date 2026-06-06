inherit EQUIP;

void create()
{
        set_name("虎骨護膝",({"tiger legging","legging"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","以邪虎骨骼為架, 加上皮革製成的護膝 , 能增強雙膝的防禦度 .\n");
        set("unit","件");
        set("value",6000);
        set("material","leather");
        set("armor_type","leggings");
        set("armor_prop/armor", 2);
        }
        setup();
}                        
