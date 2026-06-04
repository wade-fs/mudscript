//調整因為箭的色碼導致的攻擊訊息顏色不同 by blazakira 2010/10/20
//將receive_damage的攻擊參數補上攻擊方之參數 by blazakira 2011/4/23
//將非本派卻使用本技能時 以bow_action表示 by blazakira 2011/8/7
//加入敵人是否存在的判斷 by blazakira 2013/9/9

#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void upforce(object me, object victim, object  weapon, int damage);
void god_att(object me, object victim, object  weapon, int damage);
void shooting_att(object me,object *victim,object weapon,int damage);
int remove_upforce(object me);

mapping *arrow_action = ({
// 1
        ([      "action":
HIC + "$N隨風運轉﹐初招乍現﹐霎時間﹐$c" + HIC + "已隨$N$P應手架於$w" + HIC + "之身﹐隨象萬變而去﹐剎時$c" + HIC + "已從$N之手飛往$n的$l!!" + NOR,
                "dodge":       -10,
                "parry":       -30,
                "damage":       200,
                "force":        200,
                "damage_type": "刺傷",
                ]),
// 2
        ([      "action":
HIC + "$N使著優雅的指尖﹐從身後抽出了一支$c" + HIC + "﹐隨著$N$P的手臂在空中甩出一個半圓﹐只見$c" + HIC + "如流風般射向$n!!" + NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       200,
                "force":        200,
                "damage_type": "刺傷",
                "post_action":  (:upforce:),
        ]),
// 3
        ([      "action":
HIC + "$N高舉起$w" + HIC + "﹐" + NOR + "銳利的$c" + HIC + "順著$w" + HIC + "在半空中畫下一道完美的弧線﹐隨式一招" + HIR + "「" + HIG + "阡陌人迴" + HIR + "」
" + HIC + "往$n的$l飛射直去!!" + NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       200,
                "force":        200,
                "damage_type": "刺傷",
        ]),
// 4
        ([      "action":
HIC + "$N輕巧地將$c" + HIC + "搭於$w" + HIC + "之上﹐使出流星箭疾訣奔式" + HIR + "「" + HIM + " 一洩千里 " + HIR + "」" + HIC + "﹐霎時箭勢
如奔流狂河疾去﹐遁地而行﹐直射$n的下盤!!" + NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       100,
                "force":        100,
                "damage_type": "射傷",
   "post_action":    (: upforce :),
        ]),
// 5
        ([        "action":
HIC + "$N將內力運如浪波不斷貫入$w" + HIC + "上之$c" + HIC + "﹐使出流星箭疾訣破式" + HIR + "「" + HIB + "破龍驚天" + HIR + "」" + HIC + "﹐只見$c" + HIC + "箭身旋氣不羈﹐如惡龍
狂噬般地朝$n的$l狂奔擊去!!" + NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       150,
                "force" :       150,
                "damage_type": "射傷",
                "post_action": (:god_att:),
]),
// 6
        ([      "action":
HIC + "$N以落英之勢迴盪手肘﹐奔放之態取出$c" + HIC + "搭於$w" + HIC + "﹐彈指之間$c" + HIC + "已射出﹐這正是流星箭疾訣落式" + HIW + "「" + HIY + "萬昂寰宇" + HIW + "」" + HIC + "﹐
箭勢倉昂雋潔﹐直奔$n的$l而去!!" + NOR,
                "dodge":         -10,
                "parry":         -30,
                "damage":        150,
                "force":         150,
                "damage_type": "射傷",
                "post_action": (: upforce :),
        ]),
// 7
        ([      "action":
HIC + "$N手落萬方﹐以內力輔助氣息之運行﹐$c" + HIC + "似流星狂飛向$n的$l狂奔而去﹐此招正式流星箭疾訣醉式" + BLU + "「" + HIB + "啣觴射日" + BLU + "」" + HIC + "﹐
$c" + HIC + "箭勢拔挺立魄﹐雄風偉健﹐奔向$n的$l!!" + NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       170,
                "force":        170,
                "damage_type": "射傷",
                "post_action": (: shooting_att:),
]),
// 8
        ([      "action":
HIC + "$N聚氣凝神﹐靜其心志﹐手執$w" + HIC + "直視$n﹐$c" + HIC + "以萬馬奔騰之勢飛洩而出﹐此招正是流星箭疾訣靜式" + GRN + "「" + HIG + "望穿秋水" + GRN + "」" + HIC + "﹐
直衝$n的$l!!" + NOR,
                "dodge":       -10,
                "parry":       -30,
                "damage":       200,
                "force":        200,
                "damage_type": "射傷",
        ]),
// 9
        ([      "action":
HIC + "$N調停內息﹐發勁於手中的$c" + HIC + "上﹐左手放弦任箭飛揚﹐此招乃是流星箭疾訣烈式" + RED + "「" + HIR + "烈日儔陽" + RED + "」" + HIC + "﹐氣勢滂沱﹐箭疾風嘐﹐
直往$n的$l射去!!" + NOR,
                "dodge":       -10,
                "parry":      -30,
                "damage":       220,
                "foece":        220,
                "damage_type": "射傷",
                "post_action": (:god_att:),
]),
// 10
        ([      "action":
HIC + "$N以躬代劍﹐身步輕盈迅捷猛建﹐直奔$n眼前﹐以弓身直劈$n的$l﹐此招乃是流星箭疾訣無箭式" + HIW + "『誅天落日』" + HIC + "﹐
力道猛擊$n$l!!" + NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       250,
                "force":        250,
                "damage_type": "射傷",
                "post_action": (: upforce :),
        ]),
// 11
        ([      "action":
HIC + "$N以手握$c" + HIC + "﹐睥睨$n而威氣不減﹐意入" + HIC + "冰心訣" + HIC + "中" + HIW + "舞弄起清影" + HIC + "的境界﹐箭勢虎魄龍威﹐浩氣直逼$n﹐氣道直衝手腕" + HIY + "
『奔池、落合』" + HIC + "二穴﹐適時下使流星箭疾訣疾式" + HIW + "『" + HIB + "百步穿楊" + NOR+HIW + "』" + HIC + "﹐飛箭狂出直逼$n的$l!!" + NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       270,
                "force":        270,
                "damage_type": "射傷",
        ]),
// 12
        ([      "action":
HIC + "$N以朝$n連射三發$c" + HIC + "﹐其意以欺敵而用﹐驟時又發飛箭千許\隻﹐箭箭勢如破竹﹐驍勇難當﹐頓時$N以施以流星箭疾訣" + YEL + "
『" + HIY + "杯弓蛇影" + NOR+YEL + "』" + HIC + "﹐箭勢直衝$n的$l!!" + NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       300,
                "force":        300,
                "damage_type": "射傷",
                "post_action": (: upforce :),
        ]),
// 13
        ([      "action":
HIC + "$N自持$w" + HIC + "﹐蕭然吟道﹕" + HIC + "『" + HIY + "雲籠月﹐風弄鐵﹐兩般兒﹐助人淒切" + HIC + "』﹐適時提出腰際間的$c" + HIC + "﹐傲然射出﹐風嘯鶴唳﹐
箭疾傲遠﹐此招正是流星箭疾訣素招" + HIG + "『" + HIC + "乘風歸去" + HIG + "』" + HIC + "﹐$c" + HIC + "如影隨形地直奔向$n的$l去!!" + NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       300,
                "force":        300,
                "damage_type": "射傷",
                "post_action":  (: shooting_att :),
]),
// 14
        ([      "action":
HIC + "$N直視$n之所在﹐並觀風聽聞以求箭準﹐體內氣勁直衝手臂" + HIY + "『和陽、虞池』" + HIC + "兩穴﹐順其內功\心法﹐意入" + HIW + "亂石崩雲﹐驚濤裂岸﹐
捲起千堆雪" + HIC + "中之豪氣﹐手中之$c" + HIC + "飛奔而出﹐箭拔弩張﹐疾風列嘯﹐$c" + HIC + "以驚人之勢直往$n的$l射去﹐此招正是流星箭
疾訣極至" + HIW + "『" + HIR + "怒" + RED + "火" + HIR + "遼" + RED + "原" + NOR+HIW + "』" + HIC + "﹐箭勢傲然狂飆﹐直射往$n的$l處!!" + NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       300,
                "force":        300,
                "damage_type": "射傷",
                "post_action":  (: shooting_att :),
        ]),
// 15
        ([      "action":
HIC + "$N體會流星箭法中的" + HIB + "奧妙" + HIC + "﹐手中握起$w" + HIC + "﹐瞬時取箭數十餘隻﹐緩緩念道﹕" + HIG + "「一點浩然氣﹐千里快哉風。」
" + HIC + "使出射日派武學中最高箭法" + NOR + "——",
                "dodge":        -10,
                "parry":        -30,
                "damage":       300,
                "force":        300,
                "damage_type": "射傷",
                "post_action": (: shooting_att :),
]),
// 16
(["action":"你不是射手不能用其技能。",
"damage":10,
"damage_type": "白癡傷",
]),
});

// 下面是沒箭時的攻擊敘述
mapping *bow_action = ({
  (["action"     : "$N舉起$w狠狠地往$n$l砸去。",
    "damage"     : 10,
    "damage_type": "瘀傷",
  ]),
  (["action"     : "$N吃力地揮舞$w試著打傷$n。",
    "damage"     : 10,
    "damage_type": "瘀傷",
  ]),
});

int valid_learn(object me)
{
  object ob;
  if(me->query_skill("archery",1)<15)
    return notify_fail("要練流星箭法要先有相當的弓箭基礎。\n");
  if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type")!="archery")
    return notify_fail("你手上要有弓箭才能練流星箭法。\n");
  return 1;
}

int valid_enable(string usage)
{
  return usage=="archery" || usage=="parry";
}

string perform_action_file(string action)
{
  return CLASS_D("marksman")+"/god-shooting/"+action;
}

mapping query_action(object me, object weapon)
{
  int skill;
  object enemy;
  object wpn = me->query_temp("weapon");
  int i,j,p;
  p=random(10);
  if(userp(me) && me->query("family/family_name")!="射日派") return bow_action[random(sizeof(bow_action))]; //其他門派使用就當作staff才對 by blazakira

  i=wpn->query("arrow/amount");
  if( !userp(me) ) i++;
  //新增 解過fire-king , exp 三百萬以上 
  if(p < 7 && me->query("quest/gold-fire")==1 && me->query("combat_exp") > 3000000 &&
      me->query("family/family_name")=="射日派" && me->query("force") > 300 && i > 1 &&
      !me->query_temp("berserk") && me->is_fighting() )
  {
    i--;
    enemy=offensive_target(me); //圍攻時 敵人可能被隊友打倒以至於死掉或不存在時 重新判斷 by blazakira
    if( !enemy ) return arrow_action[random(1)]; //先加入是否為戰鬥中的判斷參數 by blazakira

    if(p==1)
    {
      message_vision("  
  　　　　 $N　使　出　流　星　箭　法　之　" + HIG + "奧　義　秘　招" + NOR + "　『　" + HIY + "流　星　七　訣　箭" + NOR + "　』
　　　　　　　　 $N反手取出背後的武器，氣運丹田，將體內翻騰的內勁運至箭內
　　　　　　　　　　　　 " + HIC + "※水　沁　訣※" + NOR + "　" + HBCYN + "《　水～影～濤～天　》" + NOR + "
         只見箭矢不急不徐地往$n而去，霎時箭勢一轉，如海嘯狂噬般地朝著$n而去。
                " + NOR, me, enemy);
      enemy->receive_damage("sen",me->query_skill("archery")+340,me);
      me->add("force",-100);
    }
    if(p==2)
    {
      message_vision("
　　　　　 $N　使　出　流　星　箭　法　之　" + HIG + "奧　義　秘　招" + NOR + "　『　" + HIY + "流　星　七　訣　箭" + NOR + "　』
　　　　　　 $N將身法提升至極限，迅速地搭弓射箭，箭影幻化，剎那間幻化出無數箭影
　　　　　　　　　　　　 " + MAG + "※暴　雨　訣※" + NOR + "　" + BMAG + "《　怒～雨～狂～嘯　》" + NOR + "
　　　   $n被這尤如雨下的千萬箭影所迷惑，不知如何閃躲，箭影以驚人之勢直往$n射去。
                " + NOR, me, enemy);
      enemy->receive_damage("gin",me->query_skill("archery")+340,me);
      me->add("force",-100);
    }
    if(p==3)
    {
      message_vision("  
　　　　　 $N　使　出　流　星　箭　法　之　" + HIG + "奧　義　秘　招" + NOR + "　『　" + HIY + "流　星　七　訣　箭" + NOR + "　』
　　　　　　　　 箭拔弩張，只見箭身旋氣不羈，疾風列嘯，形成一龍捲氣流
　　　　　　　　　　　　 " + CYN + "※狂　風　訣※" + NOR + "　" + BGRN + "《　風～影～無～痕　》" + NOR + "
             只見箭勢傲然狂奔，夾帶著龍捲風刃直直的往$n而去。
                " + NOR, me, enemy);
      enemy->receive_damage("kee",me->query_skill("archery")+340,me);
      me->add("force",-100);
    }
    if(p==4)
    {
      message_vision("  
　　　　　 $N　使　出　流　星　箭　法　之　" + HIG + "奧　義　秘　招" + NOR + "　『　" + HIY + "流　星　七　訣　箭" + NOR + "　』
　　　　　　　　　 $N配合自身心法，將冰寒內力提昇至最高，彈指間連射兩箭
　　　　　　　　　　　　 " + HIC + "※寒　霜　訣※" + NOR + "　" + HBCYN + "《　寒～霜～飛～雪　》" + NOR + "
　　　　　　　 只見箭矢幻化成兩道冰龍，剛柔並濟，一快一慢的直奔向$n。　　　　　　　
                " + NOR, me, enemy);
      enemy->receive_damage("kee",me->query_skill("archery")+40,me);
      enemy->apply_condition("cold",3);
      enemy->start_busy(1);
      me->add("force",-100);
    }
    if(p==5)
    {
      message_vision("  
　　　　　 $N　使　出　流　星　箭　法　之　" + HIG + "奧　義　秘　招" + NOR + "　『　" + HIY + "流　星　七　訣　箭" + NOR + "　』
　　　　　　　 只見$N簡潔有力，毫無多餘的動作，隨意射出一箭，招式璞\而不華
　　　　　　　　　　　　 " + YEL + "※地　動　訣※" + NOR + "　" + BYEL + "《　地～動～山～搖　》" + NOR + "
 　　　  箭矢夾帶著一股極大力量排山倒海般直奔$n，$n抵擋不住這股力量因而倒退了七八步。　　　　　
                " + NOR, me, enemy);
      enemy->receive_damage("kee",me->query_skill("archery")+500,me);
      me->add("force",-100);
    }
    if(p==6)
    {
      message_vision("  
　　　　　 $N　使　出　流　星　箭　法　之　" + HIG + "奧　義　秘　招" + NOR + "　『　" + HIY + "流　星　七　訣　箭" + NOR + "　』
　　　　　　 $N潛運真氣，體內陽剛之氣不斷提昇，突然真氣爆吐，內勁流入箭矢中
　　　　　　　　　　　　 " + HIR + "※烈　焰　訣※" + NOR + "　" + BRED + "《　火～翔～鳳～鳴　》" + NOR + "
         箭矢蘊含的陽剛之氣形成一隻火鳳，火鳳迅速地將$n給吞噬，將$n燒的遍體鱗傷。
                " + NOR, me, enemy);
      enemy->receive_damage("kee",me->query_skill("archery")+240,me);
      enemy->apply_condition("burn",3);
      me->add("force",-100);
    }
    if(p==0)
    {
      message_vision("  
　　　　　 $N　使　出　流　星　箭　法　之　" + HIG + "奧　義　秘　招" + NOR + "　『　" + HIY + "流　星　七　訣　箭" + NOR + "　』
　　　　　　 $N縱躍至天際，吸取天象之氣，真氣爆吐，箭矢順勢破雲而出
　　　　　　　　　　　　 " + HIB + "※雷　電　訣※" + NOR + "　" + HBBLU + "《　雷～震～九～天　》" + NOR + "
             只見箭矢尤如天雷般直奔$n，並以強大的電流襲擊$n全身，令他痛苦不已。
                " + NOR, me, enemy);
      enemy->receive_wound("kee",me->query_skill("archery")+240,me);
      me->add("force",-100);
    }
    me->set_temp("berserk", 1);
    COMBAT_D->do_attack(me,enemy,me->query_temp("weapon"), TYPE_QUICK);
    me->delete_temp("berserk");
  }

  if(i<=1) {
    tell_object(me, "\n你的" + wpn->query("arrow/name") + "用完了﹗\n\n");
    wpn->set("arrow/id","none");
    wpn->set("arrow/name","空的");
    wpn->set("weapon_prop/damage",wpn->query("bow/attack"));
  }
  if( i <= 0) { return bow_action[random(sizeof(bow_action))]; }
  else {
    i--;
    wpn->set("arrow/amount",i);
    skill = (int)me->query_skill("god-shooting", 1);
    if (skill < 7 ) return arrow_action[random(3)];
    else if (skill < 14 ) return arrow_action[random(4)];
    else if (skill < 21 ) return arrow_action[random(5)];
    else if (skill < 28 ) return arrow_action[random(6)];
    else if (skill < 35 ) return arrow_action[random(6)+1];
    else if (skill < 42 ) return arrow_action[random(7)+1];
    else if (skill < 49 ) return arrow_action[random(7)+2];
    else if (skill < 56 ) return arrow_action[random(8)+2];
    else if (skill < 63 ) return arrow_action[random(8)+3];
    else if (skill < 70 ) return arrow_action[random(9)+3];
    else if (skill < 77 ) return arrow_action[random(10)+3];
    else if (skill < 84 ) return arrow_action[random(11)+3];
    else if (skill < 91 ) return arrow_action[random(12)+3];
    else return arrow_action[random(11)+4];
  }
}

void upforce(object me, object victim, object  weapon, int damage)
{
  int skill = (int)me->query_skill("force")/10;
  int bell = (int)me->query("bellicosity")/100;
  if(bell>40) bell=40;
  if( bell < 20 ) return ;
  if(!me->query_temp("upforce") && !me->query_temp("berserk") && random(100)>50) {
    message_vision(RED + "\n\n$n" + HIR + "噴出的鮮血激起了" + NOR+RED + "$N" + HIR + "的瘋狂殺意" + HIY + "～～﹗﹗" + HIR + "頓時" + HIY + "﹐" + NOR+RED + "$N的" + HIB + "狂殺之氣" + HIR + "籠罩方圓十里之地" + HIY + "。\n\n" + NOR, me, victim);
    me->set_temp("oldforce",me->query("force_factor"));
    me->set("force_factor",bell+skill);
    me->set_temp("upforce",1);
    call_out("remove_upforce",10,me);
  }
}

int remove_upforce(object me)
{
  if(!me) return 1;
  me->set("force_factor",me->query_temp("oldforce"));
  me->delete_temp("oldforce");
  me->delete_temp("upforce");
  message_vision(HIW + "\n$N" + HIW + "殺意漸漸消退" + NOR + "﹐" + HIW + "臉上的殺意也沒之前的沉重" + NOR + "。\n", me);
  return 1;
}

void god_att(object me, object victim, object  weapon, int damage)
{
  if(50>random(100)&&!me->query_temp("berserk"))
  {
    victim->start_busy(1);
    message_vision(HIB + "$N暗使冰心訣之陰寒內勁，將$n受內勁所困動彈不得。\n" + NOR, me, victim);
  }
}

void shooting_att(object me,object *victim,object weapon,int damage)
{
  object *target;
  int i,j,k,l,m;
  int bellpower = (int)me->query_cor()/5;
  int exp= me->query("combat_exp");
  if(me->query("env/no_shooting") == "YES") return;
  if(exp >=0 && exp <=500000)
    l=1;
  if(exp > 500000 && exp <=1000000)
    l=2;
  if(exp > 2000000 && exp <= 3500000)
    l=3;
  if(exp > 3500000 && exp <=5000000)
    l=4;
  if(exp > 5000000 && exp <=7000000)
    l=5;
  if(exp > 7000000 && exp <=10000000)
    l=6;
  if(exp > 10000000 && exp <=15000000)
    l=7;
  if(exp > 15000000 && exp <=20000000)
    l=8;
  if(exp > 20000000 )
    l=9;
  m=random(5)+l;
  target=me->query_enemy();
  k=sizeof(target);
  if(random(100)<50 && !me->query_temp("berserk"))
  {
    me->set_temp("berserk", 1);
    for(i = 0;i < m; i++)
    {
      for(j=0;j<k;j++) {
        if(!target[j]) continue;
        message_vision(HIR + "\n$N拿起數支箭使勁的往$n連射過去——" + NOR,me,target[j]); //斷行(\n)改在前方 因為上面的攻擊敘述已有斷行 避免重複 by blazakira
        COMBAT_D->do_attack(me,target[j],me->query_temp("weapon"), TYPE_QUICK);
      }
    }
    message_vision(HIW + "一陣混亂後﹐$N用勁過度﹐趕緊趁機調息。\n" + NOR,me);
    me->start_busy(1);
    me->delete_temp("berserk");
    weapon=me->query_temp("weapon");
    if(weapon->query("super_bow") && me->query("family/family_name")=="射日派")
    {
      message_vision(HIY + "可是$N手中的$n" + HIY + "卻發出了淡淡藍光，似乎將精力注入$N體內，讓$N隨時可以戰鬥!!\n" + NOR,me,weapon);
      me->add("force",-20);
      me->delete_busy();
    }
  }
}
