inherit ITEM;

void create()
{
        set_name( "錦扇",({"fan"}));
        set_weight(300);
        if( clonep() )
          set_default_object(__FILE__);
        else {
          set("unit", "面");
          set("long","
一面圓形的小扇子，上面繪著一對鴛鴦戲水的圖樣。\n");
          set("value", 80);
}
        setup();
}
