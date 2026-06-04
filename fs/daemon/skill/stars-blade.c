//星夜豔夢刀法 by roger && taifar
//金風細雨第九樓樓主李夢枕skill
#include <combat.h>
#include <ansi.h>
inherit SKILL;
void sp_attack(object me,object victim,object weapon,int damage);
void sp_attack1(object me,object victim,object weapon,int damage);
void sp_attack2(object me,object victim,object weapon,int damage);
void sp_attack3(object me,object victim,object weapon,int damage);
void sp_attack4(object me,object victim,object weapon,int damage);
void sp_attack5(object me,object victim,object weapon,int damage);
void sp_attack6(object me,object victim,object weapon,int damage);
void sp_attack7(object me,object victim,object weapon,int damage);
void sp_attack8(object me,object victim,object weapon,int damage);
void sp_attack9(object me,object victim,object weapon,int damage);
void sp_attack10(object me,object victim,object weapon,int damage);
int kar,cps,str,cor,int1,spi;
int sp_value;

mapping *action = ({
//1
(["action":HIC + "$N輕舞$w使出一式" + HIY + "『夜女清芬』" + HIC + "，刀光悠遠，像麗人倩影圈撒淡淡香氳，豔烈的刀氣瞬間直奔$n喉間" + NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (: sp_attack:),
        "post_action":          (: sp_attack1:),
        "damage_type":  "砍傷",
        "weapon"     :  "情刀",
        ]),
//2
(["action":HIC + "$N刀鋒側轉使出一式" + HIY + "『夕若蘅芷』" + HIC + "，伴著紅紅刀光沁出郁郁香氣，刃隨風捲，赤虹刀氣如夕霞突落在$n眼前" + NOR,
        "damage":           850,
        "force":            850,
        "damage_type":  "割傷",
        "post_action":          (: sp_attack1:),
        "damage_type":  "砍傷",
           "weapon"     :  "情刀",
          ]),
//3
(["action":HIC + "$N倏地迴刀，一式" + HIY + "『夢醉風鈴』" + HIC + "的破風聲猶如一串風過時的鈴響，刀氣形成美麗的弧線高掠過空直墜$n腦門" + NOR,
        "damage":      850,
        "force":       850,
        "damage_type":  "砍傷",
        "post_action":          (: sp_attack:),
        "post_action":          (: sp_attack1:),
           "weapon"     :  "情刀",
           ]),

//4
(["action":HIC + "$N飛身一式" + HIY + "『星香蕉葉』" + HIC + "，刀光輪轉，身影輕的就像一陣微風迫近$n，刃裂狂旋，亂掃$n的四肢" + NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (: sp_attack:),
        "damage_type": "劈傷",
        "weapon"     :  "情刀",
            ]),
//5
(["action":HIC + "$N壓身反轉刀柄突刺$n的雙膝使出" + HIY + "『星夜醉夢刀法』" + HIC + "中的" + HIY + "『睡露海棠』" + HIC + "，在眨眼間回刀上揚平掃落刃襲向$n$l" + NOR,
        "damage":       850,
        "force":        850,
        "damage_type": "劈傷",
        "post_action":          (: sp_attack:),
        "weapon"     :  "情刀",
        ]),
//6
(["action":HIC + "$N提足劃上" + HIY + "『星夜醉夢刀法』" + HIC + "，使出了一式『借柳掛月』，$w在空中旋出粼粼弧光颯成銀月，月凜刀氣直落$n$l" + NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (: sp_attack:),
        "damage_type": "劈傷",
        "weapon"     :  "情刀",
        ]),
//7
(["action":HIC + "$N若有似無，藉由" + HIY + "『星夜醉夢刀法』" + HIC + "刀意，使出了一式『如夢似醉』，$w在$N手中劃出陣陣銀光直落$n$l" + NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (:sp_attack2:),
        "damage_type": "劈傷",
        "weapon"     :  "情刀",
        ]),

//8
        ([      
                "action"     :HIC + "$N運起身上" + HIY + "『殘陽』" + HIC + "氣勁，以刀代劍使出仙劍禁斷之" + HIY + "『殘陽千里』" + HIC + "，瞬間身化殘影落步，劍尖分指$n$l" + NOR,
                "dodge"      :               -500,
                "parry"      :               -500,
                "damage"     :                830,
                "force"      :                830,
                "post_action":                (: sp_attack3 :),
                "damage_type":               "刺傷"
        ]),
//9
        ([     
                "action"     :               HIC + "$N步若游光以刀代劍，使出仙劍禁斷之連陽七訣第四式" + HIY + "『暖陽無鋒』" + HIC + "，劍氣烘燃，一流宏大的劍壓曲地逼近$n" + NOR,
                "dodge"      :                -500,
                "parry"      :                -500,
                "damage"     :                840,
                "force"      :                840,
                "post_action":                (: sp_attack4 :),
                "damage_type":               "刺傷"
        ]),
//10
        ([   
                "action"     :               HIC + "$N飛身高躍倏然使出了仙劍禁斷之連陽七訣第三式" + HIY + "『豔陽無情』" + HIC + "，刀光如浩日輝煌，筆直落在$n眉心" + NOR,
                "dodge"      :                -500,
                "parry"      :                -500,
                "damage"     :                850,
                "force"      :                850,
                "post_action":                (: sp_attack5 :),
                "damage_type":               "刺傷"
        ]),
//11
        ([  
                "action"     :               HIC + "$N，心若止水刀光瀲豔，瞬間使出仙劍禁斷之連陽七訣" + HIY + "『冬陽無意』" + HIC + "泛起波波殺意如刃向$n繞流而去" + NOR,
                "dodge"      :                -500,
                "parry"      :                -500,
                "damage"     :                870,
                "force"      :                870,
                "post_action":                (: sp_attack6 :),
                "damage_type":               "割傷"
        ]),
//12
        ([ 
                "action"     :               HIC + "$N手裡的$w" + HIC + "配上身上無比劍氣，帶動一招仙劍禁斷之" + HIY + "『夕陽無意』" + HIC + "猶如霞光滿天盡落$n身上" + NOR,
                "dodge"      :                -500,
                "parry"      :                -500,
                "damage"     :                880,
                "force"      :                880,
                "post_action":                (: sp_attack7 :),
                "damage_type":               "割傷"
        ]),
//13
        ([
                "action"     :               HIC + "$N以刀代劍峰迴路轉，內勁猛然上竄使出仙劍禁斷" + HIY + "『烈陽氣殺』" + HIC + "，劍光如烈陽狂燄直奔$n心口" + NOR,
                "dodge"      :                -500,
                "parry"      :                -500,
                "damage"     :                890,
                "force"      :                890,
                "post_action":                (: sp_attack8 :),
                "damage_type":               "刺傷"
        ]),
//14
         ([     "action"     :               HIC + "$N將$w" + HIC + "收鞘而入，身上朝陽昊氣帶動無上劍氣，聚精凝神使出仙劍禁斷之" + HIY + "『朝陽再現』" + HIC + "，只見劍光如晨光乍現劃向$n" + NOR,
                "parry"      :                -500,
                "dodge"      :                -500,
                "damage"     :                900,
                "force"      :                900,
                "post_action":                (: sp_attack9 :),
                "damage_type":                "割傷",
           ]),
//15
         ([     "action"     :               HIM + "$N融合身上刀劍雙絕之奧妙，配合身上修羅鬥氣，聚精凝神將兩大絕學融為一體，使出刀劍雙絕之" + HIY + "『刀行劍旋』" + HIM + "，只見刀光劍光快如流星，劃向$n" + NOR,
                "parry"      :                -700,
                "dodge"      :                -700,
                "damage"     :                1000,
                "force"      :                1000,
                "post_action":                (: sp_attack10 :),
                "damage_type":                "割傷",
           ]),
});

int valid_enable(string usage)
{
        return (usage=="blade")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{

 kar=me->query_kar();
 cps=me->query_cps();
 str=me->query_str();
 cor=me->query_cor();
 int1=me->query_int();
 spi=me->query_spi();

        return action[random(sizeof(action))];
}

void sp_attack(object me,object victim, object weapon,int damage)
{
 int i;
 if(random(100) > 50 && !me->query_temp("conti")){
message_vision(HIM + "\n$N隨風一笑，情刀流香郁郁，星光迷離，刀光一散如細細的雨般往$n灑去，令人陶醉 \n" + NOR,me,victim);
  victim->start_busy(2);
  me->set_temp("conti",1);
   for(i=0;i<5;i++)
    
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
                   
  me->delete_temp("conti");
                     }
}
void sp_attack1(object me,object victim, object weapon,int damage)
{
 int i;
 if(random(100) > 50 && !me->query_temp("conti")){
message_vision(HIM + "\n$N隨風一笑，情刀流香郁郁，星光迷離，刀光一散如細細的雨般往$n灑去，令人陶醉 \n" + NOR,me,victim);
  me->set_temp("conti",1);
   for(i=0;i<2;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

  me->delete_temp("conti");
                     }
}
void sp_attack2(object me,object victim, object weapon,int damage)
{
 message_vision(sprintf(HIC + "$N人隨意轉，轉眼間來到$n身後，$n發覺急忙轉身回擋，只見$N繞到另一側並使出其本身真氣發出流星般的一擊 \n" + NOR),me,victim);
 victim->start_busy(2);
 message_vision(sprintf(HIC + "$n中招後愣了一下，瞬間$N浩翰真氣已席捲而至 \n" + NOR),me,victim);
 victim->apply_condition("tsunami",random(4)+2);
 COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
 }
void sp_attack3(object me, object victim, object  weapon, int damage)
{
  sp_value =10*(str+cor)+cps+kar+spi+int1;
message_vision(HIY + "
就在$n被擊中的瞬間，$N心轉" + HIR + "『殘陽千意』" + HIY + "，亂步分影遮光為幻
一心千切，同一把刀，舞的卻是不同的招式，招招朝著$n的要穴竄去
\n" + NOR,me,victim);
    victim->receive_damage("kee",sp_value,me);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

}

void sp_attack4(object me, object victim, object  weapon, int damage)
{
  sp_value =7*(str+cor)+cps+kar+spi+int1;

    message_vision(HIW + "
刀氣流動，隨著$N的心念越發強烈，$n無從反動，完完全全
受到刀壓的控制，衍生一式" + HIY + "『暖陽印境』" + HIW + "激出的刀芒在空中不停地聚
合盤旋，剎那間!!天地變色風起雲湧，一輪暖日在空氣之間現形而生
$n被此情景所震懾，一瞬間已被吞沒於光芒之中
\n" + NOR,me,victim);
   victim->receive_damage("kee",sp_value,me);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

void sp_attack5(object me, object victim, object  weapon, int damage)
{
  sp_value =7*(spi+int1)+cps+kar+str+cor;

    message_vision(HIY + "
就在同時，$N心擴天地，懷若宇宙，狂奔的戾氣瞬間平息，$N與
天地彷彿結合為一，瑞光豔麗光彩奪目，凝止住全部的的動作 
一式" + HIW + "『豔陽三刀--天罡\-地煞-人禍』" + HIY + "迅如雷光落向$n
\n" + NOR,me,victim);

   victim->receive_damage("kee",sp_value,me);
   victim->set_temp("no_power",1);
   victim->apply_condition("no_power",2);
   COMBAT_D->report_status(victim);
}

void sp_attack6(object me, object victim, object  weapon, int damage)
{
  sp_value =7*(cps+kar)+str+cor+spi+int1;
     message_vision(HIW + "
$N內勁頓轉使出連陽唯一陰寒之招，瞬時間一股寒氣籠罩身旁，只見
刀上薄冰漸起幻成冰柱，$N愈使愈快，宛若洶湧巨浪瞬時壓力遽增
霎時四周水波雲氣變化萬千，$n瞬間分不清刀在何方, 就在遲疑之
際，$N一式" + HIC + "『冬陽天冰』" + HIW + "捲起狂霜亂雪直搗$n心口
\n" + NOR,me,victim);

    victim->receive_damage("kee",sp_value,me);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

void sp_attack7(object me, object victim, object  weapon, int damage)
{
    int i;
  sp_value =8*(cps+kar)+str+cor+spi+int1;
    message_vision(HIR + "
$N趁勢翻身飛躍，斜迴刀尖，念轉靈動使出" + HIW + "『紅染夕陽』" + HIR + "，霎時
殺意狂奔，欲噬血腥無法自制，刀鼓風旋，連鎖成無數無形風刃，削
肉刮骨欲罷不能
" + NOR,me,victim);
    victim->receive_damage("kee",sp_value,me);
    me->set_temp("conti",1);
    for(i=0; i<3 ;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    me->delete_temp("conti");
    
}

void sp_attack8(object me, object victim, object  weapon, int damage)
{
  int i;
  sp_value =8*(cps+kar)+str+cor+spi+int1;
  message_vision(HIR + "
  眨眼間，劍鋒泛火，火光漸如燄日逼人，$N如化祝融全身火紅驀地一聲大喝
  " + HIW + "『" + HIR + "艷陽氣殺" + HIW + "』" + HIR + "，手中兵器猶似火龍摧天，刀幻千萬火只在一瞬間$n已完全火龍被吞沒" + NOR,me,victim);
  message_vision("$N閃躲不及，身上頓時多出了一道血淋淋的劍痕。\n" , victim);
    victim->receive_damage("kee",sp_value,me);
    victim->set_temp("swordkee",1);
    victim->apply_condition("swordkee",6);
    COMBAT_D->report_status(victim);
}


void sp_attack9(object me, object victim, object  weapon, int damage)
{
int i;
sp_value =8*(str+cor+cps)+spi+int1+kar;
message_vision(HIY + "
$N身上隨著『朝陽再現』這一式散發出開天潛藏的靈氣，剎那間!刀泛金光
完全照亮了暗影，如千百個太陽在$N的手中，一齊射出無與倫比的金光，令
$n根本無法逼視\n" + NOR,me,victim);
    victim->receive_wound("kee",sp_value+130,me);
    victim->start_busy(1);
    victim->set_temp("no_power",1);
    victim->apply_condition("no_power",2);
    COMBAT_D->report_status(victim);
}

void sp_attack10(object me, object victim, object  weapon, int damage)
{
int i;
sp_value =10*(str+cor+cps)+spi+int1+kar;
message_vision(HIM + "
$N身上隨著『刀形劍旋』這一式散發出浩然正氣，剎那間，$N身上竄出
一刀一劍之氣芒，若隱若現令人防不勝防，$n根本無法閃躲\n" + NOR,me,victim);
    victim->receive_wound("kee",sp_value+130,me);
    victim->start_busy(2);
    victim->apply_condition("swordkee",2);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

