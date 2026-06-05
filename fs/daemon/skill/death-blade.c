
//==========================================
//死亡樂章 by inmoon 
//重編 by ＣＫＢＯＹ
//如果有需要改的地方麻煩加上註解‧‧‧
//==========================================
#include <combat.h>
#include <ansi.h>
inherit SSERVER;
inherit SKILL;
void dea3(object me, object target, object  weapon, int damage);
void dea1(object me, object victim, object  weapon, int damage);
void dea2(object me, object target, object  weapon, int damage);
void dea4(object me, object target, object  weapon, int damage);
void dea5(object me, object target, object  weapon, int damage);
void seven(object me, object victim, object  weapon, int damage);
mapping *action = ({
//1
(["action":
HIM + "\n\n        ＊＊＊＊＊＊＊＊＊＊＊＊ " + HIR + "≡ " + HIY + "死‧亡‧樂‧譜 " + HIR + "≡ " + HIM + "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n" + HIC + "                               ◣  " + HIW + "序  章 " + HIC + "～ " + HIR + "血 祭 " + HIC + " ◥\n\n\n" + HIW + "      冰冷的殺意帶著重重刀影以排山倒海之勢飛襲而出，將目標圍在核心之中，刀光閃處，鮮血\n" + HIW + "      四散，$N宛如死神般地佇立在鮮血之中。" + NOR + "\n\n",     
    "force":               100,
    "damage":               500,
    "damage_type" : "砍傷" ,
    "post_action":          (: dea1 :),
]),
//2
(["action":
HIM + "\n\n        ＊＊＊＊＊＊＊＊＊＊＊＊ " + HIR + "≡ " + HIY + "死‧亡‧樂‧譜 " + HIR + "≡ " + HIM + "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n" + HIC + "                               ◣  " + HIW + "第一章 " + HIC + "～ " + HIB + "罪 詠" + HIC + "  ◥\n\n\n" + HIW + "     光的照耀下，數個身影急速地盤旋飛舞，$N一邊將真力灌注在刀上，一邊伺機使出致命的一擊，\n" + HIW + "     刀應聲將敵人的胸口對穿而過，挾帶的力道使得周圍的空氣不安地擾動起來。" + NOR + "\n\n",  
    "force":               100,
    "damage":               500,
    "damage_type" : "砍傷" ,
    "post_action":          (: dea4 :),
]),
//3 
(["action":
HIM + "\n\n        ＊＊＊＊＊＊＊＊＊＊＊＊ " + HIR + "≡ " + HIY + "死‧亡‧樂‧譜 " + HIR + "≡ " + HIM + "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n" + HIC + "                               ◣  " + HIW + "第二章 " + HIC + "～ 罰 詠 ◥ \n\n\n" + HIW + "     光與暗交會之際，數道刀痕以不同的速度方向，帶著一定的規律，將對手的一切生路封死，光即\n" + HIW + "     將消逝之時，$N的眼中朦朧地映照出被分屍的人影。" + NOR + "\n\n",    
    "force":               100,
    "damage":               500,
    "damage_type" : "砍傷" ,
    "post_action":          (: dea4 :),
]),
//4 
(["action":
HIM + "\n\n        ＊＊＊＊＊＊＊＊＊＊＊＊ " + HIR + "≡ " + HIY + "死‧亡‧樂‧譜 " + HIR + "≡ " + HIM + "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n" + HIC + "                               ◣  " + HIW + "第三章 " + HIC + "～ " + HIR + "制 裁 " + HIC + "◥\n\n\n" + HIW + "     黑暗的籠罩中，所帶來的只有不安、害怕、以及無助，在幾乎寂靜的空間中，忽然一道破空之聲\n" + HIW + "     響起，妳沾滿鮮血的刀上又結束了一條雙手沾滿血腥的生命。\n\n" + NOR,    
    "force":               100,
    "damage":               500,
    "damage_type" : "砍傷" ,
    "post_action":          (: dea2 :),
]),
//5 
(["action":
HIM + "\n\n        ＊＊＊＊＊＊＊＊＊＊＊＊ " + HIR + "≡ " + HIY + "死‧亡‧樂‧譜 " + HIR + "≡ " + HIM + "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n" + HIC + "                               ◣  " + HIW + "第四章 " + HIC + "～ " + HIY + "神 罰 " + HIC + "◥\n\n\n" + HIW + "     在光影交錯之時空，事物盡為虛幻不實，$N藉著光影所構成的幻象，宛如反射般地形成了數個人\n" + HIW + "     影，在敵人混淆不清之時，一刀刺入了他的心臟。\n\n" + NOR,
    "force":               100,
    "damage":               500,
    "damage_type" : "砍傷" ,
    "post_action":          (: dea1 :),
]), 
//6 
(["action":
HIM + "\n\n        ＊＊＊＊＊＊＊＊＊＊＊＊ " + HIR + "≡ " + HIY + "死‧亡‧樂‧譜 " + HIR + "≡ " + HIM + "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n" + HIC + "                                ◣  " + HIW + "第五章 " + HIC + "～ " + HIG + "天 誅 " + HIC + "◥\n\n\n" + HIW + "     這時天空雷聲大振，風雲變色，$N縱身一跳，在空中以手上的刀吸收大自然間的雷電之力，藉著\n" + HIW + "     下墜的衝勢，狠狠地將敵人一刀劈成了兩半。\n\n" + NOR,
    "force":               100,
    "damage":               500,
    "damage_type" : "砍傷" ,
    "post_action":          (: dea3 :),
]),
//7 
(["action":
HIM + "\n\n        ＊＊＊＊＊＊＊＊＊＊＊＊ " + HIR + "≡ " + HIY + "死‧亡‧樂‧譜 " + HIR + "≡ " + HIM + "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n" + HIC + "                                ◣  " + HIW + "第六章 " + HIC + "～ " + HIM + "" + HIW + "闇" + NOR+WHT + "月" + NOR+HIW+HBWHT + "隕星" + NOR+HIC + "◥\n\n\n" + HIW + "     $N腳踩清風，手攀明月，凌空躍起數十丈高，讓身體自然地下沉，像顆殞星般地朝$n筆\n" + HIW + "     直地降落，將所憎恨的對手的頭骨踩得粉碎。$n的鮮血宛如噴泉一般" + HIR + "血" + HIW + "˙" + HIR + "花" + HIW + "˙" + HIR + "四" + HIW + "˙" + HIR + "散\n\n" + NOR,
    "force":               100,
    "damage":               500,
    "damage_type" : "砍傷" ,
    "post_action":          (: dea5 :),
]),
//8
(["action":
HIM + "\n\n        ＊＊＊＊＊＊＊＊＊＊＊＊ " + HIR + "≡ " + HIY + "死‧亡‧樂‧譜 " + HIR + "≡ " + HIM + "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n" + HIC + "                                ◣  " + HIW + "第七章 " + HIC + "～ " + HIW + "帶刀步月" + NOR+HIC + "◥\n\n\n" + HIW + "     $N併攏五指，在明月之下隱約透出" + HIR + "紅" + HIW + "˙" + HIR + "色" + HIW + "˙" + HIR + "閃" + HIW + "˙" + HIR + "光" + HIW + "。忽然一團黑影挾帶一絲血光掠過了$n\n" + HIW + "     的小腹，一股血箭噴了出來，這時在$n的背後，$N貪婪的舔舐著手掌的鮮血\n\n" + NOR,
    "force":               100,
    "damage":               500,
    "damage_type" : "砍傷" ,
    "post_action":          (: dea2 :),
]),
//9
(["action":
HIM + "\n\n        ＊＊＊＊＊＊＊＊＊＊＊＊ " + HIR + "≡ " + HIY + "死‧亡‧樂‧譜 " + HIR + "≡ " + HIM + "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n" + HIC + "                                 ◣  " + HIW + "第八章 " + HIC + "～ " + HIY + "新月切斬" + NOR+HIC + "◥\n\n\n" + HIW + "     $N冰冷的臉上浮現充滿殺意的微笑，一道無形的殺氣激射而出，將$n的身軀攔腰斬斷，\n" + HIW + "     $n四散的鮮血將這道殺氣浸染成一彎明亮的" + HIR + "血" + HIW + "˙" + HIR + "色" + HIW + "˙" + HIR + "新" + HIW + "˙" + HIR + "月\n\n" + NOR,
    "force":               100,
    "damage":               500,
    "damage_type" : "砍傷" ,
    "post_action":          (: dea4 :),
]),
//10
(["action":
HIM + "\n\n        ＊＊＊＊＊＊＊＊＊＊＊＊ " + HIR + "≡ " + HIY + "死‧亡‧樂‧譜 " + HIR + "≡ " + HIM + "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n" + HIC + "                                 ◣  " + HIW + "第九章 " + HIC + "～ " + NOR+RED + "血色大地" + NOR+HIC + "◥\n\n" + HIW + "     $N嗜殺的眼神中飄出一絲殺意，對手感到腳下一股寒意而下意識地跳起。瞬間妳跨越了兩人間\n" + HIW + "     的距離，手上沾滿著血腥停留在$n的面前，以所憎恨的對象的鮮血將這污穢的大地進\n" + HIW + "     行一場神聖的" + HIR + "血" + HIW + "˙" + HIR + "之" + HIW + "˙" + HIR + "洗" + HIW + "˙" + HIR + "禮\n\n" + NOR,
    "force":               100,
    "damage":               500,
    "damage_type" : "砍傷" ,
    "post_action":          (: seven :),
]),
//11
(["action":
HIM + "\n\n        ＊＊＊＊＊＊＊＊＊＊＊＊ " + HIR + "≡ " + HIY + "死‧亡‧樂‧譜 " + HIR + "≡ " + HIM + "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n" + HIC + "                                 ◣  " + HIW + "終 章 " + HIC + "～ " + HIM + "滅 殺 " + HIC + "◥\n\n\n" + HIW + "     $N身隨刀走，一瞬間使出了所有的招式，在同一時間全部擊向對手的那時，一股巨大的能量爆發\n" + HIW + "     出來，當一切回歸平靜之際，方圓數尺之內已無生命現象，全都歸於虛無。\n\n" + NOR,
    "force":               100,
    "damage":               600,
    "damage_type" : "內傷" ,
    "post_action":          (: seven :),
]),
 });
 int valid_enable(string usage)
{
        return usage=="blade" || usage=="parry";
}
mapping query_action(object me, object victim, object  weapon, int damage)
{
mapping do_action;
object *enemy,weaponn,target;
string actionn;
int i,j,k,l,force;
int limit,time,dam,heal;
limit=(int)(me->query_skill("death-blade",1));
enemy=me->query_enemy();
i=sizeof(enemy);
target=enemy[random(i)];
if(userp(target))damage = random((int)(me->query("MKS")+me->query("bellicosity"))/1200)* ((int)limit/20) + 
   me->query("force_factor",1) * (int)me->query("combat_exp")/200000;
else  damage = (int)(me->query("MKS")+me->query("bellicosity"))/600* ((int)limit/10)+
   me->query("force_factor",1) * (int)me->query("combat_exp")/100000;
k = (int)limit/10;
if(k > 8) k =8;
heal = (int)me->query("max_force")/200;
//      ============ mapping 特攻第一招 ： 七色死亡 ===============
//         招式數量為　殺人數(MKS) 50000 多一擊，最後二擊打全
dam = (int)damage/(random(2)+1);
time = (int)me->query("MKS")/50000;
if(time > 7) time = 7;
if(me->query("class") == "blademan" && me->query("combat_exp")>=7000000 && me->query("MKS") > 50000 && random(me->query("bellicosity")) > 50000 && limit > 140)
{
message_vision(HIW + "\n               $N手起刀落，一招 " + HIC+HBBLU + "七色死亡" + NOR+HIW + " 鋪天蓋\地施展開來：\n\n\n" + NOR,me);
   for(l=0;l<time;l++)
   {
   switch(l)
   { 
    case 0:
    message_vision("\n                        "BLINK+HIR + "紅殺" + NOR+HIW + " ～ " + HBRED + "血染長城" + NOR+HIW + " ～\n\n\n
   □█   " + HIR + "╭╦═╦═╮    ╭═    ╭╯╭╯╭╯  ╮  ╮╭" + NOR+HIW + "     █□
   □█   " + HIR + "╭╯╮║    ╰╦╩══╯╰╯╠╣╰╯╰═╰╬╬╯" + NOR+HIW + "   █□
   □█   " + BRED + "║╮║║╭╮  ║        ╰╯╰╯╰╯╰═╰╣╠╯" + NOR+HIW + "   █□
   □█   " + BRED + "║╰║╠╯    ║        ╰═╬══╯╰═╰╩╩╯" + NOR+HIW + "   █□
   □█   " + HIR + "╰  ║║      ║          ║║╰╮  ╭═╠══╣" + NOR+HIW + "   █□
   □█   " + HIR + "╰═╯╰═╯  ╰═══╯╰╯╯  ╰╯╰═╰══╯" + NOR+HIW + "   █□
    \n\n" + NOR,me);
        enemy[random(i)]->receive_wound("kee",dam,me);
       COMBAT_D->report_status(enemy[random(i)]);
    break;
    case 1:
    message_vision("\n                        "BLINK+HIY + "黃殺" + NOR+HIW + " ～ " + HBYEL + "孤鴻遍野" + NOR+HIW + " ～\n\n\n
   □█   " + HIY + "╭╦═╦═╮    ╭═    ╭╯╭╯╭╯  ╮  ╮╭" + NOR+HIW + "     █□
   □█   " + HIY + "╭╯╮║    ╰╦╩══╯╰╯╠╣╰╯╰═╰╬╬╯" + NOR+HIW + "   █□
   □█   " + BYEL + "║╮║║╭╮  ║        ╰╯╰╯╰╯╰═╰╣╠╯" + NOR+HIW + "   █□
   □█   " + BYEL + "║╰║╠╯    ║        ╰═╬══╯╰═╰╩╩╯" + NOR+HIW + "   █□
   □█   " + HIY + "╰  ║║      ║          ║║╰╮  ╭═╠══╣" + NOR+HIW + "   █□
   □█   " + HIY + "╰═╯╰═╯  ╰═══╯╰╯╯  ╰╯╰═╰══╯" + NOR+HIW + "   █□
    \n\n" + NOR,me);

       i = random(sizeof(enemy));
       enemy[i]->receive_wound("kee",(int)dam*4/5);
       COMBAT_D->report_status(enemy[i]);
    break;
    case 2:
    message_vision("\n                      "BLINK+HIM + "粉紅殺" + NOR+HIW + " ～ " + HBMAG + "豪氣霸千丈" + NOR+HIW + " ～\n\n\n
   □█   " + HIM + "╭╦═╦═╮    ╭═    ╭╯╭╯╭╯  ╮  ╮╭" + NOR+HIW + "     █□
   □█   " + HIM + "╭╯╮║    ╰╦╩══╯╰╯╠╣╰╯╰═╰╬╬╯" + NOR+HIW + "   █□
   □█   " + BMAG + "║╮║║╭╮  ║        ╰╯╰╯╰╯╰═╰╣╠╯" + NOR+HIW + "   █□
   □█   " + BMAG + "║╰║╠╯    ║        ╰═╬══╯╰═╰╩╩╯" + NOR+HIW + "   █□
   □█   " + HIM + "╰  ║║      ║          ║║╰╮  ╭═╠══╣" + NOR+HIW + "   █□
   □█   " + HIM + "╰═╯╰═╯  ╰═══╯╰╯╯  ╰╯╰═╰══╯" + NOR+HIW + "   █□
    \n\n" + NOR,me);

       i = random(sizeof(enemy));
       enemy[i]->receive_wound("kee",(int)dam*2/3);
       COMBAT_D->report_status(enemy[i]);
    break;
    case 3:
    message_vision("\n                        "BLINK+HIC + "藍殺" + NOR+HIW + " ～ " + HBCYN + "長空一青" + NOR+HIW + " ～\n\n\n
   □█   " + HIC + "╭╦═╦═╮    ╭═    ╭╯╭╯╭╯  ╮  ╮╭" + NOR+HIW + "     █□
   □█   " + HIC + "╭╯╮║    ╰╦╩══╯╰╯╠╣╰╯╰═╰╬╬╯" + NOR+HIW + "   █□
   □█   " + BCYN + "║╮║║╭╮  ║        ╰╯╰╯╰╯╰═╰╣╠╯" + NOR+HIW + "   █□
   □█   " + BCYN + "║╰║╠╯    ║        ╰═╬══╯╰═╰╩╩╯" + NOR+HIW + "   █□
   □█   " + HIC + "╰  ║║      ║          ║║╰╮  ╭═╠══╣" + NOR+HIW + "   █□
   □█   " + HIC + "╰═╯╰═╯  ╰═══╯╰╯╯  ╰╯╰═╰══╯" + NOR+HIW + "   █□
    \n\n" + NOR,me);
       target->receive_wound("kee",dam,me);
       COMBAT_D->report_status(target);
    break;
    case 4:
    message_vision("\n                        "BLINK+HIG + "綠殺" + NOR+HIW + " ～ " + HBGRN + "殺神痴狂" + NOR+HIW + " ～\n\n\n
   □█   " + HIG + "╭╦═╦═╮    ╭═    ╭╯╭╯╭╯  ╮  ╮╭" + NOR+HIW + "     █□
   □█   " + HIG + "╭╯╮║    ╰╦╩══╯╰╯╠╣╰╯╰═╰╬╬╯" + NOR+HIW + "   █□
   □█   " + BGRN + "║╮║║╭╮  ║        ╰╯╰╯╰╯╰═╰╣╠╯" + NOR+HIW + "   █□
   □█   " + BGRN + "║╰║╠╯    ║        ╰═╬══╯╰═╰╩╩╯" + NOR+HIW + "   █□
   □█   " + HIG + "╰  ║║      ║          ║║╰╮  ╭═╠══╣" + NOR+HIW + "   █□
   □█   " + HIG + "╰═╯╰═╯  ╰═══╯╰╯╯  ╰╯╰═╰══╯" + NOR+HIW + "   █□
    \n\n" + NOR,me);
       i = random(sizeof(enemy));
       enemy[i]->receive_wound("kee",(int)dam*2/3);
       COMBAT_D->report_status(enemy[i]);
    break;
    case 5:
    message_vision("\n                         "BLINK+HIW + "白殺" + NOR+HIW + " ～ " + HBWHT + "渾沌異" + NOR+HIW + " ～\n\n\n
   □█   " + HIW + "╭╦═╦═╮    ╭═    ╭╯╭╯╭╯  ╮  ╮╭" + NOR+HIW + "     █□
   □█   " + HIW + "╭╯╮║    ╰╦╩══╯╰╯╠╣╰╯╰═╰╬╬╯" + NOR+HIW + "   █□
   □█   " + BWHT + "║╮║║╭╮  ║        ╰╯╰╯╰╯╰═╰╣╠╯" + NOR+HIW + "   █□
   □█   " + BWHT + "║╰║╠╯    ║        ╰═╬══╯╰═╰╩╩╯" + NOR+HIW + "   █□
   □█   " + HIW + "╰  ║║      ║          ║║╰╮  ╭═╠══╣" + NOR+HIW + "   █□
   □█   " + HIW + "╰═╯╰═╯  ╰═══╯╰╯╯  ╰╯╰═╰══╯" + NOR+HIW + "   █□

    \n\n" + NOR,me);
/*       i = sizeof(enemy);
       while(i--)
       {
*/
       target->receive_wound("kee", dam);
       COMBAT_D->report_status(enemy[i]);
//        }
 
    break;
    case 6:
    message_vision("\n                      "BLINK+HIB + "深藍殺" + NOR+HIW + " ～ " + HBBLU + "月掛琝壎" + NOR+HIW + " ～\n\n\n
   □█   " + HIB + "╭╦═╦═╮    ╭═    ╭╯╭╯╭╯  ╮  ╮╭" + NOR+HIW + "     █□
   □█   " + HIB + "╭╯╮║    ╰╦╩══╯╰╯╠╣╰╯╰═╰╬╬╯" + NOR+HIW + "   █□
   □█   " + BBLU + "║╮║║╭╮  ║        ╰╯╰╯╰╯╰═╰╣╠╯" + NOR+HIW + "   █□
   □█   " + BBLU + "║╰║╠╯    ║        ╰═╬══╯╰═╰╩╩╯" + NOR+HIW + "   █□
   □█   " + HIB + "╰  ║║      ║          ║║╰╮  ╭═╠══╣" + NOR+HIW + "   █□
   □█   " + HIB + "╰═╯╰═╯  ╰═══╯╰╯╯  ╰╯╰═╰══╯" + NOR+HIW + "   █□
    \n\n" + NOR,me);
/*       i = sizeof(enemy);
       while(i--)
       {
*/
       target->receive_wound("kee",dam);
       COMBAT_D->report_status(enemy[i]);
//       }
 
    break;
   }
 
 }
}
/*320
      if(random(4)>=2)
      {  
       message_vision(HIW + "\n
         $N右手自左腋出手一刀，刀光‧一閃‧一閃的刀光‧刀上藍燄大盛！\n
        " + HIW + "天地間飄曳起一道幽幽藍光，似真似幻，如沉靜的月光投入深邃的大海 \n
               " + HIW + "這一刀，極快、極速、極簡單、看去極平凡無奇‧‧‧ \n      
               " + HIW + "然而卻是“相思碎夢”一千零一式中所有的精華和殺招！\n
                           " + HIW + "『" + HIR + "舞刀‧捲塵‧風行斬" + HIW + "』 \n\n" + NOR, me);      
           k= sizeof(enemy);
           while(k--)
           {
                enemy[k]->receive_wound("kee",(int)random(me->query_con()) *damage);
                COMBAT_D->report_status(enemy[k]);
           }
       {
        message_vision(HIW + "\n
           一種乍看令人心動﹐細看足以讓人心血賁動的紅光﹐自刀身透了出來\n
                    " + HIW + "血紅般的刀氣有如太陽西下般撩繞在$n的周圍\n 
              " + HIW + "$n只覺得又快、又奇、又絕、驚豔、瀟灑、惆悵、不可一世\n
                                  " + HIW + "『" + HIC + "烽火紅塵路" + HIW + "』\n" + NOR,me,victim);
        message_vision(HBRED + "\n$N的烽火刀氣讓$n亂了方寸，迷失在烽火紅塵之中﹗\n" + NOR,me,victim);
        k= sizeof(enemy);
           while(k--)
           {
               enemy[k]->start_busy(random(4)+2);
               enemy[k]->receive_wound("kee",(int)random(me->query_con()) *damage);
               COMBAT_D->report_status(enemy[k]);
           }
     
     } 
*/

//==================   mapping 連擊 80 lv 以後可使用  =================
if( me->query("force")>1000 && limit > 80 && me->query_temp("weapon")->query("id")=="gich-blade"&& me->query("class") =="blademan" && me->query("MKS") > 50000) 
 {
 for(j=0; j < k ;j ++)
  {
  i = random(sizeof(enemy));
  if( limit < 20 )
     do_action= action[random(2)];
  else if ( limit < 40 )
     do_action= action[random(3)];
  else if ( limit < 60 )
     do_action= action[random(4)];
  else if ( limit <80)
     do_action= action[random(5)];
  else if ( limit <100)
     do_action= action[random(6)];
  else if ( limit <110)
     do_action= action[random(7)];
  else if ( limit <120)
     do_action= action[random(8)];
  else if ( limit <130)
     do_action= action[random(9)];
  else if ( limit <140)


     do_action= action[random(10)];
  else
     do_action= action[random(11)];
  actionn = do_action["action"];
  if( weaponn=me->query_temp("weapon") )
  actionn = replace_string(actionn, "$w", weaponn->name());         
if(me->query("env/no_act"))
{ 
     message_vision("[略]\n",me , victim);
}
else
{
     message_vision("\n"+actionn+"\n", me, victim);
}
       if( random(me->query("combat_exp")) > random(enemy[i]->query("combat_exp")) )
          {           
           message_vision(HIR + "   $N身隨刀走，一瞬間使出了所有的招式，在同一時間全部擊向對手的那時，一股巨大的能量爆發出來。\n" + NOR, me,enemy[i]);
           enemy[i]->receive_wound("kee",(int)damage/2,me);
           COMBAT_D->report_status(enemy[i]);
         }
        else 
      { 
       switch(random(3))
       {   
         case 1 : 
    message_vision(HIB + "\t\t\n$n" + HIB + "被一股刀勁振出，嚇的荒了手腳！\n" + NOR,me,enemy[i]);
    break;
    case 2 :   
    message_vision(HIB + "\t\t\n$n" + HIB + "$n在$N的猛烈刀勁下，嚇的左竄右竄，不知如何是好！！！\n" + NOR,me,enemy[i]);  
    break;      
    case 0:  
    message_vision(HIB + "\t\t\n$n" + HIB + "$N連環數刀，劈風之勢有如排山倒海，令$n一退再退，！！！\n" + NOR,me,enemy[i]);
    break;
       }  
      }           
    }
}

//action部分
  if( limit < 20 )
     return action[random(2)];
  else if ( limit < 40 )
     return action[random(3)];
  else if ( limit < 60 )
     return action[random(4)];
  else if ( limit <80)
     return action[random(5)];
  else if ( limit <100)
     return action[random(6)];
  else if ( limit <110)
     return action[random(7)];
  else if ( limit <120)
     return action[random(8)];
  else if ( limit <130)
     return action[random(9)];
  else if ( limit <140)
     return action[random(10)];
  else
     return action[random(11)];
}
void seven(object me, object target, object weapon, int damage)
{
int sk,bell,i,mks,j,exp;
 string arg;
 weapon=me->query_temp("weapon");
 exp=(int)me->query("combat_exp",1)/1000000+1;
 sk = (int)me->query_skill("death-blade",1)/10;
 mks = (int)me->query("MKS",1)/500;
 damage = (me->query_skill("death-blade",1)+mks);
 if(mks>40 && exp > 5 && sk >= 14 )
{
switch(random(2))
{
case 0:  
   message_vision("\n
" + HIW + "◤-- □■□■□■□■□■□■□■□■□■□■□■□■ -- ◥ 
∣                                                       ∣ 
∣   " + HIG+HBGRN + "刀" + NOR+HIY + "‧" + HIG+HBGRN + "鋒" + NOR+HIY + "‧" + HIG+HBGRN + "刀" + NOR + "                                          " + NOR+HIW + "∣
∣                                                       ∣
∣               " + HIC+HBCYN + "刀" + NOR+HIY + "‧" + HIC+HBCYN + "入" + NOR+HIY + "‧" + HIC+HBCYN + "心" + NOR+HIY + "‧" + HIC+HBCYN + "碎" + NOR + "                        " + NOR+HIW + "  ∣
∣                                                       ∣
∣                                " + HIM+HBMAG + "碎" + NOR+HIY + "‧" + HIM+HBMAG + "夢" + NOR+HIY + "‧" + HIM+HBMAG + "碎" + NOR+HIY + "‧" + HIM+HBMAG + "世" + NOR+HIY + "‧" + HIM+HBMAG + "情" + NOR + "    " + NOR+HIW + " ∣
∣                                                       ∣
◣-- □■□■□■□■□■□■□■□■□■□■□■□■ -- ◢   
\n\n                 " + HBBLU+HIW + "≡ " + HIC + "武。將‧之‧淚\ " + HIW + "≡\n\n" + NOR,me);   
  break;
case 1:
message_vision("\n
 
     " + HIW + "～ " + HIY + "刀" + HIW + "‧" + HIY + "鋒" + HIW + "‧" + HIY + "刀 " + HIW + "～
                         
                          ～ " + HIM + "刀" + HIW + "‧" + HIM + "入" + HIW + "‧" + HIM + "心" + HIW + "‧" + HIM + "碎 " + HIW + "～
 
 
           ～ " + HIG + "碎" + HIW + "‧" + HIG + "夢" + HIW + "‧" + HIG + "碎" + HIW + "‧" + HIG + "世" + HIW + "‧" + HIG + "情 " + HIW + "～
\n\n                 " + HBBLU+HIW + "≡ " + HIC + "武。將‧之‧淚\ " + HIW + "≡\n\n" + NOR,me); 
break;
}
     if(random(me->query("combat_exp")) > random(target->query("combat_exp")))if(random(5)>=2)
     {
     me->add("force",-50);
     i = random(6); 
     for(i;i<7;i++) //攻擊()的次數
      {  
switch(i)
{
//1 
case 0: arg =  "\n□■□■□■□■□■" + HIR + "☆" + HIW + "★ " + HIR + "" + HBRED + "幻空" + NOR + " " + HIW + "★" + HIR + "☆" + HIW + "□■□■□■□■□■\n
" + HIW + "『 $N手中之刀，" + NOR+WHT + "泛紅之光" + NOR+HIW + "乍現，斜飛起數道柔和的" + HIR + "暈紅" + HIW + "，
 
      " + HIR + "如幻似影" + HIW + "，如實若虛，" + NOR+WHT + "迷迷濛濛" + NOR+HIW + "的橫陳在天空！
只見刀芒一閃，已自$n" + NOR+WHT + "胸口飛穿而過" + NOR+HIW + "，鮮血不斷噴出，映照著天邊的" + HIR + "夕陽" + HIW + "！ 』 \n\n" + NOR; 
break;
//2
case 1: arg =  "\n□■□■□■□■□■" + HIG + "☆" + HIW + "★ " + HIG + "" + HBGRN + "碎夢" + NOR + " " + HIW + "★" + HIG + "☆" + HIW + "□■□■□■□■□■\n
  " + HIW + "『        似有" + HIG + "意" + HIW + "、似" + NOR+WHT + "無情" + NOR+HIW + "、斬" + NOR+WHT + "不斷" + NOR+HIW + "、理不" + HIG + "清" + HIW + "， 
                           像是一句" + NOR+WHT + "永不言悔" + NOR+HIW + "的" + HIW + "誓言" + HIW + "；像是一顆" + NOR+WHT + "至死不滅" + NOR+HIW + "的" + HIG + "心" + HIW + "   』\n\n" + NOR; 
break;
//3
case 2: arg =  "\n□■□■□■□■□■" + HIM + "☆" + HIW + "★ " + HIM + "" + HBMAG + "飛星" + NOR + " " + HIW + "★" + HIM + "☆" + HIW + "□■□■□■□■□■\n
" + HIW + "『 $N手中刀如" + HIM + "行雲流水" + HIW + "般的劃著，  
       只見" + NOR+WHT + "晃動之間" + NOR+HIW + "幻化出無數的異色星光宛如河流一般，
       
                  一招「" + HIM + "飛落星" + HIW + "」，無數的" + NOR+WHT + "星光急速" + NOR+HIW + "的攻向$n  』 \n\n" + NOR; 
break;
//4
case 3: arg =  "\n□■□■□■□■□■" + HIC + "☆" + HIW + "★ " + HIC+HBCYN + "雲間" + NOR + " " + HIW + "★" + HIC + "☆" + HIW + "□■□■□■□■□■" + NOR + "\n
 
       " + HIW + "『     " + NOR+WHT + "微風" + NOR+HIW + "掠過天空，" + HIC + "浮雲" + HIW + "各分西東  
　 
?        " + NOR+WHT + "微風" + NOR+HIW + "吹過" + HIC + "浮雲" + HIW + "，而" + HIC + "雲" + HIW + "還是" + HIC + "雲" + HIW + "，" + NOR+WHT + "風" + NOR+HIW + "還是" + NOR+WHT + "風" + NOR+HIW + "  』\n" + NOR; 
break;
//5      
case 4: arg =  "\n□■□■□■□■□■" + WHT + "☆" + HIW + "★ " + HIW + "" + HBWHT + "天地" + NOR + " " + HIW + "★" + WHT + "☆" + HIW + "□■□■□■□■□■\n

" + HIW + "『 一式搗入中心處，卻發現$N的刀好像是" + NOR+WHT + "漩渦般" + NOR+HIW + "生出一股吸勁，
    " + NOR+WHT + "抽絲剝繭" + NOR+HIW + "的將自己的力量抽掉，更進一步的要把$n吞沒，任$n的功\力 
         多高，被捲入這一招的中心也只有" + NOR+WHT + "力盡而亡" + NOR+HIW + "一途，駭然之下抽身猛退。 』\n\n" + NOR; 
break;
//6
case 5: arg =  "\n□■□■□■□■□■" + HIB + "☆" + HIW + "★ " + HIB + "" + HBBLU + "宙極" + NOR + " " + HIW + "★" + HIB + "☆" + HIW + "□■□■□■□■□■\n
『 $N突然" + HIB + "望天狂嘯" + HIW + "一聲，" + NOR+WHT + "連綿不絕" + NOR+HIW + "的刀影，有如天河突懸一般，
     自四面八方向$n疾捲而至！只見四周彷若" + NOR+WHT + "天雲變色" + NOR+HIW + "，" + HIB + "海嘯山崩" + HIW + "的巨響連聲而起，
 周遭的空氣好似驟然被排除一空，散裂飛芒的" + NOR+WHT + "泥沙塵土" + NOR+HIW + "，亦如" + HIB + "滿天花雨" + HIW + "般迸濺四周！！ 』\n\n" + NOR;
break; 
//7
case 6: arg =  "\n□■□■□■□■□■" + HIY + "☆" + HIW + "★ " + HIY + "" + HBYEL + "武傲" + NOR + " " + HIW + "★" + HIY + "☆" + HIW + "□■□■□■□■□■\n
    
   " + HIW + "『           面對$n的攻擊$N" + HIY + "視而不見" + HIW + "，" + NOR+WHT + "斜舉的刀" + NOR+HIW + "直劈而下。 
　　
這一刀，有如" + HIY + "閃電" + HIW + "般快速，卻又有如" + NOR+WHT + "龜行" + NOR+HIW + "般緩慢。 
　　      
                       有如" + HIY + "萬斤" + HIW + "巨石般重，卻又輕如" + NOR+WHT + "鴻毛" + NOR+HIW + "。 
　　彷彿是要將擋在眼前的障礙徹底，清除充滿了" + HIY + "一往無回" + HIW + "的氣勢。  』\n\n" + NOR; 
break;
  }         
message_vision(HIW + ""+arg+"\n" + NOR,me,target);
//        for(j=0;j<exp;j++)
//         {
           target->reveice_wound("kee",(int)((damage*exp)/4 + 1));
           COMBAT_D->report_status(target);
//         }
      }
       target->start_busy(random(2)+1);
   }
      else
      { 
       message_vision(HIB + "不料卻被$n躲開了$N凌厲的攻擊！\n" + NOR,me,target);
      }
}}
void dea2(object me, object target, object  weapon, int damage)
{
int time,i,sk,bell,mks,exp;
bell = me->query("bellicosity");
mks  = me->query("MKS");
exp  = me->query("combat_exp");
sk   = me->query_skill("death-blade",1);
time = mks/50000+1;
damage = (int)(mks+ bell)/1200+(int)me->query("combat_exp")/10000;
if(exp > 4000000 && bell > 50000 && mks > 30000 && sk > 130)
{
message_vision("\n\n
\t  " + HIW + "╭╦═══╮ ═╦═╔═╬╗  ═╦═══╦═ ═══╦═══
\t    ║      ║ ╦╯╮║╔╩╮  ╔╝      ╚╗ ╔╦═╬╦═╗
\t  " + HIW+HBMAG + "  ║      ║ ║  ║║║  ║  ╚╗      ╔╝  ╚╝╚╝╚╝ " + NOR + "
\t  " + HIW+HBMAG + "  ║      ║ ║  ║║║  ║  ═╩═══╩═ ═╦═╦═╦═" + NOR + "
\t    " + HIW + "║      ║ ║  ║║╰╦╯  ║║╰═╮★   ╭╰╮║╭╰╮
\t  ═╯      ╯ ╰═╝╯╚╯╝  ╯╚════╝ ╩═╩╩╩═╩\n\n
\t                      " + HIY + "惡" + HIR + "‧" + HIY + "殺" + HIR + "‧" + HIY + "九" + HIR + "‧" + HIY + "重" + HIR + "‧" + HIY + "天\n\n\n" + NOR,me);
if(time>9)time=9;
  for(i=1;i<=time;i++)
   {
     switch(i)
     {
     case 1:
     message_vision("\t                " + HIW + "⊙   " + HIR + "惡殺一重天" + HIW + "～" + HIR + "怒氣奔萬里   " + HIW + "⊙\n" + NOR,me);
     break;
     case 2:
     message_vision("\t                " + HIW + "⊙   " + HIR + "惡殺二重天" + HIW + "～" + HIR + "雷霆震四面   " + HIW + "⊙\n" + NOR,me);
     break;
     case 3:
     message_vision("\t                " + HIW + "⊙   " + HIR + "惡殺三重天" + HIW + "～" + HIR + "惡力撲八方   " + HIW + "⊙\n" + NOR,me);
     break;
     case 4:
     message_vision("\t                " + HIW + "⊙   " + HIR + "惡殺四重天" + HIW + "～" + HIR + "豪氣降千鬼   " + HIW + "⊙\n" + NOR,me);
     break;
     case 5:
     message_vision("\t                " + HIW + "⊙   " + HIR + "惡殺五重天" + HIW + "～" + HIR + "帝風威天下   " + HIW + "⊙\n" + NOR,me);
     break;
     case 6:
     message_vision("\t                " + HIW + "⊙   " + HIR + "惡殺六重天" + HIW + "～" + HIR + "愿懟殺無赦   " + HIW + "⊙\n" + NOR,me);
     break;
     case 7:
     message_vision("\t                " + HIW + "⊙   " + HIR + "惡殺七重天" + HIW + "～" + HIR + "恨盡天地人   " + HIW + "⊙\n" + NOR,me);
     break;
     case 8:
     message_vision("\t                " + HIW + "⊙   " + HIR + "惡殺八重天" + HIW + "～" + HIR + "玲瓏入神州   " + HIW + "⊙\n" + NOR,me);
     break;
     case 9:
     message_vision("\t                " + HIW + "⊙   " + HIR + "惡殺九重天" + HIW + "～" + HIR + "斬伐破眾惡   " + HIW + "⊙\n" + NOR,me);
     break;
     }
      if(me->query("combat_exp")> random(target->query("combat_exp"))/3 )
      {
       message_vision(HIB + "\n\t       $N運起內勁，刀氣一波波的使出。氣勢如萬馬奔騰，銳不可擋。\n" + NOR,me);
       target->receive_damage("kee",damage);
       COMBAT_D->report_status(target);
      }
      else
      {
       message_vision(WHT + "\n\t       $n身輕如燕，使出絕妙的輕功\，自$N最意想不到的地方躲去，避開了攻擊。\n" + NOR,me,target);
      }
   }
 }
}
void dea1(object me, object target, object  weapon, int damage)
{
int k,i,exp,mks,bell,sk;
bell = me->query("bellicosity");
mks  = me->query("MKS");
exp  = me->query("combat_exp");
sk   = me->query_skill("death-blade",1);
k = mks/50000+1;
damage = (int)(mks+bell)/600+sk * 50 ;
if(sk > 100 && exp > 4000000 && bell > 20000 && bell > 3000)
{
message_vision("\n\n 
\t" + HIY + "╔══╩══╯?╠══════   ═╮══╬══  ═══╔═╬╮
\t║╦╬╦╦╬╦    ═════       ║═╦╩╦═  ═╦═║  ║║
\t" + HIY+HBRED + "║╝║╚╝║╚? ══════╮    ║╚╯  ╰╝  ║║║╠═╬╣ " + NOR + "
\t" + HIY+HBRED + "║╔◎═╦═╮?  ═╮║╭═ ║    ╰ ╠══╮   ║║║║  ║║ " + NOR + "
\t" + HIY + "║╠═╦╬═╣?══╦╬╦═ ║    ╭ ╯  ╭╯   ╝║╚╰═╬╝
\t╯╭═╯╰═╣    ╰╝║╚╯ ╚  ═╯ ╰═╬═     ║      ║
\t                     " + HIR + "殺" + HIW + "‧" + HIR + "無" + HIW + "‧" + HIR + "赦" + HIW + "‧" + HIR + "八" + HIW + "‧" + HIR + "式" + NOR + "
\n\n" + NOR,me);
if(k>8)k=8;
    for(i=1;i<=k;i++)
   {
    switch(i)
    {
    case 1:
      message_vision("\t           " + HIR + "$N祭起 " + HIW + "☆☆ " + HIW+HBRED + "死亡樂章" + NOR + " " + HIW + "☆☆ " + HIR + "一式 " + HBRED + "殺眾生" + NOR + "\n" + NOR,me);
      break;
    case 2:
      message_vision("\t           " + HIR + "$N祭起 " + HIW + "☆☆ " + HIW+HBRED + "死亡樂章" + NOR + " " + HIW + "☆☆ " + HIR + "二式 " + HBRED + "斬紅顏" + NOR + "\n" + NOR,me);
      break;
    case 3:
      message_vision("\t           " + HIR + "$N祭起 " + HIW + "☆☆ " + HIW+HBRED + "死亡樂章" + NOR + " " + HIW + "☆☆ " + HIR + "三式 " + HBRED + "戰天地" + NOR + "\n" + NOR,me);
      break;
    case 4:
      message_vision("\t           " + HIR + "$N祭起 " + HIW + "☆☆ " + HIW+HBRED + "死亡樂章" + NOR + " " + HIW + "☆☆ " + HIR + "四式 " + HBRED + "砍六親" + NOR + "\n" + NOR,me);
      break;
    case 5:
      message_vision("\t           " + HIR + "$N祭起 " + HIW + "☆☆ " + HIW+HBRED + "死亡樂章" + NOR + " " + HIW + "☆☆ " + HIR + "五式 " + HBRED + "弒九族" + NOR + "\n" + NOR,me);
      break;
    case 6:
      message_vision("\t       ?  " + HIR + "$N祭起 " + HIW + "☆☆ " + HIW+HBRED + "死亡樂章" + NOR + " " + HIW + "☆☆ " + HIR + "六式 " + HBRED + "破迷咒" + NOR + "\n" + NOR,me);
      break;
    case 7:
      message_vision("\t           " + HIR + "$N祭起 " + HIW + "☆☆ " + HIW+HBRED + "死亡樂章" + NOR + " " + HIW + "☆☆ " + HIR + "七式 " + HBRED + "宰千鬼" + NOR + "\n" + NOR,me);
      break;
    case 8:
      message_vision("\t           " + HIR + "$N祭起 " + HIW + "☆☆ " + HIW+HBRED + "死亡樂章" + NOR + " " + HIW + "☆☆ " + HIR + "八式 " + HBRED + "誅萬仙" + NOR + "\n" + NOR,me);
      break;
    }
   target->receive_wound("kee",damage);
   COMBAT_D->report_status(target); 
    }
}
}
void dea3(object me, object target, object  weapon, int damage)
{
int k,i,exp,mks,bell,sk;
bell = me->query("bellicosity");
mks  = me->query("MKS");
exp  = me->query("combat_exp");
sk   = me->query_skill("death-blade",1);
k = mks/5000+1;
damage = (int)k/50+exp/10000+bell/5000 + me->query("force_factor",1) * (int)me->query("MKS")/5000 ;
if(sk>120 && exp > 4500000 && mks > 30000 && bell > 30000)
{
message_vision("\n\n 
     " + HIW + "□■□■□■□■□■□■□■□■□■□■□■□■□ 
     " + HIW + "█                                              █
     " + HIW + "█  " + HIR + "╔═══╗ ╦═╩══ ╔╔╩╗╗═╩╬═╬  " + HIW + "█
     " + HIW + "█  " + HBRED + "╔═╗╔   ║         ╠╠═╣╣ ═ ╣  ╠" + NOR+HIW + "  █
     " + HIW + "█  " + HBRED + "║  ║║╔ ║         ╚╚╦╝╝ ═ ╬═╬" + NOR+HIW + "  █
     " + HIW + "█  " + HBRED + "╚═╣╠╝ ║      ║ ╚╦╬╦╝╔╗╠═╣" + NOR+HIW + "  █
     " + HIW + "█  " + HIR + "╚═╝╚╝ ╚═══╝ ╚╝╝╚╝╚╝╚═╝  " + HIW + "█
     " + HIW + "█                                              █
     " + HIW + "□■□■□■□■□■□■□■□■□■□■□■□■□\n
   在死亡樂譜下，萬物無所遁形。被$N舞成的刀光下被各個擊倒。\n\n" + NOR,me,target);
if(k>10)k=10;
for(i=1;i<=k;i++)
   {
   message_vision("           " + HIW+HBBLU + "$N刀刀相連，繼起血光連綿不絕向$n殺去\n" + NOR,me,target);
   target->receive_wound("kee",damage);
   COMBAT_D->report_status(target);     
   }
}
}
void dea4(object me, object victim, object  weapon, int damage)
{
int mks = (int)me->query("MKS")/300;
int bell = (int)me->query("bellicosity")/600;
int time = (int)me->query("combat_exp")/10000000 + (int)me->query("MKS")/120000;
int i,sk;
sk = me->query_skill("death-blade",1);
damage = (mks+bell) + me->query("force_factor",1) * (sk/5);
if(sk > 140 && me->query("combat_exp") > 3000000 )
{
message_vision("\n\n  
" + HIW + "『幻想的" + HBCYN + "雲端" + NOR+HIW + "，罪惡的" + HBBLU + "淵藪" + NOR+HIW + "～～』\n
              『逝去的" + HBMAG + "愛" + NOR+HIW + "，未了的" + HBRED + "緣" + NOR+HIW + "～～』\n
                               " + HIY + "在這一刻，我要" + HIW + "$n" + HIY + "嘗到我" + HIY+HBRED + "死亡之力" + NOR+HIY + "的厲害！！！\n\n" + NOR,me, victim);
  for (i=0;i<time;i++)
   {
       victim->receive_wound("kee",damage,me);
       COMBAT_D->report_status(victim);     
   }
    victim ->start_busy(random(1));
}
}
void dea5(object me, object victim, object weapon, int damage)
{
 int me_sklv,en_sklv,sk,bell,i,mk,j;
 object wea=me->query_temp("secondary_weapon");
 weapon=me->query_temp("weapon");
 bell = (int)me->query("bellicosity",1)/125;
 sk = (int)me->query_skill("death-blade",1)/10;
 mk = (int)me->query("MKS",1)/500;
 me_sklv = (int)me->query("combat_exp",1)/200000 + (int)me->query_cor() + (int)me->query_cps() + sk*2+random(10);
 en_sklv = (int)victim->query("combat_exp",1)/200000 + (int)victim->query_skill("dodge",1)/5+ (int)victim->query_skill("parry",1)/5;
 damage = me->query_skill("death-blade",1)+random(mk+bell);
 if(!me->query_temp("berserk")) j=20;
 else j=4;
if(wea && weapon)
{
 for(i=1;i<=j;i++)

  {                                        
  switch(i)
         {
  case 1:
  if(random(me_sklv) > random(en_sklv))
 { 
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．固身"+HIC + "◢\n" + NOR,me,victim);       
            message_vision(HIR + "體內的銳烈煞氣注滿"+weapon->name()+""+HIR + "，凜凜殺氣劃破長空，狂飆爆起，如蛟龍天翻惡浪，\n"
                          +HIR + "無匹氣勁鑽入$n"+HIR + "體內，$n"+HIR + "的整條胳臂被勁力反震，抖動的不能自己，虎口爆裂，鮮血直冒！\n" + NOR,me,victim);
  message_vision(HIY + "亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．固身"+HIC + "◢\n" + NOR,me,victim);       
            message_vision(HIR + "體內的銳烈煞氣注滿"+weapon->name()+""+HIR + "，凜凜殺氣劃破長空，狂飆爆起，如蛟龍天翻惡浪，\n"
                          +HIR + "無匹氣勁鑽入$n"+HIR + "體內，$n"+HIR + "的整條胳臂被勁力反震，抖動的不能自己，虎口爆裂，鮮血直冒！\n" + NOR,me,victim);
  message_vision(HIM + "$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 2:
  if(random(me_sklv) > random(en_sklv))
 { 
  message_vision(HIC + "\n\n$N右手執"+wea->name()+"" + HIC + "，形如流水，使出" + HIY + "『悠美如夢』" + HIC + "，刀光淡淡，\n" + NOR+
HIC + "如遠山的望眉，夕照的依稀，刀光閃在$n的眸裡，$n冷不防地受到猛烈的攻擊！" + NOR,me,victim); 
  message_vision(HIY + "\n亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
  message_vision(HIC + "\n\n$N右手執"+wea->name()+"" + HIC + "，形如流水，使出" + HIY + "『悠美如夢』" + HIC + "，刀光淡淡，\n" + NOR+
HIC + "如遠山的望眉，夕照的依稀，刀光閃在$n的眸裡，$n冷不防地受到猛烈的攻擊！" + NOR,me,victim); 
  message_vision(HIM + "\n$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 3:
  if(random(me_sklv) > random(en_sklv))
 { 
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．誘敵"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "$N身子騰翻，全身百穴勁力聚注"+weapon->name()+""+HIR + "，半空"+weapon->name()+""+HIR + "劃出一道血紅，如蛟龍飛昇，虎嘯天下，\n"
                          +HIR + "火焚急張，龍飛舞動，刀氣在$n"+HIR + "身前裂碎地，無窮刀網濺出殘暴鮮血，$N殺意更盛！\n" + NOR,me,victim);
  message_vision(HIY + "亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．誘敵"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "$N身子騰翻，全身百穴勁力聚注"+weapon->name()+""+HIR + "，半空"+weapon->name()+""+HIR + "劃出一道血紅，如蛟龍飛昇，虎嘯天下，\n"
                          +HIR + "火焚急張，龍飛舞動，刀氣在$n"+HIR + "身前裂碎地，無窮刀網濺出殘暴鮮血，$N殺意更盛！\n" + NOR,me,victim);
  message_vision(HIM + "$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 4:
  if(random(me_sklv) > random(en_sklv))
 { 
  message_vision(HIC + "\n$N右手反轉，"+wea->name()+"" + HIC + "自鞘中翻覆而握，使出" + HIY + "『輕盈若詩』" + HIC + "，\n" + NOR+
HIC + "刀光像一首動人的詩，輕的像一陣微風，柔的像一抹月色，$n招架不及，\n" + NOR+
HIC + "著了一道嚴重的刀傷！" + NOR,me,victim); 
  message_vision(HIY + "\n亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
  message_vision(HIC + "\n$N右手反轉，"+wea->name()+"" + HIC + "自鞘中翻覆而握，使出" + HIY + "『輕盈若詩』" + HIC + "，\n" + NOR+
HIC + "刀光像一首動人的詩，輕的像一陣微風，柔的像一抹月色，$n招架不及，\n" + NOR+
HIC + "著了一道嚴重的刀傷！" + NOR,me,victim); 
  message_vision(HIM + "\n$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 5:
  if(random(me_sklv) > random(en_sklv))
 { 
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．圖機"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "$N催化淒厲殺意，手中"+weapon->name()+""+HIR + "充斥狂性，令人心膽欲裂，翻天覆地鬼神驚，驚天駭地狂飆掃向$n"+HIR + "，\n"
                          +HIR + "$n"+HIR + "氣血狂翻，全身立時如遭電殛，勁風如剖殺刀割，$n"+HIR + "血痕立現！\n" + NOR,me,victim);
  message_vision(HIY + "亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
             message_vision(HIC + "\n◤"+HIW + "藍霆十二式．圖機"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "$N催化淒厲殺意，手中"+weapon->name()+""+HIR + "充斥狂性，令人心膽欲裂，翻天覆地鬼神驚，驚天駭地狂飆掃向$n"+HIR + "，\n"
                          +HIR + "$n"+HIR + "氣血狂翻，全身立時如遭電殛，勁風如剖殺刀割，$n"+HIR + "血痕立現！\n" + NOR,me,victim);
  message_vision(HIM + "$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 6:
  if(random(me_sklv) > random(en_sklv))
 { 
  message_vision(HIC + "\n$N隨嘆息而出刀，使出" + HIY + "『夢裡花落』" + HIC + "，悠遠的刀光去勢之疾，快逾電光，\n"+
HIC + "閃電般斬向$n的腹中，$n臉上的表情，正如心肺被撕裂的痛楚！" + NOR,me,victim); 
  message_vision(HIY + "\n亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
  message_vision(HIC + "\n$N隨嘆息而出刀，使出" + HIY + "『夢裡花落』" + HIC + "，悠遠的刀光去勢之疾，快逾電光，\n"+
HIC + "閃電般斬向$n的腹中，$n臉上的表情，正如心肺被撕裂的痛楚！" + NOR,me,victim); 
  message_vision(HIM + "\n$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 7:
  if(random(me_sklv) > random(en_sklv))
 { 
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．速殺"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "$N氣勢如刀山直搗，劈天破地，銳利帶銳風，無儔刀光壟罩，寒光徒閃，疾劈的沙石紛飛，\n"
+HIR + "刀勁混和沙石，捲如巨浪，排山倒海轟向$n"+HIR + "，誓要$n"+HIR + "亡命於此刀之下！\n" + NOR,me,victim);
  message_vision(HIY + "亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．速殺"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "$N氣勢如刀山直搗，劈天破地，銳利帶銳風，無儔刀光壟罩，寒光徒閃，疾劈的沙石紛飛，\n"
                          +HIR + "刀勁混和沙石，捲如巨浪，排山倒海轟向$n"+HIR + "，誓要$n"+HIR + "亡命於此刀之下！\n" + NOR,me,victim);
  message_vision(HIM + "$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 8:
  if(random(me_sklv) > random(en_sklv))
 { 
  message_vision(HIC + "\n$N想也不想，亮出了手上的"+wea->name()+"" + HIC + "，使出" + HIY + "『細雨黃昏』" + HIC + "，刀光驚豔般\n"+HIC + "的亮起，如流星自長空劃過，$n感到無可抗拒的震怖，跌入嗜血的刀網中！" + NOR,me,victim);
  message_vision(HIY + "\n亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
  message_vision(HIC + "\n$N想也不想，亮出了手上的"+wea->name()+"" + HIC + "，使出" + HIY + "『細雨黃昏』" + HIC + "，刀光驚豔般\n"+
HIC + "的亮起，如流星自長空劃過，$n感到無可抗拒的震怖，跌入嗜血的刀網中！" + NOR,me,victim); 
  message_vision(HIM + "\n$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 9:
  if(random(me_sklv) > random(en_sklv))
 { 
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．無恨"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "$N不停的無定向旋滾翻飛，宛如龍卷旋風，血脈噴張，殺意更狂，冰霜撲面的殺意急斬$n"+HIR + "而下，\n"
                          +HIR + "一道強猛如烈浪崩山的刀勁刮動烈風，凜冽霸殺壟罩$n"+HIR + "！\n" + NOR,me,victim);
  message_vision(HIY + "亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．無恨"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "$N不停的無定向旋滾翻飛，宛如龍卷旋風，血脈噴張，殺意更狂，冰霜撲面的殺意急斬$n"+HIR + "而下，\n"
                          +HIR + "一道強猛如烈浪崩山的刀勁刮動烈風，凜冽霸殺壟罩$n"+HIR + "！\n" + NOR,me,victim);
  message_vision(HIM + "$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 10:
  if(random(me_sklv) > random(en_sklv))
 { 
  message_vision(HIC + "\n$N突然衝了出去，刀光綽約，像一抹夕暉，一場細雨，驚豔一撇" + HIY + "『飛花逐月』" + HIC + "，\n"+
HIC + "$n看見了如彩色一般的夢，刀過處，黑裡濺出厲紅，帶出了殘酷的現實！" + NOR,me,victim); 
  message_vision(HIY + "\n亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
  message_vision(HIC + "\n$N突然衝了出去，刀光綽約，像一抹夕暉，一場細雨，驚豔一撇" + HIY + "『飛花逐月』" + HIC + "，\n"+
HIC + "$n看見了如彩色一般的夢，刀過處，黑裡濺出厲紅，帶出了殘酷的現實！" + NOR,me,victim); 
  message_vision(HIM + "\n$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 11:
  if(random(me_sklv) > random(en_sklv))
 { 
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．殘心"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "泣血悲風，$N天愁地慘的淒厲殺著迎向$n"+HIR + "，如一場夢魘，如一場噩夢，斑爛彩芒把一切愁慘\n"
                          +HIR + "一掃而空，如排山倒海，惡濤驚雷轟湧向$n"+HIR + "，將一切生命劃下休止符！\n" + NOR,me,victim);
  message_vision(HIY + "亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
   COMBAT_D->report_status(victim);
 }
  else
 {
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．殘心"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "泣血悲風，$N天愁地慘的淒厲殺著迎向$n"+HIR + "，如一場夢魘，如一場噩夢，斑爛彩芒把一切愁慘\n"
                          +HIR + "一掃而空，如排山倒海，惡濤驚雷轟湧向$n"+HIR + "，將一切生命劃下休止符！\n" + NOR,me,victim);
  message_vision(HIM + "$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 12:
  if(random(me_sklv) > random(en_sklv))
 { 
  message_vision(HIC + "\n$N輕彈刀鋒，震起彷似一種相見時喜悅的輕顫" + HIY + "『秋風趕塵』" + HIC + "，一刀揮出像一道歲月的夢痕，\n"+
HIC + "刀落時還帶著些許\美麗的風華，$n沒有退路，\n無法閃躲，不能招架！" + NOR,me,victim); 
  message_vision(HIY + "\n亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
  message_vision(HIC + "\n$N輕彈刀鋒，震起彷似一種相見時喜悅的輕顫" + HIY + "『秋風趕塵』" + HIC + "，一刀揮出像一道歲月的夢痕，\n"+
HIC + "刀落時還帶著些許\美麗的風華，$n沒有退路，\n無法閃躲，不能招架！" + NOR,me,victim); 
  message_vision(HIM + "\n$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 13:
  if(random(me_sklv) > random(en_sklv))
 { 
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．瀝血"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "$N心跳暴疾，熱血狂奔，殺氣輪舞如猛銳急風，披荊斬棘，刀光華彩五色，眩目凌厲，直向$n\n"
                          +HIR + "殺出大條血路，$N全身血花濺上，彷似在地獄中殺出血路，刀勁斬入$n"+HIR + "內腑，痛楚撕裂了\n"
                          +HIR + "$n"+HIR + "的信心！\n" + NOR,me,victim);
  message_vision(HIY + "亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．瀝血"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "$N心跳暴疾，熱血狂奔，殺氣輪舞如猛銳急風，披荊斬棘，刀光華彩五色，眩目凌厲，直向$n\n"
                          +HIR + "殺出大條血路，$N全身血花濺上，彷似在地獄中殺出血路，刀勁斬入$n"+HIR + "內腑，痛楚撕裂了\n"
                          +HIR + "$n"+HIR + "的信心！\n" + NOR,me,victim);
  message_vision(HIM + "$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 14:
  if(random(me_sklv) > random(en_sklv))
 { 
  message_vision(HIC + "\n$N拔刀作龍吟，比琴鳴箏響還動聽， 帶著微微的香氣和呻吟，" + HIY + "『相思若夢』" + HIC + "刀光紛飛，\n"+
HIC + "似千道銀雨，森寒的刀勁猶如一張天羅地網，$n的去路已被封鎖、切斷！" + NOR,me,victim); 
  message_vision(HIY + "\n亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
  message_vision(HIC + "\n$N拔刀作龍吟，比琴鳴箏響還動聽， 帶著微微的香氣和呻吟，" + HIY + "『相思若夢』" + HIC + "刀光紛飛，\n"+
HIC + "似千道銀雨，森寒的刀勁猶如一張天羅地網，$n的去路已被封鎖、切斷！" + NOR,me,victim); 
  message_vision(HIM + "\n$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 15:
  if(random(me_sklv) > random(en_sklv))
 { 
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．搏命"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "$N狂號疾衝，帶著"+weapon->name()+""+HIR + "的淒涼哭聲，揮出盤旋一刀，方圓三丈被刀勁裹包，凜烈寒陰殺氣直逼$n"+HIR + "，\n"
                          +HIR + "配合迎風悲泣的淒厲哭聲，以$n"+HIR + "的血寫下畫意的人間煉獄！\n" + NOR,me,victim);
  message_vision(HIY + "亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．搏命"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "$N狂號疾衝，帶著"+weapon->name()+""+HIR + "的淒涼哭聲，揮出盤旋一刀，方圓三丈被刀勁裹包，凜烈寒陰殺氣直逼$n"+HIR + "，\n"
                          +HIR + "配合迎風悲泣的淒厲哭聲，以$n"+HIR + "的血寫下畫意的人間煉獄！\n" + NOR,me,victim);
  message_vision(HIM + "$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 16:
  if(random(me_sklv) > random(en_sklv))
 { 
  message_vision(HIC + "\n$N使出" + HIY + "『慾斷魂飛』" + HIC + "，"+wea->name()+"" + HIC + "陡然而起，瞬然而止，刀光漾起一種淒美的顏色，\n"+
HIC + "在晨曦的長空中，化作一道璨耀精虹，一縷\急風，並透了刀氣與刀風，急取$n！" + NOR,me,victim); 
  message_vision(HIY + "\n亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
  message_vision(HIC + "\n$N使出" + HIY + "『慾斷魂飛』" + HIC + "，"+wea->name()+"" + HIC + "陡然而起，瞬然而止，刀光漾起一種淒美的顏色，\n"+
HIC + "在晨曦的長空中，化作一道璨耀精虹，一縷\急風，並透了刀氣與刀風，急取$n！" + NOR,me,victim); 
  message_vision(HIM + "\n$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 17:
  if(random(me_sklv) > random(en_sklv))
 { 
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．天驚"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "戾氣沖天揮舞，陰風寒氣直上九宵，頓然烏雲蓋\頂，$N與"+weapon->name()+""+HIR + "捲纏黑雲，如天魔降世，\n"
                          +HIR + "血目仰天，寒光暴綻，登時鬼風啁啁，天際一聲轟隆，雷響雨飛，悲屈恨意急竄向$n"+HIR + "！\n" + NOR,me,victim);
  message_vision(HIY + "亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．天驚"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "戾氣沖天揮舞，陰風寒氣直上九宵，頓然烏雲蓋\頂，$N與"+weapon->name()+""+HIR + "捲纏黑雲，如天魔降世，\n"
                          +HIR + "血目仰天，寒光暴綻，登時鬼風啁啁，天際一聲轟隆，雷響雨飛，悲屈恨意急竄向$n"+HIR + "！\n" + NOR,me,victim);
  message_vision(HIM + "$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 18:
  if(random(me_sklv) > random(en_sklv))
 { 
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．地怒"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "$N已化作幻刀魔龍，張牙噬爪，一道陰森魔氣飛掠捲殺$n"+HIR + "，瘋血魔性驚天駭地，無招千變，\n"
                          +HIR + "刀氣強勁無儔，霸氣劈地開天，迎風擊盪響騙哀嚎悲泣聲，"+weapon->name()+""+HIR + "如暴浪湧向$n"+HIR + "臉龐，急疾如電，\n"
                          +HIR + "更滲透悲涼意境，煞是可怖！\n" + NOR,me,victim);
  message_vision(HIY + "亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．地怒"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "$N已化作幻刀魔龍，張牙噬爪，一道陰森魔氣飛掠捲殺$n"+HIR + "，瘋血魔性驚天駭地，無招千變，\n"
                          +HIR + "刀氣強勁無儔，霸氣劈地開天，迎風擊盪響騙哀嚎悲泣聲，"+weapon->name()+""+HIR + "如暴浪湧向$n"+HIR + "臉龐，急疾如電，\n"
                          +HIR + "更滲透悲涼意境，煞是可怖！\n" + NOR,me,victim);
  message_vision(HIM + "$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 19:
  if(random(me_sklv) > random(en_sklv))
 { 
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．雷霆"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "目如血海，精光暴射，抽刀的氣勢如惡浪濤天，殺氣騰騰如雷霆震怒，一道尖銳得比猛鬼\n"
                          +HIR + "咆哮悲哭更斷人心弦的泣聲，隨"+weapon->name()+""+HIR + "出鞘而劃破長空，刀勢如風捲殘雲，勁力凝聚刀鋒，\n"
                          +HIR + "灼熱如火，蓄勢待發，一發不可收拾！\n" + NOR,me,victim);
  message_vision(HIY + "亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．雷霆"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "目如血海，精光暴射，抽刀的氣勢如惡浪濤天，殺氣騰騰如雷霆震怒，一道尖銳得比猛鬼\n"
                          +HIR + "咆哮悲哭更斷人心弦的泣聲，隨"+weapon->name()+""+HIR + "出鞘而劃破長空，刀勢如風捲殘雲，勁力凝聚刀鋒，\n"
                          +HIR + "灼熱如火，蓄勢待發，一發不可收拾！\n" + NOR,me,victim);
  message_vision(HIM + "$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
  case 20:
  if(random(me_sklv) > random(en_sklv))
 { 
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．不滅"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "一絲殘酷的笑意，自$N嘴角揚起，眼神裡有一種殺手的殘忍，臉孔卻如情人般的溫柔，\n"
                          +HIR + "似在奮悅，似在惋惜，然後就是刀光一閃．．．\n" + NOR,me,victim);
  message_vision(HIY + "亦剛亦柔的刀招旋舞出一種極其淒豔的殺氣來,就像驚破了黑夜一般撕裂$n﹗\n" + NOR,me,victim);
  victim->receive_wound("kee", damage);
  COMBAT_D->report_status(victim);
 }
  else
 {
            message_vision(HIC + "\n◤"+HIW + "藍霆十二式．不滅"+HIC + "◢\n" + NOR,me,victim);
            message_vision(HIR + "一絲殘酷的笑意，自$N嘴角揚起，眼神裡有一種殺手的殘忍，臉孔卻如情人般的溫柔，\n"
                          +HIR + "似在奮悅，似在惋惜，然後就是刀光一閃．．．\n" + NOR,me,victim);
  message_vision(HIM + "$n看準時機的閃過了這一刀﹗\n" + NOR,me,victim);
 }
  break;
 }
}}
}
string perform_action_file(string action)
{
        return CLASS_D("blademan")+"/death-blade/"+action;
}
mapping *queryTotalAction() {return action;}

