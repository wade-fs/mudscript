inherit EQUIP;

void create()
{
        set_name("厚底小朝靴",({"sole leather boots","boots"}) );
	set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "
底是由白犀牛皮所製成的，再用柔軟的棉布作成裡襯，良好的設計讓你在
快速的運動時，腳部受到更完善的保護。也因為犀牛已經是受到國際保護
的稀有動物，所以更顯得這雙靴子的稀有。

\n");
        set("unit","雙");
	set("value",2000);
        set("material","cloth");
        set("armor_type","boots");
        set("armor_prop/armor", 2);
	set("armor_prop/dodge", 5);
        }
        setup();
}
