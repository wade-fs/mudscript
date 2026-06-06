#include <combat.h>
#include <ansi.h>
inherit SKILL;
void conti(object me, object victim, object weapon, int damage);
void sp1(object me, object victim, object weapon, int damage);
void sp2(object me, object victim, object weapon, int damage);
void power(object me, object victim, object weapon, int damage);
void attack(object me, object victim, object weapon, int damage);
mapping *action = ({
//1
([ "action":HIR + "$N" + NOR + "雙掌一提，雙臂內彎真氣隨之一吐，起手式" + HIG + "【" + YEL + "鴻漸于陸" + HIG + "】" + NOR + "，掌勢由隱而明，平平的擊向$n。",
        "dodge": -30,
        "parry":  20,
        "force":  200,
        "damage": 400,
        "damage_type":  "掌傷",
        "post_action": (: sp1 :),
]),
//2
([ "action":HIR + "$N" + NOR + "手中聚集一股真氣，右掌一開，左掌跟著一握，使出一式" + HIG + "【" + HIC + "利涉大川" + HIG + "】" + NOR + "，氣勢大開大闔，
掌勁盡透剛氣，向$n不斷推去。",
        "dodge": -30,
        "parry":  20,
        "force":  200,
        "damage": 420,
        "damage_type":  "掌傷",
]),
//3
([ "action":HIR + "$N" + NOR + "將真氣運至雙手，凝氣為劍，連劍帶掌，" + HIG + "【" + HIY + "羚羊" + MAG + "觸番" + HIG + "】" + NOR + "隨即使出，無數光芒有如迅雷疾風
向$n相互激盪而去，掌意劍意同時擊向$n。",
        "dodge": -20,
        "parry":  30,
        "force":  250,
        "damage": 450,
        "damage_type":  "掌傷",
]),
//4
([ "action":HIW + "只見" + HIR + "$N" + NOR + "的身形伏地，全身散發一股霸氣，聚集在丹田之處，打出一招" + HIG + "【" + WHT + "或躍在淵" + HIG + "】" + NOR + "左掌前探
，右掌倏從左掌底下穿了出去，直擊$n的$l。",
        "dodge": -20,
        "parry":  30,
        "force":  250,
        "damage": 450,
        "damage_type":  "掌傷",
        "post_action": (: sp1 :),
]),
//5
([ "action":HIR + "$N" + NOR + "運足十成功力，身形緩慢推動，倏地間雙掌順勢一推，一式" + HIG + "【" + HIY + "突如其來" + HIG + "】" + NOR + "彷如破天之勢，
掌勁迅如電火威，狠如滅天，猛烈地襲向$n。",
        "dodge": -10,
        "parry":  40,
        "force":  270,
        "damage": 470,
        "damage_type":  "掌傷",
]),
//6
([ "action":HIR + "$N" + NOR + "掌勁一鬆，力透黏勁，左掌一帶，牽動$n四方氣流，使出" + HIG + "【" + HIM + "損" + HIR + "則" + HIM + "有" + HIR + "孚" + HIG + "】" + NOR + "雙掌如狂雨擊
出，掌勁虛幻飄渺令$n眼花撩亂。",
        "dodge": -10,
        "parry":  40,
        "force":  270,
        "damage": 470,
        "damage_type":  "掌傷",
]),
//7
([ "action":HIW + "忽然" + HIR + "$N" + NOR + "的身形不斷晃動，並迅速地步移到$n身旁，" + HIG + "【" + HIM + "時乘六龍" + HIG + "】" + NOR + "立即擊出，突然間，六
方掌影同時狂襲而至，勢道磅礡，如群龍逆噬，盡擊向$n。",
        "dodge":  10,
        "parry":  50,
        "force":  300,
        "damage": 500,
        "damage_type":  "掌傷",
]),
//8
([ "action":HIR + "$N" + NOR + "凝聚全部精力，逐漸進入忘我的境界，吸氣吐納，化整為零，打出" + HIG + "【" + HIR + "亢龍有悔" + HIG + "】" + NOR + "一式，左
手劃了兩道圓圈，右手則順應著掌勁擊向$n。",

        "dodge":  0,
        "parry":  50,
        "force":  300,
        "damage": 500,
        "damage_type":  "掌傷",
        "post_action": (: conti :),
]),
//9
([ "action":HIR + "$N" + NOR + "身上的降龍之勁走遍全身，掌勢大開大闔，體內的真氣不斷向外放射，招式亦隨著真氣向
$n攻去，" + HIG + "【" + HIC + "震" + HIG + "驚" + HIY + "百" + HIR + "里" + HIG + "】" + NOR + "一式如爆雷般驚人。",

        "dodge":  10,
        "parry":  60,
        "force":  310,
        "damage": 510,
        "damage_type":  "掌傷",
]),
//10
([ "action":HIW + "$n只感一股極大力量排山倒海般將至，急運功抵擋。卻見" + HIR + "$N" + NOR + "掌收於胸，" + HIG + "【" + GRN + "見龍在田" + HIG + "】" + NOR + "招
式璞\而不華，雙手撒掌一合，筆直的擊向$n，$n震得倒退了七八步。",

        "dodge":  10,
        "parry":  60,
        "force":  310,
        "damage": 510,
        "damage_type":  "掌傷",
]),
//11
([ "action":HIR + "$N" + NOR + "掌影守住全身，並不搶攻，$n見狀連忙攻了過來，卻反被" + HIR + "$N" + NOR + "以一式" + HIG + "【" + WHT + "密雲不雨" + HIG + "】
" + NOR + "繁密的掌影所退，守招如大雨欲來，一掌又一掌環繞$n。",

        "dodge":  40,
        "parry":  70,
        "force":  340,
        "damage": 540,
        "damage_type":  "掌傷",
        "post_action": (: conti :),
]),
//12
([ "action":HIR + "$N" + NOR + "想起師父所言，若是雙方武功都到了爐火純青的地步，往往對戰數日，仍是難分上下，唯
一取勝之機端在對方偶犯小錯，$n一時失神，" + HIR + "$N" + NOR + "立即一招" + HIG + "【" + HIY + "笑言" + HIC + "啞啞" + HIG + "】" + NOR + "手指戳向$n的地蒼穴。",

        "dodge":  20,
        "parry":  70,
        "force":  340,
        "damage": 540,
        "damage_type":  "掌傷",
        "post_action": (: sp1 :),
]),
//13
([ "action":HIR + "$N" + NOR + "稍稍吐了一口氣，逆運體內真氣，將陽剛之氣轉化為陰柔之勁，兩肘往上微抬，將陰柔之
勁運至雙臂，右拳左掌，隨即使出" + HIG + "【" + HIW + "履" + HIC + "霜冰" + HIW + "至" + HIG + "】" + NOR + "直擊橫推幻化出兩道冰龍，剛柔並濟，一快
一慢的打向$n的$l。",
        "dodge":  50,
        "parry":  80,
        "force":  370,
        "damage": 570,
        "damage_type":  "掌傷",
        "post_action": (: attack :),
]),
//14
([ "action":HIR + "$N" + NOR + "凝神提氣，雙腳一蹬，身體不住高躍，隨即出現在天際之中，一招" + HIG + "【" + HIB + "飛龍" + HIR + "在天" + HIG + "】" + NOR + "突然一陣
狂風，雙掌如刀似剪，掌掌往$n的$l削去。",
        "dodge":  30,
        "parry":  80,
        "force":  370,
        "damage": 570,
        "damage_type":  "掌傷",
        "post_action": (: conti :),
]),
//15
([ "action":HIR + "$N" + NOR + "體內真氣運轉大週天，真氣凝聚於掌上，雙掌同時一舉，跟著背脊往前一挺，雙掌齊發，
一招" + HIG + "【" + HIC + "雙龍取水" + HIG + "】" + NOR + "左攻$l，右取$l，攻的$n手忙腳亂。",
        "dodge":  50,
        "parry":  90,
        "force":  400,
        "damage": 600,
        "damage_type":  "掌傷",
        "post_action": (: sp2 :),
]),
//16
([ "action":HIR + "$N" + NOR + "右手屈起食中兩指，半拳半掌，向$n的$l打去，" + HIG + "【" + HIW + "潛" + HIY + "龍" + HIW + "勿" + HIY + "用" + HIG + "】" + NOR + "招意蜒曲不窮，左
手同時向裏鉤拿，右推左鉤，使$n極難閃避真是妙不可言。",
        "dodge":  55,
        "parry":  95,
        "force":  400,
        "damage": 600,
        "damage_type":  "掌傷",
        "post_action": (: sp1 :),
]),
//17
([ "action":HIW + "$n正要出招，突然眼前白影微幌，背後風聲響動，疾忙向前飛躍，頸後已被" + HIR + "$N" + NOR + "拂中，
$N聽背後風響，衣上也已微有所感，就在這一瞬之間，反手橫劈，打出" + HIG + "【" + CYN + "神龍擺\尾" + HIG + "】" + NOR + "。",
        "dodge":  60,
        "parry":  100,
        "force":  450,
        "damage": 650,
        "damage_type":  "掌傷",
        "post_action": (: power :),
]),
//18
([ "action":HIR + "$N" + NOR + "運起全身內力，將力道發揮的隨心所欲，掌勢萬馬奔騰，有若開天闢地般，" + HIG + "【" + HIB + "戰" + MAG + "龍" + GRN + "在" + WHT + "野" + HIG + "】
" + NOR + "一出，掌勢如一條狂龍般撲向$n，在$n身上留下了雄厚的掌印。",
        "dodge":  80,
        "parry":  110,
        "force":  500,
        "damage": 700,
        "damage_type":  "掌傷",
        "post_action": (: sp2 :),
]),

});

void conti(object me, object victim, object weapon, int damage)
{
         int i,l,skill;
        int exp= me->query("combat_exp");
 skill=me->query_skill("dragon-fist",1);
     if(exp >=0 && exp <=100000)
              l=random(2)+1;
     if(exp > 100000 && exp <=250000)
              l=random(3)+1;
     if(exp > 250000 && exp <= 500000)
              l=random(4)+1;
     if(exp > 500000 && exp <=1000000)
              l=random(4)+2;
     if(exp > 1000000 && exp <=2000000)
              l=random(4)+3;
     if(exp > 2000000 && exp <=4000000)
              l=random(5)+3;
     if(exp > 4000000 && exp <=7000000)
              l=random(5)+4;
     if(exp > 7000000 && exp <=10000000)
              l=random(6)+4;
     if(exp > 10000000)
              l=random(10)+1;
        if( me->query("force_factor") >= 10 && 
             60>random(100) &&me->query("max_force") >= 1000 &&
             skill> 70 && me->query("family/family_name")=="丐幫")
        {
          if( me->query_temp("conti") == 0 )
          {
            me->delete_temp("super");
            me->set_temp("conti",1);
      message_vision(sprintf(HIR + "\n$N一時殺紅了眼，一掌接一掌的連續出招!!\n" + NOR),me);
              for(i=1;i<=l;i++)
              COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            me->delete_temp("conti");
message_vision(HIR + "\n強擊過後，$N內力耗損過巨，氣息大亂，呼吸沉重四肢酸痛難奈，不得不趕緊運氣調息。 \n" + NOR,me);
     me->start_busy(1);

          }
        }
}
int valid_enable(string usage)
{
        return (usage=="unarmed")||(usage=="parry");
}
mapping query_action(object me, object weapon)
{
        int level=(int)(me->query_skill("dragon-fist",1));
        if ( level < 10 )
           return action [random(3)];
        else if ( level < 20 )
           return action [random(4)];
        else if ( level < 30 )
           return action [random(7)];
        else if ( level < 40 )
           return action [random(8)];
        else if ( level < 50 )
           return action [random(11)];
        else if ( level < 60 )
           return action [random(12)];
        else if ( level < 70 )
           return action [random(13)];
        else if ( level < 80)
           return action [random(15)];
        else if ( level < 90)
           return action [random(16)];
        else
           return action [random(18)];
}
void sp1(object me, object victim, object weapon, int damage)
{
 int skill=me->query_skill("dragon-fist",1),bound,dag,das,j;
 bound = victim->query("max_kee");           
dag = victim->query("max_gin");
 das= victim->query("max_sen");
  if( random(100) < 50 && me->query("max_force") > 2000 && !me->query_temp("conti",1)&& 
me->query("family/family_name")=="丐幫")
  {
for(j=1;j<=random(4)+1;j++)
{
              switch(j)
                    {
case 1:
       message_vision(
sprintf("\n""　　　　　　　" + HIR + "" + HBBLU + "$N" + HIW + "　使　出　" + HIY + "降　龍　十　八　掌　" + HIW + "之" + HIG + "　奧　義　秘　招" + NOR + "
　　　　　　" + HIR + "$N" + NOR + "潛運真氣，體內陽剛之氣不斷提昇，突然真氣爆吐，內勁由雙掌蘊生
　　　　　　　  　　　" + HIC + "第　一　式　" + HIR + "『　火～翔～龍～鳴　』" + NOR + "
　　$N雙掌蘊含的陽剛之氣形成一隻火龍，火龍迅速地將$n給吞噬，將$n燒的遍體鱗傷\n" + NOR),me ,victim);
         victim->receive_wound("kee",(bound/50)*10,me);
         COMBAT_D->report_status(victim, 1);
                          break;
case 2:
message_vision(
sprintf("\n""　　　　　　　" + HIR + "" + HBBLU + "$N" + HIW + "　使　出　" + HIY + "降　龍　十　八　掌　" + HIW + "之" + HIG + "　奧　義　秘　招" + NOR + "
　　　　　　" + HIR + "$N" + NOR + "縱躍至天際，吸取天象之氣，真氣爆吐，一龍形氣勁破雲而出
　　　　　　　  　　　" + HIR + "第　二　式　" + HIC + "『　蒼～龍～破～雲　』" + NOR + "
　　只見龍形氣勁有如厲雷疾風的向$N飛奔而去，$n硬擋之下氣勁透體而過，留下一紫黑色的掌傷\n" + NOR),me ,victim);
         victim->receive_wound("sen",(das/50)*10,me);
         COMBAT_D->report_status(victim, 1);
                          break;
case 3:
message_vision(
sprintf("\n""　　　　　　　" + HIR + "" + HBBLU + "$N" + HIW + "　使　出　" + HIY + "降　龍　十　八　掌　" + HIW + "之" + HIG + "　奧　義　秘　招" + NOR + "
　　　　　　" + HIR + "$N" + NOR + "腳下輕點，將身法提升至極限，掌影幻化，剎那間幻化出無限身影
　　　　　　　  　　　" + HIG + "第　三　式　" + HIY + "『　千～幻～流～光　』" + NOR + "
　　千重幻影轉瞬幻化為一，$N縱身一躍，身形化作一道長虹，向$n投去，揮掌急拍，掌勁透胸而過\n" + NOR),me ,victim);
         victim->receive_wound("gin",(dag/50)*10,me);
         COMBAT_D->report_status(victim, 1);
                          break;
case 4:
message_vision(
sprintf("\n""　　　　　　　" + HIR + "" + HBBLU + "$N" + HIW + "　使　出　" + HIY + "降　龍　十　八　掌　" + HIW + "之" + HIG + "　奧　義　秘　招" + NOR + "
　　　　　　" + HIR + "$N" + NOR + "腳下輕點，將身法提升至極限，掌影幻化，剎那間幻化出無限身影
　　　　　　　  　　" + HIB + "最　終　奧　義　" + HIM + "『　九～龍～嘯～天　』" + NOR + "
　　千重幻影轉瞬幻化為一，$N縱身一躍，身形化作一道長虹，向$n投去，揮掌急拍，掌勁透胸而過\n" + NOR),me ,victim);
         victim->receive_wound("kee",(bound/50)*10,me);
         victim->receive_wound("gin",(dag/50)*10,me);
         victim->receive_wound("sen",(das/50)*10,me);
         victim->apply_condition("star-stial",random(20)+1);
         COMBAT_D->report_status(victim, 1);
                          break;
}
}
}
}

void power(object me, object victim, object weapon, int damage)
{
        int i,time,pow,combat_exp,sk,max_force;
        sk = me->query_skill("dragon-fist",1);
combat_exp = me->query("combat_exp");
max_force=me->query("max_force");
if( me->query("combat_exp") >= 7000000 && max_force >= 5000 && me->query("force") > 300 && !me->query_temp("conti",1) && 
me->query("family/family_name")=="丐幫" && random(100) < 50)
          {
                    pow=((combat_exp/8000)+sk/2+100);
                    if (pow>2000) pow=2000;

message_vision(HIM + "$N領悟降龍十八掌氣游天地。群龍無首的奧秘，拳式一式接著一式連貫出招，有如濤濤江水連綿不絕！" + HIY + "\t
╭═╮╭══╮  ╦╩╦ ╠══         ╮          ╮ ══╮       ╰╮║╭╯  
║  ║╯╮╭╯  ╩═╩ ╰══╮       ║          ║     ║     ╭══╩══╮
" + BBLU + "║╭╯  ╭╯   ╭══╮╔══╯       ╩          ║     ║     ║╭═══╮║
║╰╗╰╯╰╯ ╠══╣╠══ ╭══╣  ╠══╯  ║     ║     ╰╰═══╯╯
║  ║ ╔╬═  ╠══╣╠══         ╦        ╭╯     ╰╮       ╰╦╯    " + NOR + "" + HIY + "
║═╯ ╩╬═  ╠══╣╠══         ║      ╭╯         ╰╮     ═╬═    
║       ║    ╯    ╯╰══╯       ╰    ╭╯             ╰╮ ╭═╬═╯  
                                                                    ╰╯      
" + NOR,me);
                    time=me->query("max_force")/300;
                    if(time > 18) time=18;
                    for(i=1;i<=time;i++)
                    {
                              switch(i)
                              {        
    case 1:
message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第一式" + HIG + "《" + YEL + "鴻漸于陸" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
    case 2:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第二式" + HIG + "《" + HIC + "利涉大川" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
    case 3:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第三式" + HIG + "《" + HIY + "羚羊" + MAG + "觸番" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
    case 4:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第四式" + HIG + "《" + WHT + "或躍在淵" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
    case 5:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第五式" + HIG + "《" + HIY + "突如其來" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
    case 6:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第六式" + HIG + "《" + HIM + "損" + HIR + "則" + HIM + "有" + HIR + "孚" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
    case 7:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第七式" + HIG + "《" + HIM + "時乘六龍" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
    case 8:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第八式" + HIG + "《" + HIR + "亢龍有悔" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
    case 9:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第九式" + HIG + "《" + HIC + "震" + HIG + "驚" + HIY + "百" + HIR + "里" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
    case 10:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第十式" + HIG + "《" + GRN + "見龍在田" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
    case 11:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第十一式" + HIG + "《" + WHT + "密雲不雨" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
     case 12:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第十二式" + HIG + "《" + HIY + "笑言" + HIC + "啞啞" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
     case 13:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第十三式" + HIG + "《" + HIW + "履" + HIC + "霜冰" + HIW + "至" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
     case 14:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第十四式" + HIG + "《" + HIB + "飛龍" + HIR + "在天" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
     case 15:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第十五式" + HIG + "《" + HIC + "雙龍取水" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
    case 16:
          message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第十六式" + HIG + "《" + HIW + "潛" + HIY + "龍" + HIW + "勿" + HIY + "用" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
     case 17:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第十七式" + HIG + "《" + CYN + "神龍擺\尾" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
     case 18:
            message_vision("$N揮掌急拍使出" + BBLU+HIY + "※降龍十八掌※" + NOR + "第十八式" + HIG + "《" + HIB + "戰" + MAG + "龍" + GRN + "在" + WHT + "野" + HIG + "》" + NOR + "，在對方的胸前留下一個紫黑色的傷痕!!\n", me);
            break;
                                  }
                if (70>random(100)){             
                        victim->add("kee",-pow);
                   me->add("force",-200);
                        COMBAT_D->report_status(victim);
                     } else
                     {
message_vision(HIW + "$n在掌影的包圍之下，看出$N的破綻，左閃右躲的躲過了$N凌厲的殺招\n" + NOR,me,victim);
                   me->add("force",-200);
}                    
}
message_vision(sprintf(HIM + "\n$N使力過度,一時之間無力再戰!\n" + NOR),me,victim);
me->start_busy(1);
          }
}
int valid_learn(object me)
    {
        if( me->query("max_force") < 2000 ) {
            tell_object(me, "你的內力修為不夠, 最少要有二千點。\n");
            return 0;
        }
        if(!(me->query("class") == "beggar")) {
            tell_object(me, "只有丐幫弟子才能學降龍十八掌。\n");
            return 0;
        }
        if( me->query_cor() < 20) {
            tell_object(me, "你的膽識不夠不能學降龍十八掌。\n");
            return 0;
        }
            if( me->query_int() < 20) {
            tell_object(me, "你的資質平庸無法學降龍十八掌。\n");
            return 0;
        }
        if( me->query("force") < 500 ) {
            tell_object(me, "你目前的內力不到五百點, 無法練此絕學。\n");
            return 0;
        }
        if( (me->query("potential") - me->query("learned_points")) < 3 ) {
            tell_object(me, "你的潛能不到三點, 無法練此絕學。\n");
            return 0;
        }
       if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
       return   notify_fail("學降龍十八掌必須空手。\n");
}

void sp2(object me, object victim, object weapon, int damage)
{
 int skill=me->query_skill("dragon-fist",1);
 int bound,dag,das,j;
 bound = victim->query("max_kee");           
 dag = victim->query("max_gin");
 das= victim->query("max_sen");
  if( random(100) < 65 && me->query("max_force") > 2000 && !me->query_temp("conti",1) &&
me->query("family/family_name")=="丐幫")
  {
for(j=1;j<=random(7)+1;j++)
{
              switch(j)
                    {
case 1:
       message_vision(
sprintf(HIR + "$N心生戰意，萬拳幻影，雷霆萬鈞，團團地圍住$n!!""
" + HIY + "～九～州～龍～吟～""
" + HIY + "    ╔╗╔╗ ╮◎      ╦╩╦ ╠══     　╮　　　　  ╰╮║╭╯   
    ╚╝╚╝ ╬═      ╩═╩ ╰══╮     ║         ╭══╩══╮
   ╭═╦═╮║       ╭══╮╔══╯ ╰═╬═══╯ ║╭═══╮║
   ╠═╬═╣║╭     ╠══╣╠══       ║         ╰╰═══╯╯
   ╰═╬═╯╰╮     ╠══╣╠══       ║             ╰╦╯    
   ╰═╬═╮╯╰╮   ╠══╣╠══       ║             ═╬═    
       ╰             ╯    ╯╰══╯     ╰═══╯   ╭═╬═╮  
                                                          ╰╯   ""\n" + NOR),me ,victim);
         victim->receive_wound("kee",(bound/60)*10,me);
         victim->receive_wound("gin",(dag/60)*10,me);
         victim->receive_wound("sen",(das/60)*10,me);
         COMBAT_D->report_status(victim, 1);
                          break;
case 2:
message_vision(
sprintf("
" + HIC + "～神～龍～降～世～""
" + HIC + "    ╔╗╔╗ ╮◎      ╦╩╦ ╠══     　╮　　　　  ╰╮║╭╯   
    ╚╝╚╝ ╬═      ╩═╩ ╰══╮     ║         ╭══╩══╮
   ╭═╦═╮║       ╭══╮╔══╯ ╰═╬═══╯ ║╭═══╮║
   ╠═╬═╣║╭     ╠══╣╠══       ║         ╰╰═══╯╯
   ╰═╬═╯╰╮     ╠══╣╠══       ║             ╰╦╯    
   ╰═╬═╮╯╰╮   ╠══╣╠══       ║             ═╬═    
       ╰             ╯    ╯╰══╯     ╰═══╯   ╭═╬═╮  
                                                          ╰╯   ""\n" + NOR),me ,victim);
         victim->receive_wound("kee",(bound/60)*10,me);
         victim->receive_wound("gin",(dag/60)*10,me);
         victim->receive_wound("sen",(das/60)*10,me);
         victim->apply_condition("star-stial",random(20)+1);
         COMBAT_D->report_status(victim, 1);
                          break;
case 3:
message_vision(
sprintf("
" + HIR + "～天～龍～狂～嘯～""
" + HIR + "    ╔╗╔╗ ╮◎      ╦╩╦ ╠══     　╮　　　　  ╰╮║╭╯   
    ╚╝╚╝ ╬═      ╩═╩ ╰══╮     ║         ╭══╩══╮
   ╭═╦═╮║       ╭══╮╔══╯ ╰═╬═══╯ ║╭═══╮║
   ╠═╬═╣║╭     ╠══╣╠══       ║         ╰╰═══╯╯
   ╰═╬═╯╰╮     ╠══╣╠══       ║             ╰╦╯    
   ╰═╬═╮╯╰╮   ╠══╣╠══       ║             ═╬═    
       ╰             ╯    ╯╰══╯     ╰═══╯   ╭═╬═╮  
                                                          ╰╯   ""\n" + NOR),me ,victim);
         victim->receive_wound("kee",(bound/60)*10,me);
         victim->receive_wound("gin",(dag/60)*10,me);
         victim->receive_wound("sen",(das/60)*10,me);
         victim->apply_condition("star-stial",random(20)+1);
         COMBAT_D->report_status(victim, 1);
                          break;
case 4:
message_vision(
sprintf("
" + HIG + "～奔～雷～龍～破～""
" + HIG + "    ╔╗╔╗ ╮◎      ╦╩╦ ╠══     　╮　　　　  ╰╮║╭╯   
    ╚╝╚╝ ╬═      ╩═╩ ╰══╮     ║         ╭══╩══╮
   ╭═╦═╮║       ╭══╮╔══╯ ╰═╬═══╯ ║╭═══╮║
   ╠═╬═╣║╭     ╠══╣╠══       ║         ╰╰═══╯╯
   ╰═╬═╯╰╮     ╠══╣╠══       ║             ╰╦╯    
   ╰═╬═╮╯╰╮   ╠══╣╠══       ║             ═╬═    
       ╰             ╯    ╯╰══╯     ╰═══╯   ╭═╬═╮  
                                                          ╰╯   ""\n" + NOR),me ,victim);
         victim->receive_wound("kee",(bound/60)*10,me);
         victim->receive_wound("gin",(dag/60)*10,me);
         victim->receive_wound("sen",(das/60)*10,me);
         victim->apply_condition("star-stial",random(20)+1);
         COMBAT_D->report_status(victim, 1);
                          break;
case 5:
message_vision(
sprintf("
" + MAG + "～怒～極～龍～威～""
" + MAG + "    ╔╗╔╗ ╮◎      ╦╩╦ ╠══     　╮　　　　  ╰╮║╭╯   
    ╚╝╚╝ ╬═      ╩═╩ ╰══╮     ║         ╭══╩══╮
   ╭═╦═╮║       ╭══╮╔══╯ ╰═╬═══╯ ║╭═══╮║
   ╠═╬═╣║╭     ╠══╣╠══       ║         ╰╰═══╯╯
   ╰═╬═╯╰╮     ╠══╣╠══       ║             ╰╦╯    
   ╰═╬═╮╯╰╮   ╠══╣╠══       ║             ═╬═    
       ╰             ╯    ╯╰══╯     ╰═══╯   ╭═╬═╮  
                                                          ╰╯   ""\n" + NOR),me ,victim);
         victim->receive_wound("kee",(bound/60)*10,me);
         victim->receive_wound("gin",(dag/60)*10,me);
         victim->receive_wound("sen",(das/60)*10,me);
         victim->apply_condition("star-stial",random(20)+1);
         COMBAT_D->report_status(victim, 1);
                          break;
case 6:
message_vision(
sprintf("
" + WHT + "～殛～龍～天～雷～""
" + WHT + "    ╔╗╔╗ ╮◎      ╦╩╦ ╠══     　╮　　　　  ╰╮║╭╯   
    ╚╝╚╝ ╬═      ╩═╩ ╰══╮     ║         ╭══╩══╮
   ╭═╦═╮║       ╭══╮╔══╯ ╰═╬═══╯ ║╭═══╮║
   ╠═╬═╣║╭     ╠══╣╠══       ║         ╰╰═══╯╯
   ╰═╬═╯╰╮     ╠══╣╠══       ║             ╰╦╯    
   ╰═╬═╮╯╰╮   ╠══╣╠══       ║             ═╬═    
       ╰             ╯    ╯╰══╯     ╰═══╯   ╭═╬═╮  
                                                          ╰╯   ""\n" + NOR),me ,victim);
         victim->receive_wound("kee",(bound/60)*10,me);
         victim->receive_wound("gin",(dag/60)*10,me);
         victim->receive_wound("sen",(das/60)*10,me);
         victim->apply_condition("star-stial",random(20)+1);
         COMBAT_D->report_status(victim, 1);
                          break;
case 7:
message_vision(
sprintf("
" + HIB + "～迴～龍～鎖～關～""
" + HIB + "    ╔╗╔╗ ╮◎      ╦╩╦ ╠══     　╮　　　　  ╰╮║╭╯   
    ╚╝╚╝ ╬═      ╩═╩ ╰══╮     ║         ╭══╩══╮
   ╭═╦═╮║       ╭══╮╔══╯ ╰═╬═══╯ ║╭═══╮║
   ╠═╬═╣║╭     ╠══╣╠══       ║         ╰╰═══╯╯
   ╰═╬═╯╰╮     ╠══╣╠══       ║             ╰╦╯    
   ╰═╬═╮╯╰╮   ╠══╣╠══       ║             ═╬═    
       ╰             ╯    ╯╰══╯     ╰═══╯   ╭═╬═╮  
                                                          ╰╯   ""\n" + NOR),me ,victim);
         victim->receive_wound("kee",(bound/60)*10,me);
         victim->receive_wound("gin",(dag/60)*10,me);
         victim->receive_wound("sen",(das/60)*10,me);
         victim->apply_condition("star-stial",random(20)+1);
         victim->start_busy(1);
         COMBAT_D->report_status(victim, 1);
                          break;
}
}
}
}
void attack(object me, object victim, object weapon, int damage)
{
 int busy_value,skill;
 skill=me->query_skill("dragon-fist", 1);
 busy_value = skill / 50;
 if( random(100) < 65 &&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIC + "兩道陰柔冷冽勁氣竄入$N的體內，奇寒蝕骨使$N一時無法行動。\n" + NOR,victim);
   victim->start_busy( random(busy_value) );
   COMBAT_D->report_status(victim, 1);
   victim->apply_condition("cold",random(15));
  }
}
