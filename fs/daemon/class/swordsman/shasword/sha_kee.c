//將receive_xxx補上攻擊方之參數 與COMBAT_D->report_status() by blazakira 2011/8/26

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
  ski_value=random(me->query_skill("shasword",1))+query_function("sha_kee")*2;
  kee_lv=query_function("sha_kee");
  sha_value=me->query_skill("shasword",1);
  swordkee_lv=query_function("swordkee");
  sword_lv=me->query_skill("sword",1);

  if(kee_lv > 100) kee_lv=100;
  if(!me->is_fighting())
    return notify_fail("劍影連陽唯在戰鬥中才能使用。\n");
  if(me->query("killyao")==1)
    return notify_fail("你無法使用連陽劍。\n");
  if(!me) return 1;
  if(!sizeof(target)) return notify_fail("沒敵人..打屁阿..\n");
  if( me->query_skill("shasword",1) < 20 )
    return notify_fail("你的仙劍劍法技巧不足。\n");
  if( me->query("family/family_name") != "仙劍派")
  {
    me->add("kee",-7000);
    log_file("/sword/swordlog",sprintf("%s(%s) 使用沒萬劍on %s\n",me->query("name"),me->query("id"),ctime(time())));
    return notify_fail("[1;31m由於強運仙劍絕學....你被萬劍反噬..[0m\n");
  }
  if(me->query("class")!="swordsman")
    return notify_fail("不是劍士不能用喔。\n");
  if(me->query("force") < swordkee_lv*9+100)
    return notify_fail("你的內力不夠。\n");
  if(me->query("kee") < 500)
    return notify_fail("你的氣不夠。\n");
  message_vision(HIB" $N縱身一躍，體內暗運內勁，身體浮沈於半空之中，突然間周圍草木由聳動而漸漸
        劍拔弩張，一根根成為蓄勢待發的利器。\n"NOR,me,target[0]);
  message_vision(HIW"\n\n         $N指成劍姿大喝一聲   『"HIY"劍影連陽 朝陽再現"HIW"』   瞬間四周萬劍齊發..﹗\n\n\n"NOR,me,target[0]);
  // 劍氣100 及sha_kee 加強威力
  if (kee_lv==100 && swordkee_lv==100)
  {
    message_vision("[1;34m就在此時已由$N將利劍往自己手上一刺...![0m \n[1;31m只見暗紅色的劍氣隨血光竄出..[0m \n[1;37m半空中混雜著各式劍氣..剎那間各種劍氣轉變成數種劍陣 ...[0m \n[1;34m只聽$N高喊[1;31m劍氣[1;37m破敵[1;33m---『石破天驚』！[0m\n",me);
    //本身受傷
    if(me->query("quest/sun_fire_sword")==1)
      me->add("kee",-((sha_value*5+kee_lv*5+sword_lv*5)/8));
    else
      me->add("kee",-((sha_value*5+kee_lv*5+sword_lv*5)/5));
    me->start_busy(1);
    me->add("force",-kee_lv*4);
    COMBAT_D->report_status(me);
    write("\n你耗費大量真力，得休息一回合才能繼續攻擊。\n");
    for(j=0;j < i;j++) {
      if(!target[j]) continue;
      message_vision(HIR"$N面對此情境已完全喪失招架能力任由劍氣在其身上劃出無數的傷痕！\n"NOR,target[j]);
      target[j]->receive_damage("kee",(sha_value*5+kee_lv*5+sword_lv*6),me);
      COMBAT_D->report_status(target[j]);
      target[j]->start_busy(1);
      target[j]->receive_wound("kee",sword_lv*10,me);
      COMBAT_D->report_status(target[j],1);
    }
  }
  else if ( ski_value <  5 ) {
    me->add("force",-kee_lv);
    write(HIM"\n 不過一把都沒有命中，你當場羞紅了臉將劍收回。\n"NOR);
    COMBAT_D->report_status(me);
    say(HIM" 你發現空中亂劍飛舞，不過就是沒有命中敵人，不禁指著"+me->query("name")+"的鼻子大笑\n"NOR);
  }
  else if( ski_value < 20  )
  {
    me->add("force",-kee_lv);
    for(j=0;j < i;j++) {
      if(!target[j]) continue;
      target[j]->receive_damage("kee",(sha_value/2+kee_lv*2+sword_lv*2),me);
      COMBAT_D->report_status(target[j]);
    }
    write (HIM" 你發現大部分的劍都朝地上打去，甚至還打向自己，你發誓要好好練劍
                   將來方能完全駕馭。\n"NOR);
    say(HIM" 你看到空中一堆劍朝你射來，媽啊～快閃..發現原來是"+me->query("name")+"這個傢伙在舞劍。\n"NOR);
  }
  else if( ski_value < 40 )
  {
    me->add("force",-kee_lv);
    for(j=0;j < i;j++) {
      if(!target[j]) continue;
      target[j]->receive_damage("kee",(sha_value/2+kee_lv*2+sword_lv*2),me);
      COMBAT_D->report_status(target[j]);
    }
    write (HIM" 已有一些能準確命中敵人，使的敵人受創不小。\n"NOR);
    say(HIM" 你看見空中一些氣劍任"+me->query("name")+"揮灑自如，心中暗暗欽佩。\n"NOR);
  }
  else if( ski_value < 60)
  {
    me->add("force",-kee_lv);
    for(j=0;j < i;j++) {
      if(!target[j]) continue;
      target[j]->receive_damage("kee",(sha_value+kee_lv*3+sword_lv*3),me);
      COMBAT_D->report_status(target[j]);
    }
    write(HIM"\n 十之八九的氣劍朝敵人激射而去，使敵人受到嚴重的創傷。\n"NOR);
    say(HIM"\n 成千上萬的氣劍群集朝一目標射去，看的你瞠目結舌，半晌說不出話來。\n"NOR);
  }
  else
  {
    me->add("force",-kee_lv*3);
    me->start_busy(1);
    //新增若enable連陽七訣劍法威力加倍
    //roger 98/8/17

    for(j=0;j < i;j++) {
      if(!target[j]) continue;
      target[j]->receive_damage("kee",(sha_value*3+kee_lv*4+sword_lv*4),me);
    }

    write(HIY" 在你雙手揮舞之下，萬劍均命中敵人，穿體而過，敵人痛苦的嘶吼著。\n"NOR);
    say(HIY" 你不敢相信眼前滂勃的氣勢，群天的氣劍掩蓋\了耀眼的陽光，卻發出一股
                更為絢麗的光芒。\n"NOR);
    write("\n你耗費大量真力，得休息一回合才能繼續攻擊。\n");
    while(i--) {
      if(target[i])
        message_vision(HIR"$N面對此情境已完全喪失招架能力任由劍氣在其身上劃出無數的傷痕！\n"NOR,target[i]);
      COMBAT_D->report_status(target[i]);
    }
  }

  if(kee_lv >=100) me->set("functions/sha_kee/level",100);
  else function_improved("sha_kee",random(kee_lv*5)+kee_lv*5);
  return 1;
}
