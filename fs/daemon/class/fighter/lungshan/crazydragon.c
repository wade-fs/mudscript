//瀧山封印技『狂龍訣』 構思by assassin 敘述補充by enisx code by blazakira

#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

void perform(object me, object target)
{
  int fun,temp,add;
  if(!me->query("quests/crazydragon"))
    return notify_fail("你並未經過任正晴的許\可。\n");
  if( me->query("family/family_name") != "瀧山派" )
    return notify_fail("狂龍訣只有瀧山派的門人才可以使用。\n");
  if(!me->query_skill("haoforce",1))
    return notify_fail("狂龍訣必須使用浩日心法來催動。\n");
  if( (string)me->query_skill_mapped("unarmed")!= "lungshan")
    return notify_fail("狂龍訣必須配合瀧山絕學才能發揮效用。\n");
  if(me->query_temp("crazy_dragon/on")==1)
    return notify_fail("你已經施展狂龍訣之威。\n");
  if(me->query("force") < 1000)
    return notify_fail("你的內力不足以催動狂龍訣。\n");
  if(me->query("sen") < me->query("max_sen")/2)
    return notify_fail("你的神瞑不足以催動狂龍訣。\n");
  if(me->query("gin") < me->query("max_gin")/2)
    return notify_fail("你的精力不足以催動狂龍訣。\n");
  fun=me->query("functions/crazydragon/level")+1;
  me->set_temp("crazy_dragon/on",1); //mark
  temp=(int)(me->query("max_gin")+me->query("max_sen"))/300; //這是以gin 10000+sen 10000作為基礎的計算
  add=(int)me->query("max_sen")/300*fun;
  me->set_temp("crazy_dragon/sen",add); //紀錄 所減少的數值 用以恢復數值用
  me->add("max_sen",-add);
  me->add("eff_sen",-add);
  me->add("sen",-add);
  add=(int)me->query("max_gin")/300*fun;
  me->set_temp("crazy_dragon/gin",add);
  me->add("max_gin",-add);
  me->add("eff_gin",-add);
  me->add("gin",-add);
//  me->set_temp("crazy_dragon/temp",temp); //紀錄 作為測試數據 待刪除
  add=temp*fun/100+10;
  if(add > 65) add=65;
  me->set_temp("crazy_dragon/add",add);
  me->add_temp("apply/attack",fun); //最高65
  me->add_temp("apply/unarmed",add); //可考慮不設上限 但是不建議給太高的數值 目前上限為100
  me->add_temp("apply/defense",-fun);
  me->add("force",-300-fun*20); //提高消耗
  me->start_call_out( (: call_other, __FILE__, "remove_effect", me, fun, add:), fun+50+random(fun));
  if( me->is_fighting() ) {
      me->start_busy(2);
  }
  message_vision(HIR + "                       只見$N以渾厚的內力將浩日罡\氣吸納入體！\n\n"+

    "             四周游移的焰氣，幻化如龍形龍環繞於四周，空氣中充斥著肅殺氣息！！\n\n\n"+


    "      $N雙手綻放出無法正視的深紅色氣芒，全身勁力匯聚丹田 ！！ 忽地縱天長嘯～～～\n\n"+

    "                  ◥██◣  ▏▎▍▌▋▊ 狂 龍 訣 ▊▋▌▍▎▏◢██◤\n\n" + NOR,me);
  return notify_fail("");
}

void remove_effect(object me,int fun,int add)
{
  object ppl;
  if(!me) return;
  if( (string)me->query_skill_mapped("unarmed")!= "lungshan") {
    me->apply_condition("misforce",add/2);
    return notify_fail("失去瀧山絕學的控制，使得你身上的狂龍訣暴走，導致內勁反噬，走火入魔。\n");
  }
/*
  ppl=find_player("blazakira"); //debug
  if(!fun) {
    fun=me->query("functions/crazydragon/level")+1;
    if(ppl && !ppl->query("env/wn_msg_off"))
      tell_object(ppl,HBGRN+HIG+"狂龍訣抓不到"+me->query("id")+"的crazydragon lv參數。\n"+NOR);
  }
  if(!add) {
    add=me->query_temp("crazy_dragon/add");
    if(ppl && !ppl->query("env/wn_msg_off"))
      tell_object(ppl,HBGRN+HIG+"狂龍訣抓不到"+me->query("id")+"的crazydragon add參數。\n"+NOR);
  }
*/
  me->delete_temp("crazy_dragon/on");
  me->add("max_sen",me->query_temp("crazy_dragon/sen"));
  me->add("eff_sen",me->query_temp("crazy_dragon/sen"));
  me->add("max_gin",me->query_temp("crazy_dragon/gin"));
  me->add("eff_gin",me->query_temp("crazy_dragon/gin"));
  me->delete_temp("crazy_dragon/gin");
  me->delete_temp("crazy_dragon/sen");
  me->add_temp("apply/attack",-fun);
  me->add_temp("apply/unarmed",-add);
  me->add_temp("apply/defense",fun);
  if( me->query("functions/crazydragon/level") < 100 )
    function_improved("crazydragon",random((int)(fun/15))+random(fun)+1);
  message_vision(HIR + "         忽然一陣強烈的麻痺感充斥$N的全身，彷彿遭到了「火灼」一般難受！\n\n"+

    "   身上處處均是灼傷的痕跡，胸口還隱隱有一陣鬱悶之氣凝聚不散！感到自身烈焰浩氣無法控制，身體十分虛弱！！\n" + NOR,me);
  add=(int)fun/8+2;
  me->apply_condition("burn",add);
  return notify_fail("");
}
