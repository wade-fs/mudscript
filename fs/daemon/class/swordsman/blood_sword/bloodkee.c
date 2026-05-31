//將receive_xxx補上攻擊方之參數 與COMBAT_D->report_status() by blazakira 2011/8/26
//將出現miss的訊息補上 by blazakira 2011/9/3 << 取消訊息 一直問為什麼 讓我好煩 by blazakira 2011/9/10

#include <combat.h>
#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me)
{
  int ski_value,sha_value,i,j;
  int kee_lv;
  int sword_lv;
  int swordkee_lv;
  object ob,room,*target;
  room = environment(me);
  target=me->query_enemy(room);
  i=sizeof(target);
  ski_value=random(me->query_skill("blood_sword",1))+query_function("bloodkee")*2;
  kee_lv=query_function("bloodkee");
  sha_value=me->query_skill("bloodsword",1);
  swordkee_lv=query_function("swordkee");
  sword_lv=me->query_skill("sword",1);

  if(kee_lv > 120) kee_lv=120;
  if(me->query("class")!="swordsman")
    return notify_fail("不是劍士不能用喔。\n");
  if(!me->is_fighting())
    return notify_fail("烈焰紅魔劍唯有在戰鬥中才能使用。\n");
  if(!me->query("highsworder"))
    return notify_fail("你無法使用烈焰紅魔劍。\n");
  if(!me) return 1;
  if(!target) return notify_fail("沒敵人..打屁阿..。\n");
  if( me->query_skill("blood_sword",1) < 20 )
    return notify_fail("你的血魔霸劍式技巧不足。\n");
  if(me->query("force") < 600)
    return notify_fail("你的內力不夠。\n");
  if(me->query("kee") < 500)
    return notify_fail("你的氣不夠。\n");
  message_vision(HIR"$N縱身一躍體內暗運體內血魔氣勁，身外浮現血魔狂暴影像！！！\n\n"NOR,me);
  message_vision(HBRED"瞬間四周籠罩在一股詭異的血氣之下，$N蓄存四周大量魔氣，準備發出這狂暴一擊！\n"NOR,me);
  message_vision(HIW"只見$N指成劍姿大喝一聲 "HIB"『"HIR"熾焰狂魔  血霸天下"HIB"』"HIW"，瞬間飆出無數血光劍芒...﹗\n\n"NOR,me);
  // 劍氣100 及bloodkee 120加強威力
  if (kee_lv==120 && swordkee_lv==100)
  {
    message_vision(HIY"就在此時已由$N將利劍往自己手上一刺...﹗\n"RED"只見暗紅色的劍氣隨血光竄出..混雜著空中無限血光劍芒..剎那間各種劍芒盡碎﹗﹗\n"HIY"只聽$N高喊"HIW"劍氣破敵--"HBBLU"『渾元天驚血光斬』﹗\n"NOR,me);
    //本身受傷
    me->add("kee",-((sha_value*5+kee_lv*5+sword_lv*5)/4));
    COMBAT_D->report_status(me);
    me->start_busy(1);
    me->add("force",-kee_lv*6);
    for(j=0;j < i;j++)
    {
      if(!target[j]) continue;
      message_vision(HIR"$N面對此情境已完全喪失招架能力任由劍氣在其身上劃出無數的傷痕！\n"NOR,target[j]);
      target[j]->receive_wound("kee",(sha_value*6+kee_lv*6+sword_lv*6+swordkee_lv*6),me);
      target[j]->start_busy(2);
      COMBAT_D->report_status(target[j],1);
    }
  }
  else if ( ski_value <  5 ) {
    me->add("force",-kee_lv);
    write(HIM"\n 不過一把都沒有命中，你當場羞紅了臉將劍收回。\n"NOR);
    COMBAT_D->report_status(me);
    say(HIM" 你發現空中亂劍飛舞，不過就是沒有命中敵人，不禁指著"+me->query("name")+"的鼻子大笑。\n"NOR);
  }
  else if( ski_value < 30  )
  {
    me->add("force",-kee_lv);
    write (HIM" 你發現大部分的劍都朝地上打去，甚至還打向自己，你發誓要好好練劍
                   將來方能完全駕馭。\n"NOR);
    say(HIM" 你看到空中一堆劍朝你射來，媽啊～快閃..發現原來是"+me->query("name")+"這個傢伙在舞劍。\n"NOR);
    for(j=0;j < i;j++) {
      if(!target[j]) continue;
      target[j]->receive_damage("kee",(sha_value+kee_lv*4+sword_lv*2),me);
      COMBAT_D->report_status(target[j]);
    }
  }
  else if( ski_value < 60 )
  {
    me->add("force",-kee_lv);
    write (HIM" 已有一些能準確命中敵人，使的敵人受創不小。\n"NOR);
    say(HIM" 你看見空中一些氣劍任"+me->query("name")+"揮灑自如，心中暗暗欽佩。\n"NOR);
    for(j=0;j < i;j++) {
      if(!target[j]) continue;
      target[j]->receive_damage("kee",(sha_value+kee_lv*4+sword_lv*2),me);
      COMBAT_D->report_status(target[j]);
    }
  }
  else if( ski_value < 90)
  {
    me->add("force",-kee_lv);
    write(HIM"\n 十之八九的氣劍朝敵人激射而去，使敵人受到嚴重的創傷。\n"NOR);
    say(HIM"\n 成千上萬的氣劍群集朝一目標射去，看的你瞠目結舌，半晌說不出話來。\n"NOR);
    for(j=0;j < i;j++) {
      if(!target[j]) continue;
      target[j]->receive_damage("kee",(sha_value+kee_lv*6+sword_lv*3),me);
      COMBAT_D->report_status(target[j]);
    }
  }
  else //既然原始並未在這一級別設傷害 那就不補上了 不過補上miss的訊息 giggle by blazakira
  {
    me->add("force",-kee_lv*4);
    me->start_busy(1);
//    write(HIM"\n 糟糕！由於使勁過度，氣息一滯，反而駕馭不了眾氣劍。\n"NOR);
//    say(HIM"\n 成千上萬的氣劍群集朝四周射去，看的你瞠目結舌，但仔細一看，卻無人受傷。\n"NOR);
  }
/*
    while(i--) { //移至最前方的判斷裡 by blazakira
      if(target[i])
        message_vision(HIR"$N面對此情境已完全喪失招架能力任由劍氣在其身上劃出無數的傷痕！\n"NOR,target[i]);
      COMBAT_D->report_status(target[i],1);
    }
*/
  if(kee_lv >=120) me->set("functions/bloodkee/level",120);
  else function_improved("bloodkee",random(kee_lv*5)+kee_lv*5);
  return 1;
}
