inherit ITEM;

void create()
{
        set_name( "月半彎親筆信",({"yua's letter"}));
        set_weight(300);
        if( clonep() )
          set_default_object(__FILE__);
        else {
          set("unit", "封");
          set("long","
一封月半彎的親筆信。\n");
          set("value", 80);
}
        setup();
}
