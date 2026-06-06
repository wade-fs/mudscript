// gpaper.c

inherit ITEM;

void create()
{
   set_name("金紙", ({ "gpaper" }) );
   set_weight(20);
   if( clonep() )
      set_default_object(__FILE__);
   else
   {
      set("unit", "疊");
      set("long", "這是用來祭祀鬼神所用的金紙。\n");
      set("value", 100);
   }
}
