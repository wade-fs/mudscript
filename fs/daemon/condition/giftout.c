// 用 condition 來控制以免造成 crash 時屬性降不下來的問題 by swy
//調整gift為新函數應用的形式 by blazakira 2011/7/21

#include <ansi.h>
inherit F_FUNCTION;

int update_condition(object me, int duration)
{
  if(duration==0) {
    object wname,eq;
    int fun;
    if(me) {
      wname=me->query_temp("secondary_weapon");
      fun = me->query("functions/addbasic/level");

      me->delete_temp("addbasic");
      if(me->query("setgift-mk")) { //如果舊設定存在就照舊
        me->delete("setgift-mk");
        me->set("str",me->query("setgift/str"));
        me->set("cps",me->query("setgift/cps"));
        me->set("cor",me->query("setgift/cor"));
        me->set("int",me->query("setgift/int"));
        me->set("spi",me->query("setgift/spi"));
        me->set("kar",me->query("setgift/kar"));
//        me->delete("setgift"); //刪除舊設定紀錄
      }
      if(me->query_temp("setgift-mk/on")) { //如果存在新設定就依新設定
        me->add_temp("apply/str",-me->query_temp("setgift-mk/k"));
        me->add_temp("apply/cps",-me->query_temp("setgift-mk/k"));
        me->add_temp("apply/cor",-me->query_temp("setgift-mk/k"));
        me->add_temp("apply/int",-me->query_temp("setgift-mk/k"));
        me->add_temp("apply/spi",-me->query_temp("setgift-mk/k"));
        me->add_temp("apply/kar",-me->query_temp("setgift-mk/k"));
        me->delete_temp("setgift-mk/on");
      }
      if(me->query("cloak_add_gift")) {
        if(eq = present("Dark Moon Cloak",me)) eq->setheartbeat(1);
        me->delete("cloak_add_gift");
      }
      if(me->query("armband_add_gift")) {
        if(eq = present("red chilin armband",me)) eq->setheartbeat(1);
        me->delete("armband_add_gift");
      }
      if(me->query("plate_add_gift")) {
        if(eq = present("Holy Ghost Plate",me)) eq->setheartbeat(1);
        me->delete("plate_add_gift");
      }
      if(me->query("legging_add_gift")) {
        if(eq = present("fire bird leggings",me)) eq->setheartbeat(1);
        me->delete("legging_add_gift");
      }
      if(wname) wname->delete("nodrop");
      if(me->query("family/family_name") == "金刀門")
      {
        message_vision(HIW + "$N覺得凝聚落葉的刀勁消散了。\n" + NOR,me);
      }
      else {message_vision(HIW + "$N覺的刀的血氣消失了。\n" + NOR,me);}
      if(fun<100) { function_improved("addbasic",random(700)); }
    }
    return 0;
  }
  tell_object(me,HIW + "你『" + HIG + "筋骨異常" + HIW + "』，漫延全身似乎變了一個人。\n" + NOR);
  message("vision",HIC+me->name()+"全身『" + HIG + "筋骨異常" + HIC + "』漫延全身，附近的人都快認不出來了。\n" + NOR,environment(me),me);
  me->apply_condition("giftout",duration-1);
  return 1;
}
