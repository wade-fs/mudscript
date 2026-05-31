//將receive_wound的攻擊參數補上攻擊方之參數 且將add("kee")的部份調整為receive_damage by blazakira 2011/7/15

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me, object target)
{
  int value,k_level,unit=1,much;
  int kangfun=me->query("functions/kang-power/level");
  string msg;
  object ob;
  string *name;
  if( !target ) target = offensive_target(me);
  if(me->query_skill("haoforce",1) < 100 - ( me->query_con() + me->query_cps()*1.2 ) )
    return notify_fail("你的浩日心法不夠純熟﹐無法聚氣指尖。\n");
  if( (string)me->query_skill_mapped("unarmed")!= "lungshan")
    return notify_fail("浩日罡\氣必須配合瀧山絕學才能用。\n");
  if( me->query("family/family_name") != "瀧山派" )
    return notify_fail("浩日罡\氣只有瀧山派的門人才可以使用。\n");
  if(!(ob=me->query_temp("weapon")))
  {
    if(me->query_temp("secondary_weapon"))
      return notify_fail("不空手怎麼發浩日訣?\n");
  }
  if(ob=me->query_temp("weapon"))
  {
    if((string)ob->query("skill_type") != "unarmed")
      return notify_fail("不空手怎麼發浩日訣?\n");
  }
  if(me->query("force")<400)
    return notify_fail("你的內力不夠。\n");
  if(me->query("kee")<250)
    return notify_fail("你的氣不夠。\n");
  if(!me->is_fighting(target))
  {
    tell_object(me,"浩日罡\氣唯在戰鬥中才能使用。\n");
    return 0;
  }
  value = me->query("functions/kang_kee/level");
  value=value+((int)me->query_skill("haoforce",1) / 2);

  k_level = value;

  if(!target) return notify_fail("你找不到敵人在那!!\n");
  if ( (k_level > 110) && (me->query_skill("fire-kee",1) > 60))
  {
    message_vision(
      "\n          [1m$N雙手合十向前指去，使出浩日罡\氣中的必殺奧義★★--[1;31m烈日訣[0m[1m--★★\n
          霎時間$N的烈日護身氣勁逆流，一股至陽剛烈的真氣充斥在$N的手上\n
          $N的雙掌散發出炙熱的光芒，指尖聚集了無數顆的明亮的光球\n\n",me,target);
    message_vision(
      "          [1m$N狂吼一聲，無數的「烈日罡\氣」向$n射去﹗[1;31m\n
          -------------------------------------------------------------*
          -------------------------------------------------------------*
          -------------------------------------------------------------*
          -------------------------------------------------------------*
          -------------------------------------------------------------*
        [0m\n",me,target);
//    me->add("kee",-70);
    me->receive_damage("kee",70,me);
    me->add("force",-(k_level*4));
  } else if ( (k_level > 90) && (me->query_skill("fire-kee",1) > 30))
  {
    message_vision(
      "[1m$N將雙掌成虎形，使出浩日罡\氣中的必殺技☆☆--[1;31m浩日訣[0m[1m--☆☆\n
          $N將十尺內的熱氣集中在雙掌之內，只見$N的雙掌發出陣陣悶熱的氣勁\n
          $N雙掌發光炙熱，掌中聚集一顆明亮的光球\n\n",me,target);
    message_vision(
      "[1m$N雙掌向前一推，掌中的「浩日罡\氣」向$n射出﹗[1;31m\n
          -------------------------------------------------------------*
          =============================================================***
          -------------------------------------------------------------*
        [0m\n",me,target);
//    me->add("kee",-50);
    me->receive_damage("kee",50,me);
    me->add("force",-(k_level*3));
  } else if ( k_level > 70)
  {
    message_vision(
      "[1m$N將手向天一指，運起浩日罡\氣中的「[1;33m赤日訣[0m[1m」\n
          $N把太陽的光線集中在手中，一股至陽剛烈的內勁從丹田升起，\n
          $N全身發光炙熱，指尖聚集一顆明亮的光球\n\n",me,target);
    message_vision(
      "[1m$N運勁指尖，一道「赤日罡\氣」向$n射去﹗[1;33m\n
                                                             * *
         =====================================================* *
                                                             * *
        [0m\n",me,target);
//    me->add("kee",-40);
    me->receive_damage("kee",40,me);
    me->add("force",-(k_level*2));
  } else
  {
    message_vision(
      "[1m$N低吼一聲!!躍至空中使出浩日罡\氣中的「[1;33m旭日訣[0m[1m」\n
          $N在半空如太陽般散出至陽剛烈的真氣，$N將真氣聚在掌上\n
          真氣的聚集使$N的雙掌炙熱通紅，發出輝眼光芒!!\n\n",me,target);
    message_vision(
      "[1m$N運勁以足，將「旭日罡\氣」從天空向$n射去﹗[0m\n",me,target);
//    me->add("kee",-30);
    me->receive_damage("kee",30,me);
    me->add("force",-(k_level));
  }
  if(80>random(100))
  {
    message_vision(
      "\n[1;31m$n躲避不及﹐被罡\氣擊中﹐霎時烈火籠罩$n全身﹐嘶嚎不斷﹗\n[0m",me,target);
    message_vision( NOR,me);

    if(me->query("kang-power")&&me->query("combat_exp")>5000000) {
      message_vision(HIW"$N身上的『烈燄浩氣』與『浩日罡\氣』相輔相成提升了威力重創了$n。"NOR,me,target);
      message_vision("\n",me);
/*
  2002-12-25 修改by kalin:開放kang_power,讓kang_power不再是jen的專利,只要解過fire king,
                          且exp 500one以上的玩家也能享有kang_power,不過威力調低,不再是固定的4000....
*/
      target->receive_wound("kee",2500+(k_level*4),me);
      me->start_busy(1);
    }

    target->apply_condition("burn",random(15)+1);
//    target->receive_wound("kee",(k_level*4)+200,me);
    COMBAT_D->report_status(target);
  }
  else
  {
    if (((string)target->query_skill_mapped("parry") == "fire-kee") &&
      (random(target->query_skill("fire-kee")) > 40))
    {
      message_vision(
        "[1;37m\n$n使出浩日護身氣勁之終極絕招【[1;33m--烈--火--無--限--[1;37m】\n
只見$N的罡\氣和$n護身氣勁相撞，轟～～一聲二人四周發出漫天炙熱氣勁。[0m\n",me,target);
      message_vision( NOR,me);
    }
    else if (((string)target->query_skill_mapped("parry") == "snow-kee") &&
      (random(target->query_skill("snow-kee")) > 50))
    {
      message_vision(
        "[1;36m\n$n使出雪蒼寒勁之終極絕招【[1;37m--冰--風--雪--暴--[1;36m】\n
只見$N的罡\n氣和$n護身寒勁相撞，轟～～一聲四周散出霧氣。[0m\n",me,target);
      message_vision( NOR,me);
    }
    else
    {
      message_vision(
        "[31m$n運功\避開﹐但仍受罡\氣侵襲﹐只見$n的傷口焦黑一塊。[0m\n",me,target);
      message_vision( NOR,me);
      target->apply_condition("burn",random(15)+1);
      COMBAT_D->report_status(target);
    }
  }
  message_vision(
    "「浩日罡\氣」射出後，$N大耗內力、趕緊趁機調息內息\n",me,target);
  me->start_busy(1);
  if(me->query("functions/kang_kee/level") < 100)
  function_improved("kang_kee",random(me->query("max_force")/10));
  message_vision( NOR,me);
  return 1;
}
