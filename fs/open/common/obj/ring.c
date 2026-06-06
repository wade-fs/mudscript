inherit EQUIP;

void create()
{
        set_name("結婚戒指", ({ "wedding ring", "ring"  }) );
        set("unit", "只");
        set("long", "象徵永恆堅定的結婚戒指，獻給這受上天祝福的兩人。\n");
	set("armor_type", "finger");
	set("armor_prop/armor", 5 );
	set("material", "pearl");// 相當於 ??, 對重量跟價值有用
	set("no_drop",1);
	set("no_sell",1);
//	set("thunder",100);//受上天祝福,怎可讓雷劈呢....:p
	set("no_put",1);
	set("light_up",-1);
	set_weight(1200);
	set("value",999);
	setup();
}

int query_autoload()
{
  return 1;
}
