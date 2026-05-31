// 本命令由容器搬過來，以減少記憶體的量
// 此外，由於中文化，外加說明檔，以及以前喝水常常當機等,
// 希望這種改法會減少當機的可能.
// by wade in 1996 5 31
 
#include <ansi.h>
inherit F_CLEAN_UP;
 
int help ();
 
int main (object me,string arg)
{
  object env,can;
  mapping attr;
 
  seteuid(geteuid(me));
 
  if (!arg) return help();
  if (!objectp(can=present(arg,me))) return help();
 
  if (this_player()->is_busy())
    return notify_fail("你上一個動作還沒有完成。\n");
 
  env = environment(me);
  if (!mapp(attr = env->query("資源/液體")))
    return notify_fail("找不到任何液體可以裝.\n");
 
  if (env->query("have_poison"))
  {
    can->set ("get_poison",  env->query("poison_type"));
    can->set ("poison_power",env->query("poison_power"));
  }
 
  if (can->query("液體/剩"))
    message_vision("$N將" + can->name() + "裡剩下的" +
                can->query("液體/名稱") + "倒掉。\n",me);
 
  message_vision ("$N將" + can->name() + "裝滿" + attr["名稱"]+"。\n",me);
 
  if (me->is_fighting()) me->start_busy(2);
 
  can->set("液體/種類",attr["種類"]);
  can->set("液體/名稱",attr["名稱"]);
  can->set("液體/剩",can->query("飽和"));
  can->set("液體/止渴",attr["止渴"]);
 
  return 1;
}
 
int help()
{
        write(@HELP
指令格式 : fill <容器名稱>
 
指令說明 :
        本命令可以用來將容器裝上溶液，如裝水，裝酒等等,
        當然，附近要有液體可以裝才行，如水缸，水池，或湖泊等。
HELP
    );
    return 1;
}
