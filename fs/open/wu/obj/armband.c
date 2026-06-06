
// sun_armband.c

inherit EQUIP;

void create()
{
        set_name("陽炎臂環 ",({"Sun Fire Armband","armband"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","用赤嶙金製成的臂環, 上面鑲有一顆陽炎石, 相傳唯有拳聖才有資格配戴此臂環");
        set("unit","個");
        set("value",1750);
        set("material","crimsonsteel");
        set("armor_type","armbands");
        set("armor_prop/armor", 8);
        set("armor_prop/unarmed", 10);
        set("armor_prop/force", 10);
        set("armor_prop/dodge", 10);
        }
        setup();
}
