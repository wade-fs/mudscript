// 本命令由容器搬過來，以減少記憶體的量
// 此外，由於中文化，外加說明檔，以及以前喝水常常當機等,
// 希望這種改法會減少當機的可能.
// by wade in 1996 5 31

#include <ansi.h>
inherit F_CLEAN_UP;
 
int help (object);

int main (object me,string arg)
{
  object can;
  mapping my;

  seteuid(getuid(me));
 
  if (!arg) return help(me);
  if (!objectp(can=present(arg,me))&&
      !objectp(can=present(arg,environment(me))))
    return help(me);

  my = can->query("液體");

  // 可以在容器上頭設定額外函數
  if (can->query("液體/額外函數")) return 1;

  if( !can->query("液體/剩") ) {
    if (stringp(can->query("液體/名稱")))
      printf ("%s的%s已經被喝光了。\n",can->name(),can->query("液體/名稱"));
    else
      printf ("%s是空的。\n",can->name());
    return 1;
  }

  if (me->query("water") >= me->max_water_capacity()) {
    write ("你已經喝太多了﹐再也灌不下一滴水了。\n");
    return 1;
  }

  can->add("液體/剩",-1);
  
  // 可以在容器上頭設定飲用訊息 by ACKY
  if( !can->query("液體/飲用訊息") )
	message_vision ("$N把嘴巴對著" + can->name() + ", 咕嚕嚕地喝了幾口" + can->query("液體/名稱") + "。\n",me);

  if (!intp(can->query("液體/止渴")))
    me->add("water",10);
  else
    me->add("water",can->query("液體/止渴"));

  if ((int)me->query("water") > me->max_water_capacity())
    me->set("water",me->max_water_capacity());
  if (me->is_fighting()) me->start_busy(2);
  if (!can->query ("液體/剩")) {
    write ("你已經將" + can->name() + "裡的" + can->query("液體/名稱") +
           "喝得一滴也不剩了。\n");
    return 1;
  }

  if (can->query("get_poison"))
  {
    write ("糟了 ! 水裡有毒 !\n");
    me->apply_condition (can->query("get_poison"),can->query("poison_power"));
  }

  switch(can->query("液體/種類")) {
    case "酒":
      me->apply_condition("drunk",
        (int)me->query_condition("drunk")
        + can->query("液體/酒精成份"));
      break;
  }

  return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式 : drink <容器名稱>
 
使用說明 :
	本命令可以用來喝溶液，如喝水，喝酒等等。
	當然，附近要有溶液可以喝才行，譬如水缸或者酒袋等等。
	喝了液體之後可以止渴，但是也有可能喝到毒藥，不過喝
	到補藥也不無可能。此外，喝酒不能喝太多，會傷身喔！
HELP
    );
    return 1;
}
