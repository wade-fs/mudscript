#ifdef WEATHER
// light
// 由 wade 撰寫
// 要點亮的物件上必須有一變數: (int)light_up
// 該變數的值是可以點的秒數, 如果是負值, 表永遠有效
 
#include <ansi.h>
 
int main(object me, string arg)
{
  object	*light;
  object	ob;
  string	unit;
 
  seteuid(getuid(me));
 
  if(!arg) return notify_fail("light <物件>  <-- 如 light torch\n");

  arg = lower_case(arg);
  if (!ob = present (arg, me))
    return notify_fail("你身上沒有這樣東西。\n");
    if ( ob->query("had_light") )
    return notify_fail("你已經點著了。\n");

  if (!ob->query("light_up"))
    return notify_fail ("你點什麼啊.\n");

  unit = ob->query("unit");
  if (!unit) ob->set("unit", unit="件");
  message_vision("$N點亮一"+unit+ob->name()+"。\n", me);

  ob->set("short", sprintf ("點亮著的%s(%s)",ob->name(),ob->query("id")));
  ob->set("had_light",1);
  return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式 : light <物件>
指令說明 :
           這個指令可以讓你(妳)點亮火把。
範    例 : light torch
其他參考 :
           unlight
HELP
    );
    return 1;
}
#endif
