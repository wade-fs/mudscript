#ifdef WEATHER
// light
// 由 wade 撰寫
// 要點亮的物件上必須有一變數: (int)light_up
// 該變數的值是可以點的秒數, 如果是負值, 表永遠有效
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
  int		light;
  object	ob, *myob;
 
  seteuid(getuid(me));
 
  if(!arg) return notify_fail("unlight <物件>  <-- 如 unlight torch\n");
  arg = lower_case(arg);

  if (!ob = present (arg, me)) return
    notify_fail ("你身上沒有這樣東西。\n");

  if (!ob->query("had_light"))
    return notify_fail (sprintf ("這%s%s並沒有被點亮。\n",
      ob->query("unit"), ob->name()));

  message_vision("$N熄滅了一"+ob->query("unit")+ob->name()+"。\n", me);

  ob->delete("short");
  ob->delete("had_light");
  return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式 : unlight <物件>
範    例 : unlight torch
指令說明 : 
           這個指令可以讓你(妳)熄滅某些特定物件。
HELP
    );
    return 1;
}
#endif
