inherit EQUIP;

void create()
{
        set_name("速度戒指",({"speed ring","ring"}) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","西域破邪洞窟內特產的寶石所製成，戴上後會在你身邊產生氣流，使你的移動速度加快。\n");
        set("unit","件");
        set("value", 10000);
        set("material","gem");
        set("no_sell",1);
        set("armor_type","finger");
        set("armor_prop/move",3);
        set("armor_prop/dodge",3);
        set("armor_prop/armor", -5);
        }
        setup();
}        
