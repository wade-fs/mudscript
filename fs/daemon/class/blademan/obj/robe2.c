inherit EQUIP;

void create()
{
         set_name("紫貂昭君襖",({"girl robe","robe"}));
     set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
相傳是昭君出塞時所穿的仿品，是由紫貂皮混以銀絲而製成，美觀又舒適。
\n");
        set("unit", "套");
        set("value",10000);
 set("material","cloth");
        set("armor_type", "cloth");
     set("armor_prop/armor",10);
      set("armor_prop/dodge", 4);
      set("armor_prop/parry",5);
        }
        setup();
}
