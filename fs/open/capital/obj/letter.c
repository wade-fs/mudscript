inherit ITEM;

void create()
{
        set_name( "一封泛黃的信",({"king's letter"}));
        set_weight(300);
        if( clonep() )
          set_default_object(__FILE__);
        else {
          set("unit", "封");
          set("long","
一封皇上交給你的信。\n");
          set("value", 80);
}
        setup();
}
