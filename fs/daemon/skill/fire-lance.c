//燎原百擊 by bss
#include <ansi.h>
#include <combat.h>
void sp_attack(object me,object victim,object weapon,int damage);
void sp1(object me,object victim,object weapon,int damage);
void sp2(object me,object victim,object weapon,int damage);
inherit SKILL;

string *parry_msg=({
        "$n身軀一引, 手中$w將$N的攻勢盡數曳了開去。\n",
        "$n把手中的$w舞成圓環, 將$N的攻勢盡數擋了下來。\n",
        "$n以靜制動, 平舉手中$w, 無招勝有招, 化解了$N的攻勢!\n",
        });

mapping *action = ({
        ([
                "action"     :
"$N使出" + HIR + "燎原百擊的" + NOR + "起手式" + HIY + "「火星乍現」" + NOR + "，手中$w向$n標去，槍頭點起的氣勁，
便像一粒粒火星熾屑，，專破內家護體真氣，傷人於無形，厲害非常\n",
                "dodge"      :                -500,
                "damage"     :                750,
                "damage_type":               "內傷",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp2:),
        ]),
        ([
                "action"     :
"$N使出" + HIR + "燎原百擊" + NOR + "中的" + HIC + "「疊浪千重」" + NOR + "，手中$w湧出重重槍浪，由左至右，
挑刺正撲上來的$n\n",
                "dodge"      :                -500,
                "damage"     :                145,
                "damage_type":               "刺傷",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp2:),
        ]),
        ([
                "action"     :
"$N使出" + HIR + "燎原百擊之" + HIM + "「無定擊」" + NOR + "，手中$w晃動不已，使$n完全不
知道$w將攻向自己的那裡，正當$n在分心的時刻，$w忽然標出，
疾刺往$n的$l\n",
                "dodge"      :               -500,
                "damage"     :                165,
                "damage_type":               "刺傷",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp2:),
        ]),
        ([
                "action"     :
"$N使出" + HIR + "燎原百擊" + NOR + "之" + HIC + "「風暴雨狂」" + NOR + "，手中$w以極快的速度晃動，槍影
吞吐間，使$n產生了有很多把$w同時在攻擊自己的錯覺，使得$n跟
本不知道該如何防禦。\n",
                "dodge"      :                -500,
                "damage"     :                200,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "damage_type":                "穿體之傷",
                "post_action":  (:sp2:),
         ]),
         ([
                "action"     :
"$N使出" + HIR + "燎原百擊" + NOR + "之" + HIB + "「無槍勢」" + NOR + "，$N忽然將手中$w藏到背後，由有槍變成無槍，
使$n完全掌握不到$w下一步的變化，正當$n搞不清楚狀況的時候，$w
忽然從$N的腰旁標出，刺向$n的$l\n",
                "dodge"      :                -500,
                "damage"     :                220,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "damage_type":                "刺傷",
                "post_action":  (:sp2:),
         ]),
         ([
                "action"     :
"$N使出" + HIR + "燎原百擊" + NOR + "之" + HIY + "「借勁反」" + NOR + "，手中$w向前疾刺，$n用力一擋卻發現$N
竟可藉由巧妙的吸勁將$n的氣勁完全吸納，當勁力由槍尾傳出前，已給
$N掉轉了$w，加上$N的力道，由槍尾送出，當$n迎上槍尾的時候，等若同
時受到自己及$N的勁力，試問$n如何抵受得了?\n",
                "dodge"      :                -500,
                "damage"     :                350,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "damage_type":                "擊傷",
                "post_action":  (:sp2:),
         ]),
         ([
                "action"     :
"$N一生長嘯，使出" + HIR + "燎原百擊" + NOR + "之"BLINK+HIG + "「威凌天下」" + NOR + "，一時間$N身前廣闊空間，槍影
翻騰滾動，嗤嗤氣勁交擊奔騰，$N像藏身在一個槍浪裏，朝$n疾速的移去，
$N人還未到，因招式所引起的氣流已先一步的攻向$n\n",
                "dodge"      :                -500,
                "damage"     :                550,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "damage_type":                "割傷",
                "post_action":  (:sp2:),

         ]),
        ([
                "action"     :
"$N將手中$w一擺\，使出" + HIR + "燎原百擊" + NOR + "之" + HBRED+HIY + "「橫掃千軍」" + NOR + "，手中$w以一往無回，
與敵偕亡的氣勢朝$n掃去，槍勁有如波濤洶湧的巨浪，鋪天蓋\地的向
$n襲去\n",
                "dodge"      :                -500,
                "damage"     :                800,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "damage_type":               "刺傷",
                "post_action":  (:sp2:),
        ]),
        ([
                "action"     :
"$N眼中精光一閃，使出" + HIR + "燎原槍法" + NOR + "中的" + YEL + "「斜挑勢」" + NOR + "，槍影渙散，
似拙實巧地由下上挑，藉$w之長，挑向$n的手腕。\n",
                "dodge"      :               -500,
                "damage"     :                700,
                "damage_type":               "刺傷",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp2:),
        ]),
        ([
                "action"     :
"$N看也不看，施出" + HIR + "燎原槍法" + NOR + "之" + HIY + "「左右吞吐」" + NOR + "，當$w槍頭掃往$n的$l的時候
槍尾也順勢擊向$n，使$n連防禦的機會也沒有\n",
                "dodge"      :                -500,
                "damage"     :                800,
                "damage_type":               "擊傷",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp2:),
        ]),
        ([
                "action"     :
"$N狂喝一聲，兩手一送，使出" + HIR + "「燎原百擊」" + NOR + "中的"BLINK+HIC + "「虛有其表」" + NOR + "，$w
化作一道閃電，追上$n，「啪！」的一聲$n掌緣切在槍鋒處，立時
魄散魂飛，原來掌觸處空虛無力，紅槍觸手往地上掉去。原來
這招「虛有某表」真的只是虛張聲勢，只看著速度來勢、聽著破空之聲
，任誰都會相信這槍貫滿了力道，於是全力擋格，而犯下這使自己陷於
死境的錯誤\n",
                "dodge"      :                -500,
                "damage"     :                0,
                "damage_type":               "內傷",
                "post_action":  (:sp_attack:),
        ]),
        ([
                "action"     :
"$N使出" + HIR + "燎原槍法" + NOR + "內詭異之極的"BLINK+HIM + "「平地風生」" + NOR + "，腳跺槍尾，把槍翹起
並較正了角度。運勁一挑，$w立時由地上激射斜上，正中$n。\n",
                "dodge"      :                -500,
                "damage"     :                800,
                "damage_type":               "破體之傷",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp1:),
        ]),
});
int valid_learn(object me)
{
        return 1;
}
int valid_enable(string usage)
{
        return (usage=="lance");
}
mapping query_action(object me, object weapon)
{
                return action[random(sizeof(action))];
}
string perform_function_file(string func)
{
        return "/u/b/bss/" + func;
}

void sp_attack(object me,object victim, object weapon,int damage)
{
 if(!me->query_temp("conti")){
  message_vision(HIY + "\n$N因為耗費了太多的內力在檔格上，一時間無法動彈，任人宰割。\n" + NOR,victim);
  victim->start_busy(5);
  call_out("berserk",0,me,victim,weapon);
  }
}
void sp1(object me, object victim, object  weapon, int damage)
{
   message_vision(HIR + "「啊～～～～～～～～」" + NOR + "的一聲慘叫\n",victim);
   message_vision("$N被$n貫體而過，$n插在地上時還在不住的晃動\n",victim,weapon);
   victim->receive_damage("kee",(victim->query("kee")+1),me);
   victim->receive_wound("kee",(victim->query("kee")+1),me);
}
void sp2(object me, object victim, object  weapon, int damage)
{
 int skill_level=me->query_skill("fire-lance",1),bound;
 bound = victim->query("max_kee");
 bound = (bound/100)*5;
  if( (random(170) < 27 && me->query("force",1) > 100) || me->query_temp("super_lance") )
  {
    if(!me->query_temp("berserk2"))
    {
    if(weapon->query("id")=="red lance")
     {
       message_vision(
         sprintf(HIW + "\n$N忽然眼放精光，大喝一聲「風雲連續槍」，剎那間四週湧起一道黑雲，使$n完全失去$N的蹤影!!\n\n" + NOR),me ,victim);
       message_vision(
         sprintf(HIW + "\n$N以傳音之術對$n說到:「接招吧」，招式如狂風般朝$n襲至!!\n\n" + NOR),me ,victim);
       message_vision(
 sprintf(HIW + "\n風雲連續槍第一式" + HIB + "『行雲流水』" + HIW + "，" + HIR + "丈二紅槍" + HIW + "有如流水般朝$n攻去，使人目不暇己\n" + NOR),me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續槍第二式" + HIB + "『披星戴月』" + HIW + "，" + HIR + "丈二紅槍" + HIW + "忽然朝$n直刺過去，刺中了$n身上幾大要穴\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續槍第三式" + HIB + "『翻雲覆雨』" + HIW + "，" + HIR + "丈二紅槍" + HIW + "如風車般在$N身旁轉了起來，$n被槍招所產生的\n\n螺漩氣流所侵，受了重傷\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續槍第四式" + HIB + "『排山倒海』" + HIW + "，$N將" + HIR + "丈二紅槍" + HIW + "插入土地，跟著用力拔起，隨" + HIR + "丈二紅槍" + HIW + "而飛起的土石\n\n擊中了$n\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續槍第五式" + HIB + "『重雲深鎖』" + HIW + "，$N用手中" + HIR + "丈二紅槍" + HIW + "在$n身上畫了十幾個小圓圈，$n\n\n忽然身體一震，動彈不得\n\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
      message_vision(
 sprintf(HIW + "\n風雲連續槍第六式" + HIB + "『風捲殘樓』" + HIW + "，$N拔身而起，槍隨身轉，如一道龍捲風般朝$n攻去\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續槍第七式" + HIB + "『狂風暴雨』" + HIW + "，槍招連綿不絕的朝$n攻去，使$n身受重創\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續槍第八式" + HIB + "『神風怒嚎』" + HIW + "，" + HIR + "丈二紅槍" + HIW + "在空間中快速的砍劈，使四週產生了巨大的破空聲\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續槍第九式" + HIB + "『撕天排雲』" + HIW + "，" + HIR + "丈二紅槍" + HIW + "迅速的向左右各劈了兩下，槍氣快速地攻向$n\n" + NOR), me ,victim,weapon);
 victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續槍第十式" + HIB + "『雲海波濤』" + HIW + "，槍氣如巨浪狂湧而至，$n連閃避的機會也沒有\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW + "\n風雲連續槍第十一式" + HIB + "『殃雲天絳』" + HIW + "，$N躍至空中，手中" + HIR + "丈二紅槍" + HIW + "朝$n直劈而去，槍氣充斥著這整個空間\n" + NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
     message_vision(
 sprintf(HIW + "\n$N使完槍法一十一式後，週圍的黑雲漸漸地消散了。\n\n" + NOR), me ,victim);

}
}
}
}
int berserk(object me,object victim,object weapon)
{
        int i,j;
    if(!victim) return 1;
    if(!me->is_fighting() || !victim->is_fighting())   return 1;
 if(!me->query_temp("conti")){
  message_vision(HIC + "$N眼見$n無法動彈，抓住機會，使出非常耗內力之連續技!!!\n" + NOR,me,victim);
  me->set_temp("conti",1);
  switch(random(5)){
        case 1:
                j=2;
                break;
        case 2:
                j=3;
                break;
        case 3:
                j=4;
                break;
        case 4:
                j=5;
                break;
        case 5:
                j=6;
                break;
        default:
                j=4;
                break;
     }
   for(i=0;i<j;i++)

    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

    me->delete_temp("conti");
    me->add("force",-(j*500));
    me->start_busy(1);
                     }
}
