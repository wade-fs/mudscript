//神秘藥水供玩家飲用,屬於特殊的道具......           made by eva  
inherit COMBINED_ITEM;
void create()
{
        set_name("紅色神秘藥水", ({"red potion","potion"}) );
	set("long","紅色的液體反射出詭異的光芒, 完全不知如何製造的藥水.
聽說喝了會快速回復你的精.\n");
        set("unit", "罐");
        set("base_unit", "罐");
        set("value",100000);
        set("base_weight", 150);
	set_amount(1);
	setup();
}

void init()
{
	if( this_player()==environment() )
	{
		add_action("drink_potion", "drink");
	}	
}

int drink_potion(string arg)
{      

        object ob,me=this_player();
	int eff_gin,gin;
        if( !arg )                      return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )     return 0;
        if( ob != this_object() )       return 0;
	message_vision("$N喝下一罐紅色神秘藥水.\n", me);
        eff_gin = me->query("eff_gin");
        gin = me->query("gin");
        gin = gin + 200;
        if( gin > eff_gin )
            gin = eff_gin;
	me->set("gin",gin);
	add_amount(-1);
        return 1;
}

              
                           
