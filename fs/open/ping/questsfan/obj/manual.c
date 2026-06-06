//無敵棋意------by dhk 2000.4.9
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("" + WHT + "無敵" + HIR + "棋" + WHT + "意" + NOR + "", ({ "board chess manual","manual" }) );
    set_weight(50);
 if( clonep() )
    set_default_object(__FILE__);
 else {
       set("long", "這是一本記載古今最為奧妙棋局的釋棋譜，相傳這是" + HIR + "紅帥先生" + NOR + "嘔心瀝血的著作。\n");
       set("unit", "本");
       set("value", 150000);
       set("no_auc",1);
      }
    setup();
}
