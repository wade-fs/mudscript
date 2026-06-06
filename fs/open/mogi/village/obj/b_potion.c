//神秘藥水供玩家飲用,屬於特殊的道具......           made by eva  
inherit COMBINED_ITEM;
void create()
{
        set_name("藍色神秘藥水", ({"blue potion","potion"}) );
	set("long","藍色的液體反射出詭異的光芒, 完全不知如何製造的藥水.
聽說喝了會使傷口迅速復元, 但是卻不會回復生命力.\n");
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
	int max_kee,eff_kee;
        if( !arg )                      return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )     return 0;
        if( ob != this_object() )       return 0;
	message_vision("$N喝下一罐藍色神秘藥水.\n", me);
        max_kee = me->query("max_kee");
        eff_kee = me->query("eff_kee");
        eff_kee = eff_kee + 200;
        if( eff_kee > max_kee )
            eff_kee = max_kee;
	me->set("eff_kee",eff_kee);
	add_amount(-1);
        return 1;
}

              
                           
