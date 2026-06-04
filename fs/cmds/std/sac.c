// sac.c  可以將不需要的 物品 和 屍體奉獻給天神 不過似乎戰鬥中也可以使用
// 以後有機會再來修         By Anmy    97/11/22
// 二版修正 戰鬥中及 昏迷的mob 無法 sac 已設定好  By Anmy  98/5/22
// 三版修正能 sac all by swy
//code排版跟訊息前後的顏色不一的問題 by blazakira 2011/7/21

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object tp, string str)
{
  object ob, *inv;
  int val,i;
  tp = this_player();
  if(!str) return notify_fail("你想奉獻什麼﹖\n");
  seteuid(getuid());
  if(str=="all") {
    inv = all_inventory(environment(tp));
    for(i=0;i<sizeof(inv);i++)
    {
      if(living(inv[i])) continue;
      if(inv[i]->is_fighting()) continue;
      if(in_edit(inv[i])||in_input(inv[i])||inv[i]->query_temp("netdead")) continue;
      if(inv[i]->query("no_sac")) continue;
      if(userp(inv[i])) continue;
      if(inv[i]->query("capacity")) continue;
      message_vision(HIC + "$N將"+inv[i]->short()+HIC + "奉獻給大神。\n" + NOR, tp);
      destruct(inv[i]);
    }
    return 1;
  }
  ob = present(str, environment(tp));
  if(!ob) return notify_fail("你找不到這樣東西﹗\n");
  if (tp->is_fighting()) return notify_fail("你上個動作還沒完成。\n");
  if(living(ob)) return notify_fail("你不能奉獻活的生物﹗\n");
  if(ob->query("no_sac",1)) return notify_fail("你不能把這個奉獻掉﹗\n");
  if(ob->is_fighting()) return notify_fail("你正在戰鬥中﹗無法分心去奉獻\n");
  if(userp(ob)) return notify_fail("你不能奉獻玩家!!\n");
  if(ob->query("capacity") > 1) //板子用的
    return notify_fail("留言板不能奉獻!!!!\n");
  if (in_edit(ob) || in_input(ob) || ob->query_temp("netdead"))
    return notify_fail (ob->name() +"正在忙呢..\n");
  message_vision(HIC + "$N以很遺憾的心情將"+ob->short()+HIC + "歸入塵土風逝。\n" + NOR,tp);
//修正sac的人可以拿到潛能...一點.以提高sac的情形
  write(tp->name()+"的善心, 大神給你一文錢做為賞賜。\n");
  foreach(object obj in all_inventory(ob))
  {
    destruct(obj);
  }
  destruct(ob);
  new("/obj/money/coin")->move(tp);
  return 1;
}

void help() {
write(@HELP
      技能用法 : sac <地上物品> 
   將不用的東西奉獻給大神，大神會給予報酬。
HELP
  );
  return;
}
