//將receive_damage補上攻擊方參數 與對手是否存在的判定 by blazakira 2011/9/8

/***************************************************************************************************
  
  修改 by kalin 91-12-21

01.原本的附功傷害力都為   int dam=victim->query("max_kee")/5;的寫法，
   改為不參照mob's kee 只參照自身等級。
02.開放儒尊,也參照打死fire king與否,但是這兩點只是增加knowpen功能。

================================================================================

  修改 by kalin 2003-06-15

1.增加連擊功能，放在兩個post_action(speed1跟speed2)上，
  a.speed1最基本使用條件：解過fire-king。
  b.speed2最基本使用條件：解過儒尊。
2.因應連擊的出現，降低副功的傷害值，每個副功都不超過500的傷害值(以500萬經驗值的玩家來做依據)。
ps:今天是發薪日，很高興！但是最近工作遇到瓶頸，來fs休息一下，雖然說不去幫wade
   開發fs2，但是還是敵不過fs的誘惑，wade哥，sorry囉。 ^________________^  

================================================================================

  修改 by frequency 2003 07-27
  
  1.觀察發現ppl之連擊程度太過誇張，因此調降連擊數。
  2.plan_king4向下修正，因為原設定一出即造成12*damage傷害而damage又可無限制增高
    以exp 3000萬的ppl為例，此招一出即代表500*12 = 6000點傷害，太過誇張，
    因此增加命中率限制及降低damage，修正後平均傷害為 375*12*2/3 = 3000
    
  3.當do_attack時連擊型附攻不發動   2004 0208
  
================================================================================  
  
  修改 by unfinished 2004 02-09
  
  1.修改連擊 最大連擊數少一, 但略為增加連擊穩定度 使整體傷害更平均
  2.修正連擊時均無附攻


  修改 by unfinished 2004 03-05
  1.附攻加入儒門判定, 避免解過儒尊改拜其他們派仍可使用儒門附攻
***************************************************************************************************/

#include <combat.h>
#include <ansi.h>
inherit SKILL;

void special_attack(object me, object victim, object weapon, int damage);
void sp_att1(object me, object victim, object weapon, int damage);
void sp_att2(object me, object victim, object weapon, int damage);
void sp_att3(object me, object victim, object weapon, int damage);
void speed1(object me, object victim, object weapon, int damage);
void speed2(object me, object victim, object weapon, int damage);
void plan_king1(object me, object victim, object weapon, int damage);
void plan_king2(object me, object victim, object weapon, int damage);
void plan_king3(object me, object victim, object weapon, int damage);
void plan_king4(object me, object victim, object weapon, int damage);

mapping *action = ({
([//1
  "action"     :
    "$N手中$w一翻﹐一招"HIW"『"NOR"行雲流"HIB"水"HIW"』"NOR"手裡的$w如一條長龍流轉﹐往$n$l刺去",
  "dodge"      : -10,
  "parry"      : -10,
  "damage"     : 50,
  "force"      : 100,
  "damage_type": "刺傷",
]),
([//2
  "action"     :
    "$N身形流轉﹐連踩七步﹐手中$w一招"HIW"『"HIG"七步成"HIC"詩"HIW"』"NOR"往$n點去",
  "dodge"      : 0,
  "parry"      : 0,
  "damage"     : 50,
  "force"      : 100,
  "damage_type": "刺傷",
]),
([//3
  "action"     :
    "$N手中$w搖晃﹐步法微頓﹐倏地一招"HIW"『"HIW"把"HIR"酒"NOR"問天"HIW"』"NOR"將$w揮出﹐連出三下往$n點去",
  "dodge"      : -10,
  "parry"      : 10,
  "damage"     : 100,
  "force"      : 200,
  "damage_type": "刺傷",
]),
([//4
  "action"     :
    "$N將手裡的$w高高舉起﹐忽地手中$w急變招數﹐一招"HIW"『"HIY"菊"HIM"園盡興"HIW"』"NOR"連綿不絕的往$n急點",
  "dodge"      : -20,
  "parry"      : 20,
  "damage"     : 100,
  "force"      : 200,
  "damage_type": "刺傷",
]),
///////////////////////// Below Add By AceLan ////////////////////////////////
([//5
  "action"     :
    "$N忽然歪歪斜斜的走了兩步, 使出一招"HIW"『"HIR"拗步斜行"HIW"』"NOR",朝$n$l攻去",
  "dodge"      : -30,
  "parry"      : 30,
  "damage"     : 150,
  "force"      : 250,
  "post_action": (: sp_att1 :),
  "damage_type": "刺傷",
]),
([//6
  "action"     :
    "$N看準了$n來勢, 使出一招"HIW"『"NOR"迎門"HIB"鐵"HIR"扇"HIW"』"NOR", 瀟灑的還了一擊",
  "dodge"      : -30,
  "parry"      : 20,
  "damage"     : 150,
  "force"      : 250,
  "post_action": (: plan_king4 :),
  "damage_type": "刺傷",
]),
([//7
  "action"     :
    "$N大喝一聲, 身形急轉, 使出儒門的絕招"HIW"『"HIB"翻"HIR"花"HIY"舞"HIG"袖"HIW"』"NOR", 手裡$w如雨點般朝$n灑落",
  "dodge"      : -50,
  "parry"      : 40,
  "damage"     : 200,
  "post_action": (: plan_king1 :),
  "force"      : 300,
  "damage_type": "刺傷",
]),
([//8
  "action"     :
    "$N凝聚內力, 身旁瞬時刮起強風, 這正是儒門的"HIW"『"HIB"風"NOR"掃"HIR"梅花"HIW"』"NOR", 只見$N的身影滿天飛舞",
  "parry"      : 30,
  "dodge"      : -40,
  "damage"     : 200,
  "force"      : 300,
  "post_action": (: plan_king2 :),
  "damage_type": "刺傷",
]),
([//9
  "action"     :
    "$N使出一招"HIW"『"HIB"魁星"HIM"點"NOR"斗"HIW"』"NOR", 只見$N手中$w忽快忽慢忽左忽右地朝$n身上急點",
  "parry"      : 30,
  "dodge"      : -40,
  "damage"     : 250,
  "force"      : 300,
  "post_action": (: plan_king3 :),
  "damage_type": "刺傷",
]),
([//10        
  "action":
    "$N慢慢將真氣運行全身帶動四周氣流，緩緩收起$w，準備使出儒門鎮教絕式之一\n"
    "$N的真氣突然慢慢消失，掌力順時降至三分，$n只有點招架不住。",
  "damage"     : 300,
  "dodge"      : -30,
  "parry"      : 10,
  "post_action":  (: sp_att2 :),
  "damage_type":"瘀傷"
]),
([//11         
  "action":
    "$N將握$w換成拿劍之態，忽地手中幻化成劍，準備使出儒教鎮教絕式之一\n"
    "$N因無法掌握住誘困殺滅四項劍意，$n似乎有點看穿破招之法。",
  "damage"     : 300,
  "dodge"      : -30,
  "parry"      : 10,
  "post_action": (: sp_att3 :),
  "damage_type":"割傷"
]),
([//12
  "action"     :
    "$N身形急轉, 突然凌空躍起, 手中$w左翻右翻, 朝$n身上指指點點, 急點而至,
這一招正是儒門的絕招"HIW"『"NOR"轉"HIB"龍"HIG"迴"HIR"日"HIW"』"NOR,
  "dodge"      : 50,
  "parry"      : 30,
  "damage"     : 250,
  "force"      : 300,
  "damage_type": "刺傷",
  "post_action": (: speed1 :),
]),
([//13
  "action"     :
    "$N身形突然拔高數丈, 使出一招"HIW"『"HIB"雲"HIR"開"HIY"龍"HIB"騰"HIW"』"NOR", 手中$w從空中飄然下劃,
只見一道無形勁氣, 挾著狂風朝著$n激射而至",
  "dodge"      : 60,
  "parry"      : 40,
  "damage"     : 300,
  "force"      : 300,
  "damage_type": "刺傷",
  "post_action": (: special_attack :),
]),
([//14
  "action"     :
    "$N突然全身充滿綠光，兩眼電射出迫人的寒氣，使出儒門至高筆法"HIW"『"HIB"靈"HIR"龍"HIY"筆"HIB"書"HIW"』"NOR",
只見一道勁氣挾著萬丈光芒已將$n全身籠罩住了",
  "dodge"      : 60,
  "parry"      : 40,
  "damage"     : 300,
  "force"      : 300,
  "damage_type": "刺傷",
  "post_action": (: speed2 :),
]),
});

/***************************************************************************************************
     post_action       大致區分為(未解過Fire King)，(解過Fire King)，(解過儒尊 & EXP>500萬)3種。
===============================================================================================

未解過任何謎： 

一.special_attack：
a.chance = 80>random(100)
b.damage = me->query_skill("force")
c.less = me->add("force",-25)

二.sp_att1：
a.chance = 80>random(100)
b.damage = (me->query_cor()*5)+random(me->query_cor()*10)  ps:裝ten pen
c.damage = (me->query_cor()*5)  ps:沒裝ten pen
d.less   = me->add("force",-25)
e.busy   = victim->start_busy(1)

三.sp_att2：
a.chance = 80>random(100)
b.damage=this_player()->query("bellicosity")/20
c.less   = me->add("force",-25)
d.busy   = victim->start_busy(1)

四.sp_att3：
a.chance = 80>random(100)
b.damage = victim->receive_damage("kee", 20)
c.less   = me->add("force",-7)
d.times  = me->query("combat_exp")/1000000

五.speed1：
a.chance = 80>random(100)
b.damage = (random(100))+100
c.less   = me->add("force",-25)

-----------------------------------------------------------------------------------------------

解過Fire King： 

一.sp_att3(多連弩)：
a.chance = 80>random(100)
b.damage = victim->receive_damage("kee", 50)
c.less   = me->add("force",-7)
d.times  = (me->query("combat_exp")/1000000)+random(me->query("combat_exp")/1000000)

二.speed1(多連擊)：
a.chance = 80>random(100)
b.less   = me->add("force",-35)
c.times  = me->query("combat_exp")/500000

MARK：me->query("plan-quest/ko-fire-king",1)

-----------------------------------------------------------------------------------------------

解過儒尊 & EXP>500萬：

一.speed2：
a.chance = 80>random(100) & me->query("force")>500
b.less   = me->add("force",-50)
c.time   = (this_player()->query("combat_exp")/500000 )

二.plan_king1：
a.chance = 80>random(100) & me->query("kee")<me->query("max_kee")
b.less = me->add("force",-(heal/4))
c.amount = int heal=me->query("max_force")/20 & if( heal > 500) heal= random(200)+300
d.cure   = me->receive_curing("gin",heal/10)
           & me->receive_heal("gin",heal/10)
           & me->receive_curing("kee",heal)
           & me->receive_heal("kee",heal)
           & me->receive_curing("sen",heal/10)
           & me->receive_heal("sen",heal/10)

三.plan_king2：
a.chance = 80>random(100)
b.damage = victim->receive_damage("kee", 200+random(200))
c.busy   = victim->start_busy(1)
d.less   = me->add("force",-50)

四.plan_king3：
chance = 80>random(100)
b.damage = heal=me->query("max_force")/30    ps:victim->add("force",-heal)
c.busy   = victim->start_busy(1)
d.cure   = me->add("force",heal)
e.less   = me->add("sen",-15)

五.plan_king4：
a.chance = 80>random(100)
b.damage=me->query("combat_exp")/60000*12
c.less   = me->add("force",-(random(25)+50));

MARK：me->query("mark/sixgod-plan",1)


***************************************************************************************************/

//=================================    沒解過    ======================================

void special_attack(object me, object victim, object weapon, int damage)
{
  if(!me || !victim) return;
  damage = me->query_skill("force");
  if(80 > random(100) && me->query_temp("conti") != 1 && me->query("family/family_name")=="儒門")
  {
    message_vision(HIB"\n$N使出看家本領, 頓時狂風大作, 手中"HIW+ weapon->query("name")+HIB"幻化出陣陣剛氣, \n", me, victim);
    message_vision("忽左忽右, 似慢實快, 似輕實重地朝$n狂劈而來。\n"NOR, me, victim);
    victim->receive_damage("kee", damage,me);
    COMBAT_D->report_status(victim);
    me->add("force",-25);
  }
  else
  {
    message_vision(HIB"\n$N使出看家本領, 頓時狂風大作, 手中"HIW+ weapon->query("name")+HIB"幻化出陣陣剛氣, \n", me, victim);
    message_vision("忽左忽右, 似慢實快, 似輕實重地朝$n狂劈而來。\n"NOR, me, victim);
    message_vision(HIW"不過$n身形更快, 巧妙的避過了$N的這致命的一擊\n"NOR, me, victim);
  }
}

void sp_att1(object me, object victim, object weapon, int damage)
{
  if(!me || !victim) return;
  if( 80>random(100) && me->query_temp("conti") != 1 && me->query("family/family_name")=="儒門")
  {
    if( present("ten pen", me))
    {
      damage = (me->query_cor()*5)+random(me->query_cor()*10);
      message_vision("\n"HIY"$N口裡默唸："HIM"『筆鋒流轉，遍體寒光，冷蒼之月，凍化成芒』"NOR"\n"
        ""HIY"$N潛運詩易心法，腳踏冬霜冰雪步法，手裡靈龍天筆頓時發出陣陣剛氣。"NOR"\n"
        ""HIY"只見四周空氣結成陣陣寒霜，朝$n激射而至，射穿了$n的護體真氣，造成重創"NOR"\n",me,victim);
    }
    else
    {
      damage=me->query_cor()*5;
      message_vision(HIW"$N隨意揮撒手中"HIG+ weapon->query("name")+HIW"，只見陣陣剛氣朝$n激射而出\n"NOR,me,victim);
    }
    victim->receive_damage("kee", damage,me);
    if(!victim->is_busy()) victim->start_busy(1);
    COMBAT_D->report_status(victim);
    me->add("force",-25);
  }
}

void sp_att2(object me, object victim, object weapon, int damage)
{
  if(!me || !victim) return;
  damage=me->query("bellicosity")/20;
  if(80>random(100) && me->query_temp("conti") != 1 && me->query("family/family_name")=="儒門")
  {
    int i;
    for(i=1;i<=4;i++)
    {
      message_vision(HIW"你握起手中之諸鳳劍筆，以筆代劍，順時點破絕式精妙之處，十分流暢的使出劍招！\n"NOR,me,victim);
      switch(i)
      {
        case 1:
          message_vision(sprintf(HIW"$N使出『"HIC"劍～影～誘～敵"HIW"』，以無數虛招迷惑$n。\n"NOR),me,victim);
          break;
        case 2:
          message_vision(sprintf(HIY"$N使出"HIW"『"HIC"劍～勢～困～敵"HIW"』"HIY"，以無數劍勢困住$n。\n"NOR),me,victim);
          break;
        case 3:
          message_vision(sprintf(HIG"$N使出"HIW"『"HIC"劍～招～殺～敵"HIW"』"HIG"，以無數劍招殺向$n。\n"NOR),me,victim);
          break;
        case 4:
          message_vision(sprintf(HIC"$N使出"HIW"『"HIC"劍～鋒～滅～敵"HIW"』"HIC"，以鋒利劍鋒殺滅$n。\n"NOR),me,victim);
          break;
      }
      victim->receive_damage("kee",damage,me);
      if(!victim->is_busy()) victim->start_busy(1);
      COMBAT_D->report_status(victim);
    }
    me->add("force",-25);
  }
}

//=================================    解過 Fire King    ======================================

void sp_att3(object me, object victim, object weapon, int damage)
{
  int i;
  int time;
  if(!me || !victim) return;
  time=me->query("combat_exp")/750000;
  if(time>15) time = 15;
  if(80>random(100) && me->query_temp("conti") != 1 && me->query("family/family_name")=="儒門")
  {
    message_vision("\n\n"HIW"$N再緩緩將真氣運轉入任督二脈，順時真氣充盈於全身之中，使出儒門鎮教秘招"NOR"\n"
                       ""HIW"               『～儒～教～極～招～"HIC"君"HIW"～"HIC"子"HIW"～"HIC"風"HIW"～』"NOR"\n"
                       ""HIW"$N真氣隨掌而去，並帶動四周氣流擊向$n，$n如失線之風箏受創飛起。"NOR"\n\n",me,victim);
    if(!me->query("plan-quest/ko-fire-king"))
    {
      for(i=0;i<time;i++)
      {
        message_vision(HIB"$N"HIB"連綿不絕的掌氣擊中了$n"HIB"。\n"NOR, me, victim);
        victim->receive_damage("kee", 20,me);
        me->add("force",-7);
        COMBAT_D->report_status(victim);
      }
    }
    else
    {
      for(i=0;i<(time+random(time));i++)
      {
        victim->receive_damage("kee", 50,me);
        message_vision(HIW""BRED"$N取出諸葛孔明所創之連弩，向$n絕發而出！\n"NOR,me,victim);
        COMBAT_D->report_status(victim);
        me->add("force",-7);
      }
    }
  }
}

void speed1(object me, object victim, object weapon, int damage)
{
  int i;
  int time;
  if(!me || !victim) return;
  time = me->query("combat_exp")/1000000;
  if(time>5) time = 5;
  time = 3 + random(time);
  damage=(random(100))+100;
  if(80>random(100) && me->query_temp("conti") != 1 && me->query("family/family_name")=="儒門")
  {
    if(!me->query("plan-quest/ko-fire-king"))
    {
      message_vision(HIB"\n$N手中"HIG+ weapon->query("name")+HIY"電光火石"HIB"般連連顫動, 自$n"HIR"靈台穴"HIB"一路順勢而下, \n"NOR, me, victim);
      victim->receive_damage("kee", damage,me);
      COMBAT_D->report_status(victim);
      me->add("force",-25);
    }
    else
    {
      message_vision(HIB"\n$N手中"HIG+ weapon->query("name")+HIY"電光火石"HIB"般連連顫動, 自$n"HIR"靈台穴"HIB"一路順勢而下, \n"NOR, me, victim);
      message_vision(HIB"使的是儒門的"HIW"行雲流水筆法"HIB"中最凌厲的絕招, 在$n督脈的每一穴道都點上了一下。\n"NOR, me, victim);
      if( me->query_temp("conti") != 1 )
      {
        me->set_temp("conti",1);
        for(int k=0 ; k<time ; k++)
        {
          COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        }
        me->delete_temp("conti");
        me->add("force",-35);
      }
    }
  }
  else
  {
    message_vision(HIB"\n$N手中"HIW+ weapon->query("name")+HIB"電光火石般連連顫動, 自$n靈台穴一路順勢而下, \n"NOR, me, victim);
    message_vision(HIW"不過$n身形更快, 巧妙的避過了$N的這致命的一擊\n"NOR, me, victim);
  }
}

//=================================    解過儒尊 & EXP>500萬    ======================================

void speed2(object me, object victim, object weapon, int damage)//dam:傷害力
{
  int i;
  int time;
  if(!me || !victim) return;
  time = ( me->query("combat_exp")/2000000 );
  if(time>9) time = 9;
  time = 5 + random(time);
  if(me->query("mark/sixgod-plan",1) && me->query("combat_exp")>5000000 && me->query("force")>100 && me->query_temp("conti") != 1 && me->query("family/family_name")=="儒門")
  {
    if(80>random(100))
    {
      message_vision(HIY"\n$N手中"HIW+ weapon->query("name")+HIG"電光火石"HIY"般連連顫動, 自$n"HIC"靈台穴"HIY"一路順勢而下, \n"NOR, me, victim);
      message_vision("使的是儒門的"HIW"行雲流水筆法"HIY"中最凌厲的絕招, 在$n督脈的每一穴道都點上了一下。\n"NOR, me, victim);
      if( me->query_temp("conti") == 0 )
      {
        me->set_temp("conti",1);
        for(int k=0 ; k<time ; k++)
        {
          COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        }
        me->delete_temp("conti");
        me->add("force",-50);
      }
    }
  }
  else
  {
    message_vision(HIB"\n$N手中"HIW+ weapon->query("name")+HIB"電光火石般連連顫動, 自$n靈台穴一路順勢而下, \n"NOR, me, victim);
    message_vision(HIW"不過$n身形更快, 巧妙的避過了$N的這致命的一擊\n"NOR, me, victim);
  }
}

void plan_king1(object me, object victim, object weapon, int damage)
{
  int heal;
  if(!me || !victim) return;
  heal=me->query("max_force")/20;
  if( heal > 1000) heal= random(200)+300;
  if(me->query("kee")<me->query("max_kee") && me->query("mark/sixgod-plan",1) && me->query("combat_exp")>5000000 && 80>random(100) && me->query_temp("conti") != 1 && me->query("family/family_name")=="儒門")
  {
    message_vision(HIW"\n$N運起詩易心法裡之六韜護身內勁，一陣白煙從頭頂上帽出。\n"NOR,me);
    me->receive_curing("gin",heal/10);
    me->receive_heal("gin",heal/10);
    me->receive_curing("kee",heal);
    me->receive_heal("kee",heal);
    me->receive_curing("sen",heal/10);
    me->receive_heal("sen",heal/10);
    me->add("force",-(heal/4));
  }
}

void plan_king2(object me, object victim, object weapon, int damage)
{
  if(!me || !victim) return;
  if(me->query("mark/sixgod-plan",1) && me->query("combat_exp")>5000000 && 80>random(100) && me->query_temp("conti") != 1 && me->query("family/family_name")=="儒門")
  {
    message_vision(HIW"\n$N拿起道具『六甲天書』，口中念出咒文，讓$n身心受到極大的傷害！\n\n"NOR,me,victim);
    victim->receive_damage("kee", 200+random(200),me);
    COMBAT_D->report_status(victim);
    if(!victim->is_busy()) victim->start_busy(1);
    me->add("force",-50);
  }
}

void plan_king3(object me, object victim, object weapon, int damage)
{
  int heal=me->query("max_force")/30;
  if(!me || !victim) return;
  if(me->query("mark/sixgod-plan",1) && me->query("combat_exp")>5000000 && 80>random(100)  && me->query_temp("conti") != 1 && me->query("family/family_name")=="儒門")
  {
    message_vision(HIY"
               $N將"HIW"奇書六韜"HIY"置掌上，身上氣勁蘊藏著六韜武學
           之巔，$N叱喝迴盪"HIR"『運籌帷幄 戰無不勝』"HIY"不斷向四周吸引氣勁！\n"NOR,me);
    me->add("force",heal);
    me->add("sen",-30);
    victim->add("force",-heal);
    if(!victim->is_busy()) victim->start_busy(1);
   }
}

void plan_king4(object me, object victim, object weapon, int damage)
{
  if(!me || !victim) return;
  damage=me->query("combat_exp")/80000;
  if(me->query("mark/sixgod-plan",1) && me->query("combat_exp")>5000000 && me->query("force")>1000 && 80>random(100) && me->query_temp("conti") != 1 && me->query("family/family_name")=="儒門")
  {
    message_vision("\n\n               "HIR""BMAG"=========="HIW"『"HIY"極火一出，萬物具焚"HIW"』"HIR"==========\n"NOR,me);
    message_vision("         "HIC""BMAG"只見$N手中的"HIG+ weapon->query("name")+HIC""BMAG"幻化成一把利劍，瘋狂的向$n刺去。\n"NOR,me,victim);
    message_vision("\n\n"+
      HIW"     ▅"RED"▄▄▄▄"NOR+HIG" ▋"BGRN+HIR":"BBLU+HIW"◢"NOR+HIW"████████████████████████◣\n"NOR+
      "     "HIK+BWHT"▂"GRN+BRED"▃▃▃▃"NOR+WHT" ▋"BGRN+HIR":"+NOR+WHT+BBLU+"◥"NOR+WHT"▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇◤\n\n",me);
    message_vision(HIC"$N快意的使出行雲流水筆法第一式"HIW"『"NOR"行雲流"HIB"水"HIW"』"HIC"，筆意源源不絕的向$n刺去！\n"NOR,me,victim);
    if(random(3) != 1) {victim->receive_wound("kee",damage,me);} COMBAT_D->report_status(victim,1);
    message_vision(HIC"$N快意的使出行雲流水筆法第二式"HIW"『"HIG"七步成"HIC"詩"HIW"』"HIC"，筆意源源不絕的向$n刺去！\n"NOR,me,victim);
    if(random(3) != 1) {victim->receive_wound("kee",damage,me);} COMBAT_D->report_status(victim,1);
    message_vision(HIC"$N快意的使出行雲流水筆法第三式"HIW"『"HIW"把"HIR"酒"NOR"問天"HIW"』"HIC"，筆意源源不絕的向$n刺去！\n"NOR,me,victim);
    if(random(3) != 1) {victim->receive_wound("kee",damage,me);} COMBAT_D->report_status(victim,1);
    message_vision(HIC"$N快意的使出行雲流水筆法第四式"HIW"『"HIY"菊"HIM"園盡興"HIW"』"HIC"，筆意源源不絕的向$n刺去！\n"NOR,me,victim);
    if(random(3) != 1) {victim->receive_wound("kee",damage,me);} COMBAT_D->report_status(victim,1);
    message_vision(HIC"$N快意的使出行雲流水筆法第五式"HIW"『"HIR"拗步斜行"HIW"』"HIC"，筆意源源不絕的向$n刺去！\n"NOR,me,victim);
    if(random(3) != 1) {victim->receive_wound("kee",damage,me);} COMBAT_D->report_status(victim,1);
    message_vision(HIC"$N快意的使出行雲流水筆法第六式"HIW"『"NOR"迎門"HIB"鐵"HIR"扇"HIW"』"HIC"，筆意源源不絕的向$n刺去！\n"NOR,me,victim);
    if(random(3) != 1) {victim->receive_wound("kee",damage,me);} COMBAT_D->report_status(victim,1);
    message_vision(HIC"$N快意的使出行雲流水筆法第七式"HIW"『"HIB"翻"HIR"花"HIY"舞"HIG"袖"HIW"』"HIC"，筆意源源不絕的向$n刺去！\n"NOR,me,victim);
    if(random(3) != 1) {victim->receive_wound("kee",damage,me);} COMBAT_D->report_status(victim,1);
    message_vision(HIC"$N快意的使出行雲流水筆法第八式"HIW"『"HIB"風"NOR"掃"HIR"梅花"HIW"』"HIC"，筆意源源不絕的向$n刺去！\n"NOR,me,victim);
    if(random(3) != 1) {victim->receive_wound("kee",damage,me);} COMBAT_D->report_status(victim,1);
    message_vision(HIC"$N快意的使出行雲流水筆法第九式"HIW"『"HIB"魁星"HIM"點"NOR"斗"HIW"』"HIC"，筆意源源不絕的向$n刺去！\n"NOR,me,victim);
    if(random(3) != 1) {victim->receive_wound("kee",damage,me);} COMBAT_D->report_status(victim,1);
    message_vision(HIC"$N快意的使出行雲流水筆法第十式"HIW"『"NOR"轉"HIB"龍"HIG"迴"HIR"日"HIW"』"HIC"，筆意源源不絕的向$n刺去！\n"NOR,me,victim);
    if(random(3) != 1) {victim->receive_wound("kee",damage,me);} COMBAT_D->report_status(victim,1);
    message_vision(HIC"$N快意的使出行雲流水筆法十一式"HIW"『"HIB"雲"HIR"開"HIY"龍"HIB"騰"HIW"』"HIC"，筆意源源不絕的向$n刺去！\n"NOR,me,victim);
    if(random(3) != 1) {victim->receive_wound("kee",damage,me);} COMBAT_D->report_status(victim,1);
    message_vision(HIC"$N快意的使出行雲流水筆法十二式"HIW"『"HIB"靈"HIR"龍"HIY"筆"HIB"書"HIW"』"HIC"，筆意源源不絕的向$n刺去！\n"NOR,me,victim);
    if(random(3) != 1) {victim->receive_wound("kee",damage,me);} COMBAT_D->report_status(victim,1);
    me->add("force",-(random(25)+50));
  }
}


/***************************************************************************************************
設定          learn  ，  enable  ，  mapping  ，  practice  ，  perform 
***************************************************************************************************/

// valid_learn 只是檢查是否可以學, 不能在此加 skill
int valid_learn(object me)
{
  if ((int)me->query_skill("literate")*2<(int)me->query_skill("knowpen"))
    return notify_fail("你的讀書識字程度不夠﹐不能領悟其中的道理。\n");
  return 1;
}

int valid_enable(string usage)
{
  return (usage=="stabber")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
  // skill level < 40 只能使用前 9 招
  if( me->query_skill("knowpen",1) < 40)
    return action[ random( sizeof( action)- 4)];
  // skill level > 50 不使用前 4 招...增加特攻使用率...
  else
    return action[ random( sizeof( action)- 4)+ 4];
}

// 這個只是查詢是否可以練習, 增加 skill 不是在這兒.
int practice_skill(object me)
{
  object weapon;

  me->receive_damage("sen",30);
  if (me->query_skill("literate")*2<me->query_skill("knowpen"))
    return notify_fail("你的讀書識字不夠﹐不能領悟其中的道理。\n");
  if( !objectp(weapon = me->query_temp("weapon")) ||
    ( string)weapon->query("skill_type")!="stabber")
  {
    return notify_fail("你要有適合的武器才能練行雲流水筆法。\n");
  }
  if( ( int)me->query("sen")<30)
    return notify_fail("你的神不夠﹐不能練行雲流水筆法。\n");
  return 1;
}

string perform_action_file(string action)
{
  return CLASS_D("scholar")+"/knowpen/"+action;
}
