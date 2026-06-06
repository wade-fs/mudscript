// star head 陳星輝的頭

inherit ITEM;

void create()
{
   set_name("陳星輝的頭", ({ "star head", "head"}) );
   set_weight(20);
   if( clonep() )
      set_default_object(__FILE__);
   else
   {
      set("unit", "顆");
      set("long", "這是陳星輝的頭, 是用來祭祀女鬼用的。\n");
      set("value", 100);
   }
}
