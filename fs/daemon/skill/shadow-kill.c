// shadow-kill written by mtl on May 9th, 1996
// Ver 1.02 modified by mtl on Jul 9th, 1996
// 為了避免衝突，規則的enable三項skills的上限，所以加入限制霸雨螫魂的enable
// By Swy 最後修正 QC 98/6/23
// 加強威力以符現今 fs by swy
//增加使用者存在與否的判斷 by blazakira 2011/1/9 函數 ready1(object me) ＆ ready2(object me)
//將receive_damage補上攻擊方的參數 by blazakira 2011/8/5

#include <ansi.h>
#include <combat.h>
inherit SKILL;

void busyk(object me,object victim,object weapon, int damage);
void devour(object me, object victim, object weapon, int damage);
void bloodk(object me, object victim, object weapon, int damage);
void reversek(object me, object victim, object weapon, int damage);
void shadowk(object me, object victim, object weapon, int damage);
void devast(object me, object victim, object weapon, int damage);
void devast2(object me, object victim, object weapon, int damage);
void worldpill(object me, object victim, object weapon, int damage);
void worldkill(object me, object victim, object weapon, int damage);

mapping *action = ({
([ "action":"$N搖來晃去...感到一陣噁心...難道是有了????....還是走火入魔的現象??",
"dodge": 0,
"parry": 0,
"force": 0,
"damage_type": "刺傷",
]),
([ "action":"$N斗然使出"+BLU+"『停雲催雪，地落八荒』"+NOR+"的絕情殺著，氣吞萬里如虎，銀虹流星墜雨般的向$n罩去，讓$n避無可避。",
"dodge": -10,
"parry": -10,
"damage": 10,
"force":  10,
"damage_type": "刺傷",
]),
([ "action":"$N喟然嘆道：不恨古人吾不見，恨古人、不見吾狂耳～驟然隨著那悵然殺意，使出"+YEL+"『雲山千疊，駭浪覆頂』
"+NOR+"向$n層層遞去，招招指向要害。",
"dodge": -10,
"parry": -10,
"damage": 20,
"force":  20,
"damage_type":  "刺傷",
"post_action": (: devour :),
]),
([ "action":"$N似笑非笑，悽悽唸起"+RED+"『棄魂散魄』"+NOR+"心訣。只見$N手上的$w一抹紫孽蒸起，不住旋動，
激起一道風刃向$n腰間急劈。",
"dodge": -20,
"parry": -20,
"damage": 30,
"force":  30,
"damage_type": "割傷",
"post_action": (: bloodk :),
]),
([ "action":"$N逆走幻星步法，使出"+GRN+"『亂象錯形』"+NOR+"的奧秘，陷$n於五行易位之闇黑空間。劍首寂然指向京房卦之血脈卦位，
只見$n正向跌跌撞撞地向$w奔去....",
"dodge": -20,
"parry": -20,
"damage": 40,
"force":  40,
"damage_type": "刺傷",
"post_action": (: reversek :),
]),
([ "action":"$N意念一起一息之間，身形已然"+CYN+"『如入不動魔地』"+NOR+"，手中$w影如來如去，無聲亦無息地遞向$n$l....",
"dodge": -25,
"parry": -25,
"damage": 50,
"force":  50,
"damage_type": "刺傷",
"post_action": (: shadowk :),
]),
([ "action":"$N內照形軀、守竅通關，豁然頓悟了"+BLINK+BOLD+"『一切有形招式，"+YEL+"如夢幻泡影"+WHT+"，"+BLU+"如露亦如電"+WHT+"』"+NOR+"。
過去所學的闇影匕首，一時之間融會貫通，源源不斷在手中使出，化為不可思量之勢湧向$n....",
"dodge": -25,
"parry": -25,
"damage": 60,
"force":  60,
"damage_type": "刺傷",
"post_action": (: devast :),
]),
([ "action":"$N斗然使出"+HIB+"『停雲催雪，地落八荒』"+NOR+"的絕情殺著，氣吞萬里如虎，銀虹流星墜雨般的向$n罩去，
讓$n避無可避。",
"dodge": -30,
"parry": -30,
"damage": 70,
"force":  70,
"damage_type": "刺傷",
]),
([ "action":"$N喟然嘆道：不恨古人吾不見，恨古人、不見吾狂耳～驟然隨著那悵然殺意，使出"+HIY+"『雲山千疊，駭浪覆頂』
"+NOR+"向$n層層遞去，招招指向要害。",
"dodge": -30,
"parry": -30,
"damage": 80,
"force":  80,
"damage_type":  "刺傷",
"post_action": (: devour :),
]),
([ "action":"$N似笑非笑，悽悽唸起"+HIR+"『棄魂散魄』"+NOR+"心訣。只見$N手上的$w一抹紫孽蒸起，不住旋動，
激起一道風刃向$n腰間急劈。",
"dodge": -40,
"parry": -40,
"damage": 90,
"force":  90,
"damage_type": "割傷",
]),
([ "action":"$N逆走幻星步法，使出"+HIG+"『亂象錯形』"+NOR+"的奧秘，陷$n於五行易位之闇黑空間。
劍首寂然指向京房卦之血脈卦位，只見$n正向跌跌撞撞地向$w奔去....",
"dodge": -50,
"parry": -50,
"damage": 100,
"force":  100,
"damage_type": "刺傷",
"post_action": (: reversek :),
]),
([ "action":"$N內照形軀、守竅通關，豁然頓悟了"+BLINK+BOLD+"『一切有形招式，"+YEL+"如夢幻泡影"+WHT+"，"+BLU+"如露亦如電"+WHT+"』"+NOR+"。
過去所學的闇影匕首，一時之間融會貫通，源源不斷在手中使出，化為不可思量之勢湧向$n....",
"dodge": -60,
"parry": -60,
"damage": 110,
"force":  110,
"damage_type": "刺傷",
"post_action": (: devast2 :),
]),
([ "action":HIY"$N體內一陣絕世氣力由體內爆發而出，$w"+HIY+"幻化出一陣氣勁沖向$n$l...."NOR,
"dodge": -60,
"parry": -60,
"damage": 120,
"force":  120,
"damage_type": "刺傷",
"post_action": (: worldpill :),
]),
([ "action":HIR"$N運起全身氣勁灌注到$w"+HIR+"裡，使出驚天動地的一擊!!"+HIG+" 四 神 爆 走 第 三 式 ～ 四  神  之  怒 ～"NOR,
"dodge": -70,
"parry": -70,
"damage": 130,
"force":  130,
"damage_type": "刺傷",
"post_action": (: worldkill :),
]),
});

void busyk(object me, object victim, object weapon, int damage)
{
  if(random(1000) < me->query("bellicosity"))
    if((random(150)<me->query_skill("shadow-kill",1))&&!me->query_temp("devast")&&!me->query_temp("devast2"))
    {
      victim->start_busy(1);
      message_vision(sprintf(HIB"趁著$n忙於招架這密如繁星般的攻擊之際，$N見機不可失，劍勢疾迴，意欲再進一招....\n"NOR),me,victim);
      COMBAT_D->report_status(victim, 1);
    }
}

void devour(object me, object victim, object weapon, int damage)
{
  int my_bell = (int) (me->query("bellicosity")/20);
  if( my_bell > 60 ) my_bell = 60;

  if( random(30) < my_bell )
    if(random(150)<me->query_skill("shadow-kill",1)&&!me->query_temp("devast")&&!me->query_temp("devast2"))
    {
      victim->receive_damage("kee", 250 + random( my_bell ), me);
      message_vision(sprintf(HIC"$N 匕首上枉死的冤魂，受不住$N陣陣殺氣的催動，從匕首脫出，向$n撲噬而去。\n"NOR),me,victim);
      COMBAT_D->report_status(victim, 1);
    }
}

void bloodk(object me, object victim, object weapon, int damage)
{
  if( random(250) < me->query_skill("force")+me->query_skill("shadow-kill",1) )
    if( damage > 10 && !me->query_temp("devast")&&!me->query_temp("devast2"))
    {
      victim->receive_damage("sen",100,me);
      victim->receive_damage("kee", 250 +random( (int)me->query_skill("rain-throwing",1)/2 ), me);
      message_vision(sprintf(HIM"只見從$n傷口噴灑而出的鮮血，突然凝成無數血柱，如靈蛇般向$n竄去，攝走$n的魂魄。\n"NOR),me,victim);
      COMBAT_D->report_status(victim, 1);
    }
}

void reversek(object me, object victim, object weapon, int damage)
{        
  int my_shadow=me->query_skill("shadow-kill",1);
  if(random(250)<me->query_skill("shade-steps",1)+my_shadow&&!me->query_temp("devast")&&!me->query_temp("devast2"))
  {
    victim->apply_condition("bleeding",(int)me->query_skill("cure")/5 +
      random( (int)my_shadow/10 + (int)me->query_skill("parry")/10 ) );
    message_vision(sprintf(HIR"$N雙手倒握匕首，往自己胸口送去－－卻見到$n胸口一道血柱如飛泉般噴出。\n"NOR),me,victim);
  }
}

void shadowk(object me, object victim, object weapon, int damage)
{
  int my_shadow=me->query_skill("shadow-kill",1);
  if((random(500)<me->query_skill("force")+me->query_skill("shade-steps",1)+my_shadow)&&!me->query_temp("devast")&&!me->query_temp("devast2"))
  {
    victim->recieve_damage("kee",300+random( (int)my_shadow/2 ) );
    message_vision(sprintf(HIG"$N召喚風影化身與$n廝殺。$N的法身逕向$n背後繞去，雙手提劍往$n天靈直落。\n"NOR),me,victim);
    COMBAT_D->report_status(victim, 1);
  }
}

void devast(object me,object victim, object weapon, int damage)
{
  int i;
  int my_shadow=me->query_skill("shadow-kill",1);
  int time=(int) my_shadow/10;
  if( me->query("force_factor") >= 10 && !me->query_temp("devast")&& !me->query_temp("devast2"))
  {
    if( me->query_temp("devast") == 0 )
    {
      me->set_temp("devast",1);
      for(i=0;i<time;i++)
      {
        if( random(1600) < me->query("bellicosity")+200)
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
      }
      message_vision(sprintf(HIY"$N仰天一嘆～明白這並非招式之極致，正所謂「飄風不終朝，驟雨不終日」。於是氣歸元牝，周流六虛....\n"NOR),me,victim);
      COMBAT_D->report_status(victim, 1);
      call_out("ready1",1,me);
    }
  }
}

void devast2(object me,object victim, object weapon, int damage)
{
  int i;
  int my_shadow=me->query_skill("shadow-kill",1);
  int time=(int) my_shadow/10+3;
  if( me->query("force_factor") >= 10 &&!me->query_temp("devast")&&!me->query_temp("devast2")&& me->query("bellicosity") > 2500)
  {
    if( me->query_temp("devast2") == 0 )
    {
      me->set_temp("devast2",1);
      for(i=0;i<time;i++)
      {
        if( random(4000) < me->query("bellicosity")+200)
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
      }
      message_vision(sprintf(HIY"$N仰天一嘆～明白這並非招式之極致，正所謂「飄風不終朝，驟雨不終日」。於是氣歸元牝，周流六虛....\n"NOR),me,victim);
      COMBAT_D->report_status(victim, 1);
      call_out("ready2",1,me);
    }
  }
}

int ready1(object me) 
{
  if (me)
    me->delete_temp("devast");
  return 1;
}

int ready2(object me)
{
  if (me)
    me->delete_temp("devast2");
  return 1;
}

void worldpill(object me,object victim, object weapon, int damage)
{
  int i;
  int my_shadow=me->query_skill("shadow-kill",1);
  int time=(int) my_shadow/10;

  time=random(time)+2;
  if( me->query("force_factor") >= 5)
  {
    message_vision(HIC"\n======  "HIW"$N 使 出 闇 影 匕 首 奧 義 "HIR"絕 世 幻 氣 "HIC" ====== 
      \n\n"NOR,me);
    message_vision(HIW"$N發出的氣勁幻化出數條殘影, 令$n無法捉摸!!\n\n"NOR,me,victim);
    for(i=0;i<time;i++)
    {
      if ( random(100) < 70 )
      {
//        if( !me->is_fighting() )
//        return ;
        message_vision(sprintf(NOR"氣勁化成"+HIR+"朱雀"+NOR+"﹐"+HIG+"青龍"+NOR+"﹐"+HIC+"白虎"+NOR+"﹐"+HIY+"玄武"+NOR+"﹐四色氣勁將敵人團團包圍!!\n"NOR),me,victim);
        if (random(100)>10)
        {
          victim->receive_wound("kee",150 + random( (int)my_shadow ),me);
          COMBAT_D->report_status(victim);
        }
        else message_vision(HIR"$N手忙腳亂, 驚險地閃過了這來勢洶洶的氣勁。\n"NOR , victim);
      }
    }       
//    me->start_busy(1);
  }
}

void worldkill(object me,object victim, object weapon, int damage)
{
  int i;
  int my_shadow=me->query_skill("blackforce",1);
  int time=me->query("max_s_kee",1);
  int gin=victim->query("max_gin",1);
  int kee=victim->query("max_kee",1);
  int sen=victim->query("max_sen",1);
  time=(int) time/50;
  if (time < 1) time=1 ;
  gin=(int)gin*(5+random(5))/100+200;
  kee=(int)kee*(5+random(10))/100+350;
  sen=(int)sen*(5+random(5))/100+200;
  if(gin>400) gin=400;
  if(kee>600) kee=600;
  if(sen>400) sen=400;
  {
    message_vision(HIY"\n======  "+BLINK+BOLD+"～～    四     神     之     怒    ～～ "+NOR+HIY+" ====== 
      \n\n"NOR,me);
    for(i=0;i<time;i++)
    {
      if ( random(100) < 75 )
      {
        message_vision(sprintf("$N分身成"+HIR+"朱雀"+NOR+"﹐"+HIG+"青龍"+NOR+"﹐"+HIC+"白虎"+NOR+"﹐"+HIY+"玄武"+NOR+"﹐四神幻影﹐將$n陷入虛無的幻象之中!!\n"NOR),me,victim);
        if (random(100)<10)
        {
          victim->receive_wound("kee",kee,me);
          victim->receive_wound("gin",gin,me);
          victim->receive_wound("sen",sen,me);
          victim->start_busy(1);
          COMBAT_D->report_status(victim);
        }
        else message_vision(HIR"$N集中意志力, 識破了眼前的幻影。\n"NOR , victim);
      }
    }
  }
}

mapping query_action(object me, object *weapon)
{
//  int skill_level=(int)(me->query_skill("shadow-kill",1)/10);
  int skill_level=(int)(me->query("functions/manakee/level")/10);
  object wea=me->query_temp("weapon");
  int x=0;
  weapon=me->query_temp("weapon");
  x=me->query("quest/worldpill");
  if (me->query("class") != "killer")
    return action[0];
  if (skill_level<= 5)
    return action[(random(skill_level)+1)];
  if ((skill_level>=6) && (skill_level <10))
    return action[(5+random(6))];
  if (skill_level>=10 && base_name(weapon)!="/open/killer/headkill/obj/world_dag")
  {
    if (x)
    {
      if ( 90 < random(100))
        return action[12];
    }
    return action[(random(6)+6)];
  }
  if (skill_level>=10 && base_name(weapon)=="/open/killer/headkill/obj/world_dag")
  {
    if (x)
    {
      if ( 90 < random(100))
        return action[13];	
    }
    return action[(random(6)+6)];
  }
}

int valid_learn(object me)
{
  object wea;

  if ( me->query_skill_map("rain-throwing") == 1)
    return notify_fail("閻影匕首與霸雨螫魂內勁相衝，請勿裝備霸雨螫魂\n");

  if( !(wea = me->query_temp("weapon"))
      || (string)wea->query("skill_type") != "dagger" )
    return notify_fail("你必須先找一把匕首才能練招式。\n");
  if( (int)me->query("max_force") < 700)
    return notify_fail("你的內力上限不足, 不可以練闇影匕首。\n");
  if(me->query_skill("blackforce",1)*3 <= me->query_skill("shadow-kill",1))
    return notify_fail("你的黑牙神功\技能不足，無法練闇影匕首。\n");
  if(me->query_skill("shade-steps",1)*2 <= me->query_skill("shadow-kill",1))
    return notify_fail("你的幻星步法技能不足，無法體會闇影匕首裡，移形換位之精義。\n");
  return 1;
}

int valid_enable(string usage) 
{
  return usage=="dagger" || usage=="parry";
}

int practice_skill(object me)
{
  object wea;

  if( !(wea = me->query_temp("weapon"))
      || (string)wea->query("skill_type") != "dagger" )
    return notify_fail("練闇影匕首還是要有把匕首吧....\n");
  if( (int)me->query("kee") < 30 )
    return notify_fail("體力不夠囉,休息一下再繼續練吧.\n");
  me->receive_damage("kee", 30, me);
  return 1;
}
